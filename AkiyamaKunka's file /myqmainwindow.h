#ifndef MYQMAINWINDOW_H
#define MYQMAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QToolBar>
#include <QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QDockWidget>
#include <QTextEdit>
#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <QColorDialog>
#include <QFileDialog>
#include <QString>
#include <QListWidgetItem>
#include <QStringList>
#include <QDir>
#include <QTreeWidgetItem>
#include "mylabel.h"
#include <QTimer>
#include <QPainter>
#include <QKeyEvent>
#include <time.h>
const int BLOCK_SIZE = 25;
const int COL = 12;//列
const int ROW = 20;//行
const int MARGIN = 5;
struct Border{
    int upBound,downBound,rightBound,leftBound;
};//测量方块的边界

struct BlockPosition{
    int posX;
    int posY;
};//方块坐标

enum Direction{
    UP,DOWN,LEFT,RIGHT,SPACE
};

QT_BEGIN_NAMESPACE
namespace Ui { class myQMainWindow; }
QT_END_NAMESPACE

class myQMainWindow : public QMainWindow
{
    Q_OBJECT

private:
    int gameArea[ROW][COL]; //1是运动的方块，2是不动
    BlockPosition blockPos; //当前方块的坐标
    int nextBlock[4][4]; // 下一个方块的形状
    int curBlock[4][4]; //当前方块形状
    Border curBorder; //当前方块的边界
    bool stabled; //方块是否稳定了
    int score; //游戏分数
    int gameTimer;//方块下落的timer
    int paintTimer;//渲染刷新的timer
    int speed;//下落时间间隔
    int refreshFrequency;//刷新时间间隔

public:

    myQMainWindow(QWidget *parent = nullptr);
    ~myQMainWindow();

    void getBorder(int block[4][4],Border &border);//探测方块的边界的，为探测碰撞做准备
    void copyBlock(int fatherBlock[4][4], int subBlock[4][4]);//复制方块

    void initGame();//初始化
    void startGame();//开始游戏
    void gameFinished();//游戏结束
    void createBlock(int block[4][4], int blockId);//创建方块
    void moveBlock(Direction dir); //移动方块
    void resetBlock();//重置方块
    void rotateBlock( int block[4][4]);//旋转方块
    void convertStable( int x, int y); //转化为稳定方块
    bool isCollide(int x, int y, Direction dir); //是否碰撞

    virtual void paintEvent(QPaintEvent *event);    //绘图
    virtual void timerEvent(QTimerEvent *event);    //定时器
    virtual void keyPressEvent(QKeyEvent *event); //键盘



private:
    Ui::myQMainWindow *ui;

};
#endif // MYQMAINWINDOW_H
