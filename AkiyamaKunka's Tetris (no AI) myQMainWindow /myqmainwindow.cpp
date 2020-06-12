#include "myqmainwindow.h"
#include "ui_myqmainwindow.h"




//方块的样子
int squareItem1[4][4] =
{
    {0,0,0,0},
    {0,1,1,0},
    {0,1,1,0},
    {0,0,0,0}
};
//田
int squareItem2[4][4] =
{
    {0,1,0,0},
    {0,1,0,0},
    {0,1,1,0},
    {0,0,0,0}
};

//左L
int squareItem3[4][4] =
{
    {0,0,1,0},
    {0,0,1,0},
    {0,1,1,0},
    {0,0,0,0}
};
//右L

int squareItem4[4][4] =
{
    {0,1,0,0},
    {0,1,1,0},
    {0,0,1,0},
    {0,0,0,0}
};
//左S


int squareItem5[4][4] =
{
    {0,0,1,0},
    {0,1,1,0},
    {0,1,0,0},
    {0,0,0,0}
};
//右S


int squareItem6[4][4] =
{
    {0,0,1,0},
    {0,0,1,0},
    {0,0,1,0},
    {0,0,1,0}
};
//长条


int squareItem7[4][4] =
{
    {0,0,0,0},
    {0,0,1,0},
    {0,1,1,1},
    {0,0,0,0}
};
//土



myQMainWindow::myQMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::myQMainWindow)
{
    //ui->setupUi(this);

    QMenuBar * bar = menuBar();
    bar->setNativeMenuBar(false);
    setMenuBar(bar);

    QMenu * menuFile = bar->addMenu("File");
    QMenu * menuCreat = bar->addMenu("Creat");
    bar->addSeparator();

    QAction * actionName = menuCreat->addAction("Name");
    QAction * actionOpne = menuCreat->addAction("Open");


    QToolBar * toolBar = new QToolBar(this);
    addToolBar(Qt::LeftToolBarArea,toolBar);
    toolBar->setFloatable(false);
    toolBar->setAllowedAreas(Qt::RightToolBarArea| Qt::LeftToolBarArea);
    toolBar->addAction(actionName);
    toolBar->addAction(actionOpne);
    toolBar->addSeparator();

    QPushButton * btn = new QPushButton("Start",this);
    toolBar->addWidget(btn);

    QStatusBar * stBar = statusBar();
    setStatusBar(stBar);

    QLabel * label = new QLabel ("提示信息",this);
    stBar->addWidget(label);
    QLabel *label2 = new QLabel("右侧提示信息",this);
    stBar->addPermanentWidget(label2);

    QDockWidget * dockWidget = new QDockWidget("浮动",this);
    addDockWidget(Qt::BottomDockWidgetArea,dockWidget);
    dockWidget->setAllowedAreas(Qt::BottomDockWidgetArea| Qt::TopDockWidgetArea);

    QTextEdit *edit = new QTextEdit(this);
    setCentralWidget(edit);

    ui->setupUi(this);
    ui->actioncreat->setIcon(QIcon("://bmk_8451-65261922_p0.png"));
    ui->actionopen->setIcon(QIcon(":/aFileForParadox/Screen Shot 2020-06-04 at 07.31.05.png"));

    connect(ui->actioncreat,&QAction::triggered,[=](){
        //        QDialog dlg(this);
        //        dlg.resize(200,100);
        //        dlg.exec();
        //        qDebug() << "模态对话框弹出";

        //        QDialog * dlg2 = new QDialog(this);
        //        dlg2->resize(200,100);
        //        dlg2->show();
        //        dlg2->setAttribute((Qt::WA_DeleteOnClose));
        //        qDebug() << "another nonModel ejected";
        //        QMessageBox::critical(this,"critical","mistake");
        //        if(QMessageBox::Save == QMessageBox::question(this,"inf","information",QMessageBox::Save|QMessageBox::Cancel) ){
        //            qDebug() << "you clicked SAVE";
        //        }
        //        else{
        //            qDebug() << "you clicked CANCEL";
        //        }
        //        QMessageBox::warning(this,"warning","WARNING");

        //        QColor color = QColorDialog::getColor(QColor(255,0,0));
        //        qDebug() << "r =" << color.red() << " g = " << color.green() <<" blue =" << color.blue();

        QString str = QFileDialog::getOpenFileName(this,"openFile","/Users/robertwong/Desktop");
        qDebug() << str;
    });
    ui->radioButton_2->setChecked(true);

    //    connect (ui->radioButton_3 ,&QRadioButton::clicked,[=](bool state){

    //        if(state){
    //            state = !state;
    //            qDebug() <<"you motherfucker!" << " "<< state;
    //        }

    //    });

    QListWidgetItem * item = new QListWidgetItem("I have a pen");
    //ui->listWidget->addItem(item);
    item->setTextAlignment(Qt::AlignHCenter);
    resize(1200,800);
    QStringList list;
    list << "I hava an apple" << "Uh! Apple pen!" << " I have a pencil";

    //ui->listWidget->addItems(list);
    ui->treeWidget->setHeaderLabels(QStringList() << "Hero" << "Introduction to heros");

    QTreeWidgetItem * liItem1 = new QTreeWidgetItem(QStringList()<<"Strength");
    QTreeWidgetItem * liItem2 = new QTreeWidgetItem(QStringList()<<"Speed");
    QTreeWidgetItem * liItem3 = new QTreeWidgetItem(QStringList()<<"Intelligence");
    ui->treeWidget->addTopLevelItem(liItem1);
    ui->treeWidget->addTopLevelItem(liItem2);
    ui->treeWidget->addTopLevelItem(liItem3);

    QStringList introItem1;
    introItem1 <<"Eye of the Storm" << " She's the controller of strom, daughter of Soul";
    QTreeWidgetItem * pointIntroItem1 = new QTreeWidgetItem(introItem1);

    liItem1->addChild(pointIntroItem1);


    //startTimer(1000);

    QTimer * timer = new QTimer(this);
    timer->start(500);

    connect(timer,&QTimer::timeout,[=](){
        static int num =1;
        ui->label_4->setText( QString::number(num++) );
    });

    connect(ui->pushButton_3,&QPushButton::clicked,[=](){
        timer->stop();
    });

    connect(ui->pushButton_4, &QPushButton::clicked,[=](){
        timer->start();
    });


}



void myQMainWindow::getBorder(int block[4][4], Border &border){

    for (int i = 0; i< 4; ++i)
        for (int j = 0; j < 4; ++j)
            if( block[i][j] == 1){
                border.downBound = i;
                break;
            }
    //以左下角为00点，开始进行扫描 记录最下一行的行数

    for (int i = 0; i< 4; ++i)
        for (int j = 0; j < 4; ++j)
            if( block[j][i] == 1){
                border.leftBound = i;
                break;
            }

    for (int i = 3; i>= 0; --i)
        for (int j = 0; j < 4; ++j)
            if( block[i][j] == 1){
                border.upBound = i;
                break;
            }
    for (int i = 3; i>= 0; --i)
        for (int j = 0; j < 4; ++j)
            if( block[j][i] == 1){
                border.rightBound = i;
                break;
            }

}



inline void copyBlock(int fatherBlock[4][4], int subBlock[4][4]){
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            subBlock[i][j] = fatherBlock[i][j];
}


void myQMainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    //绘制边框
    painter.setBrush(QBrush(Qt::white, Qt::SolidPattern));
    painter.drawRect(MARGIN,MARGIN,COL*BLOCK_SIZE,ROW*BLOCK_SIZE);

    //绘制下一个方块
    painter.setBrush(QBrush(Qt::blue,Qt::SolidPattern));
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            if( nextBlock[i][j] == 1)
                painter.drawRect(MARGIN*3+COL*BLOCK_SIZE+BLOCK_SIZE*j,MARGIN+i*BLOCK_SIZE,BLOCK_SIZE,BLOCK_SIZE);


    //绘制分数
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial",14) );
    painter.drawText(QRect(MARGIN*3+COL*BLOCK_SIZE,MARGIN*2+BLOCK_SIZE*4,BLOCK_SIZE*4,BLOCK_SIZE*4),Qt::AlignCenter,"Score: "+QString::number(score) );


    //绘制方块
    for( int i = 0; i< ROW; ++i)
        for (int j = 0; j < COL; ++j ){
            if( gameArea[i][j] ==1){
                painter.setBrush(QBrush(Qt::red,Qt::SolidPattern));
                painter.drawRect(MARGIN+j*BLOCK_SIZE,MARGIN+i*BLOCK_SIZE,BLOCK_SIZE,BLOCK_SIZE);
            }

            else if( gameArea[i][j] ==2){
                painter.setBrush(QBrush(Qt::green,Qt::SolidPattern));
                painter.drawRect(MARGIN+j*BLOCK_SIZE,MARGIN+i*BLOCK_SIZE,BLOCK_SIZE,BLOCK_SIZE);
            }
        }
}

void myQMainWindow::timerEvent(QTimerEvent *event){ //再研究一下这波
    if(event->timerId() == gameTimer)
        moveBlock(DOWN);//让方块下落
    if(event->timerId() == paintTimer)
        update();//使得方块更新
}

void myQMainWindow::keyPressEvent(QKeyEvent *event){
    switch (event->key()) {
    case Qt::Key_Up:
        moveBlock(UP);
        break;
    case Qt::Key_Down:
        moveBlock(DOWN);
        break;
    case Qt::Key_Left:
        moveBlock(LEFT);
        break;
    case Qt::Key_Right:
        moveBlock(RIGHT);
        break;
    case Qt::Key_Space:
        moveBlock(SPACE);
        break;
    default:
        break;
    }
}


void myQMainWindow::createBlock(int (*block)[4], int blockId){
    switch (blockId) {
    case 0:
        copyBlock(block,squareItem1);
        break;
    case 1:
        copyBlock(block,squareItem2);
        break;
    case 2:
        copyBlock(block,squareItem3);
        break;
    case 3:
        copyBlock(block,squareItem4);
        break;
    case 4:
        copyBlock(block,squareItem5);
        break;
    case 5:
        copyBlock(block,squareItem6);
        break;
    case 6:
        copyBlock(block,squareItem7);
        break;
    default:
        break;
    }
}

void myQMainWindow::initGame(){
    for (int i =0 ;i<ROW; ++i)
        for( int j = 0; j< COL; ++j)
            gameArea[i][j]=0;
    speed =800;
    refreshFrequency = 30;//单位都是毫秒
    srand(time(0)); //用当前时间来初始化这个生成随机种子的函数
    score = 0;
    startGame();
}

void myQMainWindow::resetBlock(){
    copyBlock(nextBlock,curBlock);
    getBorder(curBlock,curBorder);
    //产生现在的方块

    int blockId = rand()%7; //这里会产生7个数字，从0到6
    createBlock(nextBlock,blockId);
    //产生下一个方块


    //左上方为原点 创建初始方块坐标
    BlockPosition startPoint;
    startPoint.posX = COL / 2 - 2;
    startPoint.posY = 0;
    blockPos = startPoint;
}

void myQMainWindow::startGame(){
    gameTimer = startTimer(speed);
    paintTimer = startTimer(refreshFrequency);
    //启动游戏计时器和界面刷新的计时器

    int blockId = rand() % 7;
    createBlock(curBlock,blockId);
    resetBlock();
}

void myQMainWindow::gameFinished(){
    //停止计时器们
    killTimer(gameTimer);
    killTimer(paintTimer);
    QMessageBox::information(this, "failed","GameOver");
}

void myQMainWindow::rotateBlock(int (*block)[4]){
    //对这个方块进行逆时针旋转
    int temp[4][4];
    for(int i = 0; i < 4; ++i)
        for(int j = 0; j < 4; ++j)
            temp[j-3][i] = block[i][j];
    for(int i = 0; i < 4; ++i)
        for(int j = 0; j < 4; ++j)
            block[i][j] = temp[i][j];
}

void myQMainWindow::convertStable(int x, int y){
    for(int i = curBorder.upBound; i < curBorder.downBound; ++i)
        for(int j = curBorder.leftBound; j < curBorder.rightBound; ++j)
            if(curBlock[i][j] == 1)
                gameArea[y+i][x+j] = 2;

}

bool myQMainWindow::isCollide(int x, int y, Direction dir){
    int tempBlock[4][4];
    Border tempBorder;
    copyBlock(curBlock,tempBlock);
    getBorder(tempBlock,tempBorder);
    //用两个临时变量储存现在方块的形状和边界信息

    switch(dir){
    case UP:
        rotateBlock(tempBlock);
        getBorder(tempBlock,tempBorder);
        break;
    case DOWN:
        ++y;
        break;
    case LEFT:
        --x;
        break;
    case RIGHT:
        ++x;
        break;
    default:
        break;
    }

    for(int i = tempBorder.upBound; i <= tempBorder.downBound; ++i)
        for(int j = tempBorder.leftBound; j <= tempBorder.rightBound; ++j)
            if( gameArea[y+i][x+j] == 2 && tempBlock[i][j] == 1|| x + tempBorder.leftBound < 0 || x + tempBorder.rightBound > COL-1)
                return true; //表示这个时候已碰撞上了
            else return false; //没碰上
}

void myQMainWindow::moveBlock(Direction dir){
    switch(dir){
    case UP:
        if(!isCollide( blockPos.posX,blockPos.posY, UP)){
            rotateBlock(curBlock);
            getBorder(curBlock,curBorder);
            //旋转方块并且获取最新的边界

            for(int i=0;i<4;i++)
                for(int j=0;j<4;j++)
                    gameArea[blockPos.posY+i][blockPos.posX+j] = curBlock[i][j];
                //将游戏区域刷新
        }
        break;
    case DOWN:
        if(blockPos.posY+curBorder.downBound == ROW - 1){
            convertStable(blockPos.posX,blockPos.posY);
            resetBlock();
            break;
        }//这个就是直接碰到边界底部了，那么就给他设定成稳定的方块好啦~

        if(isCollide(blockPos.posX,blockPos.posY,DOWN)){
            //这个时候假设向下走一格子，然后发现碰撞了，那么我们就把这个原先
            //的这个方块设定的为稳定方块好啦~
            convertStable(blockPos.posX,blockPos.posY);
            resetBlock();//这里记得一定要重新设定一个新的小方块哟~
            break;//小可爱不要忘记退出哟
        }

        //下面我们开始恢复方块下落一个格后，原先的顶部一行的残留痕迹啦
        for( int j = curBorder.leftBound; j<= curBorder.rightBound; ++j)
            gameArea[blockPos.posY][blockPos.posX+j] = 0;

        blockPos.posY++;//让方块实际下落一个格子
        for(int i =0 ;i<4 ; ++i)
            for(int j = curBorder.leftBound; j <= curBorder.rightBound; ++j)
                if(blockPos.posY+i <= ROW-1 && gameArea[blockPos.posY+i][blockPos.posX+j] != 2)
                    gameArea[blockPos.posY+i][blockPos.posX+j] = curBlock[i][j];
        //这样就更新了游戏方块区域的信息啦~

        break;
    case LEFT:
        if(blockPos.posX+curBorder.leftBound <=0 || isCollide(blockPos.posX,blockPos.posY,LEFT) )
            break;//这里的意思是越过了左边界或者向左一步发生了碰撞 就退出惹

        for(int i = curBorder.upBound; i <= curBorder.downBound; ++i )
            gameArea[blockPos.posY+i][blockPos.posX+3] = 0;
        //消除了向左一个格子后 游戏区域的方格痕迹

        blockPos.posX--;//向左一个位移

        for(int j= 0 ; j< 4;++j)
            for(int i = curBorder.leftBound; i<= curBorder.rightBound; ++i)
                if( blockPos.posX + j >0 && gameArea[blockPos.posY+i][blockPos.posX+j] != 2)
                    gameArea[blockPos.posY+i][blockPos.posX+j] = curBlock[i][j];
        //这样就更新了游戏方块区域的信息啦~
        break;

    case RIGHT:
        if(blockPos.posX+curBorder.rightBound >=COL-1 || isCollide(blockPos.posX,blockPos.posY,RIGHT) )
            break;//这里的意思是越过了right边界或者向right 1 步发生了碰撞 就退出惹

        for(int i = curBorder.upBound; i <= curBorder.downBound; ++i )
            gameArea[blockPos.posY+i][blockPos.posX] = 0;
        //消除了向right一个格子后 游戏区域的方格痕迹

        blockPos.posX++;//向right一个位移

        for(int j= 0 ; j< 4;++j)
            for(int i = curBorder.leftBound; i<= curBorder.rightBound; ++i)
                if( blockPos.posX + j <COL && gameArea[blockPos.posY+i][blockPos.posX+j] != 2)
                    gameArea[blockPos.posY+i][blockPos.posX+j] = curBlock[i][j];
        //这样就更新了游戏方块区域的信息啦~
        break;
        //SPACE我先不写了，实在是想吐,++
    default:
        break;
    }

    //这个时候，我们判断这一行能不能被消除，如果可以被消除，我们就把他们消除掉~(＾－＾)V
    //原理就是让整个行向下移动
int i = ROW-1;
int bingoLineCount = 0;
   //记录消除的行数

while( i>= 1){
    bool isLineFull = true;
    for( int j = 0; j < COL ; ++j)
        if( gameArea[i][j] ==0){
            isLineFull = false;
            i--;
            break;
        }
    if(isLineFull){
        for(int tempI = i; tempI >0 ;tempI--)
            for(int j = 0; j > COL; j++)
                gameArea[tempI][j] = gameArea[tempI-1][j];
        //把上一行的往下挪动一行
        bingoLineCount++;
    }
}
score += bingoLineCount;

for(int j=0;j<COL;j++)
        if(gameArea[0][j]==2) //最顶端也有稳定方块
            gameFinished();


}

































































myQMainWindow::~myQMainWindow()
{
    delete ui;
}

