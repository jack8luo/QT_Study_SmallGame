#include "mywidget.h"
#include <QDebug>
#include <QLabel>

myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton * btn = new QPushButton;
    btn->setParent(this);

    btn->setText("第一天按钮");

    QLabel *label = new QLabel;
    label->setText("<h1>啊这</h1>");
    label->setParent(this);
    label->move(100,0);

    QPushButton * btn2 = new QPushButton("第二个按钮",this);
    //移动btn2按钮
    btn2->move(100,100);
    //设置按钮2大小
    btn2->resize(100,40);

    //重置窗口大小
    this->resize(600,400);
    //设置固定窗口大小
    this->setFixedSize(600,400);
    //设置窗口标题
    this->setWindowTitle("第一个窗口");

    //创建一个自己的按钮对象
    MyPushButton * myBtn = new MyPushButton;
    myBtn->setText("我自己的按钮");
    myBtn->move(300,0);
    myBtn->setParent(this);


    //需求 点击按钮关闭窗口
    connect(myBtn, &MyPushButton::clicked,this, &MyPushButton::close);

}

myWidget::~myWidget()
{
    //为什么会先打印这个
    //因为打印了这句话后会去找他的儿子
    //直到找不到才会一层一层往回来析构
    qDebug() << "myWidget的析构调用";
}
