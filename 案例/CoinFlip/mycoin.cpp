#include "mycoin.h"
#include <QPixmap>
#include <QDebug>
MyCoin::MyCoin(QWidget *parent) : QPushButton(parent)
{

}
//构造函数，构造金币图标
MyCoin::MyCoin(QString butImg){
    QPixmap pixmap;
    bool ret = pixmap.load(butImg);
    if(!ret)
    {
        qDebug() << butImg << "加载失败";
    }
    this->setFixedSize(pixmap.width(),pixmap.height());
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pixmap);
    this->setIconSize(QSize(pixmap.width(),pixmap.height()));

    //初始化定时器
    timer1 = new QTimer(this);
    timer2 = new QTimer(this);

    //创建特效
    //timeout一直在，需要stop才停止。
    connect(timer1,QTimer::timeout,[=](){

        QPixmap pixmap;
        QString str = QString("://res/Coin000%1.png").arg(this->min++);
        pixmap.load(str);
        this->setFixedSize(pixmap.width(),pixmap.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pixmap);
        this->setIconSize(QSize(pixmap.width(),pixmap.height()));
        //如果大于最大值，重置最小值，并停止定时器
        if(this->min > this->max){
            this->min = 1;
            this->isAnimation = false;
            timer1->stop();
        }
    });
    connect(timer2,QTimer::timeout,[=](){

        QPixmap pixmap;
        QString str = QString("://res/Coin000%1.png").arg(this->max--);
        pixmap.load(str);
        this->setFixedSize(pixmap.width(),pixmap.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pixmap);
        this->setIconSize(QSize(pixmap.width(),pixmap.height()));
        //如果大于最大值，重置最小值，并停止定时器
        if(this->max < this->min){
            this->max = 8;
            this->isAnimation = false;
            timer2->stop();
        }
    });



}
//翻转特效
void MyCoin::changeFlag(){
    if(this->flag)
    {
        timer1->start(30);
        this->isAnimation = true;
        this->flag = false;
    }
    else{
        timer2->start(30);
        this->isAnimation = true;
        this->flag = true;
    }
}
//重写按钮的按下事件，判断如果正在执行动画，那么直接return掉，不要执行后续代码。
void MyCoin::mousePressEvent(QMouseEvent *e){
    if(this->isAnimation || isWin == true)
        return ;
    else
        return QPushButton::mousePressEvent(e);
}
