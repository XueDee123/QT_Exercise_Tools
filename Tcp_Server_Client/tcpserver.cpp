#include "tcpserver.h"
#include <algorithm>

TcpServer::TcpServer(QObject *parent,int numConnections) : QTcpServer(parent)
{
    tcpClient = new  QHash<int,TcpSocket *>;
    setMaxPendingConnections(numConnections);
}

TcpServer::~TcpServer()
{
    StopServer();
    delete tcpClient;
}

void TcpServer::setMaxPendingConnections(int numConnections)
{
    this->QTcpServer::setMaxPendingConnections(numConnections);//调用Qtcpsocket函数，设置最大连接数，主要是使maxPendingConnections()依然有效
    this->maxConnections = numConnections;
}




void TcpServer::incomingConnection(qintptr socketDescriptor) //多线程必须在此函数里捕获新连接
{
    if (tcpClient->size() > maxPendingConnections())//继承重写此函数后，QTcpServer默认的判断最大连接数失效，自己实现
    {
        QTcpSocket tcp;
        tcp.setSocketDescriptor(socketDescriptor);
        tcp.disconnectFromHost();
        return;
    }
    auto th = ThreadHandle::getClass().getThread();
    auto tcpTemp = new TcpSocket(socketDescriptor);


    connect(tcpTemp,&TcpSocket::sockDisConnect,this,&TcpServer::sockDisConnectSlot);//NOTE:断开连接的处理，从列表移除，并释放断开的Tcpsocket，此槽必须实现，线程管理计数也是考的他
    connect(this,&TcpServer::sendDisConnect,tcpTemp,&TcpSocket::disConTcp);//断开信号
    connect(this,&TcpServer::sendData,tcpTemp,&TcpSocket::SendData);
    connect(tcpTemp,&TcpSocket::RecData,this,&TcpServer::readData);
    tcpTemp->moveToThread(th);//把tcp类移动到新的线程，从线程管理类中获取
    tcpClient->insert(socketDescriptor,tcpTemp);//插入到连接信息中
    clientsStatus.push_back(tcpTemp->GetInfo());
    emit RecClientStatus(clientsStatus);//刷新客户端信息
}

void TcpServer::sockDisConnectSlot(SocketInfo& info,QThread * th)
{
    tcpClient->remove(info.socketId);//连接管理中移除断开连接的socket
    ThreadHandle::getClass().removeThread(th); //告诉线程管理类那个线程里的连接断开了

    for(auto i=clientsStatus.begin();i!=clientsStatus.end();i++)
    {
        if((*i)==info)
        {
            clientsStatus.erase(i);
            break;
        }
    }

    emit RecClientStatus(clientsStatus);//刷新客户端信息
}



bool TcpServer::StartServer(const IpInfo *p)
{
    if(!this->isListening())
    {
        return this->listen(QHostAddress(p->ip),p->port);

    }
    return false;
}

void TcpServer::StopServer()
{
    emit this->sendDisConnect(-1);
    ThreadHandle::getClass().clear();
    tcpClient->clear();
    this->close();
}

void TcpServer::CloseClient(QString info)
{
    for(auto i=clientsStatus.begin();i!=clientsStatus.end();i++)
    {
         QString str=QString("%1:%2/%3").arg((*i).ip).arg((*i).port).arg((*i).socketId);
        if(str==info)
        {
             emit this->sendDisConnect((*i).socketId);
        }
    }

}



