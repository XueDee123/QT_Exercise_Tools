#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QAction>
#include <QMainWindow>
#include "tcpserver.h"
#include <QTreeWidgetItem>
#include <QTabWidget>
#include <QMouseEvent>
#include "clientmanager.h"
#include <QThread>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTreeWidget *ipTree;
    QMenu* treeMenu;
    QAction *disconnectClientAction;
    QAction *disconnectClientToServerAction;
    QAction *newServerAction;
    QAction *newClientAction;
    QAction *clearServerAction;
    QTreeWidgetItem *serverItem;
    QTreeWidgetItem *serverSonItem;
    QTreeWidgetItem *clientItem;
    QTabWidget *tabWidget;
private:
    TcpServer *server;
    ClientManager *client;
    QVector<QString>*serverTabItems;
    QThread *clientTh;
private:
    void InitWindows();
    void NewServer();
    void NewClient();
    void SockConnect(SocketInfo& info);
    void SockConFail();
    void SockDisConnect(SocketInfo&);
    void ClearServer();
    void DisConnectClientToServer();
    void DisConnectClient();
    void ServerCallClientStatus(QList<SocketInfo>&p);
    void ClearAllSonTreeItem(QTreeWidgetItem *p);
    void AddSonTreeItem(QIcon icon,QTreeWidgetItem* parent,QTreeWidgetItem* itm);
    void ServerCallClientTreeStatus(QList<SocketInfo>&p,QTreeWidgetItem* itm);
    void ServerCallClientTabStatus(QList<SocketInfo>&p,QTabWidget* tab, QVector<QString>* serverItem);
    void ClearAllServerTabItems(QTabWidget* tab, QVector<QString>* serverItem);
    void TreeWidgetItemPressed_Slot(QTreeWidgetItem* p, int i);
    void TreeWidgetItemDoubleClicked_Slot(QTreeWidgetItem* p, int i);
};
#endif // MAINWINDOW_H
