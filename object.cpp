/*********************************************************/
/* Andrew Daniele                  adaniele1@myseneca.ca */
/* October 09, 2013                                      */
/* object.h                                              */
/*                                                       */
/* Object's method definitions.                          */
/*********************************************************/

#include "object.h"
#include "windows.h"

Object::Object()
{
    xCoord    = 0;
    yCoord    = 0;
    frame     = 0;
}
/* sets Object's coordinates and sets frame to 0 */
Object::Object(int _x, int _y)
{
    xCoord    = _x;
    yCoord    = _y;
    frame     = 0;
}

/* virtual destructor, does nothing */
Object::~Object(){}

void Object::getInput()
{
    if(GetKeyState(VK_UP) & 0x80)
    {
        moveUp();
    }
    if(GetKeyState(VK_RIGHT) & 0x80)
    {
        moveRight();
    }
    if(GetKeyState(VK_DOWN) & 0x80)
    {
        moveDown();
    }
    if(GetKeyState(VK_LEFT) & 0x80)
    {
        moveLeft();
    }
}

void Object::draw(void (*animation)(int& _x, int& _y, int& _f))
{
    (*animation)(xCoord, yCoord, frame);
}

/* Getter + Setter. Return Object's Xcoord or Ycoord */
int& Object::x(int c)
{
    if (c < 0)
    {
        return xCoord;
    }
    else
        xCoord = c;

    return xCoord;
}

int& Object::y(int r)
{
    if (r < 0)
    {
        return yCoord;
    }
    else
        yCoord = r;

    return yCoord;
}

/* Alter Object's coordinates to allow movement on the screen */
void Object::moveLeft(){
    xCoord--;
    setDirection(4);
}
void Object::moveRight(){
    xCoord++;
    setDirection(2);
}
void Object::moveUp()   {
    yCoord--;
    setDirection(1);
}
void Object::moveDown(){
    yCoord++; 
    setDirection(3);
}

void Object::setDirection(int sd) { frame = sd; }

void Object::randMove(int random)
{
    if (frame)
    {
        switch(frame)
        {
        case 1:
            moveUp();
            break;
        case 2:
            moveRight();
            break;
        case 3:
            moveDown();
            break;
        case 4:
            moveLeft();
            break;
        }
    }
    else
    {
        switch(random)
        {
        default:
            moveUp();
            break;
        case 2:
            moveRight();
            break;
        case 3:
            moveDown();
            break;
        case 4:
            moveLeft();
            break;
        }
    }
}