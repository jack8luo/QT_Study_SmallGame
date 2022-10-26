#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFontDialog>
#include <QDebug>
#include <QTimer>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFont(QFont("镊子面包手指体",16));
    //第一种定时器
    //开启定时器 单位毫秒 每隔一段时间发送一个timeevent事件
    id1 = startTimer(1000);
    id2 = startTimer(2000);
    id3 = startTimer(3000);

//    this->ui->label_2->setText(QString::number(0));
//    this->ui->label_3->setText(QString::number(0));
//    this->ui->label_4->setText(QString::number(0));

    //第二种定时器：Time类
    //通过定时器类
    QTimer * timer = new QTimer(this);
    //启动定时器 每隔500毫秒发一个信号
    timer->start(50);
    connect(timer,&QTimer::timeout,[=](){
        static int num = 1;
        if(num > 60)
        {
            int houer= num / 60;
            int min =  num % 60;
            ui->label_5->setText(QString("%1:%2").arg(houer).arg(min));
            num++;
        }
        else
        {
            ui->label_5->setText("0:"+ QString::number(num++));
        }

    });
    //点击暂停和开始
    connect(ui->btnstop,&QPushButton::clicked,[=](){
        static int flag = 0;
        if(flag)
        {
            flag = 0;
            timer->start(50);
            ui->btnstop->setText("暂停");
        }
        else
        {
            flag = 1;
            timer->stop();
            ui->btnstop->setText("开始");
        }
    });

    //给label1 安装事件过滤器
    ui->label->installEventFilter(this);
}

void MainWindow::timerEvent(QTimerEvent * ev)
{
    if(ev->timerId()== id1)
    {
        static int num1 = 0;
        this->ui->label_2->setText(QString::number(num1++));
    }
    else if(ev->timerId() == id2)
    {
        static int num2 = 0;
        this->ui->label_3->setText(QString::number(num2++));
    }
    else if(ev->timerId() == id3)
    {
        static int num3 = 0;
        this->ui->label_4->setText(QString::number(num3++));
    }

}

//过滤器中拦截
bool MainWindow::eventFilter(QObject * obj,QEvent *e)
{
    if(obj == ui->label)
    {

        if(e->type() == QEvent::MouseButtonPress)
        {
            qDebug() << QString("事件过滤器处理");
            return true;
        }
    }
    return QWidget::eventFilter(obj,e);
}

MainWindow::~MainWindow()
{
    delete ui;
}
