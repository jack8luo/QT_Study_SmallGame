#include "widget.h"
#include <QApplication>

//Teacher 类 老师类
//Student 类 学生类
//设计常见：下课后老师会触发一个信号 饿了
//学生来响应 请客吃饭

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
}
