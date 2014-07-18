/****************************************************************************
** Meta object code from reading C++ file 'util.h'
**
** Created: Tue Feb 25 23:02:54 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/util.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'util.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CAboutDlg[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_CAboutDlg[] = {
    "CAboutDlg\0"
};

void CAboutDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData CAboutDlg::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CAboutDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CAboutDlg,
      qt_meta_data_CAboutDlg, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CAboutDlg::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CAboutDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CAboutDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CAboutDlg))
        return static_cast<void*>(const_cast< CAboutDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int CAboutDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_CHelpMenu[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x0a,
      29,   10,   10,   10, 0x0a,
      43,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CHelpMenu[] = {
    "CHelpMenu\0\0OnHelpWhatsThis()\0OnHelpAbout()\0"
    "OnHelpDownloadLink()\0"
};

void CHelpMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CHelpMenu *_t = static_cast<CHelpMenu *>(_o);
        switch (_id) {
        case 0: _t->OnHelpWhatsThis(); break;
        case 1: _t->OnHelpAbout(); break;
        case 2: _t->OnHelpDownloadLink(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData CHelpMenu::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CHelpMenu::staticMetaObject = {
    { &QMenu::staticMetaObject, qt_meta_stringdata_CHelpMenu,
      qt_meta_data_CHelpMenu, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CHelpMenu::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CHelpMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CHelpMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CHelpMenu))
        return static_cast<void*>(const_cast< CHelpMenu*>(this));
    return QMenu::qt_metacast(_clname);
}

int CHelpMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMenu::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
