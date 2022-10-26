#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void timerEvent(QTimerEvent *);

    int id1; //定时器1的唯一标识符
    int id2; //定时器2的唯一标识符
    int id3; //定时器3的唯一标识符

    //重写事件过滤器
    bool eventFilter(QObject *,QEvent *);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
