#include <Windows.h>
#include "fighter.h"
#include "animations.h"

Fighter::Fighter() : Object()
{
    punching = false;
}
Fighter::Fighter(int x,int y,int s) : Object(x,y,s)
{
    punching = false;
}
void Fighter::getInput()
{
    Object::getInput();
    if (GetKeyState(VK_SPACE) & 0x80)
    {
        punching = true;
        frame=0;
    }
}
void Fighter::draw()
{
    if (!punching)
    {
        Object::draw(walkRight);
    }
    else
    {
        Object::draw(punchRight);
        if(frame > 2)
        {
            punching = false;
            frame = 0;
        }
    }
}