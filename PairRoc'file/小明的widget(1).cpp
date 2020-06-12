#include"widget.h"
Widget::Widget(QWidget *parent): QWidget(parent)
{
    setFixedSize(350, 506);
    this->setWindowTitle("Teris");
    score = second = minute = msec = 0;

    QPalette palette;                                                   //UI开始（不含box的ui设计）
    QBrush brush(QColor(255, 255, 255, 255));
    brush.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
    QBrush brush1(QColor(0, 0, 0, 255));
    brush1.setStyle(Qt::SolidPattern);
    QBrush brush4(QColor(127, 127, 127, 255));
    brush4.setStyle(Qt::SolidPattern);
    QBrush brush5(QColor(170, 170, 170, 255));
    brush5.setStyle(Qt::SolidPattern);
    QBrush brush6(QColor(0, 0, 0, 128));
    brush6.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Button, brush1);
    palette.setBrush(QPalette::Active, QPalette::Light, brush1);
    palette.setBrush(QPalette::Active, QPalette::Midlight, brush1);
    palette.setBrush(QPalette::Active, QPalette::Dark, brush1);
    palette.setBrush(QPalette::Active, QPalette::Mid, brush1);
    palette.setBrush(QPalette::Active, QPalette::Text, brush);
    palette.setBrush(QPalette::Active, QPalette::BrightText, brush);
    palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
    palette.setBrush(QPalette::Active, QPalette::Base, brush1);
    palette.setBrush(QPalette::Active, QPalette::Window, brush1);
    palette.setBrush(QPalette::Active, QPalette::Shadow, brush1);
    palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
    QBrush brush2(QColor(255, 255, 220, 255));
    brush2.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush2);
    palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
    QBrush brush3(QColor(255, 255, 255, 128));
    brush3.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush3);
#endif
    palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
    palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
    palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
    palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
    palette.setBrush(QPalette::Inactive, QPalette::Dark, brush1);
    palette.setBrush(QPalette::Inactive, QPalette::Mid, brush1);
    palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
    palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
    palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
    palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
    palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
    palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
    palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
    palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush2);
    palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush3);
#endif
    palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
    palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
    palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
    palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
    palette.setBrush(QPalette::Disabled, QPalette::Dark, brush1);
    palette.setBrush(QPalette::Disabled, QPalette::Mid, brush1);
    palette.setBrush(QPalette::Disabled, QPalette::Text, brush1);
    palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
    palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
    palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
    palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
    palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
    palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
    palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush2);
    palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush3);
#endif
    this->setPalette(palette);
    QFont font;
    font.setPointSize(9);
    font.setBold(true);
    font.setWeight(75);
    this->setFont(font);


    label_difficult_title = new QLabel(this);
    label_difficult_title->setObjectName(QString::fromUtf8("label_difficult_title"));
    label_difficult_title->setGeometry(QRect(240, 20, 91, 31));
    QFont font1;
    font1.setFamily(QString::fromUtf8("Yu Gothic Medium"));
    font1.setPointSize(11);
    font1.setBold(true);
    font1.setWeight(75);
    label_difficult_title->setFont(font1);
    label_difficult_title->setTextFormat(Qt::AutoText);
    label_difficult_title->setScaledContents(false);
    label_difficult_title->setMargin(0);
    label_difficult_title->setIndent(-1);

    label_difficult = new QLabel(this);
    label_difficult->setObjectName(QString::fromUtf8("label_difficult"));
    label_difficult->setGeometry(QRect(240, 50, 91, 20));
    QPalette palette2;
    palette2.setBrush(QPalette::Active, QPalette::WindowText, brush1);
    palette2.setBrush(QPalette::Active, QPalette::Button, brush);
    palette2.setBrush(QPalette::Active, QPalette::Light, brush);
    palette2.setBrush(QPalette::Active, QPalette::Midlight, brush);
    palette2.setBrush(QPalette::Active, QPalette::Dark, brush4);
    palette2.setBrush(QPalette::Active, QPalette::Mid, brush5);
    palette2.setBrush(QPalette::Active, QPalette::Text, brush1);
    palette2.setBrush(QPalette::Active, QPalette::BrightText, brush);
    palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
    palette2.setBrush(QPalette::Active, QPalette::Base, brush);
    palette2.setBrush(QPalette::Active, QPalette::Window, brush);
    palette2.setBrush(QPalette::Active, QPalette::Shadow, brush1);
    palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
    palette2.setBrush(QPalette::Active, QPalette::ToolTipBase, brush2);
    palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush6);
#endif
    palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
    palette2.setBrush(QPalette::Inactive, QPalette::Button, brush);
    palette2.setBrush(QPalette::Inactive, QPalette::Light, brush);
    palette2.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
    palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
    palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
    palette2.setBrush(QPalette::Inactive, QPalette::Text, brush1);
    palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
    palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
    palette2.setBrush(QPalette::Inactive, QPalette::Base, brush);
    palette2.setBrush(QPalette::Inactive, QPalette::Window, brush);
    palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
    palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
    palette2.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush2);
    palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush6);
#endif
    palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
    palette2.setBrush(QPalette::Disabled, QPalette::Button, brush);
    palette2.setBrush(QPalette::Disabled, QPalette::Light, brush);
    palette2.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
    palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
    palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
    palette2.setBrush(QPalette::Disabled, QPalette::Text, brush4);
    palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
    palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
    palette2.setBrush(QPalette::Disabled, QPalette::Base, brush);
    palette2.setBrush(QPalette::Disabled, QPalette::Window, brush);
    palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
    palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
    palette2.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush2);
    palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
    label_difficult->setPalette(palette2);
    QFont font2;
    font2.setFamily(QString::fromUtf8("Yu Gothic Medium"));
    font2.setPointSize(11);
    font2.setBold(true);
    font2.setWeight(75);
    font2.setKerning(true);
    label_difficult->setFont(font2);
    label_difficult->setLayoutDirection(Qt::LeftToRight);
    label_difficult->setAutoFillBackground(true);
    label_difficult->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

    label_score_title = new QLabel(this);
    label_score_title->setObjectName(QString::fromUtf8("label_Score_title"));
    label_score_title->setGeometry(QRect(240, 80, 91, 31));
    label_score_title->setFont(font1);
    label_score_title->setTextFormat(Qt::AutoText);
    label_score_title->setScaledContents(false);
    label_score_title->setMargin(0);
    label_score_title->setIndent(-1);
    label_score = new QLabel(this);
    label_score->setObjectName(QString::fromUtf8("label_score"));
    label_score->setGeometry(QRect(240, 110, 91, 20));
    QPalette palette3;
    palette3.setBrush(QPalette::Active, QPalette::WindowText, brush1);
    palette3.setBrush(QPalette::Active, QPalette::Button, brush);
    palette3.setBrush(QPalette::Active, QPalette::Light, brush);
    palette3.setBrush(QPalette::Active, QPalette::Midlight, brush);
    palette3.setBrush(QPalette::Active, QPalette::Dark, brush4);
    palette3.setBrush(QPalette::Active, QPalette::Mid, brush5);
    palette3.setBrush(QPalette::Active, QPalette::Text, brush1);
    palette3.setBrush(QPalette::Active, QPalette::BrightText, brush);
    palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
    palette3.setBrush(QPalette::Active, QPalette::Base, brush);
    palette3.setBrush(QPalette::Active, QPalette::Window, brush);
    palette3.setBrush(QPalette::Active, QPalette::Shadow, brush1);
    palette3.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
    palette3.setBrush(QPalette::Active, QPalette::ToolTipBase, brush2);
    palette3.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette3.setBrush(QPalette::Active, QPalette::PlaceholderText, brush6);
#endif
    palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
    palette3.setBrush(QPalette::Inactive, QPalette::Button, brush);
    palette3.setBrush(QPalette::Inactive, QPalette::Light, brush);
    palette3.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
    palette3.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
    palette3.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
    palette3.setBrush(QPalette::Inactive, QPalette::Text, brush1);
    palette3.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
    palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
    palette3.setBrush(QPalette::Inactive, QPalette::Base, brush);
    palette3.setBrush(QPalette::Inactive, QPalette::Window, brush);
    palette3.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
    palette3.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
    palette3.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush2);
    palette3.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette3.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush6);
#endif
    palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
    palette3.setBrush(QPalette::Disabled, QPalette::Button, brush);
    palette3.setBrush(QPalette::Disabled, QPalette::Light, brush);
    palette3.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
    palette3.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
    palette3.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
    palette3.setBrush(QPalette::Disabled, QPalette::Text, brush4);
    palette3.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
    palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
    palette3.setBrush(QPalette::Disabled, QPalette::Base, brush);
    palette3.setBrush(QPalette::Disabled, QPalette::Window, brush);
    palette3.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
    palette3.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
    palette3.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush2);
    palette3.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette3.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
    label_score->setPalette(palette3);
    label_score->setFont(font2);
    label_score->setLayoutDirection(Qt::LeftToRight);
    label_score->setAutoFillBackground(true);
    label_score->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
    label_clock_title = new QLabel(this);
    label_clock_title->setObjectName(QString::fromUtf8("label_Time_title"));
    label_clock_title->setGeometry(QRect(240, 140, 91, 31));
    label_clock_title->setFont(font1);
    label_clock_title->setTextFormat(Qt::AutoText);
    label_clock_title->setScaledContents(false);
    label_clock_title->setMargin(0);
    label_clock_title->setIndent(-1);
    label_clock = new QLabel(this);
    label_clock->setObjectName(QString::fromUtf8("label_time"));
    label_clock->setGeometry(QRect(240, 170, 91, 20));
    QPalette palette4;
    palette4.setBrush(QPalette::Active, QPalette::WindowText, brush1);
    palette4.setBrush(QPalette::Active, QPalette::Button, brush);
    palette4.setBrush(QPalette::Active, QPalette::Light, brush);
    palette4.setBrush(QPalette::Active, QPalette::Midlight, brush);
    palette4.setBrush(QPalette::Active, QPalette::Dark, brush4);
    palette4.setBrush(QPalette::Active, QPalette::Mid, brush5);
    palette4.setBrush(QPalette::Active, QPalette::Text, brush1);
    palette4.setBrush(QPalette::Active, QPalette::BrightText, brush);
    palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
    palette4.setBrush(QPalette::Active, QPalette::Base, brush);
    palette4.setBrush(QPalette::Active, QPalette::Window, brush);
    palette4.setBrush(QPalette::Active, QPalette::Shadow, brush1);
    palette4.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
    palette4.setBrush(QPalette::Active, QPalette::ToolTipBase, brush2);
    palette4.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette4.setBrush(QPalette::Active, QPalette::PlaceholderText, brush6);
#endif
    palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
    palette4.setBrush(QPalette::Inactive, QPalette::Button, brush);
    palette4.setBrush(QPalette::Inactive, QPalette::Light, brush);
    palette4.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
    palette4.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
    palette4.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
    palette4.setBrush(QPalette::Inactive, QPalette::Text, brush1);
    palette4.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
    palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
    palette4.setBrush(QPalette::Inactive, QPalette::Base, brush);
    palette4.setBrush(QPalette::Inactive, QPalette::Window, brush);
    palette4.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
    palette4.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
    palette4.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush2);
    palette4.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette4.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush6);
#endif
    palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
    palette4.setBrush(QPalette::Disabled, QPalette::Button, brush);
    palette4.setBrush(QPalette::Disabled, QPalette::Light, brush);
    palette4.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
    palette4.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
    palette4.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
    palette4.setBrush(QPalette::Disabled, QPalette::Text, brush4);
    palette4.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
    palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
    palette4.setBrush(QPalette::Disabled, QPalette::Base, brush);
    palette4.setBrush(QPalette::Disabled, QPalette::Window, brush);
    palette4.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
    palette4.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
    palette4.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush2);
    palette4.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette4.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
    label_clock->setPalette(palette4);
    label_clock->setFont(font2);
    label_clock->setLayoutDirection(Qt::LeftToRight);
    label_clock->setAutoFillBackground(true);
    label_clock->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);                   //UI结束


    label_score -> setText("0");
    label_clock -> setText("0:0:00");
    label_difficult -> setText("Unknown");
    label_difficult_title -> setText("Difficult");
    label_clock_title -> setText("Time");;
    label_score_title -> setText("Score");;

    timer_drop = new QTimer(this);
    timer_creat = new QTimer(this);
    timer_delay = new QTimer(this);
    timer_clock = new QTimer(this);

    connect(timer_drop, SIGNAL(timeout()), this, SLOT(drop()));
    connect(timer_creat, SIGNAL(timeout()), this, SLOT(creat()));
    connect(timer_delay, SIGNAL(timeout()), this, SLOT(delay()));
    connect(timer_clock, SIGNAL(timeout()), this, SLOT(clock()));

    status = GAME_OFF;
}
void Widget::clock()
{
    if(status != GAME_ON) return;
    ++msec;
    if(msec>=100){++second;msec=0;}
    if(second>=60){++minute;second=0;}
    label_clock->setText(QString("%1:%2:%3").arg(minute).arg(second).arg(msec));
}

void Widget::new_block()
{
    score++;
    label_score -> setText(QString("%1").arg(score));
}

void Widget::init()
{
    score = second = minute = msec = 0;
    label_score ->setText("0");
    label_clock ->setText("0:0:0");
    label_difficult ->setText("Unknown");
}

void Widget::start(int difficult)
{
    difficulty=difficult;
    if(difficulty==EASY)
    {
        label_difficult -> setText("EASY");
        timer_drop -> start(500);
        timer_creat -> start(5000);
        timer_delay -> start();
    }
    else if(difficulty==NORMAL)
    {
        label_difficult -> setText("NORMAL");
        timer_drop -> start(300);
        timer_creat -> start(3000);
        timer_delay -> start();
    }
    else if(difficulty==CHALLENGE)
    {
        label_difficult -> setText("CHALLENGE");
        timer_drop -> start(200);
        timer_creat -> start(1000);
        timer_delay -> start();
    }
    timer_clock ->start(1);
    status = GAME_ON;
}
