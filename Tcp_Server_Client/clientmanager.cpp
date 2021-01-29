#include "clientmanager.h"
#include <QTime>
#include <QThread>

ClientManager::ClientManager(QObject *parent) : QObject(parent)
{

}

void ClientManager::Run()
{
#ifdef QT_DEBUG
    qDebug()<<"---------Run处理数据-----------";
    qDebug()<<"当前时间:"<<QTime::currentTime().toString().toUtf8();
    qDebug()<<"当前线程:"<<QThread::currentThreadId();
#endif
connect(this,&ClientManager::AddClient,this,&ClientManager::AddClient_Slot);
}

ClientManager::~ClientManager()
{
    for(auto i=clients.begin();i!=clients.end();i++)
    {
        (*i)->disConTcp(-1);
    }
}

void ClientManager::SockDisConnect_Slot(SocketInfo & info)
{
   for(auto i=clients.begin();i!=clients.end();i++)
   {
       if((*i)->GetInfo()==info)
       {
           clients.erase(i);
           emit SockDisConnect(info);
           break;
       }
   }

}
//void ClientManager::CloseClient(IpInfo info)
//{
//    for(auto i=clients.begin();i!=clients.end();i++)
//    {
//        if(((IpInfo)((*i)->GetInfo()))==info)
//        {
//             emit this->SendDisConnect((*i)->GetInfo().socketId);
//        }
//    }

//}

void ClientManager::AddClient_Slot(IpInfo & info)
{
#ifdef QT_DEBUG
    qDebug()<<"---------AddClient_Slot处理数据-----------";
    qDebug()<<"当前时间:"<<QTime::currentTime().toString().toUtf8();
    qDebug()<<"当前线程:"<<QThread::currentThreadId();
    qDebug()<<QString("IP:%1 PORT:%2").arg(info.ip).arg(QString::number(info.port));
#endif
    //创建
    tempClient=new TcpClient;
    connect(tempClient,&TcpClient::SockConnect,this,&ClientManager::SockConnect_Slot);//成功连接返回
    connect(tempClient,&TcpClient::SockConFail,this ,&ClientManager::SockConFail_Slot);//异常连接返回

    tempClient->ConnectToServer(info);



}

void ClientManager::SockConnect_Slot(SocketInfo &info)
{
    //如果客户端成功打开
    connect(tempClient,&TcpClient::RecData,this,&ClientManager::readData);//绑定接收数据
    connect(this,&ClientManager::SendData,tempClient,&TcpClient::SendData);//绑定发送数据
    connect(tempClient,&TcpClient::SockDisConnect,this,&ClientManager::SockDisConnect_Slot);//异常断开
    connect(this,&ClientManager::SendDisConnect,tempClient,&TcpClient::disConTcp);//断开信号
    clients.push_back(tempClient);
    tempClient=nullptr;
    emit SockConnect(info);
}

void ClientManager::SockConFail_Slot()
{
    //未打开成功
    if(tempClient!=nullptr)
    {
        tempClient->deleteLater();
        tempClient=nullptr;
    }
    emit SockConFail();
}
