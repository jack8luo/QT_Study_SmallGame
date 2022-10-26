#include "mainscene.h"
#include "ui_mainscene.h"
#include <QPainter>
#include <mypushbutton.h>
#include <QTimer>
#include <chooselevelscene.h>
#include <QSound>

MainScene::MainScene(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainScene)
{
    ui->setupUi(this);
    //返回按钮音效
    QSound *backSound = new QSound("://res/TapButtonSound.wav",this);

    //设置窗口固定大小
    this->setFixedSize(320,588);
    //设置图标
    this->setWindowIcon(QPixmap("://res/Coin0001.png"));//flaut 1:route:  ://res/Coin0001.png not :/res/Coin0001.png
//    this->setWindowIcon();
    //设置 窗口标题
    this->setWindowTitle("翻金币咯");
    //点击退出，退出程序
    connect(ui->actionQuit,QAction::triggered,[=](){this->close();});

    //创建start动态按钮
    MyPushButton * startBtn = new MyPushButton("://res/MenuSceneStartButton.png");
    startBtn->setParent(this);
    startBtn->move(100,400);

    connect(startBtn,MyPushButton::clicked,[=](){
        //音效
        backSound->play();
        startBtn->zoom1();//down
        startBtn->zoom2();//up
        QTimer::singleShot(500,this,[=](){
            this->hide();
            chooseScene->setGeometry(this->geometry());//设置场景固定屏幕上
            chooseScene->show();
        });

    });
    //收到返回信号，显示主页面
    //第一个参数chooseScene需要在此头文件类创建对象object：：chooseScene
    connect(chooseScene,ChooseLevelScene::chooseSceneBack,[=](){
        chooseScene->setGeometry(chooseScene->geometry());//设置场景固定屏幕上
        this->show();});
}


//重写paintEvent事件，事件不需要调用运行，在打开项目时，就会调用（因为是paintEvent的构造函数）
void MainScene::paintEvent(QPaintEvent *){
    //创建画家，指定绘画设备
    QPainter painter(this);
//    创建QPixmap对象，Qpixmap是一个绘图设备
    QPixmap pix;
//    加载图片
    pix.load("://res/PlayLevelSceneBg.png");
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

MainScene::~MainScene()
{
    delete ui;
}
