#ifndef MYTIMER_H
#define MYTIMER_H

#include <QWidget>
#include <QLabel>

class mytimer : public QLabel
{
    Q_OBJECT
public:
    explicit mytimer(QWidget *parent = nullptr);
    //重写定时器实现
    void timerEvent(QTimerEvent *);

signals:

public slots:
};

#endif // MYTIMER_H
