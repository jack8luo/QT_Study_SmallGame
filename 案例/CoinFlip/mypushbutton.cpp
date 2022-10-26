#include "mypushbutton.h"
#include <QDebug>
#include <QSize>
#include <qpropertyanimation.h>

//显示不规则按钮
MyPushButton::MyPushButton(QString normalImg, QString pressImg)
{
//    成员变量normalImgPath表示normalImg的路径
    normalImgPath = normalImg;
    pressImgPath = pressImg;
//    添加画图设备
    QPixmap pixmap;
    bool ret = pixmap.load(normalImgPath);
    if(!ret){
        qDebug() << "路径" << normalImg << "加载失败";
    }
//    设置按钮的固定大小=图片大小
    this->setFixedSize(pixmap.width(),pixmap.height());
//    设置不规则图片的样式表
    this->setStyleSheet("QPushButton{border:0px solid;}");//边框border
//    设置图标
    this->setIcon(pixmap);
//    设置图标大小
    this->setIconSize(QSize(pixmap.width(),pixmap.height()));
}

//down
void MyPushButton::zoom1(){
    QPropertyAnimation * animation1 = new QPropertyAnimation(this,"geometry");
    animation1->setDuration(200);
    animation1->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    animation1->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    animation1->setEasingCurve(QEasingCurve::OutBounce);
    animation1->start();
}
//up
void MyPushButton::zoom2(){
    QPropertyAnimation * animation1 = new QPropertyAnimation(this,"geometry");
    animation1->setDuration(200);//时间
    animation1->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    animation1->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
    animation1->setEasingCurve(QEasingCurve::OutBounce);
    animation1->start();
}

void MyPushButton::mousePressEvent(QMouseEvent *e){
    if(pressImgPath != "")
    {
        QPixmap pixmap;
        bool ret = pixmap.load(pressImgPath);
        if(!ret)
            qDebug() << pressImgPath << "图片加载失败";
        this->setFixedSize(pixmap.width(),pixmap.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pixmap);
        this->setIconSize(QSize(pixmap.width(),pixmap.height()));
    }
//    交给父类；
    return QPushButton::mousePressEvent(e);
}
void MyPushButton::mouseReleaseEvent(QMouseEvent *e)
{
    if(normalImgPath != "")
    {
        QPixmap pixmap;
        bool ret = pixmap.load(normalImgPath);
        if(!ret)
            qDebug() << normalImgPath << "图片加载失败";
        this->setFixedSize(pixmap.width(),pixmap.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pixmap);
        this->setIconSize(QSize(pixmap.width(),pixmap.height()));
    }
//    交给父类
    return QPushButton::mouseReleaseEvent(e);
}
