#ifndef PANEL_H
#define PANEL_H

#include <QWidget>
#include <QPalette>
#include <QGridLayout>
#include <QTimer>
#include <QLabel>
#include <QString>

#define EASY 0
#define NORMAL 1
#define CHALLENGE 2

#define GAME_OFF 0
#define GAME_ON 1
#define GAME_OVER 2

class Panel: public QWidget
{
    Q_OBJECT

private:
    int minute, second;                   // 时间变量
    QTimer *timer_clock;                  // 时钟
    QGridLayout *main_layout;             // 布局

    QLabel *label_difficult;              // 难度标签
    QLabel *label_score;                  // 分数标签
    QLabel *label_clock;                  // 时间标签
    QLabel *label_hint;                   // 提示标签

public slots:
    void clock();                         // 显示时间

public:
    Panel(QWidget *parent = nullptr);     // 构造函数
    void init();                          // 重置
    void start();                         // 开始
    void stop_clock();                    // 时钟停止
    void print_difficult(int difficulty); // 显示难度
    void print_score(int score);          // 显示分数
    void print_hint(int status);          // 显示提示
};

#endif // PANEL_H
