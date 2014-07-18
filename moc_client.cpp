/****************************************************************************
** Meta object code from reading C++ file 'client.h'
**
** Created: Tue Feb 25 23:02:53 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/client.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'client.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CClient[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: signature, parameters, type, tag, flags
      21,    9,    8,    8, 0x05,
      73,    9,    8,    8, 0x05,
     133,  121,    8,    8, 0x05,
     169,  159,    8,    8, 0x05,
     214,  191,    8,    8, 0x05,
     301,  270,    8,    8, 0x05,
     356,    8,    8,    8, 0x05,
     371,    8,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
     404,  393,    8,    8, 0x0a,
     452,  440,    8,    8, 0x0a,
     526,  490,    8,    8, 0x0a,
     581,    8,    8,    8, 0x0a,
     615,  600,    8,    8, 0x0a,
     641,    8,    8,    8, 0x0a,
     657,    8,    8,    8, 0x0a,
     688,  675,    8,    8, 0x0a,
     743,  723,    8,    8, 0x0a,
     819,  794,    8,    8, 0x0a,
     889,  872,    8,    8, 0x0a,
     916,    8,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CClient[] = {
    "CClient\0\0vecChanInfo\0"
    "ConClientListNameMesReceived(CVector<CChannelInfo>)\0"
    "ConClientListMesReceived(CVector<CChannelInfo>)\0"
    "strChatText\0ChatTextReceived(QString)\0"
    "iPingTime\0PingTimeReceived(int)\0"
    "InetAddr,vecServerInfo\0"
    "CLServerListReceived(CHostAddress,CVector<CServerInfo>)\0"
    "InetAddr,iPingTime,iNumClients\0"
    "CLPingTimeWithNumClientsReceived(CHostAddress,int,int)\0"
    "Disconnected()\0UpstreamRateChanged()\0"
    "vecMessage\0OnSendProtMessage(CVector<uint8_t>)\0"
    "RecHostAddr\0OnInvalidPacketReceived(CHostAddress)\0"
    "vecbyMesBodyData,iRecID,RecHostAddr\0"
    "OnDetectedCLMessage(CVector<uint8_t>,int,CHostAddress)\0"
    "OnReqJittBufSize()\0iNewJitBufSize\0"
    "OnJittBufSizeChanged(int)\0OnReqChanInfo()\0"
    "OnNewConnection()\0InetAddr,iMs\0"
    "OnCLPingReceived(CHostAddress,int)\0"
    "InetAddr,vecMessage\0"
    "OnSendCLProtMessage(CHostAddress,CVector<uint8_t>)\0"
    "InetAddr,iMs,iNumClients\0"
    "OnCLPingWithNumClientsReceived(CHostAddress,int,int)\0"
    "iSndCrdResetType\0OnSndCrdReinitRequest(int)\0"
    "OnOpusSupported()\0"
};

void CClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CClient *_t = static_cast<CClient *>(_o);
        switch (_id) {
        case 0: _t->ConClientListNameMesReceived((*reinterpret_cast< CVector<CChannelInfo>(*)>(_a[1]))); break;
        case 1: _t->ConClientListMesReceived((*reinterpret_cast< CVector<CChannelInfo>(*)>(_a[1]))); break;
        case 2: _t->ChatTextReceived((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->PingTimeReceived((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->CLServerListReceived((*reinterpret_cast< CHostAddress(*)>(_a[1])),(*reinterpret_cast< CVector<CServerInfo>(*)>(_a[2]))); break;
        case 5: _t->CLPingTimeWithNumClientsReceived((*reinterpret_cast< CHostAddress(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 6: _t->Disconnected(); break;
        case 7: _t->UpstreamRateChanged(); break;
        case 8: _t->OnSendProtMessage((*reinterpret_cast< CVector<uint8_t>(*)>(_a[1]))); break;
        case 9: _t->OnInvalidPacketReceived((*reinterpret_cast< CHostAddress(*)>(_a[1]))); break;
        case 10: _t->OnDetectedCLMessage((*reinterpret_cast< CVector<uint8_t>(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< CHostAddress(*)>(_a[3]))); break;
        case 11: _t->OnReqJittBufSize(); break;
        case 12: _t->OnJittBufSizeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->OnReqChanInfo(); break;
        case 14: _t->OnNewConnection(); break;
        case 15: _t->OnCLPingReceived((*reinterpret_cast< CHostAddress(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 16: _t->OnSendCLProtMessage((*reinterpret_cast< CHostAddress(*)>(_a[1])),(*reinterpret_cast< CVector<uint8_t>(*)>(_a[2]))); break;
        case 17: _t->OnCLPingWithNumClientsReceived((*reinterpret_cast< CHostAddress(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 18: _t->OnSndCrdReinitRequest((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->OnOpusSupported(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CClient::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CClient::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CClient,
      qt_meta_data_CClient, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CClient::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CClient::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CClient))
        return static_cast<void*>(const_cast< CClient*>(this));
    return QObject::qt_metacast(_clname);
}

int CClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    }
    return _id;
}

// SIGNAL 0
void CClient::ConClientListNameMesReceived(CVector<CChannelInfo> _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CClient::ConClientListMesReceived(CVector<CChannelInfo> _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CClient::ChatTextReceived(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CClient::PingTimeReceived(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CClient::CLServerListReceived(CHostAddress _t1, CVector<CServerInfo> _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void CClient::CLPingTimeWithNumClientsReceived(CHostAddress _t1, int _t2, int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void CClient::Disconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void CClient::UpstreamRateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}
QT_END_MOC_NAMESPACE
