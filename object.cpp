/*********************************************************/
/* Andrew Daniele                  adaniele1@myseneca.ca */
/* October 09, 2013                                      */
/* object.h                                              */
/*                                                       */
/* Object's method definitions.                          */
/*********************************************************/

#include "object.h"

/* sets Object's coordinates and sets frame to 0 */
Object::Object(int _x, int _y)
{
    xCoord = _x;
    yCoord = _y;
    frame = 0;
}

/* virtual destructor, does nothing */
Object::~Object(){}

/* VERY BAD, for now this draws an image to the screen referencing Object's Xcoord, Ycoord, and frame members */
void Object::draw(void (*animation)(int&,int&,int&))
{
    (*animation)(xCoord, yCoord, frame);
}

/* Getters. Return Object's Xcoord or Ycoord */
int Object::x(){ return xCoord; }
int Object::y(){ return yCoord; }

/* Alter Object's coordinates to allow movement on the screen */
void Object::moveLeft() { xCoord--; }
void Object::moveRight(){ xCoord++; }
void Object::moveUp()   { yCoord--; }
void Object::moveDown() { yCoord++; }