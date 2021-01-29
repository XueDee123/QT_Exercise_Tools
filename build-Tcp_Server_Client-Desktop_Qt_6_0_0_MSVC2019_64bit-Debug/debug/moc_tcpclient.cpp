/****************************************************************************
** Meta object code from reading C++ file 'tcpclient.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.0.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Tcp_Server_Client/tcpclient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcpclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.0.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TcpClient_t {
    const uint offsetsAndSize[36];
    char stringdata0[192];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_TcpClient_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_TcpClient_t qt_meta_stringdata_TcpClient = {
    {
QT_MOC_LITERAL(0, 9), // "TcpClient"
QT_MOC_LITERAL(10, 7), // "RecData"
QT_MOC_LITERAL(18, 0), // ""
QT_MOC_LITERAL(19, 11), // "QByteArray&"
QT_MOC_LITERAL(31, 4), // "data"
QT_MOC_LITERAL(36, 10), // "SocketInfo"
QT_MOC_LITERAL(47, 4), // "info"
QT_MOC_LITERAL(52, 14), // "SockDisConnect"
QT_MOC_LITERAL(67, 11), // "SocketInfo&"
QT_MOC_LITERAL(79, 11), // "SockConnect"
QT_MOC_LITERAL(91, 11), // "SockConFail"
QT_MOC_LITERAL(103, 8), // "SendData"
QT_MOC_LITERAL(112, 1), // "i"
QT_MOC_LITERAL(114, 8), // "ReadData"
QT_MOC_LITERAL(123, 9), // "ReadError"
QT_MOC_LITERAL(133, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(162, 18), // "DoProcessConnected"
QT_MOC_LITERAL(181, 10) // "DisConnect"

    },
    "TcpClient\0RecData\0\0QByteArray&\0data\0"
    "SocketInfo\0info\0SockDisConnect\0"
    "SocketInfo&\0SockConnect\0SockConFail\0"
    "SendData\0i\0ReadData\0ReadError\0"
    "QAbstractSocket::SocketError\0"
    "DoProcessConnected\0DisConnect"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TcpClient[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   68,    2, 0x06,    0 /* Public */,
       7,    1,   73,    2, 0x06,    3 /* Public */,
       9,    1,   76,    2, 0x06,    5 /* Public */,
      10,    0,   79,    2, 0x06,    7 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      11,    2,   80,    2, 0x0a,    8 /* Public */,
      13,    0,   85,    2, 0x09,   11 /* Protected */,
      14,    1,   86,    2, 0x09,   12 /* Protected */,
      16,    0,   89,    2, 0x09,   14 /* Protected */,
      17,    0,   90,    2, 0x09,   15 /* Protected */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void, 0x80000000 | 8,    6,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray, 0x80000000 | 8,    2,   12,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TcpClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TcpClient *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->RecData((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< SocketInfo(*)>(_a[2]))); break;
        case 1: _t->SockDisConnect((*reinterpret_cast< SocketInfo(*)>(_a[1]))); break;
        case 2: _t->SockConnect((*reinterpret_cast< SocketInfo(*)>(_a[1]))); break;
        case 3: _t->SockConFail(); break;
        case 4: _t->SendData((*reinterpret_cast< const QByteArray(*)>(_a[1])),(*reinterpret_cast< SocketInfo(*)>(_a[2]))); break;
        case 5: _t->ReadData(); break;
        case 6: _t->ReadError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 7: _t->DoProcessConnected(); break;
        case 8: _t->DisConnect(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TcpClient::*)(QByteArray & , SocketInfo );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpClient::RecData)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TcpClient::*)(SocketInfo & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpClient::SockDisConnect)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TcpClient::*)(SocketInfo & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpClient::SockConnect)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (TcpClient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpClient::SockConFail)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject TcpClient::staticMetaObject = { {
    QMetaObject::SuperData::link<QTcpSocket::staticMetaObject>(),
    qt_meta_stringdata_TcpClient.offsetsAndSize,
    qt_meta_data_TcpClient,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_TcpClient_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray &, std::false_type>, QtPrivate::TypeAndForceComplete<SocketInfo, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<SocketInfo &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<SocketInfo &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>, QtPrivate::TypeAndForceComplete<SocketInfo &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QAbstractSocket::SocketError, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *TcpClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TcpClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TcpClient.stringdata0))
        return static_cast<void*>(this);
    return QTcpSocket::qt_metacast(_clname);
}

int TcpClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpSocket::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void TcpClient::RecData(QByteArray & _t1, SocketInfo _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TcpClient::SockDisConnect(SocketInfo & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TcpClient::SockConnect(SocketInfo & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TcpClient::SockConFail()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
