#include "playscene.h"
#include <mycoin.h>
#include <dataconfig.h>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QPainter>
#include <mypushbutton.h>
#include <QTimer>
#include <QLabel>
#include <QPropertyAnimation>
#include <QSound>

playscene::playscene(QWidget *parent) : QMainWindow(parent)
{

}
playscene::playscene(int index){
    //返回按钮音效
    QSound *backSound = new QSound("://res/TapButtonSound.wav",this);
    //翻金币音效
    QSound *flipSound = new QSound("://res/ConFlipSound.wav",this);
   //胜利按钮音效
    QSound *winSound = new QSound("://res/LevelWinSound.wav",this);

    this->levelIndex = index;
    this->setFixedSize(320,588);
    this->setWindowIcon(QPixmap("://res/Coin0001.png"));
    this->setWindowTitle("翻金币");
    //创建菜单栏
    QMenuBar * bar = this->menuBar();
    QMenu * startMenu = bar->addMenu("开始");
    QAction * quitAction = startMenu->addAction("退出");
    //点击退出，退出游戏
    connect(quitAction,QAction::triggered,[=](){this->close();});

    //返回按钮
    MyPushButton * closeBtn = new MyPushButton("://res/BackButton.png","://res/BackButtonSelected.png");
    closeBtn->setParent(this);
    closeBtn->move(this->width()-closeBtn->width(),this->height()-closeBtn->height());

    //返回功能连接
    connect(closeBtn,MyPushButton::clicked,[=](){
        backSound->play();//不能放在下面代码下，延时操作，不会执行play
        QTimer::singleShot(500,this,[=](){
            this->hide();
            emit this->chooseSceneBack();
        });
    });

    //当前关卡标题
    QLabel * label = new QLabel;
    label->setParent(this);
    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(20);
    label->setFont(font);
    QString str = QString("Leavel: %1").arg(this->levelIndex);
    label->setText(str);
    label->setGeometry(20,550,120,50);

    //创建金币背景
    for(int i = 0 ; i < 4; i++){
        for(int j = 0 ; j < 4; j++){
            //绘制背景
            QLabel * label = new QLabel;
            label->setGeometry(0,0,50,50);
            label->setParent(this);
            label->setPixmap(QPixmap("://res/BoardNode.png"));
            label->move(57+i*50,200+j*50);

            //绘制金币
            //测试
//            MyCoin * coin = new MyCoin("://res/Coin0001.png");
//            coin->setParent(this);
//            coin->move(59+i*50,204+j*50);
        }
    }


    //提前准备好的胜利图片
    QLabel* winLabel = new QLabel;
    QPixmap tmpPix;
    tmpPix.load(":/res/LevelCompletedDialogBg.png");
    winLabel->setGeometry(0,0,tmpPix.width(),tmpPix.height());
    winLabel->setPixmap(tmpPix);
    winLabel->setParent(this);
    winLabel->move( (this->width() - tmpPix.width())*0.5 , -tmpPix.height());


    //初始化二维数组
    //金币初始化
    dataConfig config;
    for(int i = 0;i<4;i++){
        for(int j = 0; j < 4; j++ ){
            gameArray[i][j] = config.mData[this->levelIndex][i][j];
            QString img;
            if(gameArray[i][j] == 1)
            {
                img = "://res/Coin0001.png";
            }
            else{
                img = "://res/Coin0008.png";
            }
            MyCoin * coin = new MyCoin(img);
            coin->setParent(this);
            coin->move(59 +i*50,204+j*50);
            coin->posX = i; //记录x
            coin->posY = j;
            coin->flag = gameArray[i][j]; // 记录正反标志

            //记录每个按钮的位置
            //如果在监听连接中记录则会异常结束，因为监听是只有触发连接之后才做的事情！！！
            coinBtn[i][j] = coin;


            //监听金币点击信号
            connect(coin,MyCoin::clicked,[=](){
                //音效
                flipSound->play();

                coin->changeFlag();
                gameArray[i][j] = (gameArray[i][j] == 0 ? 1:0);

                //延时翻转周围金币
                QTimer::singleShot(300, this,[=](){
                if(coin->posX+1 <=3)
                {
                  coinBtn[coin->posX+1][coin->posY]->changeFlag();
                  gameArray[coin->posX+1][coin->posY] = gameArray[coin->posX+1][coin->posY]== 0 ? 1 : 0;
                }
                if(coin->posX-1>=0)
                {
                  coinBtn[coin->posX-1][coin->posY]->changeFlag();
                  gameArray[coin->posX-1][coin->posY] = gameArray[coin->posX-1][coin->posY]== 0 ? 1 : 0;
                }
                if(coin->posY+1<=3)
                {
                 coinBtn[coin->posX][coin->posY+1]->changeFlag();
                 gameArray[coin->posX][coin->posY+1] = gameArray[coin->posX+1][coin->posY]== 0 ? 1 : 0;
                }
                if(coin->posY-1>=0)
                {
                 coinBtn[coin->posX][coin->posY-1]->changeFlag();
                 gameArray[coin->posX][coin->posY-1] = gameArray[coin->posX+1][coin->posY]== 0 ? 1 : 0;
                }

                // 在监听翻转后的按钮是否满足成功
                this->isWin = true;
                for(int i = 0 ; i < 4;i++)
                {
                    for(int j = 0 ; j < 4; j++)
                    {
                        //qDebug() << coinBtn[i][j]->flag ;
                        if( coinBtn[i][j]->flag == false)
                        {
                            this->isWin = false;
                            break;
                        }
                    }
                }
                if(this->isWin == true){
                    //音效
                    winSound->play();
    //              qDebug() << "成功！";
               //如果胜利了，将上面的图片移动下来
                    QPropertyAnimation * animation1 =  new QPropertyAnimation(winLabel,"geometry");
                    animation1->setDuration(1000);
                    animation1->setStartValue(QRect(winLabel->x(),winLabel->y(),winLabel->width(),winLabel->height()));
                    animation1->setEndValue(QRect(winLabel->x(),winLabel->y()+114,winLabel->width(),winLabel->height()));
                    animation1->setEasingCurve(QEasingCurve::OutBounce);
                    animation1->start();

                    //设置Mycoin中的isWin，拦截press。
                    for(int i = 0 ; i < 4;i++)
                          {
                            for(int j = 0 ; j < 4; j++)
                            {
                              coinBtn[i][j]->isWin = true;
                            }
                    }

                }
            });


            });

        }
    }

}

void playscene::paintEvent(QPaintEvent *){
    //加载背景
    QPainter painter(this);
    QPixmap pix;
    pix.load("://res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    //加载标题
    pix.load("://res/Title.png");
    //    缩放图片
    //    pix = pix.scaled(pix.width()*0.5,pix.height()*0.5);
    //    painter.drawPixmap(10,30,pix.width(),pix.height(),pix);
    //    绘制标题
    painter.drawPixmap(10,30,this->width()*0.5,this->height()*0.1,pix);
}
