#ifndef THREAD_H
#define THREAD_H

#include <QString>
#include <QTcpSocket>//这个才是用来通信的，QTcpServer只是用来接收新用户的
#include<QThread>
#include "Parameter.h"
#include <QDebug>
class Thread : public QThread
{
    Q_OBJECT
public:
    explicit Thread(qintptr socketID,QObject *parent = nullptr);
    SocketInfo GetInfo();
void Disconnected();
    virtual bool operator==(Thread& p)
    {
        return (p.info == this->info) ? true : false;
    }
signals:
    void ClientJoin( Thread * t);
    void ClientLeave(  Thread * t);
public slots:
    void run();

private:
    qintptr socketDescription;
    QTcpSocket *socket;
    SocketInfo info;
private slots:
    void Read();

};

#endif // THREAD_H
