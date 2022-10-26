#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <QColorDialog>
#include <QFileDialog>
#include <QFontDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //需求：点击新建按钮弹出一个对话框
    connect(ui->actionfont,&QAction::triggered,[=](){
        bool flag;
        QFont font = QFontDialog::getFont(&flag,QFont("黑体",12));
        setFont(font);
    });
    connect(ui->actioncolor,&QAction::triggered,[=](){
        QColor color = QColorDialog::getColor(QColor(255,0,0));
        qDebug() << color.red() << color.green() << color.blue();
    });
    connect(ui->actionnew,&QAction::triggered,[=](){
        //对话框 模态和非模态对话框 //打开一个窗口后可以继续操作原来的窗口称为非模态对话框
        //模态的 阻塞
        //创建对话框
        //QDialog dlg(this);
        //对话框太小了会警告
        //dlg.resize(200,100);
        //阻塞
        //dlg.exec();
        //qDebug() << "模态的对话框弹出了";
        //非模态的
        //防止一闪而过，创建到堆区
        //QDialog *dlg2 = new QDialog(this);
        //dlg2->resize(200,100);
        //dlg2->show();
        //关闭非模态的时候delete掉
        //dlg2->setAttribute(Qt::WA_DeleteOnClose);//55号
        //qDebug() << "非模态的对话框弹出了";


        //消息对话框
        //错误对话框
        //QMessageBox::critical(this,"critical","错误");
        //信息对话框
        //QMessageBox::information(this,"info","信息");
        //提问对话框 question 第五个参数 显示的 按回车会执行的[同时这些参数也是返回值]
        //QMessageBox::question(this,"ques","提问",QMessageBox::Save | QMessageBox::Cancel,QMessageBox::Cancel);
//        if(QMessageBox::Save == QMessageBox::question(this,"ques","提问",QMessageBox::Save | QMessageBox::Cancel,QMessageBox::Cancel))
//            qDebug() << "保存了";
//        else
//            qDebug() << "取消了";
        //警告对话框warning
//        QMessageBox::warning(this,"warning","警告");

        //颜色对话框
//        QColor a = QColorDialog::getColor(QColor(255,0,0));
        //qDebug() << a.red() << a.green() << a.blue();


        //文件对话框 最后一个是过滤(只打开cpp)
//        QString str = QFileDialog::getOpenFileName(this,"打开文件","./","(*.cpp)");
//        qDebug() << str;
        //字体对话框
        bool flag;
        QFont font = QFontDialog::getFont(&flag,QFont("华文彩云",12));
        setFont(font);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
