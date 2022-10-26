#include "widget.h"
#include "ui_widget.h"
#include <QPainter> //画家类
#include <QPushButton>
#include <QDebug>
#include <QTimer>
#include <QQueue>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    srand(1);
    posx = 0;
    ui->setupUi(this);
    randApple();
    //点击按钮移动图片
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        posFlag = 1;
        posx+=40;
        update();
    });
    connect(ui->pushButton_2,&QPushButton::clicked,[=](){
        posFlag = 2;
        posy+=40;
        update();
    });
    connect(ui->pushButton_3,&QPushButton::clicked,[=](){
        posFlag = 3;
        posy-=40;
        update();
    });
    connect(ui->pushButton_4,&QPushButton::clicked,[=](){
        posFlag = 4;
        posx-=40;
        update();
    });
    connect(ui->pushButton_5,&QPushButton::clicked,[=](){
        possize++;
    });
    //设计计时器
    QTimer *ter = new QTimer(this);
    ter->start(100);
    connect(ter,&QTimer::timeout,[=](){
        if(posFlag == 1)
        {
            posx+=40;
            update();
        }
        if(posFlag == 2)
        {
            posy+=40;
            update();
        }
        if(posFlag == 3)
        {
            posy-=40;
            update();
        }
        if(posFlag == 4)
        {
            posx-=40;
            update();
        }
    });
}

void Widget::randApple()
{
    int QW = QPixmap(":/3.gif").width();
    int QH = QPixmap(":/3.gif").height();
    while((appleposx = rand() % this->width() - QW) < 0);
    while((appleposy = rand() % this->height() - QH) < 0);
}

//绘图事件
//不管重没重写，系统都会执行这个函数
void Widget::paintEvent(QPaintEvent *p)
{
    //test01(p);
//    //高级设置
    //实例化一个画家 this指定的是绘图设备
    QPainter painter(this);


    int QW = QPixmap(":/3.gif").width();
    int QH = QPixmap(":/3.gif").height();
    if(posx > this->width() - QW)
    {
        posFlag = 4;
        //posx = 0;
    }
    if(posx < 0)
    {
        posFlag = 1;
        //posx = this->width()- QW;
    }
    if(posy > this->height() - QH)
    {
        posFlag = 3;
        //posy = 0;
    }
    if(posy < 0)
    {
        posFlag = 2;
        //posy = this->height()- QH;
    }

    static int stx = 0;
    static int sty = 0;
    if(stx != posx || sty != posy)
    {
        stx = posx;
        sty = posy;
        //appleposx= 0;
        //appleposy = 0;
        qDebug() << QString("蛇x: %1 y: %2 ,苹果x: %3 y: %4").arg(stx).arg(sty).arg(appleposx).arg(appleposy);
        if(stx >= appleposx - QW && stx <= appleposx+ QW && sty >= appleposy - QW&& sty <= appleposy + QH)
        {
            possize++;
            randApple();
        }
        else
        {
            painter.drawPixmap(appleposx,appleposy,QPixmap(":/4.gif"));
        }

        //qDebug() << quex;
        //画家画画
        painter.drawPixmap(posx,posy,QPixmap(":/3.gif"));
        quex.push_back(posx);
        quey.push_back(posy);
        if(quex.size() > possize)
        {
            quex.pop_front();
            quey.pop_front();
        }
        for(int i = 0; i < quex.size();i++)
        {
            int x = quex[i];
            int y = quey[i];
            painter.drawPixmap(x,y,QPixmap(":/3.gif"));
        }
    }

}

//void Widget::test01(QPaintEvent *p)
//{
//    //实例化一个画家的对象 this指定的是绘图的设备
//    QPainter painter(this);
//    //画一条线
//    painter.drawLine(QPoint(100,100),QPoint(50,50));
//    //设置画笔
//    //设置画笔颜色
//    QPen pen(QColor(255,0,0));
//    //设置画笔宽度
//    pen.setWidth(4);
//    //设置画笔风格
//    pen.setStyle(Qt::DotLine);
//    //让画家拿起笔
//    painter.setPen(pen);
//    //画圆
//    painter.drawEllipse(QPoint(100,100),50,50);

//    //填充颜色 画刷
//    QBrush brush(Qt::blue);
//    brush.setStyle(Qt::Dense7Pattern);
//    //让画家使用画刷
//    painter.setBrush(brush);
//    //画矩形
//    painter.drawRect(150,150,200,200);

//    //画文字
//    painter.drawText(QRect(10,200,100,50),"hello world");

//    //    //设置抗锯齿 效率较低
//    //    //painter.setRenderHint(QPainter::Antialiasing);
//    //    //painter.drawEllipse(QPoint(50,50),50,50);

//    //    painter.drawRect(QRect(20,20,50,50));
//    //    //保存画家位置
//    //    painter.save();
//    //    //让画家移动
//    //    painter.translate(100,0);
//    //    painter.drawRect(QRect(20,20,50,50));
//    //    //还原保存位置
//    //    painter.restore();
//}

Widget::~Widget()
{
    delete ui;
}
