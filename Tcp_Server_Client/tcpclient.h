#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QTcpSocket>
#include "Parameter.h"
#include <QThread>

class TcpClient : public QTcpSocket
{
    Q_OBJECT
public:
    explicit TcpClient(QObject *parent = nullptr);
    void ConnectToServer(IpInfo i);
    SocketInfo GetInfo();
    void disConTcp(int i);
signals:
    void RecData(QByteArray &data,SocketInfo info);
    void SockDisConnect(SocketInfo&);
    void SockConnect(SocketInfo& info);
    void SockConFail();
public slots:
    void SendData(const QByteArray & ,SocketInfo& i);//发送信号的槽
protected slots:
    void ReadData();//接收数据
    void ReadError(QAbstractSocket::SocketError);
    void DoProcessConnected();
    void DisConnect();
private:
    SocketInfo info;
};

#endif // TCPCLIENT_H
