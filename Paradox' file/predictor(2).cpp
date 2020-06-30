#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

#define COUNT 4
#define MAXX 10
#define MAXY 21

//一般来说需要修改的区域
//------------------------
int weight[3] = {53, -71, -13};    // AI参数权重
#define file "/Users/paradox/CLionProjects/tetris_AI/challenge2.txt"
//------------------------

class Block
{
private:
    int block_kind;
    int block_status;
    int status_period;
    bool is_dropping;
    int centerX, centerY;
    int x[COUNT], y[COUNT];
    friend class Box;

private:
    void get_coordinates()
    {
        if(block_kind == 1)
        {
            this->status_period = 2;
            if(block_status == 0)
            {
                x[0] = centerX-1, x[1] = centerX, x[2] = centerX+1, x[3] = centerX+2;
                y[0] = y[1] = y[2] = y[3] = centerY;
            }
            else if(block_status == 1)
            {
                x[0] = x[1] = x[2] = x[3] = centerX;
                y[0] = centerY-1, y[1] = centerY, y[2] = centerY+1, y[3] = centerY+2;
            }
        }

        else if(block_kind == 2)
        {
            this->status_period = 4;
            if(block_status == 0)
            {
                x[0] = x[1] = centerX-1, x[2] = centerX, x[3] = centerX+1;
                y[0] = centerY-1, y[1] = y[2] = y[3] = centerY;
            }
            else if(block_status == 1)
            {
                x[0] = centerX-1, x[1] = x[2] = x[3] = centerX;
                y[0] = y[1] = centerY+1, y[2] = centerY, y[3] = centerY-1;
            }
            else if(block_status == 2)
            {
                x[0] = x[1] = centerX+1, x[2] = centerX, x[3] = centerX-1;
                y[0] = centerY, y[1] = y[2] = y[3] = centerY-1;
            }
            else if(block_status == 3)
            {
                x[0] = centerX, x[1] = x[2] = x[3] = centerX-1;
                y[0] = y[1] = centerY-1, y[2] = centerY, y[3] = centerY+1;
            }
        }

        else if(block_kind == 3)
        {
            this->status_period = 4;
            if(block_status == 0)
            {
                x[0] = centerX, x[1] = centerX-1, x[2] = centerX, x[3] = centerX+1;
                y[0] = centerY, y[1] = centerY, y[2] = centerY-1, y[3] = centerY;
            }
            else if(block_status == 1)
            {
                x[0] = centerX, x[1] = centerX, x[2] = centerX-1, x[3] = centerX;
                y[0] = centerY, y[1] = centerY+1, y[2] = centerY, y[3] = centerY-1;
            }
            else if(block_status == 2)
            {
                x[0] = centerX, x[1] = centerX+1, x[2] = centerX, x[3] = centerX-1;
                y[0] = centerY, y[1] = centerY, y[2] = centerY+1, y[3] = centerY;
            }
            else if(block_status == 3)
            {
                x[0] = centerX, x[1] = centerX, x[2] = centerX+1, x[3] = centerX;
                y[0] = centerY, y[1] = centerY-1, y[2] = centerY, y[3] = centerY+1;
            }
        }

        else if(block_kind == 4)
        {
            this->status_period = 2;
            if(block_status == 0)
            {
                x[0] = centerX-1, x[1] = x[2] = centerX, x[3] = centerX+1;
                y[0] = y[1] = centerY, y[2] = y[3] = centerY-1;
            }
            else if(block_status == 1)
            {
                x[0] = x[1] = centerX, x[2] = x[3] = centerX-1;
                y[0] = centerY+1, y[1] = y[2] = centerY, y[3] = centerY-1;
            }
        }

        else if(block_kind == 5)
        {
            this->status_period = 1;
            if(block_status == 0)
            {
                x[0] = centerX, x[1] = x[2] = centerX-1, x[3] = centerX;
                y[0] = y[1] = centerY, y[2] = y[3] = centerY-1;
            }
        }
    }
public:
    Block(int kind)
    {
        block_kind = kind;
        block_status = 0;
        is_dropping = 0;

        centerX = block_kind==1 ? 4 : 5;
        centerY = 0;

        get_coordinates();
    }
    Block move_left()
    {
        Block new_block(block_kind);
        new_block.block_status = this->block_status;
        new_block.status_period = this->status_period;
        new_block.is_dropping = this->is_dropping;
        new_block.centerX = this->centerX - 1;
        new_block.centerY = this->centerY;
        new_block.get_coordinates();
        return new_block;
    }
    Block move_right()
    {
        Block new_block(block_kind);
        new_block.block_status = this->block_status;
        new_block.status_period = this->status_period;
        new_block.is_dropping = this->is_dropping;
        new_block.centerX = this->centerX + 1;
        new_block.centerY = this->centerY;
        new_block.get_coordinates();
        return new_block;
    }
    Block move_down()
    {
        Block new_block(block_kind);
        new_block.block_status = this->block_status;
        new_block.status_period = this->status_period;
        new_block.is_dropping = this->is_dropping;
        new_block.centerX = this->centerX;
        new_block.centerY = this->centerY + 1;
        new_block.get_coordinates();
        return new_block;
    }
    Block rotate()
    {
        Block new_block(block_kind);
        new_block.status_period = this->status_period;
        new_block.is_dropping = this->is_dropping;
        new_block.centerX = this->centerX;
        new_block.centerY = this->centerY;
        new_block.block_status = (this->block_status + 1) % new_block.status_period;
        new_block.get_coordinates();
        return new_block;
    }
};

class Box
{
private:
    int box[MAXX][MAXY];
public:
    Box()
    {
        srand((int)time(NULL));
        for(int x = 0; x < MAXX; x++)
            for(int y = 0; y < MAXY; y++)
                box[x][y] = 0;
    }
    Block new_block()
    {
        string s; int kind;   // 对文件的读入在这里，如果文件格式变化了需要修改
        if(cin >> s)
        {
            cin >> s;
            kind = s[s.size()-1]-'0';
        }
        else
            kind = (rand()%5) + 1;
        Block now(kind);
        return now;
    }

    bool can_exist(Block b)
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
    bool left(Block &b)
    {
        Block new_block = b.move_left();
        if(can_exist(new_block))
        {
            b = new_block;
            return true;
        }
        return false;
    }
    bool right(Block &b)
    {
        Block new_block = b.move_right();
        if(can_exist(new_block))
        {
            b = new_block;
            return true;
        }
        return false;
    }
    bool rotate(Block &b)
    {
        Block new_block = b.rotate();
        if(can_exist(new_block))
        {
            b = new_block;
            return true;
        }
        return false;
    }
    bool down(Block &b)
    {
        Block new_block = b.move_down();
        if(can_exist(new_block))
        {
            b = new_block;
            return true;
        }
        return false;
    }
    void drop_to_bottom(Block &b)
    {
        while(true)
            if(!down(b)) break;
    }
    void add_blocks_to_box(Block &b)
    {
        for(int i = 0; i < COUNT; i++)
            box[b.x[i]][b.y[i]] = 1;
    }

    int evaluate(Block b)
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
    void ai(Block &b)
    {
        Block first = b;
        int d[4][MAXX];
        int ro = 0, post = first.centerX; int s = -1000000;
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

        while(ro > 0)
            rotate(b), ro--;
        while(post < b.centerX)
            left(b);
        while(post > b.centerX)
            right(b);
        drop_to_bottom(b);

    }

    void kill_lines()
    {
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
    bool is_end()
    {
        for(int x = 0; x < MAXX; x++)
            if(box[x][0] == 1) return true;
        return false;
    }
};

int predictor()   // 用于预测文件中数据的运行结果
{
    freopen(file, "r", stdin);
    Box box; int cnt = 0;
    while(cnt <= 10000)
    {
        cnt++;
        Block now = box.new_block();
        box.down(now);
        box.ai(now);
        box.add_blocks_to_box(now);
        box.kill_lines();
        if(box.is_end()) break;
    }
    return cnt;
}

// 如果输出了"NONE"则需要手动调一下参数
void find_parameter()   // 用于（可能）得到一组满足条件的超参数
{
    int w0, w1, w2 = weight[2];
    for(w0 = 50; w0 <= 80; w0 += 5)
        for(w1 = -80; w1 <= -60; w1 += 5)
        {
            weight[0] = w0;
            weight[1] = w1;
            if(predictor() > 1000)   // 这里的1000是对于结果大于1000的参数输出（可能需要调）
            {
                cout << w0 << ' ' << w1 << ' ' << w2;
                return;
            }
        }
    cout << "NONE" << endl;
}

int main()
{
    cout << predictor() << endl;
    //find_parameter();
    return 0;
}
