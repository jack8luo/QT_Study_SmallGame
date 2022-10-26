#include "chooselevelscene.h"
#include <playscene.h>
#include <QMenu>
#include <mypushbutton.h>
#include <QAction>
#include <QMenuBar>
#include <QPainter>
#include <QTimer>
#include <qlabel.h>
#include <QDebug>
#include <QSound>


ChooseLevelScene::ChooseLevelScene(QWidget *parent) : QMainWindow(parent)
{
    //返回按钮音效
    QSound *backSound = new QSound("://res/TapButtonSound.wav",this);

    this->setFixedSize(320,588);
    this->setWindowIcon(QPixmap("://res/Coin0001.png"));
    this->setWindowTitle("选择关卡");
    QMenuBar * bar = this->menuBar();
    this->setMenuBar(bar);
    QMenu * startMenu = bar->addMenu("开始");
    QAction * quitAction = startMenu->addAction("退出");
    connect(quitAction,QAction::triggered,[=](){this->close();});
    //返回按钮
    MyPushButton * closeBtn = new MyPushButton("://res/BackButton.png","://res/BackButtonSelected.png");
    closeBtn->setParent(this);
    closeBtn->move(this->width()-closeBtn->width(),this->height()-closeBtn->height());

    //返回功能连接
    connect(closeBtn,MyPushButton::clicked,[=](){
        backSound->play();
        QTimer::singleShot(500,this,[=](){
            this->hide();
            emit this->chooseSceneBack();
        });
    });
    //选择关卡按钮
    for(int i = 0; i< 20;i++){
        MyPushButton * menuBtn = new MyPushButton("://res/LevelIcon.png");
        menuBtn->setParent(this);
        menuBtn->move(25 + (i%4)*70, 130 + (i/4)*70);
        //显示按钮文字
        QLabel * label = new QLabel;
        label->setParent(this);
        label->setFixedSize(menuBtn->width(),menuBtn->height());
        label->setText(QString::number(i+1));
        label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);//设置居中
        label->move(25 + (i%4)*70 , 130 + (i/4)*70);
        label->setAttribute(Qt::WA_TransparentForMouseEvents,true);//鼠标时间穿透
        //监听选择关卡按钮的信号槽
        connect(menuBtn,MyPushButton::clicked,[=](){
            backSound->play();
            if(pScene == NULL){
                qDebug() <<"xuanze"<<i;
                this->hide();
                pScene = new playscene(i+1); //返回选择的关卡

                pScene->setGeometry(this->geometry());//设置窗口固定屏幕位置

                pScene->show();

                //收到返回按钮信号，显示choose界面
                //第一个参数pScene需要在此头文件类创建对象object：：pScene
                connect(pScene,playscene::chooseSceneBack,[=](){
                    this->setGeometry(pScene->geometry());
                    this->show();
                    delete pScene;
                    pScene = NULL;
                });
            }
        });

    }




}
void ChooseLevelScene::paintEvent(QPaintEvent *){
    QPainter painter(this);
//    创建QPixmap对象，Qpixmap是一个绘图设备
    QPixmap pix;
//    加载图片
    pix.load("://res/OtherSceneBg.png");
//    绘制背景图
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
//    加载标题图
    pix.load("://res/Title.png");
//    缩放图片
//    pix = pix.scaled(pix.width()*0.5,pix.height()*0.5);
//    painter.drawPixmap(10,30,pix.width(),pix.height(),pix);
//    绘制标题
    painter.drawPixmap(10,30,this->width()*0.5,this->height()*0.1,pix);


}

