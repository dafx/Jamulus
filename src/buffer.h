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

#if !defined ( BUFFER_H__3B123453_4344_BB23945IUHF1912__INCLUDED_ )
#define BUFFER_H__3B123453_4344_BB23945IUHF1912__INCLUDED_

#include "util.h"
#include "global.h"


/* Definitions ****************************************************************/
// each regular buffer access lead to a count for put and get, assuming 2.66 ms
// blocks we have 15 s / 2.66 ms * 2 = approx. 11000
#define MAX_STATISTIC_COUNT                 11000

// definition of the error bound
#define ERROR_RATE_BOUND                    0.001

// number of simulation network jitter buffers for evaluating the statistic
#define NUM_STAT_SIMULATION_BUFFERS         11


/* Classes ********************************************************************/
// Buffer base class -----------------------------------------------------------
template<class TData> class CBufferBase
{
public:
    CBufferBase ( const bool bNIsSim = false ) :
       bIsSimulation ( bNIsSim ), bIsInitialized ( false ) {}

    void SetIsSimulation ( const bool bNIsSim ) { bIsSimulation = bNIsSim; }

    virtual void Init ( const int  iNewMemSize,
                        const bool bPreserve = false )
    {
        // in simulation mode the size is not changed during operation -> we do
        // not have to implement special code for this case
        // only enter the "preserve" branch, if object was already initialized
        if ( bPreserve && ( !bIsSimulation ) && bIsInitialized )
        {
            // copy old data in new vector using get pointer as zero per
            // definition

            int iCurPos;

            // copy current data in temporary vector
            CVector<TData> vecTempMemory ( vecMemory );

            // resize actual buffer memory
            vecMemory.Init ( iNewMemSize );

            // get maximum number of data to be copied
            int iCopyLen = GetAvailData();

            if ( iCopyLen > iNewMemSize )
            {
                iCopyLen = iNewMemSize;
            }

            // set correct buffer state
            if ( iCopyLen == iNewMemSize )
            {
                eBufState = CBufferBase<TData>::BS_FULL;
            }
            else
            {
                if ( iCopyLen == 0 )
                {
                    eBufState = CBufferBase<TData>::BS_EMPTY;
                }
                else
                {
                    eBufState = CBufferBase<TData>::BS_OK;
                }
            }

            if ( iGetPos < iPutPos )
            {
                // "get" position is before "put" position -> no wrap around
                for ( iCurPos = 0; iCurPos < iCopyLen; iCurPos++ )
                {
                    vecMemory[iCurPos] = vecTempMemory[iGetPos + iCurPos];
                }
            }
            else
            {
                // "put" position is before "get" position -> wrap around
                bool bEnoughSpaceForSecondPart = true;
                int  iFirstPartLen             = iMemSize - iGetPos;

                // check that first copy length is not larger then new memory
                if ( iFirstPartLen >= iCopyLen )
                {
                    iFirstPartLen             = iCopyLen;
                    bEnoughSpaceForSecondPart = false;
                }

                for ( iCurPos = 0; iCurPos < iFirstPartLen; iCurPos++ )
                {
                    vecMemory[iCurPos] = vecTempMemory[iGetPos + iCurPos];
                }

                if ( bEnoughSpaceForSecondPart )
                {
                    // calculate remaining copy length
                    const int iRemainingCopyLen = iCopyLen - iFirstPartLen;

                    // perform copying of second part
                    for ( iCurPos = 0; iCurPos < iRemainingCopyLen; iCurPos++ )
                    {
                        vecMemory[iCurPos + iFirstPartLen] =
                            vecTempMemory[iCurPos];
                    }
                }
            }

            // update put pointer
            if ( eBufState == CBufferBase<TData>::BS_FULL )
            {
                iPutPos = 0;
            }
            else
            {
                iPutPos = iCopyLen;
            }

            // update get position -> zero per definition
            iGetPos = 0;
        }
        else
        {
            // allocate memory for actual data buffer
            if ( !bIsSimulation )
            {
                vecMemory.Init ( iNewMemSize );
            }

            // init buffer pointers and buffer state (empty buffer)
            iGetPos   = 0;
            iPutPos   = 0;
            eBufState = CBufferBase<TData>::BS_EMPTY;
        }

        // store total memory size value
        iMemSize = iNewMemSize;

        // set initialized flag
        bIsInitialized = true;
    }

    virtual bool Put ( const CVector<TData>& vecData,
                       const int             iInSize )
    {
        if ( bIsSimulation )
        {
            // in this simulation only the buffer pointers and the buffer state
            // is updated, no actual data is transferred
            iPutPos += iInSize;

            if ( iPutPos >= iMemSize )
            {
                iPutPos -= iMemSize;
            }
        }
        else
        {
            // copy new data in internal buffer
            int iCurPos = 0;

            if ( iPutPos + iInSize > iMemSize )
            {
                // remaining space size for second block
                const int iRemSpace = iPutPos + iInSize - iMemSize;

                // data must be written in two steps because of wrap around
                while ( iPutPos < iMemSize )
                {
                    vecMemory[iPutPos++] = vecData[iCurPos++];
                }

                for ( iPutPos = 0; iPutPos < iRemSpace; iPutPos++ )
                {
                    vecMemory[iPutPos] = vecData[iCurPos++];
                }
            }
            else
            {
                // data can be written in one step
                std::copy ( vecData.begin(),
                            vecData.begin() + iInSize,
                            vecMemory.begin() + iPutPos );

                // set the put position one block further (no wrap around needs
                // to be considered here)
                iPutPos += iInSize;
            }
        }

        // take care about wrap around of put pointer
        if ( iPutPos == iMemSize )
        {
            iPutPos = 0;
        }

        // set buffer state flag
        if ( iPutPos == iGetPos )
        {
            eBufState = CBufferBase<TData>::BS_FULL;
        }
        else
        {
            eBufState = CBufferBase<TData>::BS_OK;
        }

        return true; // no error check in base class, alyways return ok
    }

    virtual bool Get ( CVector<TData>& vecData,
                       const int       iOutSize )
    {
        if ( bIsSimulation )
        {
            // in this simulation only the buffer pointers and the buffer state
            // is updated, no actual data is transferred
            iGetPos += iOutSize;

            if ( iGetPos >= iMemSize )
            {
                iGetPos -= iMemSize;
            }
        }
        else
        {
            // copy data from internal buffer in output buffer
            int iCurPos = 0;

            if ( iGetPos + iOutSize > iMemSize )
            {
                // remaining data size for second block
                const int iRemData = iGetPos + iOutSize - iMemSize;

                // data must be read in two steps because of wrap around
                while ( iGetPos < iMemSize )
                {
                    vecData[iCurPos++] = vecMemory[iGetPos++];
                }

                for ( iGetPos = 0; iGetPos < iRemData; iGetPos++ )
                {
                    vecData[iCurPos++] = vecMemory[iGetPos];
                }
            }
            else
            {
                // data can be read in one step
                std::copy ( vecMemory.begin() + iGetPos,
                            vecMemory.begin() + iGetPos + iOutSize,
                            vecData.begin() );

                // set the get position one block further (no wrap around needs
                // to be considered here)
                iGetPos += iOutSize;
            }
        }

        // take care about wrap around of get pointer
        if ( iGetPos == iMemSize )
        {
            iGetPos = 0;
        }

        // set buffer state flag
        if ( iPutPos == iGetPos )
        {
            eBufState = CBufferBase<TData>::BS_EMPTY;
        }
        else
        {
            eBufState = CBufferBase<TData>::BS_OK;
        }

        return true; // no error check in base class, alyways return ok
    }

    virtual int GetAvailSpace() const
    {
        // calculate available space in buffer
        int iAvSpace = iGetPos - iPutPos;

        // check for special case and wrap around
        if ( iAvSpace < 0 )
        {
            iAvSpace += iMemSize; // wrap around
        }
        else
        {
            if ( ( iAvSpace == 0 ) && ( eBufState == BS_EMPTY ) )
            {
                iAvSpace = iMemSize;
            }
        }

        return iAvSpace;
    }

    virtual int GetAvailData() const
    {
        // calculate available data in buffer
        int iAvData = iPutPos - iGetPos;

        // check for special case and wrap around
        if ( iAvData < 0 )
        {
            iAvData += iMemSize; // wrap around
        }
        else
        {
            if ( ( iAvData == 0 ) && ( eBufState == BS_FULL ) )
            {
                iAvData = iMemSize;
            }
        }

        return iAvData;
    }

protected:
    enum EBufState { BS_OK, BS_FULL, BS_EMPTY };

    virtual void Clear()
    {
        // clear memory
        if ( !bIsSimulation )
        {
            vecMemory.Reset ( 0 );
        }

        // init buffer pointers and buffer state (empty buffer)
        iGetPos   = 0;
        iPutPos   = 0;
        eBufState = CBufferBase<TData>::BS_EMPTY;
    }

    CVector<TData> vecMemory;
    int            iMemSize;
    int            iGetPos;
    int            iPutPos;
    EBufState      eBufState;
    bool           bIsSimulation;
    bool           bIsInitialized;
};


// Network buffer (jitter buffer) ----------------------------------------------
class CNetBuf : public CBufferBase<uint8_t>
{
public:
    CNetBuf ( const bool bNewIsSim = false ) :
       CBufferBase<uint8_t> ( bNewIsSim ) {}

    virtual void Init ( const int  iNewBlockSize,
                        const int  iNewNumBlocks,
                        const bool bPreserve = false );

    int GetSize() { return iMemSize / iBlockSize; }

    virtual bool Put ( const CVector<uint8_t>& vecbyData, const int iInSize );
    virtual bool Get ( CVector<uint8_t>& vecbyData, const int iOutSize );

protected:
    int iBlockSize;
};


// Network buffer (jitter buffer) with statistic calculations ------------------
class CNetBufWithStats : public CNetBuf
{
public:
    CNetBufWithStats();

    virtual void Init ( const int iNewBlockSize,
                        const int iNewNumBlocks,
                        const bool bPreserve = false );

    virtual bool Put ( const CVector<uint8_t>& vecbyData, const int iInSize );
    virtual bool Get ( CVector<uint8_t>& vecbyData, const int iOutSize );

    int GetAutoSetting() { return iCurAutoBufferSizeSetting; }
    void GetErrorRates ( CVector<double>& vecErrRates, double& dLimit );

protected:
    void UpdateAutoSetting();

    // statistic (do not use the vector class since the classes do not have
    // appropriate copy constructor/operator)
    CErrorRate ErrorRateStatistic[NUM_STAT_SIMULATION_BUFFERS];
    CNetBuf    SimulationBuffer[NUM_STAT_SIMULATION_BUFFERS];
    int        viBufSizesForSim[NUM_STAT_SIMULATION_BUFFERS];

    double     dCurIIRFilterResult;
    int        iCurDecidedResult;
    int        iInitCounter;
    int        iCurAutoBufferSizeSetting;
};


// Conversion buffer (very simple buffer) --------------------------------------
// For this very simple buffer no wrap around mechanism is implemented. We
// assume here, that the applied buffers are an integer fraction of the total
// buffer size.
template<class TData> class CConvBuf
{
public:
    CConvBuf() { Init ( 0 ); }

    void Init ( const int iNewMemSize )
    {
        // set memory size
        iMemSize = iNewMemSize;

        // allocate and clear memory for actual data buffer
        vecsMemory.Init ( iMemSize );

        iPutPos = 0;
    }

    int GetSize() const { return iMemSize; }

    bool Put ( const CVector<TData>& vecsData,
               const int             iVecSize )
    {
        // calculate the input size and the end position after copying
        const int iEnd = iPutPos + iVecSize;

        // first check for buffer overrun
        if ( iEnd <= iMemSize )
        {
            // copy new data in internal buffer
            std::copy ( vecsData.begin(),
                        vecsData.begin() + iVecSize,
                        vecsMemory.begin() + iPutPos );

            // set buffer pointer one block further
            iPutPos = iEnd;

            // return "buffer is ready for readout" flag
            return ( iEnd == iMemSize );
        }

        // buffer overrun or not initialized, return "not ready"
        return false;
    }

    const CVector<TData>& Get()
    {
        iPutPos = 0;
        return vecsMemory;
    }

protected:
    CVector<TData> vecsMemory;
    int            iMemSize;
    int            iPutPos;
};

#endif /* !defined ( BUFFER_H__3B123453_4344_BB23945IUHF1912__INCLUDED_ ) */
