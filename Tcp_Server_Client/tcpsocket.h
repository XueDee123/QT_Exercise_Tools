#ifndef TCPSOCKET_H
#define TCPSOCKET_H


#include <QTcpSocket>
#include <QFutureWatcher>
#include <QByteArray>
#include "Parameter.h"
#include <QTime>


class TcpSocket : public QTcpSocket
{
    Q_OBJECT
public:
    explicit TcpSocket(qintptr socketDescriptor, QObject *parent = 0);
    ~TcpSocket();
    void handleData(QByteArray data,SocketInfo info);//用来处理数据的函数
    SocketInfo GetInfo();
signals:
    void RecData(QByteArray &data,SocketInfo info);
    void sockDisConnect(SocketInfo& info, QThread *);//NOTE:断开连接的用户信息，此信号必须发出！线程管理类根据信号计数的
public slots:
    void SendData(const QByteArray & ,SocketInfo& i);//发送信号的槽
    void disConTcp(int i);

protected slots:
     void ReadData();//接收数据

private:
    SocketInfo info;
    QMetaObject::Connection dis;
};

#endif // TCPSOCKET_H
