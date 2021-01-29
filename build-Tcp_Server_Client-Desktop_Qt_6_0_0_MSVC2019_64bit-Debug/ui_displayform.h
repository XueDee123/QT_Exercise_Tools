/********************************************************************************
** Form generated from reading UI file 'displayform.ui'
**
** Created by: Qt User Interface Compiler version 6.0.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISPLAYFORM_H
#define UI_DISPLAYFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DisplayForm
{
public:
    QGridLayout *gridLayout_3;
    QWidget *widget_2;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_send;
    QPushButton *btn_clearSendData;
    QCheckBox *cb_hex;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QTextEdit *txt_sendData;
    QSpacerItem *verticalSpacer_9;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btn_clearRecData;
    QCheckBox *cb_recHex;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_3;
    QTextEdit *txt_recData;
    QWidget *widget;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_5;
    QLineEdit *txt_ip;
    QPushButton *btn_clearNum;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_2;
    QLineEdit *txt_recNum;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QLabel *label_3;
    QLineEdit *txt_port;
    QPushButton *btn_connect;
    QLineEdit *txt_sendNum;
    QLabel *label_4;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_6;

    void setupUi(QWidget *DisplayForm)
    {
        if (DisplayForm->objectName().isEmpty())
            DisplayForm->setObjectName(QString::fromUtf8("DisplayForm"));
        DisplayForm->resize(823, 583);
        gridLayout_3 = new QGridLayout(DisplayForm);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        widget_2 = new QWidget(DisplayForm);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        gridLayout_2 = new QGridLayout(widget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox = new QGroupBox(widget_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_3 = new QWidget(groupBox);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout = new QHBoxLayout(widget_3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btn_send = new QPushButton(widget_3);
        btn_send->setObjectName(QString::fromUtf8("btn_send"));

        horizontalLayout->addWidget(btn_send);

        btn_clearSendData = new QPushButton(widget_3);
        btn_clearSendData->setObjectName(QString::fromUtf8("btn_clearSendData"));

        horizontalLayout->addWidget(btn_clearSendData);

        cb_hex = new QCheckBox(widget_3);
        cb_hex->setObjectName(QString::fromUtf8("cb_hex"));

        horizontalLayout->addWidget(cb_hex);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addWidget(widget_3);

        txt_sendData = new QTextEdit(groupBox);
        txt_sendData->setObjectName(QString::fromUtf8("txt_sendData"));

        verticalLayout->addWidget(txt_sendData);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);

        verticalSpacer_9 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_2->addItem(verticalSpacer_9, 1, 0, 1, 1);

        groupBox_2 = new QGroupBox(widget_2);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget_4 = new QWidget(groupBox_2);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_2 = new QHBoxLayout(widget_4);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        btn_clearRecData = new QPushButton(widget_4);
        btn_clearRecData->setObjectName(QString::fromUtf8("btn_clearRecData"));

        horizontalLayout_2->addWidget(btn_clearRecData);

        cb_recHex = new QCheckBox(widget_4);
        cb_recHex->setObjectName(QString::fromUtf8("cb_recHex"));

        horizontalLayout_2->addWidget(cb_recHex);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout_2->addWidget(widget_4);

        txt_recData = new QTextEdit(groupBox_2);
        txt_recData->setObjectName(QString::fromUtf8("txt_recData"));

        verticalLayout_2->addWidget(txt_recData);


        gridLayout_2->addWidget(groupBox_2, 2, 0, 1, 1);


        gridLayout_3->addWidget(widget_2, 0, 1, 1, 1);

        widget = new QWidget(DisplayForm);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMaximumSize(QSize(105, 16777215));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 7, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_5, 13, 0, 1, 1);

        txt_ip = new QLineEdit(widget);
        txt_ip->setObjectName(QString::fromUtf8("txt_ip"));
        txt_ip->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(txt_ip, 1, 0, 1, 1);

        btn_clearNum = new QPushButton(widget);
        btn_clearNum->setObjectName(QString::fromUtf8("btn_clearNum"));
        btn_clearNum->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(btn_clearNum, 14, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_3, 5, 0, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        txt_recNum = new QLineEdit(widget);
        txt_recNum->setObjectName(QString::fromUtf8("txt_recNum"));
        txt_recNum->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(txt_recNum, 12, 0, 1, 1);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 15, 0, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 8, 0, 1, 1);

        txt_port = new QLineEdit(widget);
        txt_port->setObjectName(QString::fromUtf8("txt_port"));
        txt_port->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(txt_port, 4, 0, 1, 1);

        btn_connect = new QPushButton(widget);
        btn_connect->setObjectName(QString::fromUtf8("btn_connect"));
        btn_connect->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(btn_connect, 6, 0, 1, 1);

        txt_sendNum = new QLineEdit(widget);
        txt_sendNum->setObjectName(QString::fromUtf8("txt_sendNum"));
        txt_sendNum->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(txt_sendNum, 9, 0, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 11, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_4, 2, 0, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_6, 10, 0, 1, 1);


        gridLayout_3->addWidget(widget, 0, 0, 1, 1);


        retranslateUi(DisplayForm);

        QMetaObject::connectSlotsByName(DisplayForm);
    } // setupUi

    void retranslateUi(QWidget *DisplayForm)
    {
        DisplayForm->setWindowTitle(QCoreApplication::translate("DisplayForm", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("DisplayForm", "\345\217\221\351\200\201\345\214\272", nullptr));
        btn_send->setText(QCoreApplication::translate("DisplayForm", "\345\217\221\351\200\201", nullptr));
        btn_clearSendData->setText(QCoreApplication::translate("DisplayForm", "\346\270\205\347\251\272", nullptr));
        cb_hex->setText(QCoreApplication::translate("DisplayForm", "\346\214\21116\350\277\233\345\210\266", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("DisplayForm", "\346\216\245\346\224\266\345\214\272", nullptr));
        btn_clearRecData->setText(QCoreApplication::translate("DisplayForm", "\346\270\205\347\251\272", nullptr));
        cb_recHex->setText(QCoreApplication::translate("DisplayForm", "\346\214\21116\350\277\233\345\210\266", nullptr));
        btn_clearNum->setText(QCoreApplication::translate("DisplayForm", "\346\270\205\347\251\272\350\256\241\346\225\260", nullptr));
        label_2->setText(QCoreApplication::translate("DisplayForm", "\347\233\256\346\240\207\347\253\257\345\217\243", nullptr));
        label->setText(QCoreApplication::translate("DisplayForm", "\347\233\256\346\240\207IP", nullptr));
        label_3->setText(QCoreApplication::translate("DisplayForm", "\345\217\221\351\200\201", nullptr));
        btn_connect->setText(QCoreApplication::translate("DisplayForm", "\350\277\236\346\216\245", nullptr));
        label_4->setText(QCoreApplication::translate("DisplayForm", "\346\216\245\346\224\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DisplayForm: public Ui_DisplayForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISPLAYFORM_H
