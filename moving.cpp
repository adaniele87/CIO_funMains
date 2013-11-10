#include <Windows.h>
#include <iostream>
#include <cstdarg>
#include <conio.h>
#include "console.h"
#include "fighter.h"
#include "animations.h"
using namespace cio;

void testCollision(Object&, int = console.getCols()-1, int = console.getRows()-1);
void moveEnemyClose(Object&, Object&);
bool tooClose(Object&, Object&);
bool contact(Object&, Object&);
bool foundOat(Object&, Object&);

int main() 
{
    bool done = false;
    char gameOver[40] = "You Died! Score: ";
    int Ticks = GetTickCount();
    srand(Ticks);
    int rMove =1;
    int r = console.getRows()-1;
    int c = console.getCols()-1;
    int score = 0;

    Object mover(c/2,r/2);
    Object mover2(c,0);
    Object mover3(0,r);
    Object mover4(c,r);
    Object me(0,0);
    Object Oat(rand()%c, rand()%r);

    int slowDown = 0;
    int i = 20;
    while(!done)
    {
        Ticks = GetTickCount();
        console.clear();
        mover.draw(character);
        mover2.draw(character);
        mover3.draw(character);
        mover4.draw(character);
        me.draw(character);
        Oat.draw(oat);

        me.getInput();

        if (i==20)
        {
            srand(Ticks);
            rMove = rand()%5;
            i=0;
        }
        if (slowDown == 2)
        {
            switch (rMove)
            {
            default:
                if (!tooClose(mover, me)) mover.moveUp();
                if (!tooClose(mover2, me)) mover2.moveRight();
                if (!tooClose(mover3, me)) mover3.moveLeft();
                if (!tooClose(mover4, me)) mover4.moveDown();
                break;
            case 2:
                if (!tooClose(mover, me)) mover.moveRight();
                if (!tooClose(mover2, me)) mover2.moveUp();
                if (!tooClose(mover3, me)) mover3.moveRight();
                if (!tooClose(mover4, me)) mover4.moveLeft();
                break;
            case 3:
                if (!tooClose(mover, me)) mover.moveDown();
                if (!tooClose(mover2, me)) mover2.moveLeft();
                if (!tooClose(mover3, me)) mover3.moveDown();
                if (!tooClose(mover4, me)) mover4.moveUp();
                break;
            case 4:
                if (!tooClose(mover, me)) mover.moveLeft();
                if (!tooClose(mover2, me)) mover2.moveDown();
                if (!tooClose(mover3, me)) mover3.moveUp();
                if (!tooClose(mover4, me)) mover4.moveRight();
                break;
            }
            slowDown = 0;
        }
        testCollision(mover);
        testCollision(mover2);
        testCollision(mover3);
        testCollision(mover4);
        testCollision(me);
        
        done = contact(me, mover);
        if(!done) done = contact(me, mover2);
        if(!done) done = contact(me, mover3);
        if(!done) done = contact(me, mover4);
        
        if (contact(me, Oat))
        {
            Oat.x(rand()%c);
            Oat.y(rand()%r);
            score++;
        }

        i++;
        slowDown++;
        
        if (1000/60 > GetTickCount()-Ticks)
        {
            Sleep(1000/60-(GetTickCount()-Ticks));
        }
    }
    console.clear();
    console.display("YOU DIED! score: ", r/2, c/2/4);
    std::cout << score;
    while(true);
}

bool contact(Object& player, Object& enemy)
{
    return player.x() == enemy.x() && player.y() == enemy.y();
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
    if(me.x() > enemy.x()) enemy.moveRight();
    if(me.x() < enemy.x()) enemy.moveLeft();
    if(me.y() > enemy.y()) enemy.moveDown();
    if(me.y() < enemy.y()) enemy.moveUp();
}

bool tooClose(Object& enemy, Object& me)
{
    if ((me.x() > enemy.x() - 20) &&
        (me.x() < enemy.x() + 20) &&
        (me.y() > enemy.y() - 20) &&
        (me.y() < enemy.y() + 20))
    {
        moveEnemyClose(enemy, me);
        return true;
    }
    else return false;
}