#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPalette>
#include <QGridLayout>
#include <QKeyEvent>

#include "box.h"
#include "panel.h"

class Widget : public QWidget
{
    Q_OBJECT

private:
    Box *box;                             // 游戏
    Panel *panel;                         // 数据
    QGridLayout *main_layout;             // 布局

    int status;                           // 游戏状态
    int difficulty;                       // 难度
    int drop_interval;                    // 下落时间间隔
    int creat_interval;                   // 制造方块时间间隔
    int score;                            // 产生的方块个数

    QTimer *timer_drop;                   // 下落速度计时器
    QTimer *timer_creat;                  // 产生方块计时器
    QTimer *timer_delay;                  // 延时计时器

    QFile *file;                          // 读入文件
    QTextStream *in;                      // 读入内容

public slots:
    void drop();                          // 下落方块
    void creat();                         // 产生方块
    void delay();                         // 延时

public:
    Widget(QWidget *parent = nullptr);    // 构造函数
    void init();                          // 重置
    void start(int difficult);            // 开始游戏
    void new_block();                     // 新的方块
    void keyPressEvent(QKeyEvent *event); // 按键
};
#endif // WIDGET_H
