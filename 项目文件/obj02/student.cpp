#include "student.h"
#include <QDebug>

Student::Student(QObject *parent) : QObject(parent)
{
}


void Student::treat()
{
    qDebug() << "请老师吃饭";
}

void Student::treat(QString foodName)
{
    //.toUtf8().data() 转换成char *类型,打印的时候就不会用" "了
    qDebug() << "请老师吃饭,老师要吃：" << foodName.toUtf8().data();
}
