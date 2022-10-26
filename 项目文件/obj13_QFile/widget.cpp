#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QFileDialog>
#include <QFile>
#include <QTextCodec>
#include <QFileInfo>
#include <QDebug>
#include <QDateTime>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //点击选取文件按钮，弹出文件对话框
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        //获取一个路径
        QString path = QFileDialog::getOpenFileName(this,"打开文件","./");
        if(path.size() == 0)
        {
            return;
        }
        ui->lineEdit->setText(path);


        //读取内容放入到textEdit中
        QFile file(path);
        //设置打开方式
        file.open(QIODevice::ReadOnly);

        //QByteArray array = file.readAll();
        QByteArray array;
        while(!file.atEnd())
        {
            array += file.readLine(); //按行读
        }

        //将读取到的数据 放入到textEdit中
        //QFile默认支持格式是utf-8
        ui->textEdit->setText(array);

        //转码 你如果打开的是一个GBK的
        //编码格式类
        //QTextCodec *codec = QTextCodec::codecForName("gbk");
        //ui->textEdit->setText(codec->toUnicode(array));
        file.close();

        //进行写入
//        file.open(QIODevice::Append); //追加的方式进行写
//        file.write("//咕咕咕");
//        file.close();


        //获取文件信息
        QFileInfo info(path);


        QString s;
        s += "大小:" + QString::number(info.size()) + "byte";
        s += "\n后缀名:" + info.suffix();
        s += "\n文件名:" + info.fileName();
        s += "\n路径名:" + info.filePath();
        s += "\n创建日期:" + info.birthTime().toString("yyyy/MM/dd hh:mm:ss");
        s += "\n修改日期:" + info.lastModified().toString("yyyy/MM/dd hh:mm:ss");
        ui->textEdit_2->setText(s);
    });
}

Widget::~Widget()
{
    delete ui;
}
