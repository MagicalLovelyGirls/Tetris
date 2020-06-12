#ifndef WIDGET_H
#define WIDGET_H

#include <QKeyEvent>
#include <QWidget>
#include <QPalette>
#include <QTimer>
#include <QGridLayout>
#include <QLabel>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QByteArray>

#include "block.h"
#include "box.h"

#define GAME_OFF 0
#define GAME_ON 1
#define GAME_OVER 2

#define EASY 0
#define NORMAL 1
#define CHALLENGE 2

const int di[3] = {500, 300, 200};
const int ci[3] = {5000, 3000, 1000};

class Widget : public QWidget
{
    Q_OBJECT

private:
    int status;                                          // 游戏状态
    int difficulty;                                      // 难度
    int drop_interval;                                   // 下落时间间隔
    int creat_interval;                                  // 制造方块时间间隔
    int score;                                           // 产生的砖块个数
    int minute, second, msec;                                  // 时间变量 Updated

    Box *box;                                            // 棋盘
    QTimer *timer_drop;                                  // 下落速度计时器
    QTimer *timer_creat;                                 // 花费时间计时器
    QTimer *timer_delay;                                 // 延时计时器
    QTimer *timer_clock;                                 // 钟表计时器
    QGridLayout *main_layout;                            // 布局
    QLabel *label_difficult_title;                       // 难度标题 New
    QLabel *label_difficult;                             // 难度标签
    QLabel *label_score_title;                           // 分数标题 New
    QLabel *label_score;                                 // 分数标签
    QLabel *label_clock_title;                           // 时间标题 New
    QLabel *label_clock;                                 // 时间标签
    QLabel *label_hint;                                  // 提示标签
    QFile *file;                                         // 读入文件
    QTextStream *in;                                     // 读入内容

public slots:
    void drop();                                         // 下落方块
    void creat();                                        // 产生方块
    void delay();                                        // 延时
    void clock();                                        // 时间

public:
    Widget(QWidget *parent = nullptr);                   // 构造函数
    void new_block();                                    // 用读入构造新的方块
    void init();                                         // 重置
    void start(int difficult);                           // 开始游戏
    void keyPressEvent(QKeyEvent *event);                // 按键

};
#endif // WIDGET_H
