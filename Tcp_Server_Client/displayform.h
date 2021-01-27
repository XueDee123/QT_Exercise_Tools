#ifndef DISPLAYFORM_H
#define DISPLAYFORM_H

#include <QWidget>
#include "Parameter.h"

namespace Ui {
class DisplayForm;
}

class DisplayForm : public QWidget
{
    Q_OBJECT

public:
    explicit DisplayForm(bool connect=false,QWidget *parent = nullptr);
    explicit DisplayForm(SocketInfo info,bool connect=false,QWidget *parent = nullptr);
    ~DisplayForm();
    void RecData(QByteArray &data,SocketInfo info);
signals:
     void sendData(const QByteArray & data,SocketInfo& i);
private:
    Ui::DisplayForm *ui;
private:
    void Init(bool p);
private:
    SocketInfo info;
    QString recDispData;
    QString sendDispData;
    long long recDataNum;
    long long sendDataNum;
};

#endif // DISPLAYFORM_H
