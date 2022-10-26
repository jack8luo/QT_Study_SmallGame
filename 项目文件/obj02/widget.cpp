#include "widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
//    //需求：下课了--老师饿了--学生请客
//        /*1、创建信号singal与槽socket，建立老师饿了信号与学生请客的槽连接(如果函数重载,则需要使用函数指针指明函数地址)
//          2、创建下课函数，调用函数执行发送老师饿了的信号
//          3、收到信号调用槽函数执行操作*/

//    //创建一个老师的对象和学生对象
//    this->tea = new Teacher(this);
//    this->st = new Student(this);

//    //链接带参数的槽 声明作用域的函数指针
//    void(Teacher::*teacherSigna)(void) = &Teacher::hungry; //告诉他这个信号是无参的
//    void(Student::*StudenTreat)(void) = &Student::treat;


//    //链接带参数的槽 声明作用域的函数指针
//    void(Teacher::*teacherSigna)(QString) = &Teacher::hungry; //告诉他这个信号是有参的
//    void(Student::*StudenTreat)(QString) = &Student::treat;

//    connect(tea,teacherSigna,st,StudenTreat);
//    classIsOver();

            /*需求:点击按钮，然后才下课
              1.创建对象&&新建按钮
              2.按钮按下信号与下课了函数(触发老师饿了信号)连接
              3.老师饿了信号与学习请客槽连接*/

//    //创建一个老师的对象和学生对象
//    this->tea = new Teacher(this);
//    this->st = new Student(this);

//    QPushButton * btn = new QPushButton("下课",this); // 这个QPushButton窗口大小默认很小
//    this->resize(600,400);

//    //按钮按下 触发 下课函数 下课函数 触发老师饿了的信号
//    connect(btn,&QPushButton::clicked,this,&Widget::classIsOver);

//    //信号也可以连接信号
//    void(Teacher::*teacherSigna2)() = &Teacher::hungry;
//    void(Student::*StudenTreat2)() = &Student::treat;
//    connect(tea,teacherSigna2,st,StudenTreat2);//信号和槽连接

    //connect(btn,&QPushButton::clicked,tea,teacherSigna2);//信号和信号连接



//需求:实现点击按钮关闭操作
//    //lambda表达式
//    QPushButton *btn1 = new QPushButton("关闭按钮",this);
//    btn1->resize(100,30);
//    btn1->move(100,0);
//    connect(btn1,&QPushButton::clicked,this,[=](){ //lambda表达式
//        //emit tea->hungry("宫保鸡丁");
//        //this->close();
//        btn1->setText("失败了");
//    });
}

void Widget::classIsOver()
{
    //下课函数 调用后触发老师饿了的信号
    emit tea->hungry();
//    emit tea->hungry("宫保鸡丁");
}

Widget::~Widget()
{

}
