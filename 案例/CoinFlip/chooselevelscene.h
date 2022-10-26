#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H

#include <QMainWindow>
#include <playscene.h>

class ChooseLevelScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseLevelScene(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    playscene * pScene = NULL;
signals:
    void chooseSceneBack();
public slots:
};

#endif // CHOOSESCENE_H
