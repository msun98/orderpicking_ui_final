/****************************************************************************
** Meta object code from reading C++ file 'kitech_gripper.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "kitech_gripper.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'kitech_gripper.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Kitech_gripper_t {
    QByteArrayData data[11];
    char stringdata0[145];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Kitech_gripper_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Kitech_gripper_t qt_meta_stringdata_Kitech_gripper = {
    {
QT_MOC_LITERAL(0, 0, 14), // "Kitech_gripper"
QT_MOC_LITERAL(1, 15, 16), // "SIGNAL_LOG_WRITE"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 10), // "kitech_cmd"
QT_MOC_LITERAL(4, 44, 3), // "msg"
QT_MOC_LITERAL(5, 48, 9), // "msgSignal"
QT_MOC_LITERAL(6, 58, 12), // "connect_flag"
QT_MOC_LITERAL(7, 71, 14), // "onReadyCmdRead"
QT_MOC_LITERAL(8, 86, 19), // "onReconnectToServer"
QT_MOC_LITERAL(9, 106, 17), // "onKitechConnected"
QT_MOC_LITERAL(10, 124, 20) // "onKitechdisConnected"

    },
    "Kitech_gripper\0SIGNAL_LOG_WRITE\0\0"
    "kitech_cmd\0msg\0msgSignal\0connect_flag\0"
    "onReadyCmdRead\0onReconnectToServer\0"
    "onKitechConnected\0onKitechdisConnected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Kitech_gripper[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    1,   50,    2, 0x06 /* Public */,
       5,    1,   53,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   56,    2, 0x0a /* Public */,
       8,    0,   57,    2, 0x0a /* Public */,
       9,    0,   58,    2, 0x0a /* Public */,
      10,    0,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::Bool,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Kitech_gripper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Kitech_gripper *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SIGNAL_LOG_WRITE(); break;
        case 1: _t->kitech_cmd((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->msgSignal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->onReadyCmdRead(); break;
        case 4: _t->onReconnectToServer(); break;
        case 5: _t->onKitechConnected(); break;
        case 6: _t->onKitechdisConnected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Kitech_gripper::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Kitech_gripper::SIGNAL_LOG_WRITE)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Kitech_gripper::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Kitech_gripper::kitech_cmd)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Kitech_gripper::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Kitech_gripper::msgSignal)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Kitech_gripper::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Kitech_gripper.data,
    qt_meta_data_Kitech_gripper,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Kitech_gripper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Kitech_gripper::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Kitech_gripper.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Kitech_gripper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void Kitech_gripper::SIGNAL_LOG_WRITE()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Kitech_gripper::kitech_cmd(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Kitech_gripper::msgSignal(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
