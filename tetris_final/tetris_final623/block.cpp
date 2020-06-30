#include "block.h"

Block::Block(int kind)
{
    block_kind = kind;
    block_status = 0;
    is_dropping = 0;

    centerX = block_kind==1 ? 4 : 5;
    centerY = 0;

    get_coordinates();
}

void Block::get_coordinates()
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

Block Block::move_left()
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

Block Block::move_right()
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

Block Block::move_down()
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

Block Block::rotate()
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



