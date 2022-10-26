#include "mainwindow.h"
#include <QMenuBar>
#include <QToolBar>
#include <QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QTimeEdit>
#include <QDockWidget>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
//    test01();

    setWindowTitle("带菜单的界面");
    resize(600,400);
    //菜单栏创建[菜单栏最多只能有一个]
    QMenuBar * bar =  menuBar();
    setMenuBar(bar);
    //创建菜单
    QMenu * fileMenu = bar->addMenu("文件");
    QMenu * editMenu = bar->addMenu("编辑");

    //创建菜单项目
    QAction * newAction =  fileMenu->addAction("新建");
    //添加分割符
    fileMenu->addSeparator();
    QAction * openAction =  fileMenu->addAction("打开");

    //工具栏[可以有多个]
    QToolBar * toolBar = new QToolBar(this); // this放在父亲状态树，减少内存释放工作。
    //addToolBar(toolBar);
    addToolBar(Qt::LeftToolBarArea,toolBar);
    //只允许左右停靠
    toolBar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);
    //取消浮动
    toolBar->setFloatable(false);
    //设置禁止移动[上面的两个没意义了]
    toolBar->setMovable(false);

    //工具栏设置内容[公用一个菜单项]
    toolBar->addAction("绝了");
    toolBar->addSeparator();
    toolBar->addAction(openAction);
    //工具栏添加控件
    QPushButton * btn = new QPushButton("aa",this);
    toolBar->addWidget(btn);

    //状态栏[最多有一个]
    QStatusBar * stBar = statusBar();
    //设置到窗口中
    setStatusBar(stBar);
    //标签控件，类似于按钮
    QLabel * label = new QLabel("左侧提示的信息",this);
    QLabel * label1 = new QLabel("右侧提示的信息",this);
    stBar->addWidget(label);
    //右侧提示
    stBar->addPermanentWidget(label1);


    //铆接部件 浮动窗口[允许多个]
    QDockWidget * dockWidget = new QDockWidget("浮动",this);
    addDockWidget(Qt::BottomDockWidgetArea,dockWidget);
    //只允许上下
    dockWidget->setAllowedAreas(Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea);

    //中心部件文本窗口[中心内容也只能有一个]
//    QTextEdit * edit1 = new QTextEdit(this);
//    dockWidget->setWidget(edit1);



    //中心部件文本窗口[中心内容也只能有一个]
    QTextEdit * edit = new QTextEdit(this);
    setCentralWidget(edit);
}

void MainWindow::test01()
{



    setWindowTitle("TeamSpeak 3");
    resize(554,522);
    //菜单栏创建
    QMenuBar* bar = menuBar();
    //将菜单栏放入窗口中
    setMenuBar(bar);
    //创建菜单
    QMenu * insertMenu = bar->addMenu("连接(C)");
    QMenu * markMenu = bar->addMenu("书签(B)");
    QMenu * myMenu = bar->addMenu("自己(E)");
    QMenu * rootMenu = bar->addMenu("权限(M)");
    QMenu * toolMenu = bar->addMenu("工具(T)");
    QMenu * helpMenu = bar->addMenu("帮助(H)");
    //创建菜单项目
    helpMenu->addAction("主页(W)");
    helpMenu->addAction("技术支持中心(S)");
    helpMenu->addAction("myTeamSpeak(m)");
    helpMenu->addAction("租赁自己的TS服务器");
    helpMenu->addSeparator();
    helpMenu->addAction("检查更新(U)");
    helpMenu->addAction("显示更新记录(C)");
    helpMenu->addAction("查看许可协议(L)");
    helpMenu->addAction("显示新闻(I)");
    helpMenu->addSeparator();
    helpMenu->addAction("关于TeamSpeak3(A)");

    //设置工具栏
    QToolBar * toolbar = new QToolBar(this);
    addToolBar(Qt::BottomToolBarArea,toolbar);
    toolbar->setMovable(false);
    QPushButton * btn1 = new QPushButton;
    btn1->setText(" TeamSpeak 3");
    QPushButton * btn2 = new QPushButton;
    btn2->setText("粉色星球");
    toolbar->addWidget(btn1);
    toolbar->addWidget(btn2);



}

MainWindow::~MainWindow()
{

}
