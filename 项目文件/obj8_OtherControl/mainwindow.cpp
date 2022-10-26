#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QMovie>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //默认位置
    ui->stackedWidget->setCurrentIndex(0);
    //栈控件的使用
    connect(ui->btn_scr,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(0);
    });
    connect(ui->btn_tool,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(1);
    });

    //下拉框
    ui->comboBox->addItem("奔驰");
    ui->comboBox->addItem("宝马");
    ui->comboBox->addItem("法拉利");
    //通过按钮选择
    connect(ui->pushButton_15,&QPushButton::clicked,[=](){
        //ui->comboBox->setCurrentText((2)); 二号
        ui->comboBox->setCurrentText("法拉利");
    });

    //利用QLabel显示图片
    ui->label_image->setPixmap(QPixmap(QString(":/1.jpg")));
    //显示动图
    QMovie * m = new QMovie(":/3.gif");
    ui->label_gif->setMovie(m);
    //播放
    m->start();

}

MainWindow::~MainWindow()
{
    delete ui;
}
