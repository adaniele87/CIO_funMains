#include "object.h"
Object::Object(int _x, int _y)
{
    xCoord = _x;
    yCoord = _y;
    frame = 0;
}

void Object::draw(void (*animation)(int&,int&,int&))
{
    (*animation)(xCoord, yCoord, frame);
}

int Object::x(){ return xCoord; }
int Object::y(){ return yCoord; }

void Object::moveLeft() { xCoord--; }
void Object::moveRight(){ xCoord++; }
void Object::moveUp()   { yCoord--; }
void Object::moveDown() { yCoord++; }