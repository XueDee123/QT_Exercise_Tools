#ifndef PARAMETER_H
#define PARAMETER_H
#include <QString>

#define SERVER_MAX_LISTEN_NUM 100




struct IpInfo
{
    QString ip;
    int port;
     bool operator==(IpInfo& p)
    {
        return ((p.port == this->port)&& (p.ip == this->ip)) ? true : false;
    }
};

struct SocketInfo:public IpInfo
{
    qintptr socketId;
    bool operator==(SocketInfo& p)
    {
        return ((p.socketId == this->socketId) && (p.port == this->port)&& (p.ip == this->ip)) ? true : false;
    }
};



#endif // PARAMETER_H
