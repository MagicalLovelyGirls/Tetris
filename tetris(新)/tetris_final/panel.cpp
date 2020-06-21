#include "panel.h"

void Panel::clock()
{
    second++;
    if(second == 60)
    {
        second = 0;
        minute++;
    }
    QString str;
    str += QString("time: %1").arg(minute);
    str += QString(":%1").arg(second);
    label_clock->setText(str);
}

Panel::Panel(QWidget *parent): QWidget(parent)
{
    setFixedSize(300, 600);

    timer_clock = new QTimer(this);
    connect(timer_clock, SIGNAL(timeout()), this, SLOT(clock()));

    label_difficult = new QLabel;
    label_score = new QLabel;
    label_clock = new QLabel;
    label_hint = new QLabel;

    main_layout = new QGridLayout(this);
    main_layout->addWidget(label_difficult, 1, 0);
    main_layout->addWidget(label_score, 2, 0);
    main_layout->addWidget(label_clock, 3, 0);
    main_layout->addWidget(label_hint, 4, 0);

    init();
}

void Panel::init()
{
    minute = second = 0;
    print_difficult(-1);
    print_score(0);
    print_hint(0);
    label_clock->setText("time: 0:0");
}

void Panel::start()
{
    timer_clock->start(1000);
}

void Panel::stop_clock()
{
    timer_clock->stop();
}

void Panel::print_difficult(int difficulty)
{
    QString str;
    str += QString("difficulty: ");
    if(difficulty == EASY)
        str += QString("easy");
    else if(difficulty == NORMAL)
        str += QString("normal");
    else if(difficulty == CHALLENGE)
        str += QString("challenge");
    label_difficult->setText(str);
}

void Panel::print_score(int score)
{
    QString str;
    str += QString("score: %1").arg(score);
    label_score->setText(str);
}

void Panel::print_hint(int status)
{
    QString str;
    if(status == GAME_OFF)
        str += QString("easy-1, normal-2, challenge-3");
    else if(status == GAME_ON)
        str += QString("left-A, right-B, rotate-W, drop-S");
    else if(status == GAME_OVER)
        str += QString("GameOver, again-Space");
    label_hint->setText(str);
}









