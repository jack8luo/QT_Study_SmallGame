/********************************************************************************
** Form generated from reading UI file 'ovo.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OVO_H
#define UI_OVO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ovo
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QTextEdit *textEdit;
    QPushButton *pushserver;
    QListWidget *listWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ovo)
    {
        if (ovo->objectName().isEmpty())
            ovo->setObjectName(QString::fromUtf8("ovo"));
        ovo->resize(800, 600);
        centralwidget = new QWidget(ovo);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 400, 781, 151));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        textEdit = new QTextEdit(widget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        horizontalLayout->addWidget(textEdit);

        pushserver = new QPushButton(widget);
        pushserver->setObjectName(QString::fromUtf8("pushserver"));

        horizontalLayout->addWidget(pushserver);

        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(10, 10, 781, 381));
        ovo->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ovo);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        ovo->setMenuBar(menubar);
        statusbar = new QStatusBar(ovo);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ovo->setStatusBar(statusbar);

        retranslateUi(ovo);

        QMetaObject::connectSlotsByName(ovo);
    } // setupUi

    void retranslateUi(QMainWindow *ovo)
    {
        ovo->setWindowTitle(QApplication::translate("ovo", "MainWindow", nullptr));
        pushserver->setText(QApplication::translate("ovo", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ovo: public Ui_ovo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OVO_H
