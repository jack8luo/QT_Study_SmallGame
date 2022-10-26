#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFontDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionfont,&QAction::triggered,[=](){
        bool flag;
        QFont font = QFontDialog::getFont(&flag,QFont("黑体",12));
        setFont(font);
    });


}

MainWindow::~MainWindow()
{
    delete ui;
}
