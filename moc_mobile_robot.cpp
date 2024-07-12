/****************************************************************************
** Meta object code from reading C++ file 'mobile_robot.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mobile_robot.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mobile_robot.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_mobile_robot_t {
    QByteArrayData data[16];
    char stringdata0[186];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_mobile_robot_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_mobile_robot_t qt_meta_stringdata_mobile_robot = {
    {
QT_MOC_LITERAL(0, 0, 12), // "mobile_robot"
QT_MOC_LITERAL(1, 13, 9), // "LiftState"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 10), // "mobile_run"
QT_MOC_LITERAL(4, 35, 3), // "run"
QT_MOC_LITERAL(5, 39, 10), // "img_signal"
QT_MOC_LITERAL(6, 50, 7), // "cv::Mat"
QT_MOC_LITERAL(7, 58, 3), // "img"
QT_MOC_LITERAL(8, 62, 13), // "mobile_status"
QT_MOC_LITERAL(9, 76, 8), // "pose_msg"
QT_MOC_LITERAL(10, 85, 17), // "newConnection_tcp"
QT_MOC_LITERAL(11, 103, 17), // "disConnection_tcp"
QT_MOC_LITERAL(12, 121, 8), // "sendData"
QT_MOC_LITERAL(13, 130, 13), // "readyRead_tcp"
QT_MOC_LITERAL(14, 144, 21), // "on_read_mobile_status"
QT_MOC_LITERAL(15, 166, 19) // "on_map_read_command"

    },
    "mobile_robot\0LiftState\0\0mobile_run\0"
    "run\0img_signal\0cv::Mat\0img\0mobile_status\0"
    "pose_msg\0newConnection_tcp\0disConnection_tcp\0"
    "sendData\0readyRead_tcp\0on_read_mobile_status\0"
    "on_map_read_command"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mobile_robot[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    1,   65,    2, 0x06 /* Public */,
       5,    1,   68,    2, 0x06 /* Public */,
       8,    1,   71,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   74,    2, 0x08 /* Private */,
      11,    0,   75,    2, 0x08 /* Private */,
      12,    0,   76,    2, 0x08 /* Private */,
      13,    0,   77,    2, 0x08 /* Private */,
      14,    0,   78,    2, 0x08 /* Private */,
      15,    0,   79,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::QString,    9,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void mobile_robot::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<mobile_robot *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->LiftState(); break;
        case 1: _t->mobile_run((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->img_signal((*reinterpret_cast< cv::Mat(*)>(_a[1]))); break;
        case 3: _t->mobile_status((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->newConnection_tcp(); break;
        case 5: _t->disConnection_tcp(); break;
        case 6: _t->sendData(); break;
        case 7: _t->readyRead_tcp(); break;
        case 8: _t->on_read_mobile_status(); break;
        case 9: _t->on_map_read_command(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (mobile_robot::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&mobile_robot::LiftState)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (mobile_robot::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&mobile_robot::mobile_run)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (mobile_robot::*)(cv::Mat );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&mobile_robot::img_signal)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (mobile_robot::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&mobile_robot::mobile_status)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject mobile_robot::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_mobile_robot.data,
    qt_meta_data_mobile_robot,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *mobile_robot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mobile_robot::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_mobile_robot.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int mobile_robot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void mobile_robot::LiftState()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void mobile_robot::mobile_run(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void mobile_robot::img_signal(cv::Mat _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void mobile_robot::mobile_status(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
