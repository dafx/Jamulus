/****************************************************************************
** Meta object code from reading C++ file 'connectdlg.h'
**
** Created: Tue Feb 25 23:02:53 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/connectdlg.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'connectdlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CConnectDlg[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      22,   13,   12,   12, 0x05,
      55,   13,   12,   12, 0x05,
      95,   13,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
     142,   12,   12,   12, 0x0a,
     183,  177,   12,   12, 0x0a,
     235,   12,   12,   12, 0x0a,
     272,   12,   12,   12, 0x0a,
     291,   12,   12,   12, 0x0a,
     305,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CConnectDlg[] = {
    "CConnectDlg\0\0InetAddr\0"
    "ReqServerListQuery(CHostAddress)\0"
    "CreateCLServerListPingMes(CHostAddress)\0"
    "CreateCLServerListReqVerAndOSMes(CHostAddress)\0"
    "OnServerListItemSelectionChanged()\0"
    "Item,\0OnServerListItemDoubleClicked(QTreeWidgetItem*,int)\0"
    "OnServerAddrEditTextChanged(QString)\0"
    "OnConnectClicked()\0OnTimerPing()\0"
    "OnTimerReRequestServList()\0"
};

void CConnectDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CConnectDlg *_t = static_cast<CConnectDlg *>(_o);
        switch (_id) {
        case 0: _t->ReqServerListQuery((*reinterpret_cast< CHostAddress(*)>(_a[1]))); break;
        case 1: _t->CreateCLServerListPingMes((*reinterpret_cast< CHostAddress(*)>(_a[1]))); break;
        case 2: _t->CreateCLServerListReqVerAndOSMes((*reinterpret_cast< CHostAddress(*)>(_a[1]))); break;
        case 3: _t->OnServerListItemSelectionChanged(); break;
        case 4: _t->OnServerListItemDoubleClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->OnServerAddrEditTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->OnConnectClicked(); break;
        case 7: _t->OnTimerPing(); break;
        case 8: _t->OnTimerReRequestServList(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CConnectDlg::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CConnectDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CConnectDlg,
      qt_meta_data_CConnectDlg, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CConnectDlg::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CConnectDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CConnectDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CConnectDlg))
        return static_cast<void*>(const_cast< CConnectDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int CConnectDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void CConnectDlg::ReqServerListQuery(CHostAddress _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CConnectDlg::CreateCLServerListPingMes(CHostAddress _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CConnectDlg::CreateCLServerListReqVerAndOSMes(CHostAddress _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
