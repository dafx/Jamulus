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

#if !defined ( UTIL_HOIH934256GEKJH98_3_43445KJIUHF1912__INCLUDED_ )
#define UTIL_HOIH934256GEKJH98_3_43445KJIUHF1912__INCLUDED_

#include <QHostAddress>
#include <QHostInfo>
#include <QMenu>
#include <QWhatsThis>
#include <QTextBrowser>
#include <QLabel>
#include <QDateTime>
#include <QFile>
#include <QDesktopServices>
#include <QUrl>
#include <QLocale>
#include <vector>
#include <algorithm>
#include "global.h"
using namespace std; // because of the library: "vector"
#ifdef _WIN32
# include <windows.h>
# include <mmsystem.h>
#elif !defined ( __APPLE__ ) && !defined ( __MACOSX )
# include <sys/time.h>
#endif
#include "ui_aboutdlgbase.h"


/* Definitions ****************************************************************/
#define METER_FLY_BACK              2


/* Global functions ***********************************************************/
// converting double to short
inline short Double2Short ( const double dInput )
{
    // lower bound
    if ( dInput < _MINSHORT )
    {
        return _MINSHORT;
    }

    // upper bound
    if ( dInput > _MAXSHORT )
    {
        return _MAXSHORT;
    }

    return (short) dInput;
}

// debug error handling
void DebugError ( const QString& pchErDescr,
                  const QString& pchPar1Descr, 
                  const double   dPar1,
                  const QString& pchPar2Descr,
                  const double   dPar2 );

// calculate the bit rate in bits per second from the number of coded bytes
inline int CalcBitRateBitsPerSecFromCodedBytes ( const int iCeltNumCodedBytes )
{
    return ( SYSTEM_SAMPLE_RATE_HZ * iCeltNumCodedBytes * 8 ) /
        SYSTEM_FRAME_SIZE_SAMPLES;
}



/******************************************************************************\
* CVector Base Class                                                           *
\******************************************************************************/
template<class TData> class CVector : public std::vector<TData>
{
public:
    CVector() {}
    CVector ( const int iNeSi ) { Init ( iNeSi ); }
    CVector ( const int   iNeSi,
              const TData tInVa ) { Init ( iNeSi, tInVa ); }

    void Init ( const int iNewSize );

    // use this init to give all elements a defined value
    void Init ( const int   iNewSize,
                const TData tIniVal );

    // set all values to the given reset value
    void Reset ( const TData tResetVal )
    {
        std::fill ( this->begin(), this->end(), tResetVal );
    }

    void Enlarge ( const int iAddedSize )
    {
        std::vector<TData>::resize ( std::vector<TData>::size() + iAddedSize );
    }

    void Add ( const TData& tI )
    {
        Enlarge ( 1 );
        std::vector<TData>::back() = tI;
    }

    int StringFiFoWithCompare ( const QString strNewValue,
                                const bool    bDoAdding = true );

    // this function simply converts the type of size to integer
    inline int Size() const { return std::vector<TData>::size(); }

    // This operator allows for a l-value assignment of this object:
    // CVector[x] = y is possible
    inline TData& operator[] ( const int iPos )
    {
#ifdef _DEBUG_
        if ( ( iPos < 0 ) || ( iPos > Size() - 1 ) )
        {
            DebugError ( "Writing vector out of bounds", "Vector size",
                Size(), "New parameter", iPos );
        }
#endif
        return std::vector<TData>::operator[] ( iPos );
    }

    inline TData operator[] ( const int iPos ) const
    {
#ifdef _DEBUG_
        if ( ( iPos < 0 ) || ( iPos > Size() - 1 ) )
        {
            DebugError ( "Reading vector out of bounds", "Vector size",
                Size(), "New parameter", iPos );
        }
#endif
        return std::vector<TData>::operator[] ( iPos );
    }

    inline CVector<TData>& operator= ( const CVector<TData>& vecI )
    {
#ifdef _DEBUG_
        // vectors which shall be copied MUST have same size!
        if ( vecI.Size() != Size() )
        {
            DebugError ( "Vector operator=() different size", "Vector size",
                Size(), "New parameter", vecI.Size() );
        }
#endif
        std::vector<TData>::operator= ( vecI );

        return *this;
    }
};


/* Implementation *************************************************************/
template<class TData> void CVector<TData>::Init ( const int iNewSize )
{
    // clear old buffer and reserve memory for new buffer
    std::vector<TData>::clear();
    std::vector<TData>::resize ( iNewSize );
}

template<class TData> void CVector<TData>::Init ( const int   iNewSize, 
                                                  const TData tIniVal )
{
    // call actual init routine and reset all values to the given value
    Init ( iNewSize );
    Reset ( tIniVal );
}

// note: this is only supported for string vectors
template<class TData> int CVector<TData>::StringFiFoWithCompare ( const QString strNewValue,
                                                                  const bool    bDoAdding )
{
    const int iVectorSize = Size();

    CVector<QString> vstrTempList ( iVectorSize, "" );

    // init with illegal index per definition
    int iOldIndex = -1;

    // init temporary list count (may be overwritten later on)
    int iTempListCnt = 0;

    if ( bDoAdding )
    {
        // store the new element in the current storage list at
        // the top, make sure we do not have more than allowed stored
        // elements
        vstrTempList[0] = strNewValue;
        iTempListCnt    = 1;
    }

    for ( int iIdx = 0; iIdx < iVectorSize; iIdx++ )
    {
        // first check if we still have space in our data storage
        if ( iTempListCnt < iVectorSize )
        {
            // only add old element if it is not the same as the
            // selected one
            if ( operator[] ( iIdx ).compare ( strNewValue ) )
            {
                vstrTempList[iTempListCnt] = operator[] ( iIdx );

                iTempListCnt++;
            }
            else
            {
                iOldIndex = iIdx;
            }
        }
    }

    // copy new generated list to data base
    *this = vstrTempList;

    return iOldIndex;
}



/******************************************************************************\
* CFIFO Class (First In, First Out)                                            *
\******************************************************************************/
template<class TData> class CFIFO : public CVector<TData>
{
public:
    CFIFO() : iCurIdx ( 0 ) {}
    CFIFO ( const int iNeSi ) : CVector<TData> ( iNeSi ), iCurIdx ( 0 ) {}
    CFIFO ( const int iNeSi, const TData tInVa ) :
        CVector<TData> ( iNeSi, tInVa ), iCurIdx ( 0 ) {}

    void Add ( const TData tNewD );
    inline TData Get() { return CVector<TData>::operator[] ( iCurIdx ); }

    virtual void Init ( const int iNewSize );

    virtual void Init ( const int   iNewSize,
                        const TData tIniVal );

protected:
    int iCurIdx;
};

template<class TData> void CFIFO<TData>::Init ( const int iNewSize )
{
    iCurIdx = 0;
    CVector<TData>::Init ( iNewSize );
}

template<class TData> void CFIFO<TData>::Init ( const int   iNewSize,
                                                const TData tIniVal )
{
    iCurIdx = 0;
    CVector<TData>::Init ( iNewSize, tIniVal );
}

template<class TData> void CFIFO<TData>::Add ( const TData tNewD )
{
    CVector<TData>::operator[] ( iCurIdx ) = tNewD;

    // increment index and check for wrap around
    iCurIdx++;

    if ( iCurIdx >= CVector<TData>::Size() )
    {
        iCurIdx = 0;
    }
}


/******************************************************************************\
* CMovingAv Class (Moving Average)                                             *
\******************************************************************************/
template<class TData> class CMovingAv : public CVector<TData>
{
public:
    CMovingAv() :
        CVector<TData>(),
        iCurIdx ( 0 ),
        iNorm ( 0 ),
        dCurAvResult ( 0 ),
        dNoDataResult ( 0 ) {}

    void Add ( const TData tNewD );
    
    void Init ( const int    iNewSize,
                const double dNNoDRes = 0 );

    void Reset();

    inline double GetAverage()
    {
        // make sure we do not divide by zero
        if ( iNorm == 0 )
        {
            return dNoDataResult;
        }
        else
        {
            return dCurAvResult / iNorm;
        }
    }

    double InitializationState() const
    {
        // make sure we do not divide by zero
        if ( CVector<TData>::Size() != 0 )
        {
            return static_cast<double> ( iNorm ) / CVector<TData>::Size();
        }
        else
        {
            return 0;
        }
     }

protected:
    int    iCurIdx;
    int    iNorm;
    double dCurAvResult;
    double dNoDataResult;
};

template<class TData> void CMovingAv<TData>::Init ( const int    iNewSize,
                                                    const double dNNoDRes )
{
    iNorm         = 0;
    iCurIdx       = 0;
    dCurAvResult  = 0; // only for scalars!
    dNoDataResult = dNNoDRes;
    CVector<TData>::Init ( iNewSize );
}

template<class TData> void CMovingAv<TData>::Reset()
{
    iNorm        = 0;
    iCurIdx      = 0;
    dCurAvResult = 0; // only for scalars!
    CVector<TData>::Reset ( TData ( 0 ) );
}

template<class TData> void CMovingAv<TData>::Add ( const TData tNewD )
{
/*
    Optimized calculation of the moving average. We only add a new value and
    subtract the old value from the result. We only need one addition and a
    history buffer.
*/

    // subtract oldest value
    dCurAvResult -= CVector<TData>::operator[] ( iCurIdx );

    // add new value and write in memory
    dCurAvResult += tNewD;
    CVector<TData>::operator[] ( iCurIdx ) = tNewD;

    // increase position pointer and test if wrap
    iCurIdx++;
    if ( iCurIdx >= CVector<TData>::Size() )
    {
        iCurIdx = 0;
    }

    // take care of norm
    if ( iNorm < CVector<TData>::Size() )
    {
        iNorm++;
    }
}


/******************************************************************************\
* GUI Utilities                                                                *
\******************************************************************************/
// About dialog ----------------------------------------------------------------
class CAboutDlg : public QDialog, private Ui_CAboutDlgBase
{
    Q_OBJECT

public:
    CAboutDlg ( QWidget* parent = 0 );

    static QString GetVersionAndNameStr ( const bool bWithHtml = true );
};


// Help menu -------------------------------------------------------------------
class CHelpMenu : public QMenu
{
    Q_OBJECT

public:
    CHelpMenu ( QWidget* parent = 0 );

protected:
    CAboutDlg AboutDlg;

public slots:
    void OnHelpWhatsThis() { QWhatsThis::enterWhatsThisMode(); }
    void OnHelpAbout() { AboutDlg.exec(); }
    void OnHelpDownloadLink()
        { QDesktopServices::openUrl ( QUrl ( LLCON_DOWNLOAD_URL ) ); }
};


/******************************************************************************\
* Other Classes/Enums                                                          *
\******************************************************************************/


// Audio channel configuration -------------------------------------------------
enum EAudChanConf
{
    // used for settings -> enum values must be fixed!
    CC_MONO = 0,
    CC_MONO_IN_STEREO_OUT = 1,
    CC_STEREO = 2
};


// Audio compression type enum -------------------------------------------------
enum EAudComprType
{
    // used for protocol -> enum values must be fixed!
    CT_NONE = 0,
    CT_CELT = 1,
    CT_OPUS = 2
};


// Audio quality enum ----------------------------------------------------------
enum EAudioQuality
{
    // used for settings and the comobo box index -> enum values must be fixed!
    AQ_LOW = 0,
    AQ_NORMAL = 1,
    AQ_HIGH = 2
};


// Get data status enum --------------------------------------------------------
enum EGetDataStat
{
    GS_BUFFER_OK,
    GS_BUFFER_UNDERRUN,
    GS_CHAN_NOW_DISCONNECTED,
    GS_CHAN_NOT_CONNECTED
};


// GUI design enum -------------------------------------------------------------
enum EGUIDesign
{
    // used for settings -> enum values must be fixed!
    GD_STANDARD = 0,
    GD_ORIGINAL = 1
};


// Skill level enum ------------------------------------------------------------
enum ESkillLevel
{
    // used for protocol -> enum values must be fixed!
    SL_NOT_SET = 0,
    SL_BEGINNER = 1,
    SL_INTERMEDIATE = 2,
    SL_PROFESSIONAL = 3
};


// Stereo signal level meter ---------------------------------------------------
class CStereoSignalLevelMeter
{
public:
    CStereoSignalLevelMeter() { Reset(); }

    void   Update ( const CVector<short>& vecsAudio );
    double MicLevelLeft()  { return CalcLogResult ( dCurLevelL ); }
    double MicLevelRight() { return CalcLogResult ( dCurLevelR ); }
    void   Reset()
    {
        dCurLevelL = 0.0;
        dCurLevelR = 0.0;
    }

protected:
    double CalcLogResult  ( const double& dLinearLevel );
    double UpdateCurLevel ( double        dCurLevel,
                            const short&  sMax );

    double dCurLevelL;
    double dCurLevelR;
};


// Host address ----------------------------------------------------------------
class CHostAddress
{
public:
    enum EStringMode
    {
        SM_IP_PORT,
        SM_IP_NO_LAST_BYTE,
        SM_IP_NO_LAST_BYTE_PORT
    };

    CHostAddress() :
        InetAddr ( static_cast<quint32> ( 0 ) ),
        iPort ( 0 ) {}

    CHostAddress ( const QHostAddress NInetAddr,
                   const quint16      iNPort ) :
        InetAddr ( NInetAddr ),
        iPort    ( iNPort ) {}

    CHostAddress ( const CHostAddress& NHAddr ) :
        InetAddr ( NHAddr.InetAddr ),
        iPort    ( NHAddr.iPort ) {}

    // copy operator
    CHostAddress& operator= ( const CHostAddress& NHAddr )
    {
        InetAddr = NHAddr.InetAddr;
        iPort    = NHAddr.iPort;
        return *this;
    }

    // compare operator
    bool operator== ( const CHostAddress& CompAddr ) const
    {
        return ( ( CompAddr.InetAddr == InetAddr ) &&
                 ( CompAddr.iPort    == iPort ) );
    }

    QString toString ( const EStringMode eStringMode = SM_IP_PORT ) const
    {
        QString strReturn = InetAddr.toString();

        // special case: for local host address, we do not replace the last byte
        if ( ( ( eStringMode == SM_IP_NO_LAST_BYTE ) ||
               ( eStringMode == SM_IP_NO_LAST_BYTE_PORT ) ) && 
             ( InetAddr != QHostAddress ( QHostAddress::LocalHost ) ) )
        {
            // replace last byte by an "x"
            strReturn = strReturn.section ( ".", 0, 2 ) + ".x";
        }

        if ( ( eStringMode == SM_IP_PORT ) ||
             ( eStringMode == SM_IP_NO_LAST_BYTE_PORT ) )
        {
            // add port number after a semicolon
            strReturn += ":" + QString().setNum ( iPort );
        }

        return strReturn;
    }

    QHostAddress InetAddr;
    quint16      iPort;
};


// Instrument picture data base ------------------------------------------------
// this is a pure static class
class CInstPictures
{
public:
    enum EInstCategory
    {
        IC_OTHER_INSTRUMENT,
        IC_WIND_INSTRUMENT,
        IC_STRING_INSTRUMENT,
        IC_PLUCKING_INSTRUMENT,
        IC_PERCUSSION_INSTRUMENT,
        IC_KEYBOARD_INSTRUMENT
    };

    // per definition: the very first instrument is the "not used" instrument
    static int  GetNotUsedInstrument() { return 0; }
    static bool IsNotUsedInstrument ( const int iInstrument ) { return iInstrument == 0; }

    static int GetNumAvailableInst() { return GetTable().Size(); }
    static QString GetResourceReference ( const int iInstrument );
    static QString GetName ( const int iInstrument );

// TODO make use of instrument category (not yet implemented)

protected:
    class CInstPictProps
    {
    public:
        CInstPictProps() :
            strName              ( "" ),
            strResourceReference ( "" ),
            eInstCategory        ( IC_OTHER_INSTRUMENT ) {}

        CInstPictProps ( const QString       NsName,
                         const QString       NsResRef,
                         const EInstCategory NeInstCat ) :
            strName              ( NsName ),
            strResourceReference ( NsResRef ),
            eInstCategory        ( NeInstCat ) {}

        QString       strName;
        QString       strResourceReference;
        EInstCategory eInstCategory;
    };

    static bool IsInstIndexInRange ( const int iIdx );

    static CVector<CInstPictProps>& GetTable();
};


// Info of a channel -----------------------------------------------------------
class CChannelCoreInfo
{
public:
    CChannelCoreInfo() :
        strName         ( "" ),
        eCountry        ( QLocale::AnyCountry ),
        strCity         ( "" ),
        iInstrument     ( CInstPictures::GetNotUsedInstrument() ),
        eSkillLevel     ( SL_NOT_SET ) {}

    CChannelCoreInfo ( const QString           NsName,
                       const QLocale::Country& NeCountry,
                       const QString&          NsCity,
                       const int               NiInstrument,
                       const ESkillLevel       NeSkillLevel ) :
        strName     ( NsName ),
        eCountry    ( NeCountry ),
        strCity     ( NsCity ),
        iInstrument ( NiInstrument ),
        eSkillLevel ( NeSkillLevel ) {}

    CChannelCoreInfo ( const CChannelCoreInfo& NCorInf ) :
        strName     ( NCorInf.strName ),
        eCountry    ( NCorInf.eCountry ),
        strCity     ( NCorInf.strCity ),
        iInstrument ( NCorInf.iInstrument ),
        eSkillLevel ( NCorInf.eSkillLevel ) {}

    // compare operator
    bool operator!= ( const CChannelCoreInfo& CompChanInfo )
    {
        return ( ( CompChanInfo.strName     != strName ) ||
                 ( CompChanInfo.eCountry    != eCountry ) ||
                 ( CompChanInfo.strCity     != strCity ) ||
                 ( CompChanInfo.iInstrument != iInstrument ) ||
                 ( CompChanInfo.eSkillLevel != eSkillLevel ) );
    }

    // fader tag text (channel name)
    QString          strName;

    // country in which the client is located
    QLocale::Country eCountry;

    // city in which the client is located
    QString          strCity;

    // instrument ID of the client (which instrument is he/she playing)
    int              iInstrument;

    // skill level of the musician
    ESkillLevel      eSkillLevel;
};

class CChannelInfo : public CChannelCoreInfo
{
public:
    CChannelInfo() :
        bOnlyNameIsUsed ( false ),
        iChanID ( 0 ),
        iIpAddr ( 0 ) {}

    CChannelInfo ( const int               NiID,
                   const quint32           NiIP,
                   const CChannelCoreInfo& NCorInf ) :
        CChannelCoreInfo ( NCorInf ),
        bOnlyNameIsUsed ( false ),
        iChanID ( NiID ),
        iIpAddr ( NiIP ) {}

    CChannelInfo ( const int               NiID,
                   const quint32           NiIP,
                   const QString           NsName,
                   const QLocale::Country& NeCountry,
                   const QString&          NsCity,
                   const int               NiInstrument,
                   const ESkillLevel       NeSkillLevel ) :
        CChannelCoreInfo ( NsName,
                           NeCountry,
                           NsCity,
                           NiInstrument,
                           NeSkillLevel ),
        bOnlyNameIsUsed ( false ),
        iChanID ( NiID ),
        iIpAddr ( NiIP ) {}


// #### COMPATIBILITY OLD VERSION, TO BE REMOVED ####
CChannelInfo ( const int               NiID,
               const quint32           NiIP,
               const QString           NsName ) :
    CChannelCoreInfo ( NsName,
                       QLocale::AnyCountry,
                       "",
                       CInstPictures::GetNotUsedInstrument(),
                       SL_NOT_SET ),
    bOnlyNameIsUsed ( true ),
    iChanID ( NiID ),
    iIpAddr ( NiIP ) {}

// in old versions, the name was the only client info -> to be removed
// when compatiblility to old versions is removed
bool bOnlyNameIsUsed;


    // ID of the channel
    int     iChanID;

    // IP address of the channel
    quint32 iIpAddr;
};


// Server info -----------------------------------------------------------------
class CServerCoreInfo
{
public:
    CServerCoreInfo() :
        iLocalPortNumber ( 0 ),
        strName          ( "" ),
        strTopic         ( "" ),
        eCountry         ( QLocale::AnyCountry ),
        strCity          ( "" ),
        iMaxNumClients   ( 0 ),
        bPermanentOnline ( false ) {}

    CServerCoreInfo (
        const quint16           NLocPort,
        const QString&          NsName,
        const QString&          NsTopic,
        const QLocale::Country& NeCountry,
        const QString&          NsCity,
        const int               NiMaxNumClients,
        const bool              NbPermOnline) :
        iLocalPortNumber ( NLocPort ),
        strName          ( NsName ),
        strTopic         ( NsTopic ),
        eCountry         ( NeCountry ),
        strCity          ( NsCity ),
        iMaxNumClients   ( NiMaxNumClients ),
        bPermanentOnline ( NbPermOnline ) {}

    // local port number of the server
    quint16          iLocalPortNumber;

    // name of the server
    QString          strName;

    // topic of the current jam session or server
    QString          strTopic;

    // country in which the server is located
    QLocale::Country eCountry;

    // city in which the server is located
    QString          strCity;

    // maximum number of clients which can connect to the server at the same
    // time
    int              iMaxNumClients;

    // is the server permanently online or not (flag)
    bool             bPermanentOnline;
};

class CServerInfo : public CServerCoreInfo
{
public:
    CServerInfo() :
        HostAddr ( CHostAddress() ) {}

    CServerInfo (
        const CHostAddress&     NHAddr,
        const quint16           NLocPort,
        const QString&          NsName,
        const QString&          NsTopic,
        const QLocale::Country& NeCountry,
        const QString&          NsCity,
        const int               NiMaxNumClients,
        const bool              NbPermOnline) :
            CServerCoreInfo ( NLocPort,
                              NsName,
                              NsTopic,
                              NeCountry,
                              NsCity,
                              NiMaxNumClients,
                              NbPermOnline ), HostAddr ( NHAddr ) {}

    // internet address of the server
    CHostAddress HostAddr;
};


// Network transport properties ------------------------------------------------
class CNetworkTransportProps
{
public:
    CNetworkTransportProps() :
        iBaseNetworkPacketSize ( 0 ),
        iBlockSizeFact         ( 0 ),
        iNumAudioChannels      ( 0 ),
        iSampleRate            ( 0 ),
        eAudioCodingType       ( CT_NONE ),
        iAudioCodingArg        ( 0 ) {}

    CNetworkTransportProps ( const uint32_t      iNBNPS,
                             const uint16_t      iNBSF,
                             const uint32_t      iNNACH,
                             const uint32_t      iNSR,
                             const EAudComprType eNACT,
                             const uint32_t      iNVers,
                             const int32_t       iNACA ) :
        iBaseNetworkPacketSize ( iNBNPS ),
        iBlockSizeFact         ( iNBSF ),
        iNumAudioChannels      ( iNNACH ),
        iSampleRate            ( iNSR ),
        eAudioCodingType       ( eNACT ),
        iVersion               ( iNVers ),
        iAudioCodingArg        ( iNACA ) {}

    uint32_t      iBaseNetworkPacketSize;
    uint16_t      iBlockSizeFact;
    uint32_t      iNumAudioChannels;
    uint32_t      iSampleRate;
    EAudComprType eAudioCodingType;
    uint32_t      iVersion;
    int32_t       iAudioCodingArg;
};


// Network utility functions ---------------------------------------------------
class NetworkUtil
{
public:
    static bool ParseNetworkAddress ( QString       strAddress,
                                      CHostAddress& HostAddress );
};


// Operating system utility functions ------------------------------------------
class COSUtil
{
public:
    enum EOpSystemType
    {
        // used for protocol -> enum values must be fixed!
        OT_WINDOWS = 0,
        OT_MAC_OS = 1,
        OT_LINUX = 2,
        OT_ANDROID = 3,
        OT_I_OS = 4,
        OT_UNIX = 5
    };

    static QString GetOperatingSystemString ( const EOpSystemType eOSType )
    {
        switch ( eOSType )
        {
        case OT_WINDOWS: return "Windows"; break;
        case OT_MAC_OS:  return "MacOS";   break;
        case OT_LINUX:   return "Linux";   break;
        case OT_ANDROID: return "Android"; break;
        case OT_I_OS:    return "iOS";     break;
        case OT_UNIX:    return "Unix";    break;
        default:         return "Unknown"; break;
        }
    }

    static EOpSystemType GetOperatingSystem()
    {
#ifdef _WIN32
    return OT_WINDOWS;
#elif defined ( __APPLE__ ) || defined ( __MACOSX )
    return OT_MAC_OS;
#elif defined ( ANDROID )
    return OT_ANDROID;
#else
    return OT_LINUX;
#endif
    }
};


// Audio reverbration ----------------------------------------------------------
class CAudioReverb
{
public:
    CAudioReverb() {}
    
    void Init ( const int iSampleRate, const double rT60 = (double) 1.1 );
    void Clear();
    void ProcessSample ( int16_t&     iInputOutputLeft,
                         int16_t&     iInputOutputRight,
                         const double dAttenuation );

protected:
    void setT60 ( const double rT60, const int iSampleRate );
    bool isPrime ( const int number );

    class COnePole
    {
    public:
        COnePole() : dA ( 0 ), dB ( 0 ) { Reset(); }
        void setPole ( const double dPole );
        double Calc ( const double dIn );
        void Reset() { dLastSample = 0; }

    protected:
        double dA;
        double dB;
        double dLastSample;
    };

    CFIFO<double> allpassDelays[3];
    CFIFO<double> combDelays[4];
    COnePole      combFilters[4];
    CFIFO<double> outLeftDelay;
    CFIFO<double> outRightDelay;
    double        allpassCoefficient;
    double        combCoefficient[4];
};


// CRC -------------------------------------------------------------------------
class CCRC
{
public:
    CCRC() : iPoly ( ( 1 << 5 ) | ( 1 << 12 ) ), iBitOutMask ( 1 << 16 )
        { Reset(); }

    void Reset();
    void AddByte ( const uint8_t byNewInput );
    bool CheckCRC ( const uint32_t iCRC ) { return iCRC == GetCRC(); }
    uint32_t GetCRC();

protected:
    uint32_t iPoly;
    uint32_t iBitOutMask;
    uint32_t iStateShiftReg;
};


// Mathematics utilities -------------------------------------------------------
class MathUtils
{
public:
    static int round ( double x )
    {
        return (int) ( ( x - floor ( x ) ) >= 0.5 ) ? ceil(x) : floor(x);
    }

    static void UpDownIIR1 ( double&       dOldValue,
                             const double& dNewValue,
                             const double& dWeightUp,
                             const double& dWeightDown )
    {
        // different IIR weights for up and down direction
        if ( dNewValue < dOldValue )
        {
            dOldValue =
                dOldValue * dWeightDown + ( 1.0 - dWeightDown ) * dNewValue;
        }
        else
        {
            dOldValue =
                dOldValue * dWeightUp + ( 1.0 - dWeightUp ) * dNewValue;
        }
    }

    static int DecideWithHysteresis ( const double dValue,
                                      const int    iOldValue,
                                      const double dHysteresis )
    {
        // apply hysteresis
        if ( dValue > static_cast<double> ( iOldValue ) )
        {
            return round ( dValue - dHysteresis );
        }
        else
        {
            return round ( dValue + dHysteresis );
        }
    }
};


// Precise time ----------------------------------------------------------------
// required for ping measurement
class CPreciseTime
{
public:
#ifdef _WIN32
    // for the Windows version we have to define a minimum timer precision
    // -> set it to 1 ms
    CPreciseTime() { timeBeginPeriod ( 1 ); }
    virtual ~CPreciseTime() { timeEndPeriod ( 1 ); }
#endif

    // precise time (on Windows the QTime is not precise enough)
    int elapsed()
    {
#ifdef _WIN32
        return timeGetTime();
#elif defined ( __APPLE__ ) || defined ( __MACOSX )
        return QTime().elapsed();
#else
        timespec tp;
        clock_gettime ( CLOCK_MONOTONIC, &tp );
        return tp.tv_nsec / 1000000; // convert ns in ms
#endif
    }
};


/******************************************************************************\
* Statistics                                                                   *
\******************************************************************************/
// Error rate measurement ------------------------------------------------------
class CErrorRate
{
public:
    CErrorRate() {}

    void Init ( const int  iHistoryLength,
                const bool bNBlockOnDoubleErr = false )
    {
        // initialize buffer (use "no data result" of 1.0 which stands for the
        // worst error rate possible)
        ErrorsMovAvBuf.Init ( iHistoryLength, 1.0 );

        bPreviousState = true;

        // store setting
        bBlockOnDoubleErrors = bNBlockOnDoubleErr;
    }

    void Reset()
    {
        ErrorsMovAvBuf.Reset();
        bPreviousState = true;
    }

    void Update ( const bool bState )
    {
        // if two states were false, do not use the new value
        if ( bBlockOnDoubleErrors && bPreviousState && bState )
        {
            return;
        }

        // add errors as values 0 and 1 to get correct error rate average
        if ( bState )
        {
            ErrorsMovAvBuf.Add ( 1 );
        }
        else
        {
            ErrorsMovAvBuf.Add ( 0 );

        }

        // store state
        bPreviousState = bState;
    }

    double GetAverage() { return ErrorsMovAvBuf.GetAverage(); }
    double InitializationState() { return ErrorsMovAvBuf.InitializationState(); } 

protected:
    CMovingAv<char> ErrorsMovAvBuf;
    bool            bBlockOnDoubleErrors;
    bool            bPreviousState;
};

#endif /* !defined ( UTIL_HOIH934256GEKJH98_3_43445KJIUHF1912__INCLUDED_ ) */
