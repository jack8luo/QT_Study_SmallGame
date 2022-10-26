#ifndef SMALLWIDGET_H
#define SMALLWIDGET_H

#include <QWidget>

namespace Ui {
class SmallWidget;
}

class SmallWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SmallWidget(QWidget *parent = nullptr);
    ~SmallWidget();

    void setNum(int num);//设置数字
    int getNum();//获取数字

private:
    Ui::SmallWidget *ui;
};

#endif // SMALLWIDGET_H
