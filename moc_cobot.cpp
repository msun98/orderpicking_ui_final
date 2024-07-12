/****************************************************************************
** Meta object code from reading C++ file 'cobot.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "cobot.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cobot.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Cobot_t {
    QByteArrayData data[16];
    char stringdata0[216];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Cobot_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Cobot_t qt_meta_stringdata_Cobot = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Cobot"
QT_MOC_LITERAL(1, 6, 16), // "SIGNAL_LOG_WRITE"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 8), // "CobotMSG"
QT_MOC_LITERAL(4, 33, 3), // "msg"
QT_MOC_LITERAL(5, 37, 13), // "onSystemCheck"
QT_MOC_LITERAL(6, 51, 18), // "task_intialization"
QT_MOC_LITERAL(7, 70, 14), // "onReadyCmdRead"
QT_MOC_LITERAL(8, 85, 15), // "onReadyDataRead"
QT_MOC_LITERAL(9, 101, 17), // "requestDataPacket"
QT_MOC_LITERAL(10, 119, 14), // "onCmdConnected"
QT_MOC_LITERAL(11, 134, 17), // "onCmdDisconnected"
QT_MOC_LITERAL(12, 152, 15), // "onDataConnected"
QT_MOC_LITERAL(13, 168, 18), // "onDataDisconnected"
QT_MOC_LITERAL(14, 187, 24), // "onSliderChange_RB5_Speed"
QT_MOC_LITERAL(15, 212, 3) // "val"

    },
    "Cobot\0SIGNAL_LOG_WRITE\0\0CobotMSG\0msg\0"
    "onSystemCheck\0task_intialization\0"
    "onReadyCmdRead\0onReadyDataRead\0"
    "requestDataPacket\0onCmdConnected\0"
    "onCmdDisconnected\0onDataConnected\0"
    "onDataDisconnected\0onSliderChange_RB5_Speed\0"
    "val"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Cobot[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,
       3,    1,   75,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   78,    2, 0x0a /* Public */,
       6,    0,   79,    2, 0x0a /* Public */,
       7,    0,   80,    2, 0x0a /* Public */,
       8,    0,   81,    2, 0x0a /* Public */,
       9,    0,   82,    2, 0x0a /* Public */,
      10,    0,   83,    2, 0x0a /* Public */,
      11,    0,   84,    2, 0x0a /* Public */,
      12,    0,   85,    2, 0x0a /* Public */,
      13,    0,   86,    2, 0x0a /* Public */,
      14,    1,   87,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   15,

       0        // eod
};

void Cobot::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Cobot *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SIGNAL_LOG_WRITE(); break;
        case 1: _t->CobotMSG((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->onSystemCheck(); break;
        case 3: _t->task_intialization(); break;
        case 4: _t->onReadyCmdRead(); break;
        case 5: _t->onReadyDataRead(); break;
        case 6: _t->requestDataPacket(); break;
        case 7: _t->onCmdConnected(); break;
        case 8: _t->onCmdDisconnected(); break;
        case 9: _t->onDataConnected(); break;
        case 10: _t->onDataDisconnected(); break;
        case 11: _t->onSliderChange_RB5_Speed((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Cobot::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Cobot::SIGNAL_LOG_WRITE)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Cobot::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Cobot::CobotMSG)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Cobot::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Cobot.data,
    qt_meta_data_Cobot,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Cobot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Cobot::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Cobot.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Cobot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void Cobot::SIGNAL_LOG_WRITE()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Cobot::CobotMSG(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
