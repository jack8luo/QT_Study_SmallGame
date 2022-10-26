#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->actionnew->setIcon(QIcon("C:/Users/aa/Pictures/1.jpg"));
    //使用QT添加资源 ": + 前缀名 + 文件名"
    ui->actionnew->setIcon(QIcon(":/images/1.jpg"));
    ui->actionopen->setIcon(QIcon(":/images/2.jpg"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
