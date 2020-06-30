#include "box.h"

void Box::flash()
{
    if(cnt > 2)
    {
        timer_flash->stop();
        cnt = 0;
        for(int y = MAXY-1; y >= 1;)
        {
            bool full = 1;
            for(int x = 0; x < MAXX; x++)
            {
                if(box[x][y] == 0)
                {
                    full = 0;
                    break;
                }
            }
            if(full)
            {
                for(int y0 = y; y0 >= 1; y0--)
                    for(int x = 0; x < MAXX; x++)
                        box[x][y0] = box[x][y0-1];
            }
            else y--;
        }
    }
    else
    {
        for(int y = 0; y < MAXY; y++)
        {
            if(line[y])
            {
                for(int x = 0; x < MAXX; x++)
                    box[x][y] = 1^box[x][y];
            }
        }
    }
    repaint();
    cnt++;
}

void Box::ai_operate()
{
    if(ro > 0)
    {
        rotate();
        ro--;
        return;
    }
    if(post < blocks.head().centerX)
    {
        left();
        return;
    }
    if(post > blocks.head().centerX)
    {
        right();
        return;
    }
    is_aied = 0;
    timer_ai->stop();
    drop_to_bottom();
}

Box::Box(QWidget *parent): QWidget(parent)
{
    width = MAXX * WIDTH + (MAXX+1) * INTERVAL;
    height = MAXY * HEIGHT + (MAXY+1) * INTERVAL;
    setFixedSize(width, height);
    setPalette(QPalette(Qt::gray));
    setAutoFillBackground(true);

    srand((int)time(NULL));
    for(int x = 0; x < MAXX; x++)
        for(int y = 0; y < MAXY; y++)
            box[x][y] = 0;
    blocks.clear();

    timer_flash = new QTimer(this);
    connect(timer_flash, SIGNAL(timeout()), this, SLOT(flash()));
    timer_ai = new QTimer(this);
    connect(timer_ai, SIGNAL(timeout()), this, SLOT(ai_operate()));
}

void Box::init()
{
    srand((int)time(NULL));
    for(int x = 0; x < MAXX; x++)
        for(int y = 0; y < MAXY; y++)
            box[x][y] = 0;
    blocks.clear();
    repaint();
}

void Box::new_block(int kind)
{
    if(kind == 0)
        kind = (rand() % 5) + 1;
    Block new_block(kind);
    if(!blocks.isEmpty())
        blocks.back().is_dropping = 1;
    blocks.enqueue(new_block);
}

bool Box::can_exist(Block b)
{
    bool failed = false;
    for(int i = 0; i < COUNT; i++)
    {
        if(box[b.x[i]][b.y[i]] == 1 || b.y[i] >= MAXY ||
           b.x[i] < 0 || b.x[i] >= MAXX)
        {
            failed = true;
            break;
        }
    }
    if(failed) return false;
    else return true;
}

bool Box::left()
{
    if(blocks.isEmpty()) return false;
    Block &first = blocks.head();
    if(!first.is_dropping) return false;
    Block new_block = first.move_left();
    if(can_exist(new_block))
    {
        first = new_block;
        repaint();
        return true;
    }
    else return false;
}

bool Box::right()
{
    if(blocks.isEmpty()) return false;
    Block &first = blocks.head();
    if(!first.is_dropping) return false;
    Block new_block = first.move_right();
    if(can_exist(new_block))
    {
        first = new_block;
        repaint();
        return true;
    }
    else return false;
}

bool Box::rotate()
{
    if(blocks.isEmpty()) return false;
    Block &first = blocks.head();
    if(!first.is_dropping) return false;
    Block new_block = first.rotate();
    if(can_exist(new_block))
    {
        first = new_block;
        repaint();
        return true;
    }
    else return false;
}

bool Box::down()
{
    if(blocks.isEmpty()) return false;
    Block &first = blocks.head();
    if(!first.is_dropping) return false;
    Block new_block = first.move_down();
    if(can_exist(new_block))
    {
        first = new_block;
        repaint();
        return true;
    }
    else
        return false;
}

void Box::drop_to_bottom()
{
    while(true)
         if(!down()) break;
}

void Box::add_blocks_to_box()
{
    if(!blocks.isEmpty())
    {
        Block first = blocks.dequeue();
        for(int i = 0; i < COUNT; i++)
            box[first.x[i]][first.y[i]] = 1;
    }
}

int Box::evaluate(Block b)
{
    for(int i = 0; i < COUNT; i++)
        box[b.x[i]][b.y[i]] = 1;
    int lines = 0, holes = 0, bumpiness = 0;

    int h[MAXX];
    for(int x = 0; x < MAXX; x++)
    {
        h[x] = 0;
        for(int y = 0; y < MAXY; y++)
        {
            if(box[x][y])
            {
                h[x] = MAXY-y;
                break;
            }
        }
        if(x > 0) bumpiness += abs(h[x] - h[x-1]);
        for(int y = MAXY-h[x]; y < MAXY; y++)
        {
            if(box[x][y] == 0)
                holes = holes + 1;
        }
    }

    for(int y = 0; y < MAXY; y++)
    {
        bool full = true;
        for(int x = 0; x < MAXX; x++)
        {
            if(box[x][y] == 0)
            {
                full = false;
                break;
            }
        }
        if(full) lines = lines + 1;
    }
    for(int i = 0; i < COUNT; i++)
        box[b.x[i]][b.y[i]] = 0;

    return weight[0]*lines + weight[1]*holes + weight[2]*bumpiness;
}

void Box::ai()
{
    Block first = blocks.head();

    int d[4][MAXX];
    ro = 0, post = first.centerX; int s = -1000000;
    for(int i = 0; i < first.status_period; i++)
    {
        if(!can_exist(first)) break;
        Block left_side = first;
        while(true)
        {
            Block new_block = left_side.move_left();
            if(can_exist(new_block)) left_side = new_block;
            else break;
        }
        while(true)
        {
            Block down_side = left_side;
            while(true)
            {
                Block new_block = down_side.move_down();
                if(can_exist(new_block)) down_side = new_block;
                else
                {
                    d[i][left_side.centerX] = evaluate(down_side);
                    if(d[i][left_side.centerX] > s)
                    {
                        s = d[i][left_side.centerX];
                        ro = i; post = left_side.centerX;
                    }
                    break;
                }
            }
            Block new_block = left_side.move_right();
            if(can_exist(new_block)) left_side = new_block;
            else break;
        }
        first = first.rotate();
    }
}

void Box::kill_lines()
{
    line[0] = 0;
    for(int y = 1; y < MAXY; y++)
    {
        bool full = 1;
        line[y] = 0;
        for(int x = 0; x < MAXX; x++)
        {
            if(box[x][y] == 0)
            {
                full = 0;
                break;
            }
        }
        if(full) line[y] = 1;
    }
    timer_flash->start(100);
}

bool Box::is_end()
{
    for(int x = 0; x < MAXX; x++)
        if(box[x][0] == 1) return true;
    return false;
}


void Box::update_box()
{
    if(blocks.head().centerY == 1 && is_aied == 0)
    {
        ai();
        int flag = 0;
        for(int x = 0; x < MAXX; x++)
            if(box[x][5]) { flag = 1; break; }
        if(flag)
        {
            for(int i = 0; i < ro; i++)
            {
                rotate();
            }

            if(post < blocks.head().centerX)
            {
                while(blocks.head().centerX != post)
                    left();
            }
            else if(post > blocks.head().centerX)
            {
                while(blocks.head().centerX != post)
                    right();
            }

            drop_to_bottom();
        }
        else
        {
            is_aied = 1;
            timer_ai->start(40);
        }
    }
    int cnt = blocks.size();
    int flag = 0;
    for(int i = 0; i < cnt; i++)
    {
        if(blocks.head().is_dropping == 0)
        {
            blocks.enqueue(blocks.dequeue());
            continue;
        }
        if(down())
            blocks.enqueue(blocks.dequeue());
        else
            flag = 1, add_blocks_to_box();
    }
    repaint();
    if(flag) kill_lines();
}


void Box::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPen pen;
    pen.setColor(Qt::white);
    pen.setStyle(Qt::SolidLine);
    QBrush brush;
    brush.setColor(Qt::white);
    brush.setStyle(Qt::SolidPattern);
    painter.setPen(pen);
    painter.setBrush(brush);

    for(int x = 0; x < MAXX; x++)
        for(int y = 0; y < MAXY; y++)
            if(box[x][y] == 0)
            {
                int px = WIDTH * x + INTERVAL * (x+1);
                int py = HEIGHT * y + INTERVAL * (y+1);
                painter.drawRect(px, py, WIDTH, HEIGHT);
            }

    pen.setColor(Qt::black);
    pen.setStyle(Qt::SolidLine);
    brush.setColor(Qt::black);
    brush.setStyle(Qt::SolidPattern);
    painter.setPen(pen);
    painter.setBrush(brush);

    for(int x = 0; x < MAXX; x++)
        for(int y = 0; y < MAXY; y++)
            if(box[x][y] == 1)
            {
                int px = WIDTH * x + INTERVAL * (x+1);
                int py = HEIGHT * y + INTERVAL * (y+1);
                painter.drawRect(px, py, WIDTH, HEIGHT);
            }

    for(int i = 0; i < blocks.size(); i++)
    {
        Block &first = blocks.head();
        for(int j = 0; j < COUNT; j++)
        {
            int x = first.x[j], y = first.y[j];
            if(x < 0 || x >= MAXX || y < 0 || y >= MAXY) continue;
            int px = WIDTH * x + INTERVAL * (x+1);
            int py = HEIGHT * y + INTERVAL * (y+1);
            painter.drawRect(px, py, WIDTH, HEIGHT);
        }
        blocks.enqueue(blocks.dequeue());
    }
}









