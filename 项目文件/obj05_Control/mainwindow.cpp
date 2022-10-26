#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QListWidget>
#include <QListWidgetItem>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //设置单选按钮 男默认选中
    ui->rBtnman->setChecked(true);
    //选中女后,打印信息
    connect(ui->rBtnwoman,&QRadioButton::clicked,[=](){
        qDebug() << "选中女性" ;
    });

    //多选按钮
    connect(ui->checkBox_4,&QCheckBox::stateChanged,[=](int state){
        qDebug() << state;
    });

    //利用listWidget写诗
//    QListWidgetItem * item = new QListWidgetItem("锄禾日当午");
    //放入到listWidget控件中
//    ui->listWidget->addItem(item);
//    item->setTextAlignment(Qt::AlignHCenter);

    //QStringList = QList<Qsting>
    QStringList list;
    list << "锄禾日当午" << "汗滴禾下土" << "谁知盘中餐" << "粒粒皆辛苦";
    ui->listWidget->addItems(list);
}

MainWindow::~MainWindow()
{
    delete ui;
}
