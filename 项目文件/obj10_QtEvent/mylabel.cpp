#include "mylabel.h"
#include <QDebug>
#include <QString>
#include <QMouseEvent>

myLabel::myLabel(QWidget *parent) : QLabel(parent)
{
    LeftButtoncount = 0;
    rightButtoncount = 0;
    //设置鼠标追踪 鼠标进入后就能显示坐标
    this->setMouseTracking(true);
}

//鼠标进入事件
void myLabel::enterEvent(QEvent *event)
{
    qDebug() << "鼠标进入了";
    this->setText("Σ(⊙▽⊙)");

}

//鼠标离开事件
void myLabel::leaveEvent(QEvent *event)
{
    qDebug() << "鼠标离开了";
    this->setText("o(*////▽////*)q");
}

//鼠标释放
void myLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    QString str;
    if(ev->button()== Qt::LeftButton)
    {
        LeftButtoncount++;
        str = QString("Σ(⊙▽⊙)\n鼠标左键按下了%1次").arg(QString::number(LeftButtoncount));
    }
    if(ev->button() == Qt::RightButton)
    {
        rightButtoncount++;
        str = QString("Σ(⊙▽⊙)\n鼠标右键按下了%1次").arg(QString::number(rightButtoncount));
    }
    this->setText(str);
}

//鼠标按下
void myLabel::mousePressEvent(QMouseEvent *ev)
{
    qDebug() << "鼠标松开了";
}

//鼠标移动
void myLabel::mouseMoveEvent(QMouseEvent *ev)
{
    int x = ev->x();
    int y = ev->y();
    QString s = QString("Σ(⊙▽⊙) \n位置是上: %1 下: %2 \n基于屏幕的上: %3 下: %4").arg(x).arg(y).arg(ev->globalX()).arg(ev->globalY());
    this->setText(s);

    //只允许鼠标左键
//    if(ev->buttons() & Qt::LeftButton)
//    {
//        int x = ev->x();
//        int y = ev->y();
//        QString s = QString("Σ(⊙▽⊙) \n位置是上: %1 下: %2 \n基于屏幕的上: %3 下: %4").arg(x).arg(y).arg(ev->globalX()).arg(ev->globalY());
//        this->setText(s);
//    }
}

bool myLabel::event(QEvent *e)
{
    //如果鼠标按下，event事件分发中做拦截，按下不交给event类处理
    if(e->type() == QEvent::MouseButtonPress)
    {
        //静态类型转换 然后就可以像鼠标按下一样用了
        QMouseEvent *ev = static_cast<QMouseEvent *>(e);
        qDebug() << "拦截了鼠标按下" << "x坐标" << ev->x();
        return true;
    }

    //其他事件交给默认父类处理
    return QLabel::event(e);
}
