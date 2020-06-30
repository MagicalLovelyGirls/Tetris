#include "widget.h"

void Widget::drop()
{
    box->update_box();
    if(box->is_end())
    {
        file->close();
        delete(in);
        timer_drop->stop();
        timer_creat->stop();
        panel->stop_clock();
        status = GAME_OVER;
        panel->print_hint(status);
    }
}

void Widget::creat()
{
    new_block();
}

void Widget::delay()
{
    timer_delay->stop();
    timer_creat->start(creat_interval);
}

Widget::Widget(QWidget *parent): QWidget(parent)
{
    setFixedSize(800, 600);
    setPalette(QPalette(Qt::gray));

    box = new Box;
    panel = new Panel;

    main_layout = new QGridLayout(this);
    main_layout->addWidget(box, 0, 0);
    main_layout->addWidget(panel, 0, 1);

    timer_drop = new QTimer(this);
    timer_creat = new QTimer(this);
    timer_delay = new QTimer(this);
    connect(timer_drop, SIGNAL(timeout()), this, SLOT(drop()));
    connect(timer_creat, SIGNAL(timeout()), this, SLOT(creat()));
    connect(timer_delay, SIGNAL(timeout()), this, SLOT(delay()));

    status = GAME_OFF;
    score = -1;
}

void Widget::init()
{
    box->init();
    status = GAME_OFF;
    score = -1;
    panel->print_score(0);
}

void Widget::start(int difficult)
{
    status = GAME_ON;
    difficulty = difficult;
    drop_interval = di[difficulty];
    creat_interval = ci[difficulty];
    if(difficulty == EASY)
    {
        file = new QFile(":/testSet/testSet/easy.txt");
        file->open(QIODevice::ReadOnly | QIODevice::Text);
        in = new QTextStream(file);
    }
    else if(difficulty == NORMAL)
    {
        file = new QFile(":/testSet/testSet/normal.txt");
        file->open(QIODevice::ReadOnly | QIODevice::Text);
        in = new QTextStream(file);
    }
    else if(difficulty == CHALLENGE)
    {
        file = new QFile(":/testSet/testSet/challenge.txt");
        file->open(QIODevice::ReadOnly | QIODevice::Text);
        in = new QTextStream(file);
    }

    new_block();
    new_block();
    timer_drop->start(drop_interval);
    timer_delay->start(drop_interval/5);
    panel->print_difficult(difficulty);
    panel->print_hint(status);
}

void Widget::new_block()
{
    QString str;
    str = in->readLine();
    if(!str.isNull())
    {
        char *ch;
        QByteArray ba = str.toLatin1();
        ch = ba.data();
        int kind = ch[str.size()-1] - '0';
        box->new_block(kind);
    }
    else box->new_block();
    score++;
    panel->print_score(score);
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_A)
    {
        if(status == GAME_ON)
            box->left();
    }
    else if(event->key() == Qt::Key_D)
    {
        if(status == GAME_ON)
            box->right();
    }
    else if(event->key() == Qt::Key_W)
    {
        if(status == GAME_ON)
            box->rotate();
    }
    else if(event->key() == Qt::Key_S)
    {
        if(status == GAME_ON)
            box->drop_to_bottom();
    }
    else if(event->key() == Qt::Key_Space)
    {
        if(status == GAME_OVER)
        {
            init();
            panel->init();
            status = GAME_OFF;
        }
    }
    else if(event->key() == Qt::Key_1)
    {
        if(status == GAME_OFF)
        {
            start(EASY);
            panel->start();
            status = GAME_ON;
            panel->print_hint(status);
        }
    }
    else if(event->key() == Qt::Key_2)
    {
        if(status == GAME_OFF)
        {
            start(NORMAL);
            panel->start();
            status = GAME_ON;
            panel->print_hint(status);
        }
    }
    else if(event->key() == Qt::Key_3)
    {
        if(status == GAME_OFF)
        {
            start(CHALLENGE);
            panel->start();
            status = GAME_ON;
            panel->print_hint(status);
        }
    }
}


