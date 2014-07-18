/****************************************************************************
** Meta object code from reading C++ file 'audiomixerboard.h'
**
** Created: Tue Feb 25 23:02:53 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/audiomixerboard.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'audiomixerboard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CChannelFader[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      21,   15,   14,   14, 0x05,
      46,   15,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      68,   15,   14,   14, 0x0a,
      93,   15,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CChannelFader[] = {
    "CChannelFader\0\0value\0gainValueChanged(double)\0"
    "soloStateChanged(int)\0OnLevelValueChanged(int)\0"
    "OnMuteStateChanged(int)\0"
};

void CChannelFader::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CChannelFader *_t = static_cast<CChannelFader *>(_o);
        switch (_id) {
        case 0: _t->gainValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->soloStateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->OnLevelValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->OnMuteStateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CChannelFader::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CChannelFader::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CChannelFader,
      qt_meta_data_CChannelFader, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CChannelFader::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CChannelFader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CChannelFader::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CChannelFader))
        return static_cast<void*>(const_cast< CChannelFader*>(this));
    return QObject::qt_metacast(_clname);
}

int CChannelFader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void CChannelFader::gainValueChanged(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CChannelFader::soloStateChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
static const uint qt_meta_data_CAudioMixerBoard[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      28,   18,   17,   17, 0x05,
      70,   55,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
     100,   93,   17,   17, 0x0a,
     130,   93,   17,   17, 0x0a,
     160,   93,   17,   17, 0x0a,
     190,   93,   17,   17, 0x0a,
     220,   93,   17,   17, 0x0a,
     250,   93,   17,   17, 0x0a,
     280,   93,   17,   17, 0x0a,
     310,   93,   17,   17, 0x0a,
     340,   93,   17,   17, 0x0a,
     370,   93,   17,   17, 0x0a,
     400,   93,   17,   17, 0x0a,
     431,   93,   17,   17, 0x0a,
     462,   93,   17,   17, 0x0a,
     493,   93,   17,   17, 0x0a,
     524,   93,   17,   17, 0x0a,
     555,   93,   17,   17, 0x0a,
     586,   93,   17,   17, 0x0a,
     617,   93,   17,   17, 0x0a,
     648,   93,   17,   17, 0x0a,
     679,   93,   17,   17, 0x0a,
     710,   17,   17,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CAudioMixerBoard[] = {
    "CAudioMixerBoard\0\0iId,dGain\0"
    "ChangeChanGain(int,double)\0iNewNumClients\0"
    "NumClientsChanged(int)\0dValue\0"
    "OnGainValueChangedCh0(double)\0"
    "OnGainValueChangedCh1(double)\0"
    "OnGainValueChangedCh2(double)\0"
    "OnGainValueChangedCh3(double)\0"
    "OnGainValueChangedCh4(double)\0"
    "OnGainValueChangedCh5(double)\0"
    "OnGainValueChangedCh6(double)\0"
    "OnGainValueChangedCh7(double)\0"
    "OnGainValueChangedCh8(double)\0"
    "OnGainValueChangedCh9(double)\0"
    "OnGainValueChangedCh10(double)\0"
    "OnGainValueChangedCh11(double)\0"
    "OnGainValueChangedCh12(double)\0"
    "OnGainValueChangedCh13(double)\0"
    "OnGainValueChangedCh14(double)\0"
    "OnGainValueChangedCh15(double)\0"
    "OnGainValueChangedCh16(double)\0"
    "OnGainValueChangedCh17(double)\0"
    "OnGainValueChangedCh18(double)\0"
    "OnGainValueChangedCh19(double)\0"
    "OnChSoloStateChanged()\0"
};

void CAudioMixerBoard::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CAudioMixerBoard *_t = static_cast<CAudioMixerBoard *>(_o);
        switch (_id) {
        case 0: _t->ChangeChanGain((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 1: _t->NumClientsChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->OnGainValueChangedCh0((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->OnGainValueChangedCh1((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->OnGainValueChangedCh2((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->OnGainValueChangedCh3((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->OnGainValueChangedCh4((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->OnGainValueChangedCh5((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->OnGainValueChangedCh6((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: _t->OnGainValueChangedCh7((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: _t->OnGainValueChangedCh8((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: _t->OnGainValueChangedCh9((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 12: _t->OnGainValueChangedCh10((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 13: _t->OnGainValueChangedCh11((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 14: _t->OnGainValueChangedCh12((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 15: _t->OnGainValueChangedCh13((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 16: _t->OnGainValueChangedCh14((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 17: _t->OnGainValueChangedCh15((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 18: _t->OnGainValueChangedCh16((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 19: _t->OnGainValueChangedCh17((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 20: _t->OnGainValueChangedCh18((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 21: _t->OnGainValueChangedCh19((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 22: _t->OnChSoloStateChanged(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CAudioMixerBoard::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CAudioMixerBoard::staticMetaObject = {
    { &QGroupBox::staticMetaObject, qt_meta_stringdata_CAudioMixerBoard,
      qt_meta_data_CAudioMixerBoard, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CAudioMixerBoard::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CAudioMixerBoard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CAudioMixerBoard::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CAudioMixerBoard))
        return static_cast<void*>(const_cast< CAudioMixerBoard*>(this));
    return QGroupBox::qt_metacast(_clname);
}

int CAudioMixerBoard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGroupBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    }
    return _id;
}

// SIGNAL 0
void CAudioMixerBoard::ChangeChanGain(int _t1, double _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CAudioMixerBoard::NumClientsChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
