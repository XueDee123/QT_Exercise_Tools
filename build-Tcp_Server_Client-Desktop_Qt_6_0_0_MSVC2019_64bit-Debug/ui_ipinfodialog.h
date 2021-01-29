/********************************************************************************
** Form generated from reading UI file 'ipinfodialog.ui'
**
** Created by: Qt User Interface Compiler version 6.0.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IPINFODIALOG_H
#define UI_IPINFODIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IpInfoDialog
{
public:
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_2;
    QWidget *widget;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *txt_ip;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_ok;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn_cancel;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_5;
    QLineEdit *txt_port;
    QLabel *label_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *IpInfoDialog)
    {
        if (IpInfoDialog->objectName().isEmpty())
            IpInfoDialog->setObjectName(QString::fromUtf8("IpInfoDialog"));
        IpInfoDialog->resize(332, 174);
        gridLayout_2 = new QGridLayout(IpInfoDialog);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalSpacer_2 = new QSpacerItem(20, 6, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 2, 0, 1, 1);

        widget = new QWidget(IpInfoDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 2, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 0, 4, 1, 1);

        txt_ip = new QLineEdit(widget);
        txt_ip->setObjectName(QString::fromUtf8("txt_ip"));

        gridLayout->addWidget(txt_ip, 0, 3, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btn_ok = new QPushButton(widget);
        btn_ok->setObjectName(QString::fromUtf8("btn_ok"));

        horizontalLayout->addWidget(btn_ok);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        btn_cancel = new QPushButton(widget);
        btn_cancel->setObjectName(QString::fromUtf8("btn_cancel"));

        horizontalLayout->addWidget(btn_cancel);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        gridLayout->addLayout(horizontalLayout, 3, 1, 1, 3);

        horizontalSpacer_5 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 1, 0, 1, 1);

        txt_port = new QLineEdit(widget);
        txt_port->setObjectName(QString::fromUtf8("txt_port"));

        gridLayout->addWidget(txt_port, 1, 3, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 1, 1, 1);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 0, 2, 1, 1);


        gridLayout_2->addWidget(widget, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 6, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 0, 0, 1, 1);


        retranslateUi(IpInfoDialog);

        QMetaObject::connectSlotsByName(IpInfoDialog);
    } // setupUi

    void retranslateUi(QDialog *IpInfoDialog)
    {
        IpInfoDialog->setWindowTitle(QCoreApplication::translate("IpInfoDialog", "Dialog", nullptr));
        btn_ok->setText(QCoreApplication::translate("IpInfoDialog", "\347\241\256\345\256\232", nullptr));
        btn_cancel->setText(QCoreApplication::translate("IpInfoDialog", "\345\217\226\346\266\210", nullptr));
        label_2->setText(QCoreApplication::translate("IpInfoDialog", "\347\253\257\345\217\243\345\217\267:", nullptr));
        label->setText(QCoreApplication::translate("IpInfoDialog", "IP\345\234\260\345\235\200:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IpInfoDialog: public Ui_IpInfoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IPINFODIALOG_H
