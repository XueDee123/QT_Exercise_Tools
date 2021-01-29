#ifndef CLIENTMANAGER_H
#define CLIENTMANAGER_H

#include <QObject>
#include "tcpclient.h"
#include <QList>
#include "Parameter.h"

class ClientManager : public QObject
{
    Q_OBJECT
public:
    explicit ClientManager(QObject *parent = nullptr);
    void Run();
    ~ClientManager();
    //void CloseClient(IpInfo);
signals:
    void AddClient(IpInfo &);
    void readData(QByteArray &data,SocketInfo info);
    void SendData(const QByteArray & ,SocketInfo& i);
    void SockConFail();
    void SockConnect(SocketInfo& info);
    void SockDisConnect(SocketInfo&);
    void SendDisConnect(int i);
private:
    void SockDisConnect_Slot(SocketInfo&);
    void AddClient_Slot(IpInfo &);
    void SockConnect_Slot(SocketInfo& info);
    void SockConFail_Slot();
private:
    QList<TcpClient*>clients;
    TcpClient *tempClient;
};

#endif // CLIENTMANAGER_H
