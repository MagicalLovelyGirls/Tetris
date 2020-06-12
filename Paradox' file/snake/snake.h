#ifndef SNAKE_H
#define SNAKE_H

#include <QQueue>

#define WIDTH 10
#define HEIGHT 10

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

#define MAXX 40
#define MAXY 60

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {-1, 0, 1, 0};

struct Block
{
    int x, y;
    Block(int x, int y);
    bool operator == (const Block &rhs);
};

class Snake
{
private:
    friend class Board;
    int direction;                 // 当前蛇前进的方向
    QQueue<Block> blocks;          // 蛇的整个序列
public:
    Snake();
    void turn(int new_dirction);   // 转向
    void advance();                // 前进一格，若无法前进返回false
};

#endif // SNAKE_H
