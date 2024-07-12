/****************************************************************************
** Meta object code from reading C++ file 'websocket.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "websocket.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'websocket.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_websocket_t {
    QByteArrayData data[29];
    char stringdata0[351];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_websocket_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_websocket_t qt_meta_stringdata_websocket = {
    {
QT_MOC_LITERAL(0, 0, 9), // "websocket"
QT_MOC_LITERAL(1, 10, 9), // "msgSignal"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 3), // "msg"
QT_MOC_LITERAL(4, 25, 15), // "msgReciveSignal"
QT_MOC_LITERAL(5, 41, 7), // "message"
QT_MOC_LITERAL(6, 49, 13), // "msgSendSignal"
QT_MOC_LITERAL(7, 63, 21), // "check_robot_connected"
QT_MOC_LITERAL(8, 85, 9), // "connected"
QT_MOC_LITERAL(9, 95, 10), // "order_pass"
QT_MOC_LITERAL(10, 106, 4), // "open"
QT_MOC_LITERAL(11, 111, 8), // "Feedback"
QT_MOC_LITERAL(12, 120, 11), // "SEND_NOTICE"
QT_MOC_LITERAL(13, 132, 15), // "onNewConnection"
QT_MOC_LITERAL(14, 148, 8), // "onClosed"
QT_MOC_LITERAL(15, 157, 21), // "onTextMessageReceived"
QT_MOC_LITERAL(16, 179, 23), // "onBinaryMessageReceived"
QT_MOC_LITERAL(17, 203, 12), // "MissionCheck"
QT_MOC_LITERAL(18, 216, 4), // "uuid"
QT_MOC_LITERAL(19, 221, 14), // "onDisconnected"
QT_MOC_LITERAL(20, 236, 16), // "send_img_package"
QT_MOC_LITERAL(21, 253, 15), // "map_config_path"
QT_MOC_LITERAL(22, 269, 15), // "image_file_size"
QT_MOC_LITERAL(23, 285, 9), // "signature"
QT_MOC_LITERAL(24, 295, 8), // "fileName"
QT_MOC_LITERAL(25, 304, 9), // "moveCheck"
QT_MOC_LITERAL(26, 314, 8), // "cmd_loop"
QT_MOC_LITERAL(27, 323, 11), // "QWebSocket*"
QT_MOC_LITERAL(28, 335, 15) // "pClient_address"

    },
    "websocket\0msgSignal\0\0msg\0msgReciveSignal\0"
    "message\0msgSendSignal\0check_robot_connected\0"
    "connected\0order_pass\0open\0Feedback\0"
    "SEND_NOTICE\0onNewConnection\0onClosed\0"
    "onTextMessageReceived\0onBinaryMessageReceived\0"
    "MissionCheck\0uuid\0onDisconnected\0"
    "send_img_package\0map_config_path\0"
    "image_file_size\0signature\0fileName\0"
    "moveCheck\0cmd_loop\0QWebSocket*\0"
    "pClient_address"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_websocket[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   99,    2, 0x06 /* Public */,
       4,    1,  102,    2, 0x06 /* Public */,
       6,    1,  105,    2, 0x06 /* Public */,
       7,    1,  108,    2, 0x06 /* Public */,
       9,    1,  111,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,  114,    2, 0x0a /* Public */,
      11,    0,  115,    2, 0x0a /* Public */,
      12,    0,  116,    2, 0x0a /* Public */,
      13,    0,  117,    2, 0x0a /* Public */,
      14,    0,  118,    2, 0x0a /* Public */,
      15,    1,  119,    2, 0x0a /* Public */,
      16,    1,  122,    2, 0x0a /* Public */,
      17,    1,  125,    2, 0x0a /* Public */,
      19,    0,  128,    2, 0x0a /* Public */,
      20,    4,  129,    2, 0x0a /* Public */,
      25,    0,  138,    2, 0x0a /* Public */,
      26,    1,  139,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::QJsonObject,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QByteArray,    5,
    QMetaType::Void, QMetaType::QString,   18,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString,   21,   22,   23,   24,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 27,   28,

       0        // eod
};

void websocket::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<websocket *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->msgSignal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->msgReciveSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->msgSendSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->check_robot_connected((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->order_pass((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 5: _t->open(); break;
        case 6: _t->Feedback(); break;
        case 7: _t->SEND_NOTICE(); break;
        case 8: _t->onNewConnection(); break;
        case 9: _t->onClosed(); break;
        case 10: _t->onTextMessageReceived((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->onBinaryMessageReceived((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 12: _t->MissionCheck((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->onDisconnected(); break;
        case 14: _t->send_img_package((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 15: _t->moveCheck(); break;
        case 16: _t->cmd_loop((*reinterpret_cast< QWebSocket*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 16:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWebSocket* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (websocket::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&websocket::msgSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (websocket::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&websocket::msgReciveSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (websocket::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&websocket::msgSendSignal)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (websocket::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&websocket::check_robot_connected)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (websocket::*)(QJsonObject );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&websocket::order_pass)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject websocket::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_websocket.data,
    qt_meta_data_websocket,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *websocket::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *websocket::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_websocket.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int websocket::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void websocket::msgSignal(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void websocket::msgReciveSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void websocket::msgSendSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void websocket::check_robot_connected(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void websocket::order_pass(QJsonObject _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
