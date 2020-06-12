#include "board.h"

Board::Board(QWidget *parent): QWidget(parent)
{
    srand((int)time(NULL));
    snake = new Snake;
    snake->blocks.push_front(Block(0, MAXY-1));
    snake->blocks.push_front(Block(0, MAXY-2));
    snake->blocks.push_front(Block(0, MAXY-3));
    for(int x = 0; x < MAXX; x++)
        for(int y = 0; y < MAXY; y++)
            box[x][y] = 0;
    box[0][MAXY-1] = box[0][MAXY-2] = box[0][MAXY-3] = 1;
    new_block();

    int w = WIDTH * MAXX, h = HEIGHT * MAXY;
    setFixedSize(w, h);
    setPalette(QPalette(Qt::white));
    setAutoFillBackground(true);
}

int Board::update_board()
{
    QQueue<Block> &b = snake->blocks;
    Block last = b.last();
    Block head = b.head();
    int next_x = (head.x + dx[snake->direction] + MAXX) % MAXX;
    int next_y = (head.y + dy[snake->direction] + MAXY) % MAXY;
    bool failed = false;
    for(int i = 0; i < b.size(); i++)
    {
        Block first = b.dequeue();
        if(first.x == next_x && first.y == next_y) failed = true;
        b.enqueue(first);
    }
    if(failed) return 0;
    if(box[next_x][next_y] == 1)
    {
        b.push_front(Block(next_x, next_y));
        new_block();
        repaint();
        return 2;
    }
    else
    {
        snake->advance();
        box[last.x][last.y] = 0;
        box[b.head().x][b.head().y] = 1;
        repaint();
        return 1;
    }
}

void Board::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPen pen;
    pen.setColor(Qt::black);
    pen.setStyle(Qt::SolidLine);
    QBrush brush;
    brush.setColor(Qt::black);
    brush.setStyle(Qt::SolidPattern);
    painter.setPen(pen);
    painter.setBrush(brush);

    for(int x = 0; x < MAXX; x++)
        for(int y = 0; y < MAXY; y++)
            if(box[x][y])
            {
                int px = x * WIDTH, py = y * WIDTH;
                painter.drawRect(px, py, WIDTH, HEIGHT);
            }
}

void Board::turn(int dir)
{
    snake->turn(dir);
}

void Board::new_block()
{
    int x, y;
    while(true)
    {
        x = rand() % MAXX, y = rand() % MAXY;
        if(box[x][y] == 0) break;
    }
    box[x][y] = 1;
}

void Board::init()
{
    srand((int)time(NULL));
    snake = new Snake;
    snake->blocks.push_front(Block(0, MAXY-1));
    snake->blocks.push_front(Block(0, MAXY-2));
    snake->blocks.push_front(Block(0, MAXY-3));
    for(int x = 0; x < MAXX; x++)
        for(int y = 0; y < MAXY; y++)
            box[x][y] = 0;
    box[0][MAXY-1] = box[0][MAXY-2] = box[0][MAXY-3] = 1;
    new_block();
}










