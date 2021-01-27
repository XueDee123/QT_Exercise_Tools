#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QToolBar>
#include <QPushButton>
#include <QDebug>
#include <QMessageBox>
#include "ipinfodialog.h"
#include "Parameter.h"
#include <QDockWidget>
#include <QPushButton>
#include <QTreeWidget>
#include "displayform.h"
#include <algorithm>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    InitWindows();
    server=nullptr;
    serverSonItem=nullptr;
    serverTabItems=new QVector<QString>;
}

MainWindow::~MainWindow()
{
    ClearAllSonTreeItem(serverItem);
    delete serverItem;
    ClearAllSonTreeItem(clientItem);
    delete clientItem;
    for(int i=tabWidget->count()-1;i>=0;i--)
    {
        delete tabWidget->widget(i);
        tabWidget->removeTab(i);

    }
    if(server!=nullptr)
    {

        delete  server;
        server=nullptr;
    }
    if(serverTabItems!=nullptr)
    {
        delete serverTabItems;
        serverTabItems=nullptr;
    }
    delete ui;

}

void MainWindow::InitWindows()
{
    qDebug()<<"InitWindows当前线程:"<<QThread::currentThreadId();
    this->setWindowIcon(QIcon(":/img/debug.svg"));
    this->setWindowTitle("TCP调试工具");
    //create toolbar
    QToolBar *toolbar=new QToolBar(this);
    //add toolbar to windows
    this->addToolBar(toolbar);
    //更换工具栏样式
    this->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    //创建动作
    newServerAction=new QAction(QIcon(":/img/add.png"),"创建服务器",this);
    clearServerAction=new QAction(QIcon(":/img/remove.svg"),"移除服务器",this);
    disconnectClientToServerAction=new QAction(QIcon(":/img/disconnect.svg"),"断开连接",this);
    clearServerAction->setEnabled(false);

    //给工具栏添加动作
    toolbar->addAction(newServerAction);
    toolbar->addAction(clearServerAction);
    toolbar->addSeparator();

    //绑定信号槽
    connect(newServerAction,&QAction::triggered,this,&MainWindow::NewServer);
    connect(clearServerAction,&QAction::triggered,this,&MainWindow::ClearServer);
    connect(disconnectClientToServerAction,&QAction::triggered,this,&MainWindow::DisConnectClientToServer);

    //浮动窗口
    QDockWidget * dock = new QDockWidget("属性栏",this);
    dock->setFeatures(QDockWidget::DockWidgetMovable);
    dock->setAllowedAreas(Qt::DockWidgetArea::LeftDockWidgetArea|Qt::DockWidgetArea::RightDockWidgetArea);
    //添加浮动窗口到主窗口
    this->addDockWidget(Qt::DockWidgetArea::LeftDockWidgetArea,dock);

    //树控件
    ipTree=new QTreeWidget(this);
    treeMenu = new QMenu(ipTree);
    ipTree->setColumnCount(1);
    //设置水平头
    ipTree->setHeaderLabel("信息显示");

    serverItem=new QTreeWidgetItem(ipTree,QStringList()<<"服务器");
    serverItem->setIcon(0,QIcon(":/img/source.svg"));
    clientItem=new QTreeWidgetItem(ipTree,QStringList()<<"客户端");
    clientItem->setIcon(0,QIcon(":/img/source.svg"));
    ipTree->addTopLevelItem(serverItem);
    ipTree->addTopLevelItem(clientItem);
    //把树添加到浮动窗口
    dock->setWidget(ipTree);

    //创建tab
    tabWidget=new QTabWidget(this);
    this->setCentralWidget(tabWidget);



    connect(ipTree,&QTreeWidget::itemPressed, this, &MainWindow::TreeWidgetItemPressed_Slot);
    connect(ipTree,&QTreeWidget::itemDoubleClicked,this,&MainWindow::TreeWidgetItemDoubleClicked_Slot);
}

void MainWindow::NewServer()
{
    //这里创建服务器

    //通过对话框获取IP和端口
    IpInfoDialog *ipInfoDalg=new IpInfoDialog(this); // 创建一个对话框
    Qt::WindowFlags flags = ipInfoDalg->windowFlags(); // 需要获取返回值
    ipInfoDalg->setWindowFlags(flags | Qt::MSWindowsFixedSizeDialogHint);  // 设置对话框固定大小


    int ref = ipInfoDalg->exec();             // 以模态方式显示对话框
    if (ref==QDialog::Accepted)        // OK键被按下,对话框关闭
    {
        // 当BtnOk被按下时,则设置对话框中的数据
        IpInfo info={};
        ipInfoDalg->GetIpInfo(&info);
#ifdef QT_DEBUG
        qDebug()<<"NewServer()获取ip:"<<info.ip;
        qDebug()<<"NewServer()获取port:"<<info.port;
#endif
        if(server==nullptr) server=new TcpServer;

        if(server->StartServer(&info))
        {
            connect(server,&TcpServer::RecClientStatus,this,&MainWindow::ServerCallClientStatus);
            QString str=QString("%1:%2").arg(info.ip).arg(info.port);
            serverSonItem=new QTreeWidgetItem(QStringList()<<str);

            AddSonTreeItem(QIcon(":/img/server.svg"),serverItem,serverSonItem);

            ipTree->expandAll();
            //当服务器成功创建之后执行UI操作
            newServerAction->setEnabled(false);
            clearServerAction->setEnabled(true);
        }
        else
        {
            QMessageBox::critical(this,"服务器异常","服务器IP或端口绑定失败");
        }


    }
    // 最后删除释放对话框句柄
    delete ipInfoDalg;
}

void MainWindow::ClearServer()
{
    //这个清理服务器
    if(server!=nullptr)
    {
        disconnect(server,&TcpServer::RecClientStatus,this,&MainWindow::ServerCallClientStatus);
        delete  server;
        server=nullptr;
        //清理服务器下所有节点
        ClearAllSonTreeItem(serverItem);
        ClearAllServerTabItems(tabWidget,serverTabItems);
    }

    //当服务器成功清理之后执行UI操作
    newServerAction->setEnabled(true);
    clearServerAction->setEnabled(false);
}



//这里是服务器反馈客户端状态
void MainWindow::ServerCallClientStatus(QList<SocketInfo>&p)
{
    ServerCallClientTreeStatus(p,serverSonItem);
    ServerCallClientTabStatus(p,tabWidget,serverTabItems);
}
//清理该节点下是所有子节点
void MainWindow::ClearAllSonTreeItem(QTreeWidgetItem *p)
{
    if(p!=nullptr)
    {
        for(int i=p->childCount()-1;i>=0;i--)
        {
            QTreeWidgetItem *temp= p->child(i);
            ClearAllSonTreeItem(temp);
            p->removeChild(temp);
#ifdef QT_DEBUG
            qDebug()<<QString("%1->%2").arg("开始清理节点").arg(temp->text(0));
#endif
            delete temp;
            temp=nullptr;
        }
    }
}
//添加节点
void MainWindow::AddSonTreeItem(QIcon icon, QTreeWidgetItem *parent,QTreeWidgetItem* itm)
{
    itm->setIcon(0,icon);
    parent->addChild(itm);

}




void MainWindow::ServerCallClientTreeStatus(QList<SocketInfo>&p, QTreeWidgetItem *item)
{
    if(item->childCount()>0&&p.count()>0)
    {
        QVector<QString> tempSock;
        QVector<QString> tempItem;
        QVector<QString> tempIntersection;
        QVector<QString> tempdifference;


        for(auto i=p.begin();i!=p.end();i++)
        {
            tempSock.push_back(QString("%1:%2").arg((*i).ip).arg((*i).port));
        }

        for(int i=item->childCount()-1;i>=0;i--)
        {
            tempItem.push_back( item->child(i)->text(0));
        }
        //目标容器需要开辟空间
        //大容器包含小容器 ，取小容器
        tempIntersection.resize(std::min( tempSock.size() , tempItem.size()));
#ifdef QT_DEBUG
        qDebug()<<"tempSock->size()="<<tempSock.size();
        qDebug()<<"tempItem->size()="<<tempItem.size();
        qDebug()<<"tempIntersection->size()="<<tempIntersection.size();
#endif
        //求交集之前一定先排序
        std::sort(tempSock.begin(), tempSock.end());
        std::sort(tempItem.begin(), tempItem.end());
        //获取交集
        QVector<QString>::iterator iend= std::set_intersection(tempSock.begin(), tempSock.end(), tempItem.begin(), tempItem.end(), tempIntersection.begin());
        //删除不包含的子节
        for(int i=item->childCount()-1;i>=0;i--)
        {
            QVector<QString>::iterator it = std::find(tempIntersection.begin(), iend, item->child(i)->text(0));
            if (it == iend)
            {
                QTreeWidgetItem *tepitm= item->child(i);
                item->removeChild(tepitm);
#ifdef QT_DEBUG
                qDebug()<<QString("%1->%2").arg("开始清理节点").arg(tepitm->text(0));
#endif
                delete tepitm;
                tepitm=nullptr;
            }
        }
        //目标容器需要开辟空间
        tempdifference.resize(std::max( tempSock.size() , tempIntersection.size()));
        QVector<QString>::iterator diend= std::set_difference(tempSock.begin(), tempSock.end(), tempIntersection.begin(), iend,tempdifference.begin());
        //增加子节
        for(auto i=p.begin();i!=p.end();i++)
        {
            QString str=QString("%1:%2").arg((*i).ip).arg((*i).port);
            QVector<QString>::iterator it = std::find(tempdifference.begin(), diend, str);
            if(it!=diend)
            {
                //添加子节点
                AddSonTreeItem(QIcon(":/img/client.svg"),item,new QTreeWidgetItem(QStringList()<<str));
            }

        }
        ipTree->expandAll();
    }
    else if(p.count()>0) {
        //增加子节
        for(auto i=p.begin();i!=p.end();i++)
        {
            QString str=QString("%1:%2").arg((*i).ip).arg((*i).port);
            //添加子节点
            AddSonTreeItem(QIcon(":/img/client.svg"),item,new QTreeWidgetItem(QStringList()<<str));

        }
        ipTree->expandAll();
    }
    else if (item->childCount()>0) {
        ClearAllSonTreeItem(item);
    }

}

void MainWindow::ServerCallClientTabStatus(QList<SocketInfo>&p, QTabWidget *tab, QVector<QString>* serverItem)
{
    if(serverItem->count()>0&&p.count()>0)
    {
        QVector<QString> tempSock;
        QVector<QString> tempIntersection;
        QVector<QString> tempdifference;
        QVector<QString> tempServerItemdifference;


        for(auto i=p.begin();i!=p.end();i++)
        {
            tempSock.push_back(QString("%1:%2").arg((*i).ip).arg((*i).port));
        }

        //目标容器需要开辟空间
        //大容器包含小容器 ，取小容器
        tempIntersection.resize(std::min( tempSock.size() , serverItem->size()));

        //求交集之前一定先排序
        std::sort(tempSock.begin(), tempSock.end());
        std::sort(serverItem->begin(), serverItem->end());
        //获取交集
        QVector<QString>::iterator iend= std::set_intersection(tempSock.begin(), tempSock.end(), serverItem->begin(), serverItem->end(), tempIntersection.begin());

        //求差集
        tempServerItemdifference.resize(std::max( serverItem->size() , tempIntersection.size()));
        QVector<QString>::iterator diendServerItem= std::set_difference(serverItem->begin(), serverItem->end(), tempIntersection.begin(), iend,tempServerItemdifference.begin());

        //删除不包含的子节
        for(int i=tab->count()-1;i>=0;i--)
        {
            QString str=tab->tabText(i);
            QVector<QString>::iterator it = std::find(tempServerItemdifference.begin(), diendServerItem, str);
            if(it!=diendServerItem)
            {
                delete tab->widget(i);
                tab->removeTab(i);
                QVector<QString>::iterator it1 = std::find(serverItem->begin(), serverItem->end(), str);
                if(it1!=serverItem->end())serverItem->erase(it1);

#ifdef QT_DEBUG
                qDebug()<<QString("serverItem移除%1,容器大小:%2").arg(str).arg(serverItem->count());
#endif
            }
        }
        //目标容器需要开辟空间
        tempdifference.resize(std::max( tempSock.size() , tempIntersection.size()));
        QVector<QString>::iterator diend= std::set_difference(tempSock.begin(), tempSock.end(), tempIntersection.begin(), iend,tempdifference.begin());
        //增加子节
        for(auto i=p.begin();i!=p.end();i++)
        {
            QString str=QString("%1:%2").arg((*i).ip).arg((*i).port);
            QVector<QString>::iterator it = std::find(tempdifference.begin(), diend, str);
            if(it!=diend)
            {
               auto frm= new DisplayForm((*i),true);
               connect(server,&TcpServer::readData,frm,&DisplayForm::RecData);
               connect(frm,&DisplayForm::sendData,server,&TcpServer::sendData);
                tab->addTab(frm,QIcon(":/img/client.svg"),str);
                serverItem->push_back(str);
#ifdef QT_DEBUG
                qDebug()<<QString("serverItem新增%1,容器大小:%2").arg(str).arg(serverItem->count());
#endif
            }

        }
    }
    else if(p.count()>0) {
        //增加
        for(auto i=p.begin();i!=p.end();i++)
        {
           QString str=QString("%1:%2").arg((*i).ip).arg((*i).port);
           auto frm= new DisplayForm((*i),true);
           connect(server,&TcpServer::readData,frm,&DisplayForm::RecData);
           connect(frm,&DisplayForm::sendData,server,&TcpServer::sendData);
            tabWidget->addTab(frm,QIcon(":/img/client.svg"),str);
            serverItem->push_back(str);
#ifdef QT_DEBUG
            qDebug()<<QString("serverItem新增%1,容器大小:%2").arg(str).arg(serverItem->count());
#endif
        }
    }
    //清空
    else if (serverItem->count()>0) {
        ClearAllServerTabItems(tab,serverItem);
    }
}

void MainWindow::ClearAllServerTabItems(QTabWidget *tab, QVector<QString> *serverItem)
{

    for(int i=tab->count()-1;i>=0;i--)
    {
        QString str=tab->tabText(i);
        QVector<QString>::iterator it = std::find(serverItem->begin(), serverItem->end(), str);
        if(it!=serverItem->end())
        {
            delete tab->widget(i);
            tab->removeTab(i);
            serverItem->erase(it);
#ifdef QT_DEBUG
            qDebug()<<QString("serverItem移除%1,容器大小:%2").arg(str).arg(serverItem->count());
#endif
        }
    }
    if(tab->count()==0)serverItem->clear();
#ifdef QT_DEBUG
    qDebug()<<QString("tabwidget大小%1,serverItem大小:%2").arg(tab->count()).arg(serverItem->count());
#endif
}

void MainWindow::TreeWidgetItemPressed_Slot(QTreeWidgetItem *p, int i)
{
    if (QApplication::mouseButtons()& Qt::RightButton)
        {
                treeMenu->clear();

                if((p->text(i)==serverItem->text(i)))
                {
                    treeMenu->addAction(newServerAction);
                    treeMenu->addAction(clearServerAction);
                    treeMenu->exec(QCursor::pos());
                }
                else if(serverSonItem!=nullptr)
                {
                    if(serverSonItem->text(i)==p->parent()->text(i))
                    {
                        treeMenu->addAction(disconnectClientToServerAction);
                        treeMenu->exec(QCursor::pos());   //菜单弹出位置为鼠标点击位置

                    }
                }

    }
}

void MainWindow::TreeWidgetItemDoubleClicked_Slot(QTreeWidgetItem *p, int index)
{
#ifdef QT_DEBUG
    qDebug()<<"触发双击事件";
#endif
     for(int i=tabWidget->count()-1;i>=0;i--)
     {
         if(tabWidget->tabText(i)==p->text(index))
         {
             tabWidget->setCurrentIndex(i);
             break;
         }
     }
}

void MainWindow::DisConnectClientToServer()
{
#ifdef QT_DEBUG
    qDebug()<<"收到断开客户端信号"<<ipTree->currentItem()->text(0);
#endif
    QStringList temp =  ipTree->currentItem()->text(0).split(":");
    IpInfo info;
    info.ip=temp[0];
    info.port=temp[1].toInt();
    server->CloseClient(info);

}
