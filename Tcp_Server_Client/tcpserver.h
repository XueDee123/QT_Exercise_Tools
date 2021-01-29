#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QTcpServer>
#include <QString>
#include "Parameter.h"
#include <QHash>
#include "tcpsocket.h"
#include "threadhandle.h"
#include <QList>

class TcpServer : public QTcpServer
{
    Q_OBJECT
public:
    //初始化
    explicit TcpServer(QObject *parent = nullptr,int numConnections=10000);
    ~TcpServer();
    void setMaxPendingConnections(int numConnections);//重写设置最大连接数函数
signals:

    void readData(QByteArray &data,SocketInfo info);//发送获得用户发过来的数据
    void sockDisConnect(int ,QString ,quint16);//断开连接的用户信息
    void sendData(const QByteArray & data,SocketInfo& i);//向scoket发送消息
    void sendDisConnect(int i); //断开特定连接，并释放资源，-1为断开所有。
    void RecClientStatus( QList<SocketInfo>&);
public slots:
    bool StartServer(const IpInfo *p);
    void StopServer();
    void CloseClient(QString);
protected slots:
    void sockDisConnectSlot(SocketInfo& info, QThread *th);//断开连接的用户信息
protected:
    void incomingConnection(qintptr socketDescriptor);//覆盖已获取多线程

private:
    QHash<int,TcpSocket *> * tcpClient;//管理连接的map
    int maxConnections;
    QList<SocketInfo>clientsStatus;
};

#endif // TCPSERVER_H
