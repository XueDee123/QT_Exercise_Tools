#include "tcpsocket.h"
#include <QHostAddress>
#include <QDebug>

TcpSocket::TcpSocket(qintptr socketDescriptor, QObject *parent) : //构造函数在主线程执行，lambda在子线程
    QTcpSocket(parent)
{

    this->setSocketDescriptor(socketDescriptor);
    info.ip=this->peerAddress().toString();
    info.port=this->peerPort();
    info.socketId=socketDescriptor;
    connect(this,&TcpSocket::readyRead,this,&TcpSocket::ReadData);
    dis = connect(this,&TcpSocket::disconnected,
        [&](){
            qDebug() << "disconnect" ;
            emit sockDisConnect(info,QThread::currentThread());//发送断开连接的用户信息
            this->deleteLater();
        });

    qDebug() << "new connect" ;
}

TcpSocket::~TcpSocket()
{
}


void TcpSocket::SendData(const QByteArray &data, SocketInfo& id)
{
    if(id == info)
    {
        write(data);
    }
}

void TcpSocket::disConTcp(int i)
{
    if (i == info.socketId)
    {
        this->disconnectFromHost();
    }
    else if (i == -1) //-1为全部断开
    {
        disconnect(dis); //先断开连接的信号槽，防止二次析构
        this->disconnectFromHost();
        this->deleteLater();
    }
}

void TcpSocket::ReadData()
{
    handleData(this->readAll(),this->info);
}

void TcpSocket::handleData(QByteArray data, SocketInfo info)
{
#ifdef QT_DEBUG
    qDebug()<<"---------handleData处理数据-----------";
    qDebug()<<"当前时间:"<<QTime::currentTime().toString().toUtf8();
    qDebug()<<"当前线程:"<<QThread::currentThreadId();
    qDebug()<<QString("IP:%1 PORT:%2").arg(info.ip).arg(QString::number(info.port));
#endif
    emit RecData(data,info);
}

SocketInfo TcpSocket::GetInfo()
{
    return info;
}

