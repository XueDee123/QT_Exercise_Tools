#include "displayform.h"
#include "ui_displayform.h"
#include <QDebug>
#include <QTime>
#include <QThread>
#include <QPushButton>

DisplayForm::DisplayForm(bool connect,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DisplayForm)
{
    ui->setupUi(this);
    Init(connect);


}

DisplayForm::DisplayForm(SocketInfo info, bool connect, QWidget *parent):DisplayForm(connect,parent)
{
    this->info=info;
    ui->txt_ip->setText(info.ip);
    ui->txt_port->setText(QString::number(info.port));
}


DisplayForm::~DisplayForm()
{
    delete ui;
}

void DisplayForm::RecData(QByteArray &data, SocketInfo info)
{
    if(this->info==info)
    {
#ifdef QT_DEBUG
        qDebug()<<"---------RecData-----------";
        qDebug()<<"当前时间:"<<QTime::currentTime().toString().toUtf8();
        qDebug()<<"当前线程:"<<QThread::currentThreadId();
        qDebug()<<QString(data.toHex().toUpper());
#endif
        if(recDispData.count()>200)
        {
            recDispData.remove(0,recDispData.count()/2);
        }
        if(ui->cb_recHex->checkState()==Qt::CheckState::Checked)
        {
            QString ret(data.toHex().toUpper());
            int len = ret.length()/2;
            for(int i=1;i<len;i++)
            {
                ret.insert(2*i+i-1," ");
            }
            recDispData+=ret;
            recDispData+=" ";
            ui->txt_recData->setText(recDispData);
            recDataNum+=data.count();
            ui->txt_recNum->setText(QString::number(recDataNum));
        }
        else
        {
            for(int i = 0; i < data .count(); ++i)
            {
                recDispData.append(QChar(data .at(i)));
                recDataNum++;
            }
            qDebug()<<recDispData;
            ui->txt_recData->setText(recDispData);
            ui->txt_recNum->setText(QString::number(recDataNum));
        }
    }


}

SocketInfo DisplayForm::GetInfo()
{
    return info;
}

void DisplayForm::Init(bool p)
{
    if(p)
    {
        ui->txt_ip->setEnabled(!p);
        ui->txt_port->setEnabled(!p);
    }
    ui->cb_hex->setCheckState(Qt::CheckState::Checked);
     ui->cb_recHex->setCheckState(Qt::CheckState::Checked);
    ui->btn_send->setEnabled(p);
    ui->btn_connect->setVisible(!p);
    ui->txt_recData->setText("");
    ui->txt_sendData->setText("");
    ui->txt_recNum->setText("0");
    ui->txt_sendNum->setText("0");
    recDispData="";
    sendDispData="";
    recDataNum=0;
    sendDataNum=0;
    connect(ui->btn_clearNum,&QPushButton::pressed,[&](){
        recDataNum=0;
        sendDataNum=0;
        ui->txt_recNum->setText(QString::number(recDataNum));
        ui->txt_sendNum->setText(QString::number(sendDataNum));
    });
    connect(ui->btn_clearRecData,&QPushButton::pressed,this,[&](){
        recDispData="";
        ui->txt_recData->setText(recDispData);
    });
    connect(ui->btn_clearSendData,&QPushButton::pressed,this,[&](){
        sendDispData="";
        ui->txt_sendData->setText(sendDispData);
    });
    connect(ui->btn_send,&QPushButton::pressed,this,[&](){
        sendDispData=ui->txt_sendData->toPlainText();
        if(ui->cb_hex->checkState()==Qt::CheckState::Checked)
        {
            auto data = QByteArray::fromHex(sendDispData.toUtf8());
            sendDataNum+=data.count();
            ui->txt_sendNum->setText(QString::number(sendDataNum));
            emit sendData(data,info);
        }
        else
        {
            auto data = sendDispData.toUtf8();
            sendDataNum+=data.count();
            ui->txt_sendNum->setText(QString::number(sendDataNum));
            emit sendData(data,info);
        }
    });
}
