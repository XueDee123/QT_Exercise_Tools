/****************************************************************************
** Meta object code from reading C++ file 'tcpserver.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.0.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Tcp_Server_Client/tcpserver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcpserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.0.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TcpServer_t {
    const uint offsetsAndSize[44];
    char stringdata0[223];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_TcpServer_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_TcpServer_t qt_meta_stringdata_TcpServer = {
    {
QT_MOC_LITERAL(0, 9), // "TcpServer"
QT_MOC_LITERAL(10, 8), // "readData"
QT_MOC_LITERAL(19, 0), // ""
QT_MOC_LITERAL(20, 11), // "QByteArray&"
QT_MOC_LITERAL(32, 4), // "data"
QT_MOC_LITERAL(37, 10), // "SocketInfo"
QT_MOC_LITERAL(48, 4), // "info"
QT_MOC_LITERAL(53, 14), // "sockDisConnect"
QT_MOC_LITERAL(68, 8), // "sendData"
QT_MOC_LITERAL(77, 11), // "SocketInfo&"
QT_MOC_LITERAL(89, 1), // "i"
QT_MOC_LITERAL(91, 14), // "sendDisConnect"
QT_MOC_LITERAL(106, 15), // "RecClientStatus"
QT_MOC_LITERAL(122, 18), // "QList<SocketInfo>&"
QT_MOC_LITERAL(141, 11), // "StartServer"
QT_MOC_LITERAL(153, 13), // "const IpInfo*"
QT_MOC_LITERAL(167, 1), // "p"
QT_MOC_LITERAL(169, 10), // "StopServer"
QT_MOC_LITERAL(180, 11), // "CloseClient"
QT_MOC_LITERAL(192, 18), // "sockDisConnectSlot"
QT_MOC_LITERAL(211, 8), // "QThread*"
QT_MOC_LITERAL(220, 2) // "th"

    },
    "TcpServer\0readData\0\0QByteArray&\0data\0"
    "SocketInfo\0info\0sockDisConnect\0sendData\0"
    "SocketInfo&\0i\0sendDisConnect\0"
    "RecClientStatus\0QList<SocketInfo>&\0"
    "StartServer\0const IpInfo*\0p\0StopServer\0"
    "CloseClient\0sockDisConnectSlot\0QThread*\0"
    "th"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TcpServer[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   68,    2, 0x06,    0 /* Public */,
       7,    3,   73,    2, 0x06,    3 /* Public */,
       8,    2,   80,    2, 0x06,    7 /* Public */,
      11,    1,   85,    2, 0x06,   10 /* Public */,
      12,    1,   88,    2, 0x06,   12 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      14,    1,   91,    2, 0x0a,   14 /* Public */,
      17,    0,   94,    2, 0x0a,   16 /* Public */,
      18,    1,   95,    2, 0x0a,   17 /* Public */,
      19,    2,   98,    2, 0x09,   19 /* Protected */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::UShort,    2,    2,    2,
    QMetaType::Void, QMetaType::QByteArray, 0x80000000 | 9,    4,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, 0x80000000 | 13,    2,

 // slots: parameters
    QMetaType::Bool, 0x80000000 | 15,   16,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 9, 0x80000000 | 20,    6,   21,

       0        // eod
};

void TcpServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TcpServer *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->readData((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< SocketInfo(*)>(_a[2]))); break;
        case 1: _t->sockDisConnect((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< quint16(*)>(_a[3]))); break;
        case 2: _t->sendData((*reinterpret_cast< const QByteArray(*)>(_a[1])),(*reinterpret_cast< SocketInfo(*)>(_a[2]))); break;
        case 3: _t->sendDisConnect((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->RecClientStatus((*reinterpret_cast< QList<SocketInfo>(*)>(_a[1]))); break;
        case 5: { bool _r = _t->StartServer((*reinterpret_cast< const IpInfo*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->StopServer(); break;
        case 7: _t->CloseClient((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->sockDisConnectSlot((*reinterpret_cast< SocketInfo(*)>(_a[1])),(*reinterpret_cast< QThread*(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 8:
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
            using _t = void (TcpServer::*)(QByteArray & , SocketInfo );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpServer::readData)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TcpServer::*)(int , QString , quint16 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpServer::sockDisConnect)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TcpServer::*)(const QByteArray & , SocketInfo & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpServer::sendData)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (TcpServer::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpServer::sendDisConnect)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (TcpServer::*)(QList<SocketInfo> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpServer::RecClientStatus)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject TcpServer::staticMetaObject = { {
    QMetaObject::SuperData::link<QTcpServer::staticMetaObject>(),
    qt_meta_stringdata_TcpServer.offsetsAndSize,
    qt_meta_data_TcpServer,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_TcpServer_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray &, std::false_type>, QtPrivate::TypeAndForceComplete<SocketInfo, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<quint16, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>, QtPrivate::TypeAndForceComplete<SocketInfo &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QList<SocketInfo> &, std::false_type>
, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<const IpInfo *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<SocketInfo &, std::false_type>, QtPrivate::TypeAndForceComplete<QThread *, std::false_type>


>,
    nullptr
} };


const QMetaObject *TcpServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TcpServer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TcpServer.stringdata0))
        return static_cast<void*>(this);
    return QTcpServer::qt_metacast(_clname);
}

int TcpServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpServer::qt_metacall(_c, _id, _a);
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
void TcpServer::readData(QByteArray & _t1, SocketInfo _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TcpServer::sockDisConnect(int _t1, QString _t2, quint16 _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TcpServer::sendData(const QByteArray & _t1, SocketInfo & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TcpServer::sendDisConnect(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void TcpServer::RecClientStatus(QList<SocketInfo> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
