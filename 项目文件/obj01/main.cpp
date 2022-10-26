#include "mywidget.h"
#include <QApplication>//包含一个应用程序类的头文件
#include <QFile>
#include <QString>
#include <QLabel>

int main(int argc, char *argv[])
{
    //应用程序对象,在QT中,应用程序对象有且只有一个
    QApplication a(argc, argv);
    setStyle(":/css.css");


    //窗口对象[父类:QWidget 只是个窗口]
    myWidget w;
    //窗口对象默认不显示,但是得调用show方法
     w.show();

    //让应用程序对象进入消息循环
    return a.exec();
}
