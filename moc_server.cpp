/****************************************************************************
** Meta object code from reading C++ file 'server.h'
**
** Created: Tue Feb 25 23:02:53 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/server.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'server.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CHighPrecisionTimer[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      21,   20,   20,   20, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_CHighPrecisionTimer[] = {
    "CHighPrecisionTimer\0\0timeout()\0"
};

void CHighPrecisionTimer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CHighPrecisionTimer *_t = static_cast<CHighPrecisionTimer *>(_o);
        switch (_id) {
        case 0: _t->timeout(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData CHighPrecisionTimer::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CHighPrecisionTimer::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_CHighPrecisionTimer,
      qt_meta_data_CHighPrecisionTimer, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CHighPrecisionTimer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CHighPrecisionTimer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CHighPrecisionTimer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CHighPrecisionTimer))
        return static_cast<void*>(const_cast< CHighPrecisionTimer*>(this));
    return QThread::qt_metacast(_clname);
}

int CHighPrecisionTimer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void CHighPrecisionTimer::timeout()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
static const uint qt_meta_data_CServer[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
     117,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x05,
      19,    8,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
      29,    8,    8,    8, 0x0a,
      56,   39,    8,    8, 0x0a,
     114,   96,    8,    8, 0x0a,
     160,  148,    8,    8, 0x0a,
     207,  187,    8,    8, 0x0a,
     294,  258,    8,    8, 0x0a,
     404,  356,    8,    8, 0x0a,
     481,  468,    8,    8, 0x0a,
     530,  516,    8,    8, 0x0a,
     598,  583,    8,    8, 0x0a,
     638,  629,    8,    8, 0x0a,
     670,  629,    8,    8, 0x0a,
     724,  704,    8,    8, 0x0a,
     781,  629,    8,    8, 0x0a,
     824,  629,    8,    8, 0x0a,
     861,  856,    8,    8, 0x0a,
     897,  856,    8,    8, 0x0a,
     933,  856,    8,    8, 0x0a,
     969,  856,    8,    8, 0x0a,
    1005,  856,    8,    8, 0x0a,
    1041,  856,    8,    8, 0x0a,
    1077,  856,    8,    8, 0x0a,
    1113,  856,    8,    8, 0x0a,
    1149,  856,    8,    8, 0x0a,
    1185,  856,    8,    8, 0x0a,
    1221,  856,    8,    8, 0x0a,
    1258,  856,    8,    8, 0x0a,
    1295,  856,    8,    8, 0x0a,
    1332,  856,    8,    8, 0x0a,
    1369,  856,    8,    8, 0x0a,
    1406,  856,    8,    8, 0x0a,
    1443,  856,    8,    8, 0x0a,
    1480,  856,    8,    8, 0x0a,
    1517,  856,    8,    8, 0x0a,
    1554,  856,    8,    8, 0x0a,
    1591,    8,    8,    8, 0x0a,
    1617,    8,    8,    8, 0x0a,
    1643,    8,    8,    8, 0x0a,
    1669,    8,    8,    8, 0x0a,
    1695,    8,    8,    8, 0x0a,
    1721,    8,    8,    8, 0x0a,
    1747,    8,    8,    8, 0x0a,
    1773,    8,    8,    8, 0x0a,
    1799,    8,    8,    8, 0x0a,
    1825,    8,    8,    8, 0x0a,
    1851,    8,    8,    8, 0x0a,
    1878,    8,    8,    8, 0x0a,
    1905,    8,    8,    8, 0x0a,
    1932,    8,    8,    8, 0x0a,
    1959,    8,    8,    8, 0x0a,
    1986,    8,    8,    8, 0x0a,
    2013,    8,    8,    8, 0x0a,
    2040,    8,    8,    8, 0x0a,
    2067,    8,    8,    8, 0x0a,
    2094,    8,    8,    8, 0x0a,
    2121,    8,    8,    8, 0x0a,
    2147,    8,    8,    8, 0x0a,
    2173,    8,    8,    8, 0x0a,
    2199,    8,    8,    8, 0x0a,
    2225,    8,    8,    8, 0x0a,
    2251,    8,    8,    8, 0x0a,
    2277,    8,    8,    8, 0x0a,
    2303,    8,    8,    8, 0x0a,
    2329,    8,    8,    8, 0x0a,
    2355,    8,    8,    8, 0x0a,
    2381,    8,    8,    8, 0x0a,
    2408,    8,    8,    8, 0x0a,
    2435,    8,    8,    8, 0x0a,
    2462,    8,    8,    8, 0x0a,
    2489,    8,    8,    8, 0x0a,
    2516,    8,    8,    8, 0x0a,
    2543,    8,    8,    8, 0x0a,
    2570,    8,    8,    8, 0x0a,
    2597,    8,    8,    8, 0x0a,
    2624,    8,    8,    8, 0x0a,
    2663, 2651,    8,    8, 0x0a,
    2694, 2651,    8,    8, 0x0a,
    2725, 2651,    8,    8, 0x0a,
    2756, 2651,    8,    8, 0x0a,
    2787, 2651,    8,    8, 0x0a,
    2818, 2651,    8,    8, 0x0a,
    2849, 2651,    8,    8, 0x0a,
    2880, 2651,    8,    8, 0x0a,
    2911, 2651,    8,    8, 0x0a,
    2942, 2651,    8,    8, 0x0a,
    2973, 2651,    8,    8, 0x0a,
    3005, 2651,    8,    8, 0x0a,
    3037, 2651,    8,    8, 0x0a,
    3069, 2651,    8,    8, 0x0a,
    3101, 2651,    8,    8, 0x0a,
    3133, 2651,    8,    8, 0x0a,
    3165, 2651,    8,    8, 0x0a,
    3197, 2651,    8,    8, 0x0a,
    3229, 2651,    8,    8, 0x0a,
    3261, 2651,    8,    8, 0x0a,
    3302, 3293,    8,    8, 0x0a,
    3340, 3293,    8,    8, 0x0a,
    3378, 3293,    8,    8, 0x0a,
    3416, 3293,    8,    8, 0x0a,
    3454, 3293,    8,    8, 0x0a,
    3492, 3293,    8,    8, 0x0a,
    3530, 3293,    8,    8, 0x0a,
    3568, 3293,    8,    8, 0x0a,
    3606, 3293,    8,    8, 0x0a,
    3644, 3293,    8,    8, 0x0a,
    3682, 3293,    8,    8, 0x0a,
    3721, 3293,    8,    8, 0x0a,
    3760, 3293,    8,    8, 0x0a,
    3799, 3293,    8,    8, 0x0a,
    3838, 3293,    8,    8, 0x0a,
    3877, 3293,    8,    8, 0x0a,
    3916, 3293,    8,    8, 0x0a,
    3955, 3293,    8,    8, 0x0a,
    3994, 3293,    8,    8, 0x0a,
    4033, 3293,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CServer[] = {
    "CServer\0\0Started()\0Stopped()\0OnTimer()\0"
    "iChID,vecMessage\0"
    "OnSendProtMessage(int,CVector<uint8_t>)\0"
    "iChID,RecHostAddr\0OnNewConnection(int,CHostAddress)\0"
    "RecHostAddr\0OnServerFull(CHostAddress)\0"
    "InetAddr,vecMessage\0"
    "OnSendCLProtMessage(CHostAddress,CVector<uint8_t>)\0"
    "iRecID,vecbyMesBodyData,RecHostAddr\0"
    "OnProtcolCLMessageReceived(int,CVector<uint8_t>,CHostAddress)\0"
    "iRecCounter,iRecID,vecbyMesBodyData,RecHostAddr\0"
    "OnProtcolMessageReceived(int,int,CVector<uint8_t>,CHostAddress)\0"
    "InetAddr,iMs\0OnCLPingReceived(CHostAddress,int)\0"
    "InetAddr,iMs,\0"
    "OnCLPingWithNumClientsReceived(CHostAddress,int,int)\0"
    "TargetInetAddr\0OnCLSendEmptyMes(CHostAddress)\0"
    "InetAddr\0OnCLReqServerList(CHostAddress)\0"
    "OnCLReqVersionAndOS(CHostAddress)\0"
    "InetAddr,ServerInfo\0"
    "OnCLRegisterServerReceived(CHostAddress,CServerCoreInfo)\0"
    "OnCLUnregisterServerReceived(CHostAddress)\0"
    "OnCLDisconnection(CHostAddress)\0mess\0"
    "OnSendProtMessCh0(CVector<uint8_t>)\0"
    "OnSendProtMessCh1(CVector<uint8_t>)\0"
    "OnSendProtMessCh2(CVector<uint8_t>)\0"
    "OnSendProtMessCh3(CVector<uint8_t>)\0"
    "OnSendProtMessCh4(CVector<uint8_t>)\0"
    "OnSendProtMessCh5(CVector<uint8_t>)\0"
    "OnSendProtMessCh6(CVector<uint8_t>)\0"
    "OnSendProtMessCh7(CVector<uint8_t>)\0"
    "OnSendProtMessCh8(CVector<uint8_t>)\0"
    "OnSendProtMessCh9(CVector<uint8_t>)\0"
    "OnSendProtMessCh10(CVector<uint8_t>)\0"
    "OnSendProtMessCh11(CVector<uint8_t>)\0"
    "OnSendProtMessCh12(CVector<uint8_t>)\0"
    "OnSendProtMessCh13(CVector<uint8_t>)\0"
    "OnSendProtMessCh14(CVector<uint8_t>)\0"
    "OnSendProtMessCh15(CVector<uint8_t>)\0"
    "OnSendProtMessCh16(CVector<uint8_t>)\0"
    "OnSendProtMessCh17(CVector<uint8_t>)\0"
    "OnSendProtMessCh18(CVector<uint8_t>)\0"
    "OnSendProtMessCh19(CVector<uint8_t>)\0"
    "OnReqConnClientsListCh0()\0"
    "OnReqConnClientsListCh1()\0"
    "OnReqConnClientsListCh2()\0"
    "OnReqConnClientsListCh3()\0"
    "OnReqConnClientsListCh4()\0"
    "OnReqConnClientsListCh5()\0"
    "OnReqConnClientsListCh6()\0"
    "OnReqConnClientsListCh7()\0"
    "OnReqConnClientsListCh8()\0"
    "OnReqConnClientsListCh9()\0"
    "OnReqConnClientsListCh10()\0"
    "OnReqConnClientsListCh11()\0"
    "OnReqConnClientsListCh12()\0"
    "OnReqConnClientsListCh13()\0"
    "OnReqConnClientsListCh14()\0"
    "OnReqConnClientsListCh15()\0"
    "OnReqConnClientsListCh16()\0"
    "OnReqConnClientsListCh17()\0"
    "OnReqConnClientsListCh18()\0"
    "OnReqConnClientsListCh19()\0"
    "OnChanInfoHasChangedCh0()\0"
    "OnChanInfoHasChangedCh1()\0"
    "OnChanInfoHasChangedCh2()\0"
    "OnChanInfoHasChangedCh3()\0"
    "OnChanInfoHasChangedCh4()\0"
    "OnChanInfoHasChangedCh5()\0"
    "OnChanInfoHasChangedCh6()\0"
    "OnChanInfoHasChangedCh7()\0"
    "OnChanInfoHasChangedCh8()\0"
    "OnChanInfoHasChangedCh9()\0"
    "OnChanInfoHasChangedCh10()\0"
    "OnChanInfoHasChangedCh11()\0"
    "OnChanInfoHasChangedCh12()\0"
    "OnChanInfoHasChangedCh13()\0"
    "OnChanInfoHasChangedCh14()\0"
    "OnChanInfoHasChangedCh15()\0"
    "OnChanInfoHasChangedCh16()\0"
    "OnChanInfoHasChangedCh17()\0"
    "OnChanInfoHasChangedCh18()\0"
    "OnChanInfoHasChangedCh19()\0strChatText\0"
    "OnChatTextReceivedCh0(QString)\0"
    "OnChatTextReceivedCh1(QString)\0"
    "OnChatTextReceivedCh2(QString)\0"
    "OnChatTextReceivedCh3(QString)\0"
    "OnChatTextReceivedCh4(QString)\0"
    "OnChatTextReceivedCh5(QString)\0"
    "OnChatTextReceivedCh6(QString)\0"
    "OnChatTextReceivedCh7(QString)\0"
    "OnChatTextReceivedCh8(QString)\0"
    "OnChatTextReceivedCh9(QString)\0"
    "OnChatTextReceivedCh10(QString)\0"
    "OnChatTextReceivedCh11(QString)\0"
    "OnChatTextReceivedCh12(QString)\0"
    "OnChatTextReceivedCh13(QString)\0"
    "OnChatTextReceivedCh14(QString)\0"
    "OnChatTextReceivedCh15(QString)\0"
    "OnChatTextReceivedCh16(QString)\0"
    "OnChatTextReceivedCh17(QString)\0"
    "OnChatTextReceivedCh18(QString)\0"
    "OnChatTextReceivedCh19(QString)\0"
    "iNNumFra\0OnServerAutoSockBufSizeChangeCh0(int)\0"
    "OnServerAutoSockBufSizeChangeCh1(int)\0"
    "OnServerAutoSockBufSizeChangeCh2(int)\0"
    "OnServerAutoSockBufSizeChangeCh3(int)\0"
    "OnServerAutoSockBufSizeChangeCh4(int)\0"
    "OnServerAutoSockBufSizeChangeCh5(int)\0"
    "OnServerAutoSockBufSizeChangeCh6(int)\0"
    "OnServerAutoSockBufSizeChangeCh7(int)\0"
    "OnServerAutoSockBufSizeChangeCh8(int)\0"
    "OnServerAutoSockBufSizeChangeCh9(int)\0"
    "OnServerAutoSockBufSizeChangeCh10(int)\0"
    "OnServerAutoSockBufSizeChangeCh11(int)\0"
    "OnServerAutoSockBufSizeChangeCh12(int)\0"
    "OnServerAutoSockBufSizeChangeCh13(int)\0"
    "OnServerAutoSockBufSizeChangeCh14(int)\0"
    "OnServerAutoSockBufSizeChangeCh15(int)\0"
    "OnServerAutoSockBufSizeChangeCh16(int)\0"
    "OnServerAutoSockBufSizeChangeCh17(int)\0"
    "OnServerAutoSockBufSizeChangeCh18(int)\0"
    "OnServerAutoSockBufSizeChangeCh19(int)\0"
};

void CServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CServer *_t = static_cast<CServer *>(_o);
        switch (_id) {
        case 0: _t->Started(); break;
        case 1: _t->Stopped(); break;
        case 2: _t->OnTimer(); break;
        case 3: _t->OnSendProtMessage((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< CVector<uint8_t>(*)>(_a[2]))); break;
        case 4: _t->OnNewConnection((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< CHostAddress(*)>(_a[2]))); break;
        case 5: _t->OnServerFull((*reinterpret_cast< CHostAddress(*)>(_a[1]))); break;
        case 6: _t->OnSendCLProtMessage((*reinterpret_cast< CHostAddress(*)>(_a[1])),(*reinterpret_cast< CVector<uint8_t>(*)>(_a[2]))); break;
        case 7: _t->OnProtcolCLMessageReceived((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< CVector<uint8_t>(*)>(_a[2])),(*reinterpret_cast< CHostAddress(*)>(_a[3]))); break;
        case 8: _t->OnProtcolMessageReceived((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< CVector<uint8_t>(*)>(_a[3])),(*reinterpret_cast< CHostAddress(*)>(_a[4]))); break;
        case 9: _t->OnCLPingReceived((*reinterpret_cast< CHostAddress(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 10: _t->OnCLPingWithNumClientsReceived((*reinterpret_cast< CHostAddress(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 11: _t->OnCLSendEmptyMes((*reinterpret_cast< CHostAddress(*)>(_a[1]))); break;
        case 12: _t->OnCLReqServerList((*reinterpret_cast< CHostAddress(*)>(_a[1]))); break;
        case 13: _t->OnCLReqVersionAndOS((*reinterpret_cast< CHostAddress(*)>(_a[1]))); break;
        case 14: _t->OnCLRegisterServerReceived((*reinterpret_cast< CHostAddress(*)>(_a[1])),(*reinterpret_cast< CServerCoreInfo(*)>(_a[2]))); break;
        case 15: _t->OnCLUnregisterServerReceived((*reinterpret_cast< CHostAddress(*)>(_a[1]))); break;
        case 16: _t->OnCLDisconnection((*reinterpret_cast< CHostAddress(*)>(_a[1]))); break;
        case 17: _t->OnSendProtMessCh0((*reinterpret_cast< CVector<uint8_t>(*)>(_a[1]))); break;
        case 18: _t->OnSendProtMessCh1((*reinterpret_cast< CVector<uint8_t>(*)>(_a[1]))); break;
        case 19: _t->OnSendProtMessCh2((*reinterpret_cast< CVector<uint8_t>(*)>(_a[1]))); break;
        case 20: _t->OnSendProtMessCh3((*reinterpret_cast< CVector<uint8_t>(*)>(_a[1]))); break;
        case 21: _t->OnSendProtMessCh4((*reinterpret_cast< CVector<uint8_t>(*)>(_a[1]))); break;
        case 22: _t->OnSendProtMessCh5((*reinterpret_cast< CVector<uint8_t>(*)>(_a[1]))); break;
        case 23: _t->OnSendProtMessCh6((*reinterpret_cast< CVector<uint8_t>(*)>(_a[1]))); break;
        case 24: _t->OnSendProtMessCh7((*reinterpret_cast< CVector<uint8_t>(*)>(_a[1]))); break;
        case 25: _t->OnSendProtMessCh8((*reinterpret_cast< CVector<uint8_t>(*)>(_a[1]))); break;
        case 26: _t->OnSendProtMessCh9((*reinterpret_cast< CVector<uint8_t>(*)>(_a[1]))); break;
        case 27: _t->OnSendProtMessCh10((*reinterpret_cast< CVector<uint8_t>(*)>(_a[1]))); break;
        case 28: _t->OnSendProtMessCh11((*reinterpret_cast< CVector<uint8_t>(*)>(_a[1]))); break;
        case 29: _t->OnSendProtMessCh12((*reinterpret_cast< CVector<uint8_t>(*)>(_a[1]))); break;
        case 30: _t->OnSendProtMessCh13((*reinterpret_cast< CVector<uint8_t>(*)>(_a[1]))); break;
        case 31: _t->OnSendProtMessCh14((*reinterpret_cast< CVector<uint8_t>(*)>(_a[1]))); break;
        case 32: _t->OnSendProtMessCh15((*reinterpret_cast< CVector<uint8_t>(*)>(_a[1]))); break;
        case 33: _t->OnSendProtMessCh16((*reinterpret_cast< CVector<uint8_t>(*)>(_a[1]))); break;
        case 34: _t->OnSendProtMessCh17((*reinterpret_cast< CVector<uint8_t>(*)>(_a[1]))); break;
        case 35: _t->OnSendProtMessCh18((*reinterpret_cast< CVector<uint8_t>(*)>(_a[1]))); break;
        case 36: _t->OnSendProtMessCh19((*reinterpret_cast< CVector<uint8_t>(*)>(_a[1]))); break;
        case 37: _t->OnReqConnClientsListCh0(); break;
        case 38: _t->OnReqConnClientsListCh1(); break;
        case 39: _t->OnReqConnClientsListCh2(); break;
        case 40: _t->OnReqConnClientsListCh3(); break;
        case 41: _t->OnReqConnClientsListCh4(); break;
        case 42: _t->OnReqConnClientsListCh5(); break;
        case 43: _t->OnReqConnClientsListCh6(); break;
        case 44: _t->OnReqConnClientsListCh7(); break;
        case 45: _t->OnReqConnClientsListCh8(); break;
        case 46: _t->OnReqConnClientsListCh9(); break;
        case 47: _t->OnReqConnClientsListCh10(); break;
        case 48: _t->OnReqConnClientsListCh11(); break;
        case 49: _t->OnReqConnClientsListCh12(); break;
        case 50: _t->OnReqConnClientsListCh13(); break;
        case 51: _t->OnReqConnClientsListCh14(); break;
        case 52: _t->OnReqConnClientsListCh15(); break;
        case 53: _t->OnReqConnClientsListCh16(); break;
        case 54: _t->OnReqConnClientsListCh17(); break;
        case 55: _t->OnReqConnClientsListCh18(); break;
        case 56: _t->OnReqConnClientsListCh19(); break;
        case 57: _t->OnChanInfoHasChangedCh0(); break;
        case 58: _t->OnChanInfoHasChangedCh1(); break;
        case 59: _t->OnChanInfoHasChangedCh2(); break;
        case 60: _t->OnChanInfoHasChangedCh3(); break;
        case 61: _t->OnChanInfoHasChangedCh4(); break;
        case 62: _t->OnChanInfoHasChangedCh5(); break;
        case 63: _t->OnChanInfoHasChangedCh6(); break;
        case 64: _t->OnChanInfoHasChangedCh7(); break;
        case 65: _t->OnChanInfoHasChangedCh8(); break;
        case 66: _t->OnChanInfoHasChangedCh9(); break;
        case 67: _t->OnChanInfoHasChangedCh10(); break;
        case 68: _t->OnChanInfoHasChangedCh11(); break;
        case 69: _t->OnChanInfoHasChangedCh12(); break;
        case 70: _t->OnChanInfoHasChangedCh13(); break;
        case 71: _t->OnChanInfoHasChangedCh14(); break;
        case 72: _t->OnChanInfoHasChangedCh15(); break;
        case 73: _t->OnChanInfoHasChangedCh16(); break;
        case 74: _t->OnChanInfoHasChangedCh17(); break;
        case 75: _t->OnChanInfoHasChangedCh18(); break;
        case 76: _t->OnChanInfoHasChangedCh19(); break;
        case 77: _t->OnChatTextReceivedCh0((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 78: _t->OnChatTextReceivedCh1((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 79: _t->OnChatTextReceivedCh2((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 80: _t->OnChatTextReceivedCh3((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 81: _t->OnChatTextReceivedCh4((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 82: _t->OnChatTextReceivedCh5((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 83: _t->OnChatTextReceivedCh6((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 84: _t->OnChatTextReceivedCh7((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 85: _t->OnChatTextReceivedCh8((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 86: _t->OnChatTextReceivedCh9((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 87: _t->OnChatTextReceivedCh10((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 88: _t->OnChatTextReceivedCh11((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 89: _t->OnChatTextReceivedCh12((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 90: _t->OnChatTextReceivedCh13((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 91: _t->OnChatTextReceivedCh14((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 92: _t->OnChatTextReceivedCh15((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 93: _t->OnChatTextReceivedCh16((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 94: _t->OnChatTextReceivedCh17((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 95: _t->OnChatTextReceivedCh18((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 96: _t->OnChatTextReceivedCh19((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 97: _t->OnServerAutoSockBufSizeChangeCh0((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 98: _t->OnServerAutoSockBufSizeChangeCh1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 99: _t->OnServerAutoSockBufSizeChangeCh2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 100: _t->OnServerAutoSockBufSizeChangeCh3((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 101: _t->OnServerAutoSockBufSizeChangeCh4((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 102: _t->OnServerAutoSockBufSizeChangeCh5((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 103: _t->OnServerAutoSockBufSizeChangeCh6((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 104: _t->OnServerAutoSockBufSizeChangeCh7((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 105: _t->OnServerAutoSockBufSizeChangeCh8((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 106: _t->OnServerAutoSockBufSizeChangeCh9((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 107: _t->OnServerAutoSockBufSizeChangeCh10((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 108: _t->OnServerAutoSockBufSizeChangeCh11((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 109: _t->OnServerAutoSockBufSizeChangeCh12((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 110: _t->OnServerAutoSockBufSizeChangeCh13((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 111: _t->OnServerAutoSockBufSizeChangeCh14((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 112: _t->OnServerAutoSockBufSizeChangeCh15((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 113: _t->OnServerAutoSockBufSizeChangeCh16((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 114: _t->OnServerAutoSockBufSizeChangeCh17((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 115: _t->OnServerAutoSockBufSizeChangeCh18((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 116: _t->OnServerAutoSockBufSizeChangeCh19((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CServer::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CServer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CServer,
      qt_meta_data_CServer, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CServer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CServer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CServer))
        return static_cast<void*>(const_cast< CServer*>(this));
    return QObject::qt_metacast(_clname);
}

int CServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 117)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 117;
    }
    return _id;
}

// SIGNAL 0
void CServer::Started()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void CServer::Stopped()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
