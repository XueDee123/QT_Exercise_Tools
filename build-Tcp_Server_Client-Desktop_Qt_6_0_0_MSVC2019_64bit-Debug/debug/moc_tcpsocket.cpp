/****************************************************************************
** Meta object code from reading C++ file 'tcpsocket.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.0.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Tcp_Server_Client/tcpsocket.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcpsocket.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.0.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TcpSocket_t {
    const uint offsetsAndSize[28];
    char stringdata0[118];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_TcpSocket_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_TcpSocket_t qt_meta_stringdata_TcpSocket = {
    {
QT_MOC_LITERAL(0, 9), // "TcpSocket"
QT_MOC_LITERAL(10, 7), // "RecData"
QT_MOC_LITERAL(18, 0), // ""
QT_MOC_LITERAL(19, 11), // "QByteArray&"
QT_MOC_LITERAL(31, 4), // "data"
QT_MOC_LITERAL(36, 10), // "SocketInfo"
QT_MOC_LITERAL(47, 4), // "info"
QT_MOC_LITERAL(52, 14), // "sockDisConnect"
QT_MOC_LITERAL(67, 11), // "SocketInfo&"
QT_MOC_LITERAL(79, 8), // "QThread*"
QT_MOC_LITERAL(88, 8), // "SendData"
QT_MOC_LITERAL(97, 1), // "i"
QT_MOC_LITERAL(99, 9), // "disConTcp"
QT_MOC_LITERAL(109, 8) // "ReadData"

    },
    "TcpSocket\0RecData\0\0QByteArray&\0data\0"
    "SocketInfo\0info\0sockDisConnect\0"
    "SocketInfo&\0QThread*\0SendData\0i\0"
    "disConTcp\0ReadData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TcpSocket[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   44,    2, 0x06,    0 /* Public */,
       7,    2,   49,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      10,    2,   54,    2, 0x0a,    6 /* Public */,
      12,    1,   59,    2, 0x0a,    9 /* Public */,
      13,    0,   62,    2, 0x09,   11 /* Protected */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,
    QMetaType::Void, 0x80000000 | 8, 0x80000000 | 9,    6,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray, 0x80000000 | 8,    2,   11,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,

       0        // eod
};

void TcpSocket::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TcpSocket *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->RecData((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< SocketInfo(*)>(_a[2]))); break;
        case 1: _t->sockDisConnect((*reinterpret_cast< SocketInfo(*)>(_a[1])),(*reinterpret_cast< QThread*(*)>(_a[2]))); break;
        case 2: _t->SendData((*reinterpret_cast< const QByteArray(*)>(_a[1])),(*reinterpret_cast< SocketInfo(*)>(_a[2]))); break;
        case 3: _t->disConTcp((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->ReadData(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QThread* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TcpSocket::*)(QByteArray & , SocketInfo );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpSocket::RecData)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TcpSocket::*)(SocketInfo & , QThread * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpSocket::sockDisConnect)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject TcpSocket::staticMetaObject = { {
    QMetaObject::SuperData::link<QTcpSocket::staticMetaObject>(),
    qt_meta_stringdata_TcpSocket.offsetsAndSize,
    qt_meta_data_TcpSocket,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_TcpSocket_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray &, std::false_type>, QtPrivate::TypeAndForceComplete<SocketInfo, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<SocketInfo &, std::false_type>, QtPrivate::TypeAndForceComplete<QThread *, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>, QtPrivate::TypeAndForceComplete<SocketInfo &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *TcpSocket::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TcpSocket::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TcpSocket.stringdata0))
        return static_cast<void*>(this);
    return QTcpSocket::qt_metacast(_clname);
}

int TcpSocket::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpSocket::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void TcpSocket::RecData(QByteArray & _t1, SocketInfo _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TcpSocket::sockDisConnect(SocketInfo & _t1, QThread * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
