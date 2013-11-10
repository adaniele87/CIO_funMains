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
    xCoord = 0;
    yCoord = 0;
    frame  = 0;
    speed  = 1; 
}
/* sets Object's coordinates and sets frame to 0 */
Object::Object(int _x, int _y, int _speed)
{
    xCoord = _x;
    yCoord = _y;
    frame = 0;
    speed = _speed;
}

/* virtual destructor, does nothing */
Object::~Object(){}

void Object::getInput()
{
    if(GetKeyState(VK_UP) & 0x80)
    {
        for(int i=0;i<speed;moveUp(),i++);
    }
    else if(GetKeyState(VK_DOWN) & 0x80)
    {
        for(int i=0;i<speed;moveDown(),i++);
    }
    else if(GetKeyState(VK_LEFT) & 0x80)
    {
        for(int i=0;i<speed;moveLeft(),i++);
    }
    else if(GetKeyState(VK_RIGHT) & 0x80)
    {
        for(int i=0;i<speed;moveRight(),i++);
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
void Object::moveLeft() { xCoord--; frame++; }
void Object::moveRight(){ xCoord++; frame++; }
void Object::moveUp()   { yCoord--; }
void Object::moveDown() { yCoord++; }