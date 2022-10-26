
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //点击获取值

    connect(ui->btnget,&QPushButton::clicked,ui->widget,[=](){
        //ui->widget->getNum();
        QMessageBox::information(this,"提示框",QString::number(ui->widget->getNum()));
    });

    //点击设置值
    connect(ui->btnset,&QPushButton::clicked,ui->widget,[=](){
        ui->widget->setNum(50);
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}
