#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //TableWidget控件
    //设置列数
    ui->tableWidget->setColumnCount(3);
    //设置表头
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "姓名" << "性别" << "年龄");
    //设置行数
    ui->tableWidget->setRowCount(5);
    //隐藏行号和列头
    ui->tableWidget->horizontalHeader()->hide();
    ui->tableWidget->verticalHeader()->hide();
    //设置正文
    //ui->tableWidget->setItem(0,0,new QTableWidgetItem("张三"));

    QStringList nameList;
    nameList << "张三" << "李四" << "王五" << "老六" << "小柒";
    QList<QString> genderList;
    genderList << "男" << "女" << "男" << "男" << "女";
    QList<int> ageList;
    ageList << 12 << 14 << 18 << 21 << 8;
    for(int i = 0 ; i < 5 ; i++)
    {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(nameList[i]));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(genderList[i]));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString::number(ageList[i])));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
