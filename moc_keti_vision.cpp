/****************************************************************************
** Meta object code from reading C++ file 'keti_vision.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "keti_vision.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'keti_vision.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Keti_vision_t {
    QByteArrayData data[14];
    char stringdata0[172];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Keti_vision_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Keti_vision_t qt_meta_stringdata_Keti_vision = {
    {
QT_MOC_LITERAL(0, 0, 11), // "Keti_vision"
QT_MOC_LITERAL(1, 12, 16), // "SIGNAL_LOG_WRITE"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 9), // "msgSignal"
QT_MOC_LITERAL(4, 40, 12), // "connect_flag"
QT_MOC_LITERAL(5, 53, 15), // "keti_img_signal"
QT_MOC_LITERAL(6, 69, 7), // "cv::Mat"
QT_MOC_LITERAL(7, 77, 3), // "img"
QT_MOC_LITERAL(8, 81, 14), // "keti_img_point"
QT_MOC_LITERAL(9, 96, 5), // "point"
QT_MOC_LITERAL(10, 102, 14), // "onReadyCmdRead"
QT_MOC_LITERAL(11, 117, 15), // "onKetiConnected"
QT_MOC_LITERAL(12, 133, 18), // "onKetidisConnected"
QT_MOC_LITERAL(13, 152, 19) // "onReconnectToServer"

    },
    "Keti_vision\0SIGNAL_LOG_WRITE\0\0msgSignal\0"
    "connect_flag\0keti_img_signal\0cv::Mat\0"
    "img\0keti_img_point\0point\0onReadyCmdRead\0"
    "onKetiConnected\0onKetidisConnected\0"
    "onReconnectToServer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Keti_vision[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    1,   55,    2, 0x06 /* Public */,
       5,    1,   58,    2, 0x06 /* Public */,
       8,    1,   61,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   64,    2, 0x0a /* Public */,
      11,    0,   65,    2, 0x0a /* Public */,
      12,    0,   66,    2, 0x0a /* Public */,
      13,    0,   67,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::QString,    9,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Keti_vision::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Keti_vision *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SIGNAL_LOG_WRITE(); break;
        case 1: _t->msgSignal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->keti_img_signal((*reinterpret_cast< cv::Mat(*)>(_a[1]))); break;
        case 3: _t->keti_img_point((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->onReadyCmdRead(); break;
        case 5: _t->onKetiConnected(); break;
        case 6: _t->onKetidisConnected(); break;
        case 7: _t->onReconnectToServer(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Keti_vision::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Keti_vision::SIGNAL_LOG_WRITE)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Keti_vision::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Keti_vision::msgSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Keti_vision::*)(cv::Mat );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Keti_vision::keti_img_signal)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Keti_vision::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Keti_vision::keti_img_point)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Keti_vision::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Keti_vision.data,
    qt_meta_data_Keti_vision,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Keti_vision::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Keti_vision::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Keti_vision.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Keti_vision::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Keti_vision::SIGNAL_LOG_WRITE()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Keti_vision::msgSignal(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Keti_vision::keti_img_signal(cv::Mat _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Keti_vision::keti_img_point(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
