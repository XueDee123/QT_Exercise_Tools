#include "tcpclient.h"
#include <QTime>
#include <QThread>
#include <QHostAddress>

TcpClient::TcpClient(QObject *parent) : QTcpSocket(parent)
{
    connect(this,&TcpClient::errorOccurred,this,&TcpClient::ReadError);
    connect(this,&TcpClient::connected,this,&TcpClient::DoProcessConnected);
    connect(this,&TcpClient::readyRead,this,&TcpClient::ReadData);
    connect(this,&TcpClient::disconnected,this,&TcpClient::DisConnect);
}

void TcpClient::ConnectToServer(IpInfo i)
{
    this->connectToHost(QHostAddress(i.ip),i.port);
    this->waitForConnected(5000);
}

void TcpClient::SendData(const QByteArray &data, SocketInfo &id)
{
    if(id == info)
    {
        write(data);
    }
}


void TcpClient::disConTcp(int i)
{
#ifdef QT_DEBUG
    qDebug()<<"---------disConTcp处理数据-----------";
    qDebug()<<"当前时间:"<<QTime::currentTime().toString().toUtf8();
    qDebug()<<"当前线程:"<<QThread::currentThreadId();
#endif
    if (i == info.socketId)
    {
        this->disconnectFromHost();
    }
    else if (i == -1) //-1为全部断开
    {
        disconnect(this,&TcpClient::disconnected,this,&TcpClient::DisConnect); //先断开连接的信号槽，防止二次析构
        this->disconnectFromHost();
        this->deleteLater();
    }
}
void TcpClient::ReadData()
{
#ifdef QT_DEBUG
    qDebug()<<"---------ReadData处理数据-----------";
    qDebug()<<"当前时间:"<<QTime::currentTime().toString().toUtf8();
    qDebug()<<"当前线程:"<<QThread::currentThreadId();
    qDebug()<<QString("IP:%1 PORT:%2").arg(info.ip).arg(QString::number(info.port));
#endif
    auto data=this->readAll();
    emit RecData(data,info);
}

void TcpClient::ReadError(QAbstractSocket::SocketError er)
{
#ifdef QT_DEBUG
    qDebug()<<"---------Error客户端异常-----------";
    qDebug()<<"当前时间:"<<QTime::currentTime().toString().toUtf8();
    qDebug()<<"当前线程:"<<QThread::currentThreadId();
    qDebug()<<QString("IP:%1 PORT:%2").arg(info.ip).arg(QString::number(info.port));
    qDebug()<<QString("异常信息:%1").arg(er);
#endif
    if(er==QAbstractSocket::SocketError::HostNotFoundError||
            er==QAbstractSocket::SocketError::ConnectionRefusedError)
    {
        //客户端连接失败
        emit SockConFail();
    }
}

void TcpClient::DoProcessConnected()
{
#ifdef QT_DEBUG
    qDebug()<<"---------Debug客户端连接成功-----------";
    qDebug()<<"当前时间:"<<QTime::currentTime().toString().toUtf8();
    qDebug()<<"当前线程:"<<QThread::currentThreadId();
    qDebug()<<QString("IP:%1 PORT:%2").arg(info.ip).arg(QString::number(info.port));
#endif
    info.ip=this->peerAddress().toString();
    info.port=this->peerPort();
    info.socketId=this->socketDescriptor();
    emit SockConnect(info);
}

void TcpClient::DisConnect()
{
#ifdef QT_DEBUG
        qDebug()<<"---------Info客户端断开连接-----------";
        qDebug()<<"当前时间:"<<QTime::currentTime().toString().toUtf8();
        qDebug()<<"当前线程:"<<QThread::currentThreadId();
        qDebug()<<QString("IP:%1 PORT:%2").arg(info.ip).arg(QString::number(info.port));
#endif
        emit SockDisConnect(info);//发送断开连接的用户信息
        this->deleteLater();
}
SocketInfo TcpClient::GetInfo()
{
    return info;
}
