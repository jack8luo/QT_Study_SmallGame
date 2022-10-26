#include "smallwidget.h"
#include "ui_smallwidget.h"
#include <QSpinBox>
#include <QSlider>
#include <QDial>

SmallWidget::SmallWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SmallWidget)
{
    ui->setupUi(this);
    /**/

    //使用函数指针指定重载函数地址
    void(QSpinBox:: *getValue)(int) = &QSpinBox::valueChanged;
    connect(ui->spinBox,getValue,ui->horizontalSlider,&QSlider::setValue);
    //拉伸条的信号触发 调数值的数字改变的槽
    connect(ui->horizontalSlider,&QSlider::valueChanged,ui->spinBox,&QSpinBox::setValue);

    //sliderMoved
    connect(ui->spinBox,getValue,ui->dial,&QDial::setValue);
    connect(ui->dial,&QDial::sliderMoved,ui->spinBox,&QSpinBox::setValue);

}

//设置数字
void SmallWidget::setNum(int num)
{
    ui->spinBox->setValue(num);
}

//获取数字
int SmallWidget::getNum()
{
    return ui->spinBox->value();
}

SmallWidget::~SmallWidget()
{
    delete ui;
}
