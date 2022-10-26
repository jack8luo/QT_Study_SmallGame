#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include <mycoin.h>

class playscene : public QMainWindow
{
    Q_OBJECT
public:
    explicit playscene(QWidget *parent = 0);
    playscene(int index);
    int levelIndex;//记录关卡索引
    //改写绘画事件
    void paintEvent(QPaintEvent *);
    //二维数组数据
    int gameArray[4][4];

    //创建按钮数组
    MyCoin * coinBtn[4][4];
    bool isWin = true;
signals:
    void chooseSceneBack();
public slots:
};

#endif // PLAYSCENE_H
