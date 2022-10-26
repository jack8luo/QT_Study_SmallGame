#include "mytimer.h"

mytimer::mytimer(QWidget *parent) : QLabel(parent)
{
    //启动定时器 单位ms毫秒
    startTimer(1000);
}

void mytimer::timerEvent(QTimerEvent *ev)
{
    static int timerNum = 1;
    this->setText(QString::number(timerNum++));
}
