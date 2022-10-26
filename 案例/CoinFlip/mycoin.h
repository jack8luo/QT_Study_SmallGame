#ifndef MYCOIN_H
#define MYCOIN_H

#include <QPushButton>
#include <QTimer>

class MyCoin : public QPushButton
{
    Q_OBJECT
public:
    explicit MyCoin(QWidget *parent = 0);
    MyCoin(QString butImg);//代表图片路径
    int posX;//x
    int posY;//y
    bool flag;//正反标志
    void changeFlag();//翻转效果
    QTimer *timer1;//正面翻反面
    QTimer *timer2;//反面翻正面
    int min = 1;//最小图片
    int max = 8;//最大图片

    bool isAnimation = false;//禁用按钮//防止停止播放特效
    void mousePressEvent(QMouseEvent *e);

    //判断是否胜利
    bool isWin = false;

signals:

public slots:
};

#endif // MYCOIN_H
