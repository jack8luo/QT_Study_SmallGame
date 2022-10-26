#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QPushButton>
#include "mypushbutton.h"

class myWidget : public QWidget
{
    Q_OBJECT //允许类中使用信号和槽的机制

public:
    myWidget(QWidget *parent = 0);
    ~myWidget();
};

#endif // MYWIDGET_H
