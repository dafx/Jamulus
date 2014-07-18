/****************************************************************************
** Meta object code from reading C++ file 'clientsettingsdlg.h'
**
** Created: Tue Feb 25 23:02:53 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/clientsettingsdlg.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clientsettingsdlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CClientSettingsDlg[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x05,
      39,   19,   19,   19, 0x05,

 // slots: signature, parameters, type, tag, flags
      62,   19,   19,   19, 0x0a,
      84,   78,   19,   19, 0x0a,
     110,   78,   19,   19, 0x0a,
     142,   78,   19,   19, 0x0a,
     173,   78,   19,   19, 0x0a,
     203,   78,   19,   19, 0x0a,
     237,   78,   19,   19, 0x0a,
     277,   19,   19,   19, 0x0a,
     324,  317,   19,   19, 0x0a,
     391,  380,   19,   19, 0x0a,
     426,  417,   19,   19, 0x0a,
     450,  417,   19,   19, 0x0a,
     474,  417,   19,   19, 0x0a,
     499,  417,   19,   19, 0x0a,
     524,  417,   19,   19, 0x0a,
     566,  554,   19,   19, 0x0a,
     595,   19,   19,   19, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CClientSettingsDlg[] = {
    "CClientSettingsDlg\0\0GUIDesignChanged()\0"
    "AudioChannelsChanged()\0OnTimerStatus()\0"
    "value\0OnNetBufValueChanged(int)\0"
    "OnNetBufServerValueChanged(int)\0"
    "OnSliderSndCrdBufferDelay(int)\0"
    "OnAutoJitBufStateChanged(int)\0"
    "OnGUIDesignFancyStateChanged(int)\0"
    "OnDefaultCentralServerStateChanged(int)\0"
    "OnCentralServerAddressEditingFinished()\0"
    "button\0OnSndCrdBufferDelayButtonGroupClicked(QAbstractButton*)\0"
    "iSndDevIdx\0OnSoundcardActivated(int)\0"
    "iChanIdx\0OnLInChanActivated(int)\0"
    "OnRInChanActivated(int)\0"
    "OnLOutChanActivated(int)\0"
    "OnROutChanActivated(int)\0"
    "OnAudioChannelsActivated(int)\0iQualityIdx\0"
    "OnAudioQualityActivated(int)\0"
    "OnDriverSetupClicked()\0"
};

void CClientSettingsDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CClientSettingsDlg *_t = static_cast<CClientSettingsDlg *>(_o);
        switch (_id) {
        case 0: _t->GUIDesignChanged(); break;
        case 1: _t->AudioChannelsChanged(); break;
        case 2: _t->OnTimerStatus(); break;
        case 3: _t->OnNetBufValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->OnNetBufServerValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->OnSliderSndCrdBufferDelay((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->OnAutoJitBufStateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->OnGUIDesignFancyStateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->OnDefaultCentralServerStateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->OnCentralServerAddressEditingFinished(); break;
        case 10: _t->OnSndCrdBufferDelayButtonGroupClicked((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        case 11: _t->OnSoundcardActivated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->OnLInChanActivated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->OnRInChanActivated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->OnLOutChanActivated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->OnROutChanActivated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->OnAudioChannelsActivated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->OnAudioQualityActivated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->OnDriverSetupClicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CClientSettingsDlg::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CClientSettingsDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CClientSettingsDlg,
      qt_meta_data_CClientSettingsDlg, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CClientSettingsDlg::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CClientSettingsDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CClientSettingsDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CClientSettingsDlg))
        return static_cast<void*>(const_cast< CClientSettingsDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int CClientSettingsDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void CClientSettingsDlg::GUIDesignChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void CClientSettingsDlg::AudioChannelsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
