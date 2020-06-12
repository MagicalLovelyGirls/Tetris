#ifndef BOARD_H
#define BOARD_H

#include <cstdlib>
#include <ctime>

#include <QWidget>
#include <QPalette>
#include <QPainter>
#include <QPen>
#include <QBrush>

#include "snake.h"

class Board: public QWidget
{
    Q_OBJECT

private:
    Snake *snake;
    int box[MAXX][MAXY];

public:
    Board(QWidget *parent = nullptr);         // 构造函数，初始在左下角竖着3个方块
    int update_board();                       // 移动一次并改变box，成功返回1，相撞返回0，吃了返回2
    void paintEvent(QPaintEvent *event);      // box为1的部分为黑色
    void turn(int dir);                       // box中的蛇转向
    void new_block();                         // 新的方块
    void init();                             // 全部刷新
};

#endif // BOARD_H
