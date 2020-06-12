#ifndef BOX_H
#define BOX_H

#include <cstdlib>
#include <ctime>
#include <cstdio>

#include <QWidget>
#include <QQueue>
#include <QPalette>
#include <QPainter>
#include <QPen>
#include <QBrush>

#include "block.h"

#define WIDTH 20
#define HEIGHT 20
#define MAXX 10
#define MAXY 21
#define INTERVAL 2

class Box: public QWidget
{
    Q_OBJECT
private:
    int box[MAXX][MAXY];                        // 棋盘

    void add_blocks_to_box();                   // 将blocks的第一个元素转移到box中并弹出
    bool can_exist(Block b);                    // 某个方块是否能存在

public:
    Box(QWidget *parent = nullptr);             // 构造函数
    QQueue<Block> blocks;                       // 当前在box中的block
    void init();                                // 重置
    void new_block(int kind=0);                 // 创造一个新的方块，如果没有读入就随机创建并放入blocks
    int get_width();                            // 宽度
    int get_height();                           // 高度
    bool left();                                // 将blocks的第一个元素左移一格
    bool right();                               // 将blocks的第一个元素右移一格
    bool rotate();                              // 将blocks的第一个元素旋转一次
    int  drop();                                // 将blocks的第一个元素下移一格，如果移动返回1，停止返回0，游戏结束返回-1
    int drop_to_bottom();                       // 将bolcks的第一个元素移到底端，移动成功返回1，游戏结束返回-1
    int kill_lines();                           // 消去整行
    bool is_end();                              // 判断是否游戏结束
    void update_box();                          // blocks除最后一个元素以外全体下移一格，第一个元素实现AI
    void paintEvent(QPaintEvent *event);        // 绘制box和blocks的图像
};

#endif // BOX_H
