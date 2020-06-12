#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QKeyEvent>
#include <QPalette>
#include <QGridLayout>
#include <QTimer>
#include <QLabel>
#include <QString>

#include "board.h"

#define GAME_OFF 0
#define GAME_ON 1
#define GAME_OVER 2

class Widget : public QWidget
{
    Q_OBJECT

private:
    int status;
    int score;
    int second, minute;

    Board *board;
    QGridLayout *mainlayout;
    QTimer *timer;
    QTimer *clock_timer;
    QLabel *score_panel;
    QLabel *clock_panel;

public slots:
    void onTimer();
    void clock();

public:
    Widget(QWidget *parent = nullptr);
    void keyPressEvent(QKeyEvent *event);
};
#endif // WIDGET_H
