/******************************************************************************\
 * Copyright (c) 2004-2014
 *
 * Author(s):
 *  Volker Fischer
 *
 ******************************************************************************
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation; either version 2 of the License, or (at your option) any later 
 * version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT 
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more 
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc., 
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
\******************************************************************************/

#include "channel.h"


// CChannel implementation *****************************************************
CChannel::CChannel ( const bool bNIsServer ) :
    vecdGains          ( MAX_NUM_CHANNELS, (double) 1.0 ),
    bDoAutoSockBufSize ( true ),
    bIsEnabled         ( false ),
    bIsServer          ( bNIsServer )
{
    // reset network transport properties
    ResetNetworkTransportProperties();

    // initial value for connection time out counter, we calculate the total
    // number of samples here and subtract the number of samples of the block
    // which we take out of the buffer to be independent of block sizes
    iConTimeOutStartVal = CON_TIME_OUT_SEC_MAX * SYSTEM_SAMPLE_RATE_HZ;

    // init time-out for the buffer with zero -> no connection
    iConTimeOut = 0;

    // init the socket buffer
    SetSockBufNumFrames ( DEF_NET_BUF_SIZE_NUM_BL );

    // initialize channel info
    ResetInfo();


    // Connections -------------------------------------------------------------

// TODO if we later do not fire vectors in the emits, we can remove this again
qRegisterMetaType<CVector<uint8_t> > ( "CVector<uint8_t>" );
qRegisterMetaType<CHostAddress> ( "CHostAddress" );

    QObject::connect ( &Protocol,
        SIGNAL ( MessReadyForSending ( CVector<uint8_t> ) ),
        this, SLOT ( OnSendProtMessage ( CVector<uint8_t> ) ) );

    QObject::connect ( &Protocol,
        SIGNAL ( ChangeJittBufSize ( int ) ),
        this, SLOT ( OnJittBufSizeChange ( int ) ) );

    QObject::connect ( &Protocol,
        SIGNAL ( ReqJittBufSize() ),
        SIGNAL ( ReqJittBufSize() ) );

    QObject::connect ( &Protocol,
        SIGNAL ( ReqChanInfo() ),
        SIGNAL ( ReqChanInfo() ) );

    QObject::connect ( &Protocol,
        SIGNAL ( ReqConnClientsList() ),
        SIGNAL ( ReqConnClientsList() ) );

    QObject::connect ( &Protocol,
        SIGNAL ( ConClientListNameMesReceived ( CVector<CChannelInfo> ) ),
        SIGNAL ( ConClientListNameMesReceived ( CVector<CChannelInfo> ) ) );

    QObject::connect ( &Protocol,
        SIGNAL ( ConClientListMesReceived ( CVector<CChannelInfo> ) ),
        SIGNAL ( ConClientListMesReceived ( CVector<CChannelInfo> ) ) );

    QObject::connect( &Protocol, SIGNAL ( ChangeChanGain ( int, double ) ),
        this, SLOT ( OnChangeChanGain ( int, double ) ) );

    QObject::connect( &Protocol, SIGNAL ( ChangeChanName ( QString ) ),
        this, SLOT ( OnChangeChanName ( QString ) ) );

    QObject::connect( &Protocol, SIGNAL ( ChangeChanInfo ( CChannelCoreInfo ) ),
        this, SLOT ( OnChangeChanInfo ( CChannelCoreInfo ) ) );

    QObject::connect( &Protocol,
        SIGNAL ( ChatTextReceived ( QString ) ),
        SIGNAL ( ChatTextReceived ( QString ) ) );

// #### COMPATIBILITY OLD VERSION, TO BE REMOVED ####
QObject::connect ( &Protocol,
    SIGNAL ( OpusSupported() ),
    SIGNAL ( OpusSupported() ) );

    QObject::connect ( &Protocol,
        SIGNAL ( NetTranspPropsReceived ( CNetworkTransportProps ) ),
        this, SLOT ( OnNetTranspPropsReceived ( CNetworkTransportProps ) ) );

    QObject::connect ( &Protocol,
        SIGNAL ( ReqNetTranspProps() ),
        this, SLOT ( OnReqNetTranspProps() ) );
}

bool CChannel::ProtocolIsEnabled()
{
    // for the server, only enable protocol if the channel is connected, i.e.,
    // successfully audio packets are received from a client
    // for the client, enable protocol if the channel is enabled, i.e., the
    // connection button was hit by the user
    if ( bIsServer )
    {
        return IsConnected();
    }
    else
    {
        return bIsEnabled;
    }
}

void CChannel::SetEnable ( const bool bNEnStat )
{
    QMutexLocker locker ( &Mutex );

    // set internal parameter
    bIsEnabled = bNEnStat;

    // if channel is not enabled, reset time out count and protocol
    if ( !bNEnStat )
    {
        iConTimeOut = 0;
        Protocol.Reset();
    }
}

void CChannel::SetAudioStreamProperties ( const EAudComprType eNewAudComprType,
                                          const int iNewNetwFrameSize,
                                          const int iNewNetwFrameSizeFact,
                                          const int iNewNumAudioChannels )
{
/*
    this function is intended for the client (not the server)
*/

    CNetworkTransportProps NetworkTransportProps;

    Mutex.lock();
    {
        // store new values
        eAudioCompressionType = eNewAudComprType;
        iNumAudioChannels     = iNewNumAudioChannels;
        iNetwFrameSize        = iNewNetwFrameSize;
        iNetwFrameSizeFact    = iNewNetwFrameSizeFact;

        MutexSocketBuf.lock();
        {
            // init socket buffer
            SockBuf.Init ( iNetwFrameSize, iCurSockBufNumFrames );
        }
        MutexSocketBuf.unlock();

        MutexConvBuf.lock();
        {
            // init conversion buffer
            ConvBuf.Init ( iNetwFrameSize * iNetwFrameSizeFact );
        }
        MutexConvBuf.unlock();

        // fill network transport properties struct
        NetworkTransportProps =
            GetNetworkTransportPropsFromCurrentSettings();
    }
    Mutex.unlock();

    // tell the server about the new network settings
    Protocol.CreateNetwTranspPropsMes ( NetworkTransportProps );
}

bool CChannel::SetSockBufNumFrames ( const int  iNewNumFrames,
                                     const bool bPreserve )
{
    bool ReturnValue           = true;  // init with error
    bool bCurDoAutoSockBufSize = false; // we have to init but init values does not matter

    // first check for valid input parameter range
    if ( ( iNewNumFrames >= MIN_NET_BUF_SIZE_NUM_BL ) &&
         ( iNewNumFrames <= MAX_NET_BUF_SIZE_NUM_BL ) )
    {
        // only apply parameter if new parameter is different from current one
        if ( iCurSockBufNumFrames != iNewNumFrames )
        {
            MutexSocketBuf.lock();
            {
                // store new value
                iCurSockBufNumFrames = iNewNumFrames;

                // the network block size is a multiple of the minimum network
                // block size
                SockBuf.Init ( iNetwFrameSize, iNewNumFrames, bPreserve );

                // store current auto socket buffer size setting in the mutex
                // region since if we use the current parameter below in the
                // if condition, it may have been changed in between the time
                // when we have left the mutex region and entered the if
                // condition
                bCurDoAutoSockBufSize = bDoAutoSockBufSize;

                ReturnValue = false; // -> no error
            }
            MutexSocketBuf.unlock();
        }
    }

    // only in case there is no error, we are the server and auto jitter buffer
    // setting is enabled, we have to report the current setting to the client
    if ( !ReturnValue && bIsServer && bCurDoAutoSockBufSize )
    {
        // we cannot call the "CreateJitBufMes" function directly since
        // this would give us problems with different threads (e.g. the
        // timer thread) and the protocol mechanism (problem with
        // qRegisterMetaType(), etc.)
        emit ServerAutoSockBufSizeChange ( iNewNumFrames );
    }

    return ReturnValue; // set error flag
}

void CChannel::SetGain ( const int    iChanID,
                         const double dNewGain )
{
    QMutexLocker locker ( &Mutex );

    // set value (make sure channel ID is in range)
    if ( ( iChanID >= 0 ) && ( iChanID < MAX_NUM_CHANNELS ) )
    {
        vecdGains[iChanID] = dNewGain;
    }
}

double CChannel::GetGain ( const int iChanID )
{
    QMutexLocker locker ( &Mutex );

    // get value (make sure channel ID is in range)
    if ( ( iChanID >= 0 ) && ( iChanID < MAX_NUM_CHANNELS ) )
    {
        return vecdGains[iChanID];
    }
    else
    {
        return 0;
    }
}

void CChannel::SetChanInfo ( const CChannelCoreInfo& NChanInf )
{
    // apply value (if different from previous one)
    if ( ChannelInfo != NChanInf )
    {
        ChannelInfo = NChanInf;

        // fire message that the channel info has changed
        emit ChanInfoHasChanged();
    }
}

void CChannel::SetName ( const QString strNewName )
{
    bool bNameHasChanged = false;

    Mutex.lock();
    {
        // apply value (if different from previous one)
        if ( ChannelInfo.strName.compare ( strNewName ) )
        {
            ChannelInfo.strName = strNewName;
            bNameHasChanged     = true;
        }
    }
    Mutex.unlock();

    // fire message that name has changed
    if ( bNameHasChanged )
    {
        // the "emit" has to be done outside the mutexed region
        emit ChanInfoHasChanged();
    }
}
QString CChannel::GetName()
{
    // make sure the string is not written at the same time when it is
    // read here -> use mutex to secure access
    QMutexLocker locker ( &Mutex );

    return ChannelInfo.strName;
}

void CChannel::OnSendProtMessage ( CVector<uint8_t> vecMessage )
{
    // only send messages if protocol is enabled, otherwise delete complete
    // queue
    if ( ProtocolIsEnabled() )
    {
        // emit message to actually send the data
        emit MessReadyForSending ( vecMessage );
    }
    else
    {
        // delete send message queue
        Protocol.Reset();
    }
}

void CChannel::OnJittBufSizeChange ( int iNewJitBufSize )
{
    // for server apply setting, for client emit message
    if ( bIsServer )
    {
        // first check for special case: auto setting
        if ( iNewJitBufSize == AUTO_NET_BUF_SIZE_FOR_PROTOCOL )
        {
            SetDoAutoSockBufSize ( true );
        }
        else
        {
            // manual setting is received, turn OFF auto setting and apply new value
            SetDoAutoSockBufSize ( false );
            SetSockBufNumFrames ( iNewJitBufSize, true );
        }
    }
    else
    {
        emit JittBufSizeChanged ( iNewJitBufSize );
    }
}

void CChannel::OnChangeChanGain ( int    iChanID,
                                  double dNewGain )
{
    SetGain ( iChanID, dNewGain );
}

void CChannel::OnChangeChanName ( QString strName )
{
    SetName ( strName );
}

void CChannel::OnChangeChanInfo ( CChannelCoreInfo ChanInfo )
{
    SetChanInfo ( ChanInfo );
}

bool CChannel::GetAddress ( CHostAddress& RetAddr )
{
    QMutexLocker locker ( &Mutex );

    if ( IsConnected() )
    {
        RetAddr = InetAddr;
        return true;
    }
    else
    {
        RetAddr = CHostAddress();
        return false;
    }
}

void CChannel::OnNetTranspPropsReceived ( CNetworkTransportProps NetworkTransportProps )
{
    // only the server shall act on network transport properties message
    if ( bIsServer )
    {
        Mutex.lock();
        {
            // store received parameters
            eAudioCompressionType = NetworkTransportProps.eAudioCodingType;
            iNumAudioChannels     = NetworkTransportProps.iNumAudioChannels;
            iNetwFrameSizeFact    = NetworkTransportProps.iBlockSizeFact;
            iNetwFrameSize =
                NetworkTransportProps.iBaseNetworkPacketSize;

            MutexSocketBuf.lock();
            {
                // update socket buffer (the network block size is a multiple of the
                // minimum network frame size
                SockBuf.Init ( iNetwFrameSize, iCurSockBufNumFrames );
            }
            MutexSocketBuf.unlock();

            MutexConvBuf.lock();
            {
                // init conversion buffer
                ConvBuf.Init ( iNetwFrameSize * iNetwFrameSizeFact );
            }
            MutexConvBuf.unlock();
        }
        Mutex.unlock();

        // if old CELT codec is used, inform the client that the new OPUS codec
        // is supported
        if ( NetworkTransportProps.eAudioCodingType != CT_OPUS )
        {
            Protocol.CreateOpusSupportedMes();
        }
    }
}

void CChannel::OnReqNetTranspProps()
{
    // fill network transport properties struct from current settings and send it
    Protocol.CreateNetwTranspPropsMes ( GetNetworkTransportPropsFromCurrentSettings() );
}

CNetworkTransportProps CChannel::GetNetworkTransportPropsFromCurrentSettings()
{
    // use current stored settings of the channel to fill the network transport
    // properties structure
    return CNetworkTransportProps (
        iNetwFrameSize,
        iNetwFrameSizeFact,
        iNumAudioChannels,
        SYSTEM_SAMPLE_RATE_HZ,
        eAudioCompressionType,
        0, // version of the codec
        0 );
}

void CChannel::Disconnect()
{
    // we only have to disconnect the channel if it is actually connected
    if ( IsConnected() )
    {
        // set time out counter to a small value > 0 so that the next time a
        // received audio block is queried, the disconnection is performed
        // (assuming that no audio packet is received in the meantime)
        iConTimeOut = 1; // a small number > 0
    }
}

void CChannel::PutProtcolData ( const int               iRecCounter,
                                const int               iRecID,
                                const CVector<uint8_t>& vecbyMesBodyData,
                                const CHostAddress&     RecHostAddr )
{
    // Only process protocol message if:
    // - for client only: the packet comes from the server we want to talk to
    // - the channel is enabled
    // - the protocol mechanism is enabled
    if ( ( bIsServer || ( GetAddress() == RecHostAddr ) ) &&
         IsEnabled() &&
         ProtocolIsEnabled() )
    {
        // parse the message assuming this is a regular protocol message
        Protocol.ParseMessageBody ( vecbyMesBodyData, iRecCounter, iRecID );
    }
}

EPutDataStat CChannel::PutAudioData ( const CVector<uint8_t>& vecbyData,
                                      const int               iNumBytes,
                                      CHostAddress            RecHostAddr )
{
    // init return state
    EPutDataStat eRet = PS_GEN_ERROR;

    // Only process audio data if:
    // - for client only: the packet comes from the server we want to talk to
    // - the channel is enabled
    if ( ( bIsServer || ( GetAddress() == RecHostAddr ) ) &&
         IsEnabled() )
    {
        MutexSocketBuf.lock();
        {
            // only process audio if packet has correct size
            if ( iNumBytes == ( iNetwFrameSize * iNetwFrameSizeFact ) )
            {
                // store new packet in jitter buffer
                if ( SockBuf.Put ( vecbyData, iNumBytes ) )
                {
                    eRet = PS_AUDIO_OK;
                }
                else
                {
                    eRet = PS_AUDIO_ERR;
                }
            }
            else
            {
                // the protocol parsing failed and this was no audio block,
                // we treat this as protocol error (unkown packet)
                eRet = PS_PROT_ERR;
            }

            // All network packets except of valid protocol messages
            // regardless if they are valid or invalid audio packets lead to
            // a state change to a connected channel.
            // This is because protocol messages can only be sent on a
            // connected channel and the client has to inform the server
            // about the audio packet properties via the protocol.

            // check if channel was not connected, this is a new connection
            if ( !IsConnected() )
            {
                // overwrite status
                eRet = PS_NEW_CONNECTION;
            }

            // reset time-out counter (note that this must be done after the
            // "IsConnected()" query above)
            ResetTimeOutCounter();
        }
        MutexSocketBuf.unlock();
    }
    else
    {
        eRet = PS_AUDIO_INVALID;
    }

    return eRet;
}

EGetDataStat CChannel::GetData ( CVector<uint8_t>& vecbyData,
                                 const int         iNumBytes )
{
    EGetDataStat eGetStatus;

    MutexSocketBuf.lock();
    {
        // the socket access must be inside a mutex
        const bool bSockBufState = SockBuf.Get ( vecbyData, iNumBytes );

        // decrease time-out counter
        if ( iConTimeOut > 0 )
        {
            // subtract the number of samples of the current block since the
            // time out counter is based on samples not on blocks (definition:
            // always one atomic block is get by using the GetData() function
            // where the atomic block size is "SYSTEM_FRAME_SIZE_SAMPLES")

// TODO this code only works with the above assumption -> better
// implementation so that we are not depending on assumptions

            iConTimeOut -= SYSTEM_FRAME_SIZE_SAMPLES;

            if ( iConTimeOut <= 0 )
            {
                // channel is just disconnected
                eGetStatus  = GS_CHAN_NOW_DISCONNECTED;
                iConTimeOut = 0; // make sure we do not have negative values

                // reset network transport properties
                ResetNetworkTransportProperties();
            }
            else
            {
                if ( bSockBufState )
                {
                    // everything is ok
                    eGetStatus = GS_BUFFER_OK;
                }
                else
                {
                    // channel is not yet disconnected but no data in buffer
                    eGetStatus = GS_BUFFER_UNDERRUN;
                }
            }
        }
        else
        {
            // channel is disconnected
            eGetStatus = GS_CHAN_NOT_CONNECTED;
        }
    }
    MutexSocketBuf.unlock();

    // in case we are just disconnected, we have to fire a message
    if ( eGetStatus == GS_CHAN_NOW_DISCONNECTED )
    {
        // emit message
        emit Disconnected();
    }

    return eGetStatus;
}

void CChannel::PrepAndSendPacket ( CHighPrioSocket*        pSocket,
                                   const CVector<uint8_t>& vecbyNPacket,
                                   const int               iNPacketLen )
{
    QMutexLocker locker ( &MutexConvBuf );

    // use conversion buffer to convert sound card block size in network
    // block size
    if ( ConvBuf.Put ( vecbyNPacket, iNPacketLen ) )
    {
        pSocket->SendPacket ( ConvBuf.Get(), GetAddress() );
    }
}

int CChannel::GetUploadRateKbps()
{
    const int iAudioSizeOut = iNetwFrameSizeFact * SYSTEM_FRAME_SIZE_SAMPLES;

    // we assume that the UDP packet which is transported via IP has an
    // additional header size of ("Network Music Performance (NMP) in narrow
    // band networks; Carot, Kraemer, Schuller; 2006")
    // 8 (UDP) + 20 (IP without optional fields) = 28 bytes
    // 2 (PPP) + 6 (PPPoE) + 18 (MAC)            = 26 bytes
    // 5 (RFC1483B) + 8 (AAL) + 10 (ATM)         = 23 bytes
    return ( iNetwFrameSize * iNetwFrameSizeFact + 28 + 26 + 23 /* header */ ) *
        8 /* bits per byte */ *
        SYSTEM_SAMPLE_RATE_HZ / iAudioSizeOut / 1000;
}

void CChannel::UpdateSocketBufferSize()
{
    // just update the socket buffer size if auto setting is enabled, otherwise
    // do nothing
    if ( bDoAutoSockBufSize )
    {
        // use auto setting result from channel, make sure we preserve the
        // buffer memory since we just adjust the size here
        SetSockBufNumFrames ( SockBuf.GetAutoSetting(), true );
    }
}
