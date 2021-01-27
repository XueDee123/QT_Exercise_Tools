#include "ipinfodialog.h"
#include "ui_ipinfodialog.h"
#include <QPushButton>
#include <QDebug>
#include <QMessageBox>
#include <QRegExp>


IpInfoDialog::IpInfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IpInfoDialog)
{
    ui->setupUi(this);
    ui->txt_ip->setText("127.0.0.1");
    ui->txt_port->setText("2000");
    //绑定信号槽
    connect(ui->btn_cancel,&QPushButton::clicked,this,[=](){this->reject();});
    connect(ui->btn_ok,&QPushButton::clicked,this,[=](){
        if(!ui->txt_ip->text().isEmpty()&&
                !ui->txt_ip->text().isNull()&&
                !ui->txt_port->text().isEmpty()&&
                !ui->txt_port->text().isNull())
        {
            QRegExp rx("((2{2}[0-3]|2[01][0-9]|1[0-9]{2}|0?[1-9][0-9]|0{0,2}[1-9])\\.)((25[0-5]|2[0-4][0-9]|[01]?[0-9]{0,2})\\.){2}(25[0-5]|2[0-4][0-9]|[01]?[0-9]{0,2})");
            if(rx.exactMatch(ui->txt_ip->text()))
            {
                this->accept();
            }
            else
            {
                QMessageBox::critical(this,"错误","IP不合法");
            }
        }
        else
        {
            QMessageBox::critical(this,"错误","IP与端口必填");
        }
    });
}

IpInfoDialog::~IpInfoDialog()
{
    delete ui;
}

void IpInfoDialog::GetIpInfo(IpInfo *p)
{
#ifdef QT_DEBUG
    qDebug()<<"txt_ip:"<<ui->txt_ip->text();
    qDebug()<<"txt_port:"<<ui->txt_port->text().toInt();
#endif
    p->ip=ui->txt_ip->text();
    p->port=ui->txt_port->text().toInt();
}
