#ifndef BLOCK_H
#define BLOCK_H

#define COUNT 4                 // 每一个Bolck所占的方格数

class Block
{
private:
    int block_kind;             // Block的种类
    int block_status;           // Block的状态(按照转动顺序分别为0,1,2...)
    int status_period;          // 状态周期
    bool is_dropping;           // 是否正在下落
    int centerX, centerY;       // 中心坐标
    int x[COUNT], y[COUNT];     // Block的4个坐标
    friend class Box;
    friend class Widget;

private:
    void get_coordinates();     // 通过center和status得到四个方块坐标

public:
    Block(int kind);            // 构造函数(注意按照要求将Block构造在最顶端一行)
    int get_kind();             // 获得Block的种类
    int get_status();           // 获得Block的状态
    Block move_left();          // 左移一个单位
    Block move_right();         // 右移一个单位
    Block drop();               // 下移一个单位
    Block rotate();             // 旋转一次
};

#endif // BLOCK_H

// kind = 1, status = 0: start_center(4, 0)
// x[0] = centerX-1, x[1] = centerX, x[2] = centerX+1, x[3] = centerX+2
// y[0] = y[1] = y[2] = y[3] = centerY

// kind = 1, status = 1:
// x[0] = x[1] = x[2] = x[3] = centerX
// y[0] = centerY-1, y[1] = centerY, y[2] = centerY+1, y[3] = centerY+2


// kind = 2, status = 0: start_center(5, 0)
// x[0] = x[1] = centerX-1, x[2] = centerX, x[3] = centerX+1
// y[0] = centerY-1, y[1] = y[2] = y[3] = centerY

// kind = 2, status = 1:
// x[0] = centerX-1, x[1] = x[2] = x[3] = centerX
// y[0] = y[1] = centerY+1, y[2] = centerY, y[3] = centerY-1

// kind = 2, status = 2:
// x[0] = x[1] = centerX+1, x[2] = centerX, x[3] = centerX-1
// y[0] = centerY, y[1] = y[2] = y[3] = centerY-1

// kind = 2, status = 3:
// x[0] = centerX, x[1] = x[2] = x[3] = centerX-1
// y[0] = y[1] = centerY-1, y[2] = centerY, y[3] = centerY+1


// kind = 3, status = 0: start_center(5, 0)
// x[0] = centerX, x[1] = centerX-1, x[2] = centerX, x[3] = centerX+1
// y[0] = centerY, y[1] = centerY, y[2] = centerY-1, y[3] = centerY

// kind = 3, status = 1:
// x[0] = centerX, x[1] = centerX, x[2] = centerX-1, x[3] = centerX
// y[0] = centerY, y[1] = centerY+1, y[2] = centerY, y[3] = centerY-1

// kind = 3, status = 2:
// x[0] = centerX, x[1] = centerX+1, x[2] = centerX, x[3] = centerX-1
// y[0] = centerY, y[1] = centerY, y[2] = centerY+1, y[3] = centerY

// kind = 3, status = 3:
// x[0] = centerX, x[1] = centerX, x[2] = centerX+1, x[3] = centerX
// y[0] = centerY, y[1] = centerY-1, y[2] = centerY, y[3] = centerY+1


// kind = 4, status = 0: start_center(5, 0)
// x[0] = centerX-1, x[1] = x[2] = centerX, x[3] = centerX+1
// y[0] = y[1] = centerY, y[2] = y[3] = centerY-1

// kind = 4, status = 1:
// x[0] = x[1] = centerX, x[2] = x[3] = centerX-1
// y[0] = centerY+1, y[1] = y[2] = centerY, y[3] = centerY-1


// kind = 5, status = 0: start_center(5, 0)
// x[0] = centerX, x[1] = x[2] = centerX-1, x[3] = centerX
// y[0] = y[1] = centerY, y[2] = y[3] = centerY-1

















