#include "thread.h"
#include <QHostAddress>

Thread::Thread(qintptr socketID,QObject *parent) : QThread(parent)
{
    this->socketDescription=socketID;//
    info.socketId=socketID;
}

SocketInfo Thread::GetInfo()
{
    return info;
}




void Thread::run()
{
    //这里实例化socket
    this->socket=new QTcpSocket;
    if(!socket->setSocketDescriptor(this->socketDescription))
    {
#ifdef QT_DEBUG
        qDebug()<<"error: setSocketDescriptor is fasle";
        return;
#endif
    }
#ifdef QT_DEBUG
    qDebug()<< QString("客户端[%1:%2]加入").arg(socket->peerAddress().toString()).arg(socket->peerPort());
    qDebug()<<"debug:run()当前线程号"<<QThread::currentThreadId();
#endif
    //下面代表没问题
    //可以开始逻辑业务了
    //对方客户发消息的时候我们这里进行处理，因为多线程所以用到了最后一个参数
    connect(socket,&QTcpSocket::readyRead,this,&Thread::Read,Qt::DirectConnection);
    connect(socket,&QTcpSocket::disconnected,this,&Thread::Disconnected,Qt::DirectConnection);
    info.ip=socket->peerAddress().toString();
    info.port=socket->peerPort();
    //触发信号告诉调用者
    emit ClientJoin(this);

    //因为涉及到线程，所以这里需要循环监听
    this->exec();
}



void Thread::Read()
{

    //连接了信号槽，执行这里的时候代表可以读取
    QByteArray buff=this->socket->readAll();
#ifdef QT_DEBUG
    qDebug()<<"debug:Read()当前线程号"<<QThread::currentThreadId();

#endif

}
//这个是断开连接后，释放内存的函数
void Thread::Disconnected()
{
#ifdef QT_DEBUG
    qDebug()<< QString("客户端[%1:%2]退出").arg(socket->peerAddress().toString()).arg(socket->peerPort());
    qDebug()<<"debug:run()当前线程号"<<QThread::currentThreadId();
#endif
    //触发信号告诉调用者
    emit ClientLeave(this);
    //断开主机
    this->socket->disconnectFromHost();
    //关闭类
    this->socket->close();
    //释放
    this->socket->deleteLater();
    //退出当前线程
    this->exit();
}
