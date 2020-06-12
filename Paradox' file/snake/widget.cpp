#include "widget.h"

Widget::Widget(QWidget *parent): QWidget(parent)
{
    int w = WIDTH * MAXX * 2 + 200, h = HEIGHT * MAXY + 200;
    setFixedSize(w, h);
    setPalette(QPalette(Qt::gray));

    score = 0;
    second = minute = 0;
    board = new Board;
    score_panel = new QLabel(tr("0"));
    clock_panel = new QLabel(tr("0:0"));

    mainlayout = new QGridLayout(this);
    mainlayout->setHorizontalSpacing(20);
    mainlayout->setVerticalSpacing(20);
    mainlayout->addWidget(board, 0, 0);
    mainlayout->addWidget(score_panel, 0, 1);
    mainlayout->addWidget(clock_panel, 0, 2);

    timer = new QTimer(this);
    timer->start(50);
    clock_timer = new QTimer(this);
    clock_timer->start(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimer()));
    connect(clock_timer, SIGNAL(timeout()), this, SLOT(clock()));

    board->repaint();
    status = GAME_OFF;
}

void Widget::onTimer()
{
    if(status != GAME_ON) return;
    int s = board->update_board();
    if(s == 0)
    {
        timer->stop();
        clock_timer->stop();
        status = GAME_OVER;
    }
    else if(s == 2)
    {
        score++;
        QString str;
        str += QString("%1").arg(score);
        score_panel->setText(str);
    }
}

void Widget::clock()
{
    if(status != GAME_ON) return;
    second++;
    if(second == 60)
    {
        second = 0;
        minute++;
    }
    QString str;
    str += QString("%1").arg(minute);
    str += ":";
    str += QString("%1").arg(second);
    clock_panel->setText(str);
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_W)
    {
        board->turn(UP);
    }
    else if(event->key() == Qt::Key_D)
    {
        board->turn(RIGHT);
    }
    else if(event->key() == Qt::Key_S)
    {
        board->turn(DOWN);
    }
    else if(event->key() == Qt::Key_A)
    {
        board->turn(LEFT);
    }
    else if(event->key() == Qt::Key_Space)
    {
        if(status == GAME_OVER)
        {
            board->init();
            score = 0;
            second = minute = 0;
            score_panel->setText("0");
            clock_panel->setText("0:0");
            timer->start(50);
            clock_timer->start(1000);
            board->repaint();
            status = GAME_ON;
        }
        else if(status == GAME_OFF)
            status = GAME_ON;
    }
}
