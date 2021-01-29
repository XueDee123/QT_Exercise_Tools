/****************************************************************************
** Meta object code from reading C++ file 'clientmanager.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.0.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Tcp_Server_Client/clientmanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clientmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.0.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ClientManager_t {
    const uint offsetsAndSize[32];
    char stringdata0[152];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ClientManager_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ClientManager_t qt_meta_stringdata_ClientManager = {
    {
QT_MOC_LITERAL(0, 13), // "ClientManager"
QT_MOC_LITERAL(14, 9), // "AddClient"
QT_MOC_LITERAL(24, 0), // ""
QT_MOC_LITERAL(25, 7), // "IpInfo&"
QT_MOC_LITERAL(33, 8), // "readData"
QT_MOC_LITERAL(42, 11), // "QByteArray&"
QT_MOC_LITERAL(54, 4), // "data"
QT_MOC_LITERAL(59, 10), // "SocketInfo"
QT_MOC_LITERAL(70, 4), // "info"
QT_MOC_LITERAL(75, 8), // "SendData"
QT_MOC_LITERAL(84, 11), // "SocketInfo&"
QT_MOC_LITERAL(96, 1), // "i"
QT_MOC_LITERAL(98, 11), // "SockConFail"
QT_MOC_LITERAL(110, 11), // "SockConnect"
QT_MOC_LITERAL(122, 14), // "SockDisConnect"
QT_MOC_LITERAL(137, 14) // "SendDisConnect"

    },
    "ClientManager\0AddClient\0\0IpInfo&\0"
    "readData\0QByteArray&\0data\0SocketInfo\0"
    "info\0SendData\0SocketInfo&\0i\0SockConFail\0"
    "SockConnect\0SockDisConnect\0SendDisConnect"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ClientManager[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   56,    2, 0x06,    0 /* Public */,
       4,    2,   59,    2, 0x06,    2 /* Public */,
       9,    2,   64,    2, 0x06,    5 /* Public */,
      12,    0,   69,    2, 0x06,    8 /* Public */,
      13,    1,   70,    2, 0x06,    9 /* Public */,
      14,    1,   73,    2, 0x06,   11 /* Public */,
      15,    1,   76,    2, 0x06,   13 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 7,    6,    8,
    QMetaType::Void, QMetaType::QByteArray, 0x80000000 | 10,    2,   11,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,    8,
    QMetaType::Void, 0x80000000 | 10,    2,
    QMetaType::Void, QMetaType::Int,   11,

       0        // eod
};

void ClientManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ClientManager *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->AddClient((*reinterpret_cast< IpInfo(*)>(_a[1]))); break;
        case 1: _t->readData((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< SocketInfo(*)>(_a[2]))); break;
        case 2: _t->SendData((*reinterpret_cast< const QByteArray(*)>(_a[1])),(*reinterpret_cast< SocketInfo(*)>(_a[2]))); break;
        case 3: _t->SockConFail(); break;
        case 4: _t->SockConnect((*reinterpret_cast< SocketInfo(*)>(_a[1]))); break;
        case 5: _t->SockDisConnect((*reinterpret_cast< SocketInfo(*)>(_a[1]))); break;
        case 6: _t->SendDisConnect((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ClientManager::*)(IpInfo & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClientManager::AddClient)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ClientManager::*)(QByteArray & , SocketInfo );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClientManager::readData)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ClientManager::*)(const QByteArray & , SocketInfo & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClientManager::SendData)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ClientManager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClientManager::SockConFail)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ClientManager::*)(SocketInfo & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClientManager::SockConnect)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (ClientManager::*)(SocketInfo & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClientManager::SockDisConnect)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (ClientManager::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClientManager::SendDisConnect)) {
                *result = 6;
                return;
            }
        }
    }
}

const QMetaObject ClientManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ClientManager.offsetsAndSize,
    qt_meta_data_ClientManager,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ClientManager_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<IpInfo &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray &, std::false_type>, QtPrivate::TypeAndForceComplete<SocketInfo, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>, QtPrivate::TypeAndForceComplete<SocketInfo &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<SocketInfo &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<SocketInfo &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>



>,
    nullptr
} };


const QMetaObject *ClientManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClientManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ClientManager.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ClientManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void ClientManager::AddClient(IpInfo & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ClientManager::readData(QByteArray & _t1, SocketInfo _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ClientManager::SendData(const QByteArray & _t1, SocketInfo & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ClientManager::SockConFail()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void ClientManager::SockConnect(SocketInfo & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void ClientManager::SockDisConnect(SocketInfo & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void ClientManager::SendDisConnect(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
