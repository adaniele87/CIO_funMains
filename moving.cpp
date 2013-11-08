#include <Windows.h>
#include <conio.h>
#include "console.h"
#include "object.h"
#include "animations.h"
using namespace cio;

int speed = 3;

void getInput(Object&);
void testCollision(Object&, int, int);
void moveEnemyClose(Object&, Object&);
bool specialMove(int keyHit = 0, char* str = "UDLR");

int main() 
{
    int Ticks;
    int r = console.getRows()-1;
    int c = console.getCols()-1;

    Object me(0,0);
    Object enemy(c,0);

    while(true)
    {
        Ticks = GetTickCount();
        console.clear();
        me.draw(character);
        enemy.draw(character);

        getInput(me);
        testCollision(me, c, r);
        moveEnemyClose(enemy, me);
        
        if (specialMove()) console.alarm();

        if (1000/30 > GetTickCount()-Ticks)
        {
            Sleep(1000/30-(GetTickCount()-Ticks));
        }
    }
}

void getInput(Object& me)
{
    if(GetKeyState(VK_UP) & 0x80){
        specialMove(VK_UP);
        for(int i=0;i<speed;me.moveUp(),i++);
    }
    else if(GetKeyState(VK_DOWN) & 0x80){
        specialMove(VK_DOWN);
        for(int i=0;i<speed;me.moveDown(),i++);
    }
    else if(GetKeyState(VK_LEFT) & 0x80){
        specialMove(VK_LEFT);
        for(int i=0;i<speed;me.moveLeft(),i++);
    }
    else if(GetKeyState(VK_RIGHT) & 0x80){
        specialMove(VK_RIGHT);
        for(int i=0;i<speed;me.moveRight(),i++);
    }
}

void testCollision(Object& me, int c, int r)
{
    if(me.x() < 0) me.x(0);
    if(me.y() < 0) me.y(0);
    if(me.x() > c) me.x(c);
    if(me.y() > r) me.y(r);
}

void moveEnemyClose(Object& enemy, Object& me)
{
    static int move = 0;
    if(move == 2)
    {
        if(me.x() > enemy.x()) enemy.moveRight();
        if(me.x() < enemy.x()) enemy.moveLeft();
        if(me.y() > enemy.y()) enemy.moveDown();
        if(me.y() < enemy.y()) enemy.moveUp();
        move = 0;
    }   
    move++;
}

bool specialMove(int keyHit, char* str)
{
    static char move[5] = {'X'};

    if (keyHit)
    {
        for (int i=0; i<4; move[i]=move[i+1],i++);
        switch(keyHit)
        {
        case VK_UP:
            move[3] = 'U';
            break;
        case VK_DOWN:
            move[3] = 'D';
            break;
        case VK_LEFT:
            move[3] = 'L';
            break;
        case VK_RIGHT:
            move[3] = 'R';
            break;
        }
    }

    return !strcmp(move, str);
}