#ifndef IPINFODIALOG_H
#define IPINFODIALOG_H

#include <QDialog>
#include "Parameter.h"

namespace Ui {
class IpInfoDialog;
}

class IpInfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit IpInfoDialog(QWidget *parent = nullptr);
    ~IpInfoDialog();

    void GetIpInfo(IpInfo *p);

private:
    Ui::IpInfoDialog *ui;
};

#endif // IPINFODIALOG_H
