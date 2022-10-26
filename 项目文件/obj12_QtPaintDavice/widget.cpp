#include "widget.h"
#include "ui_widget.h"
#include <QPixmap>
#include <QPainter>
#include <QPicture>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

//    //Pixmap绘图设备
//    QPixmap pix(300,300);

//    //声明画家对象
//    QPainter painter(&pix);
//    //填充颜色
//    pix.fill(Qt::white);
//    painter.setPen((QPen(Qt::green)));
//    painter.drawEllipse(QPoint(150,150),100,100);
//    //保存
//    pix.save("E:\\pix.png");

    //QImage 绘图设备 可以对像素进行访问
//    QImage img(300,300,QImage::Format_RGB32);
//    img.fill(Qt::white);
//    QPainter painter(&img);
//    painter.setPen(QPen(Qt::blue));
//    painter.drawEllipse(QPoint(150,150),100,100);



//    img.save("E:\\pix.png");


    //QPicture 绘图设备
    QPicture pic;
    QPainter painter;
    painter.begin(&pic);

    painter.setPen(QPen(Qt::blue));
    painter.drawEllipse(QPoint(150,150),100,100);

    painter.end();

    //保存到磁盘
    pic.save("E:\\pic.abcdefg");



}

//绘图事件
void Widget::paintEvent(QPaintEvent *)
{
//    this->resize(QImage(":/5.jpg").width(),QImage(":/5.jpg").height());
//    QPainter painter(this);
//    //利用QImage 对像素进行修改
//    QImage img;
//    img.load(":/5.jpg");

//    QRgb value = qRgb(0,0,255);
//    //修改像素点
//    int x = QImage(":/5.jpg").width();
//    int y = QImage(":/5.jpg").height();
//    for(int i = 0 ; i < x;i++)
//    {
//        for(int j = 0 ; j < 10 ;j++)
//        {
//            img.setPixel(i,j,value);
//            img.setPixel(j,i,value);
//        }
//    }
//    for(int i = x ; i > 0; i--)
//    {
//        for(int j = y ; j > y - 10; j--)
//        {
//            img.setPixel(i,j,value);
//            img.setPixel(j,i,value);
//        }
//    }

//    painter.drawImage(0,0,img);



    //QPicture重现指令
    QPainter painter(this);//画板在窗口上
    QPicture pic;
    pic.load("E:\\pic.abcdefg");
    painter.drawPicture(0,0,pic);
}

Widget::~Widget()
{
    delete ui;
}
