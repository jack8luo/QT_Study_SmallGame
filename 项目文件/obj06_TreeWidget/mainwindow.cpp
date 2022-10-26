#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QTreeWidgetItem>
#include <QFile>
#include <QTextStream>
#include <QStyle>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QFile file(":/1.qss");
    file.open(QFile::ReadOnly);
    QTextStream filetext(&file);
    QString stylesheet = filetext.readAll();
    this->setStyleSheet(stylesheet);
    file.close();
    //树控件的使用
    //设置水平头
    ui->treeWidget->setHeaderLabels(QStringList() << "食物" << "食物简介");

    QTreeWidgetItem * item1 = new QTreeWidgetItem(QStringList() << "蔬菜");
    QTreeWidgetItem * item2 = new QTreeWidgetItem(QStringList() << "水果");
    QTreeWidgetItem * item3 = new QTreeWidgetItem(QStringList() << "肉类");
    //加载顶层节点
    ui->treeWidget->addTopLevelItem(item1);
    ui->treeWidget->addTopLevelItem(item2);
    ui->treeWidget->addTopLevelItem(item3);
    //追加子节点
    QTreeWidgetItem * item4 = new QTreeWidgetItem(QStringList()<< "胡萝卜" << "1.5格饱食度");
    item1->addChild(item4);
    QTreeWidgetItem * item5 = new QTreeWidgetItem(QStringList()<< "马铃薯" << "1格饱食度");
    item1->addChild(item5);

    QTreeWidgetItem * item6 = new QTreeWidgetItem(QStringList()<< "苹果" << "3格饱食度");
    item2->addChild(item6);
    QTreeWidgetItem * item7 = new QTreeWidgetItem(QStringList()<< "梨子" << "3格饱食度");
    item2->addChild(item7);


    QTreeWidgetItem * item8 = new QTreeWidgetItem(QStringList()<< "牛肉" << "3格饱食度");
    item3->addChild(item8);
    QTreeWidgetItem * item9 = new QTreeWidgetItem(QStringList()<< "鸡肉" << "2.5格饱食度");
    item3->addChild(item9);

    QStringList s;
    s << "苹果" << "栗子" << "西瓜" << "粒子" << "鸽子" << "鸡肉";
    ui->comboBox->addItems(s);


}

MainWindow::~MainWindow()
{
    delete ui;
}
