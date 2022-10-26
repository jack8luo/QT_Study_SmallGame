#include "widget.h"
#include <QDebug>
#include <QPushButton>
#include <QLabel>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

    this->resize(800,600);
    QPushButton* btn1 = new QPushButton("打开",this);
    btn1->resize(100,40);
    this->setWindowTitle("我的标题");
    QLabel *label = new QLabel;
    label->setText("<h1>这是一个复窗口</h1>");
    label->resize(400,300);
    connect(btn1,&QPushButton::clicked,this,[=](){
        static int flag = 0;
        if(flag == 0)
        {
            flag = 1;
            label->show();
            btn1->setText("关闭");
            qDebug() << flag ;
        }
        else
        {
            flag = 0;
            label->close();
            btn1->setText("打开");
            qDebug() << flag ;
        }
    });

}

Widget::~Widget()
{

}
