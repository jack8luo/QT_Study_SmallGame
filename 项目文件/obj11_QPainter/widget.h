#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMap>
#include <QQueue>
#include <QVector>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

    //绘图事件
    void paintEvent(QPaintEvent *);
    void test01(QPaintEvent *p);
    void randApple();

    int posx = 0;
    int posy = 0;
    int posFlag = 0;
    int possize = 1;

    int appleposx= 0;
    int appleposy = 0;

    QVector<int> quex;
    QVector<int> quey;
private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
