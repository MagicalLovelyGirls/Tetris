#ifndef BOX_H
#define BOX_H

#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cmath>

#include <QKeyEvent>
#include <QWidget>
#include <QQueue>
#include <QPalette>
#include <QTimer>
#include <QGridLayout>
#include <QLabel>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QByteArray>
#include <QPainter>
#include <QPen>
#include <QBrush>

#include "block.h"

#define WIDTH 20
#define HEIGHT 20
#define MAXX 10
#define MAXY 21
#define INTERVAL 2

#define GAME_OFF 0
#define GAME_ON 1
#define GAME_OVER 2

#define EASY 0
#define NORMAL 1
#define CHALLENGE 2

const int weight[3] = {53, -71, -13};    // AI参数权重
const int di[3] = {500, 300, 200};       // 下落时间间隔
const int ci[3] = {5000, 3000, 1000};    // 产生时间间隔

class Box: public QWidget
{
    Q_OBJECT

private:
    int width, height;                   // 图像宽和高
    int box[MAXX][MAXY];                 // 棋盘
    QQueue<Block> blocks;                // 当前Box中的Block

    QTimer *timer_flash;                 // 消失闪烁计时器
    int cnt;                             // 闪烁次数
    int line[MAXY];                      // 需要闪烁的行

    QTimer *timer_ai;                    // AI操作计时器
    int is_aied;                         // 第一个方块是否已经被评估
    int ro;                              // AI需要旋转的次数
    int post;                            // AI移动的目标x坐标


public slots:
    void flash();                        // 闪烁
    void ai_operate();                   // AI操作间隔

public:
    Box(QWidget *parent = nullptr);      // 构造函数
    void init();                         // 重置
    void new_block(int kind=0);          // 创造一个新的方块

    bool can_exist(Block b);             // 某个Block是否能存在
    bool left();                         // blocks第一个元素左移
    bool right();                        // blocks第一个元素右移
    bool rotate();                       // blocks第一个元素旋转
    bool down();                         // blocks第一个元素下移一格
    void drop_to_bottom();               // blocks第一个元素移到底端
    void add_blocks_to_box();            // 将blocks的第一个元素转移到box中并弹出

    int evaluate(Block b);               // 计算加入一个Block后得到的评分
    void ai();                           // 实现AI

    void kill_lines();                   // 消去整行
    bool is_end();                       // 是否游戏结束

    void update_box();                   // blocks除最后一个元素以外全部下移一格，实现AI
    void paintEvent(QPaintEvent *event); // 绘制box和blocks的图像
};

#endif // BOX_H


















