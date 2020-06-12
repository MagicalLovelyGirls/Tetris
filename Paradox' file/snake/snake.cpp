#include "snake.h"

Block::Block(int x, int y)
{
    this->x = x; this->y = y;
}

bool Block::operator == (const Block &rhs)
{
return this->x == rhs.x && this->y == rhs.y;
}

Snake::Snake()
{
    direction = 0;
    blocks.clear();
}

void Snake::turn(int new_dirction)
{
    if(new_dirction != (direction+2) % 4)
        direction = new_dirction;
}

void Snake::advance()
{
    blocks.pop_back();
    Block new_block = blocks.head();
    new_block.x = (new_block.x + dx[direction] + MAXX) % MAXX;
    new_block.y = (new_block.y + dy[direction] + MAXY) % MAXY;
    blocks.push_front(new_block);
}
