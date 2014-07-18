/****************************************************************************
** Meta object code from reading C++ file 'clientdlg.h'
**
** Created: Tue Feb 25 23:02:53 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/clientdlg.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clientdlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CClientDlg[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      35,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      28,   11,   11,   11, 0x0a,
      49,   11,   11,   11, 0x0a,
      68,   11,   11,   11, 0x0a,
      84,   11,   11,   11, 0x0a,
     104,   11,   11,   11, 0x0a,
     120,   11,   11,   11, 0x0a,
     144,  134,   11,   11, 0x0a,
     197,  166,   11,   11, 0x0a,
     254,   11,   11,   11, 0x0a,
     284,   11,   11,   11, 0x0a,
     308,   11,   11,   11, 0x0a,
     327,   11,   11,   11, 0x0a,
     361,  351,   11,   11, 0x0a,
     405,  399,   11,   11, 0x0a,
     433,  399,   11,   11, 0x0a,
     457,  399,   11,   11, 0x0a,
     485,  399,   11,   11, 0x0a,
     516,   11,   11,   11, 0x0a,
     538,   11,   11,   11, 0x0a,
     572,  560,   11,   11, 0x0a,
     633,  622,   11,   11, 0x0a,
     676,  664,   11,   11, 0x0a,
     714,  704,   11,   11, 0x0a,
     743,  664,   11,   11, 0x0a,
     781,  772,   11,   11, 0x0a,
     816,  772,   11,   11, 0x0a,
     858,  772,   11,   11, 0x0a,
     930,  907,   11,   11, 0x0a,
     988,   11,   11,   11, 0x0a,
    1011,   11,   11,   11, 0x0a,
    1028,   11,   11,   11, 0x0a,
    1052,   11,   11,   11, 0x0a,
    1073,   11,   11,   11, 0x0a,
    1113, 1098,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CClientDlg[] = {
    "CClientDlg\0\0OnAboutToQuit()\0"
    "OnConnectDisconBut()\0OnInstPictureBut()\0"
    "OnTimerSigMet()\0OnTimerBuffersLED()\0"
    "OnTimerStatus()\0OnTimerPing()\0iPingTime\0"
    "OnPingTimeResult(int)\0"
    "InetAddr,iPingTime,iNumClients\0"
    "OnCLPingTimeWithNumClientsReceived(CHostAddress,int,int)\0"
    "OnOpenConnectionSetupDialog()\0"
    "OnOpenGeneralSettings()\0OnOpenChatDialog()\0"
    "OnOpenAnalyzerConsole()\0SelAction\0"
    "OnInstPicturesMenuTriggered(QAction*)\0"
    "value\0OnSettingsStateChanged(int)\0"
    "OnChatStateChanged(int)\0"
    "OnAudioPanValueChanged(int)\0"
    "OnAudioReverbValueChanged(int)\0"
    "OnReverbSelLClicked()\0OnReverbSelRClicked()\0"
    "vecChanInfo\0"
    "OnConClientListMesReceived(CVector<CChannelInfo>)\0"
    "strNewName\0OnFaderTagTextChanged(QString)\0"
    "strChatText\0OnChatTextReceived(QString)\0"
    "iId,dGain\0OnChangeChanGain(int,double)\0"
    "OnNewLocalInputText(QString)\0InetAddr\0"
    "OnReqServerListQuery(CHostAddress)\0"
    "OnCreateCLServerListPingMes(CHostAddress)\0"
    "OnCreateCLServerListReqVerAndOSMes(CHostAddress)\0"
    "InetAddr,vecServerInfo\0"
    "OnCLServerListReceived(CHostAddress,CVector<CServerInfo>)\0"
    "OnConnectDlgAccepted()\0OnDisconnected()\0"
    "OnUpstreamRateChanged()\0OnGUIDesignChanged()\0"
    "OnAudioChannelsChanged()\0iNewNumClients\0"
    "OnNumClientsChanged(int)\0"
};

void CClientDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CClientDlg *_t = static_cast<CClientDlg *>(_o);
        switch (_id) {
        case 0: _t->OnAboutToQuit(); break;
        case 1: _t->OnConnectDisconBut(); break;
        case 2: _t->OnInstPictureBut(); break;
        case 3: _t->OnTimerSigMet(); break;
        case 4: _t->OnTimerBuffersLED(); break;
        case 5: _t->OnTimerStatus(); break;
        case 6: _t->OnTimerPing(); break;
        case 7: _t->OnPingTimeResult((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->OnCLPingTimeWithNumClientsReceived((*reinterpret_cast< CHostAddress(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 9: _t->OnOpenConnectionSetupDialog(); break;
        case 10: _t->OnOpenGeneralSettings(); break;
        case 11: _t->OnOpenChatDialog(); break;
        case 12: _t->OnOpenAnalyzerConsole(); break;
        case 13: _t->OnInstPicturesMenuTriggered((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 14: _t->OnSettingsStateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->OnChatStateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->OnAudioPanValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->OnAudioReverbValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->OnReverbSelLClicked(); break;
        case 19: _t->OnReverbSelRClicked(); break;
        case 20: _t->OnConClientListMesReceived((*reinterpret_cast< CVector<CChannelInfo>(*)>(_a[1]))); break;
        case 21: _t->OnFaderTagTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 22: _t->OnChatTextReceived((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 23: _t->OnChangeChanGain((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 24: _t->OnNewLocalInputText((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 25: _t->OnReqServerListQuery((*reinterpret_cast< CHostAddress(*)>(_a[1]))); break;
        case 26: _t->OnCreateCLServerListPingMes((*reinterpret_cast< CHostAddress(*)>(_a[1]))); break;
        case 27: _t->OnCreateCLServerListReqVerAndOSMes((*reinterpret_cast< CHostAddress(*)>(_a[1]))); break;
        case 28: _t->OnCLServerListReceived((*reinterpret_cast< CHostAddress(*)>(_a[1])),(*reinterpret_cast< CVector<CServerInfo>(*)>(_a[2]))); break;
        case 29: _t->OnConnectDlgAccepted(); break;
        case 30: _t->OnDisconnected(); break;
        case 31: _t->OnUpstreamRateChanged(); break;
        case 32: _t->OnGUIDesignChanged(); break;
        case 33: _t->OnAudioChannelsChanged(); break;
        case 34: _t->OnNumClientsChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CClientDlg::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CClientDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CClientDlg,
      qt_meta_data_CClientDlg, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CClientDlg::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CClientDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CClientDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CClientDlg))
        return static_cast<void*>(const_cast< CClientDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int CClientDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 35)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 35;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
