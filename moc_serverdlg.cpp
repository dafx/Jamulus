/****************************************************************************
** Meta object code from reading C++ file 'serverdlg.h'
**
** Created: Tue Feb 25 23:02:53 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/serverdlg.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serverdlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CServerDlg[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      34,   28,   11,   11, 0x0a,
      68,   28,   11,   11, 0x0a,
     108,   28,   11,   11, 0x0a,
     142,   11,   11,   11, 0x0a,
     193,  182,   11,   11, 0x0a,
     237,  226,   11,   11, 0x0a,
     287,  272,   11,   11, 0x0a,
     319,   11,   11,   11, 0x0a,
     329,   11,   11,   11, 0x0a,
     347,   11,   11,   11, 0x0a,
     365,   11,   11,   11, 0x0a,
     385,   11,   11,   11, 0x0a,
     405,   11,   11,   11, 0x0a,
     435,  425,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CServerDlg[] = {
    "CServerDlg\0\0OnAboutToQuit()\0value\0"
    "OnRegisterServerStateChanged(int)\0"
    "OnDefaultCentralServerStateChanged(int)\0"
    "OnStartOnOSStartStateChanged(int)\0"
    "OnCentralServerAddressEditingFinished()\0"
    "strNewName\0OnServerNameTextChanged(QString)\0"
    "strNewCity\0OnLocationCityTextChanged(QString)\0"
    "iCntryListItem\0OnLocationCountryActivated(int)\0"
    "OnTimer()\0OnServerStarted()\0"
    "OnServerStopped()\0OnSysTrayMenuOpen()\0"
    "OnSysTrayMenuHide()\0OnSysTrayMenuExit()\0"
    "ActReason\0"
    "OnSysTrayActivated(QSystemTrayIcon::ActivationReason)\0"
};

void CServerDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CServerDlg *_t = static_cast<CServerDlg *>(_o);
        switch (_id) {
        case 0: _t->OnAboutToQuit(); break;
        case 1: _t->OnRegisterServerStateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->OnDefaultCentralServerStateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->OnStartOnOSStartStateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->OnCentralServerAddressEditingFinished(); break;
        case 5: _t->OnServerNameTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->OnLocationCityTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->OnLocationCountryActivated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->OnTimer(); break;
        case 9: _t->OnServerStarted(); break;
        case 10: _t->OnServerStopped(); break;
        case 11: _t->OnSysTrayMenuOpen(); break;
        case 12: _t->OnSysTrayMenuHide(); break;
        case 13: _t->OnSysTrayMenuExit(); break;
        case 14: _t->OnSysTrayActivated((*reinterpret_cast< QSystemTrayIcon::ActivationReason(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CServerDlg::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CServerDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CServerDlg,
      qt_meta_data_CServerDlg, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CServerDlg::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CServerDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CServerDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CServerDlg))
        return static_cast<void*>(const_cast< CServerDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int CServerDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
