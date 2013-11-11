#include <Windows.h>
#include <iostream>
#include "console.h"
#include "object.h"
#include "animations.h"
using namespace cio;

void testCollision(Object&, int = console.getCols()-1, int = console.getRows()-1);
void moveEnemyClose(Object&, Object&);
bool tooClose(Object&, Object&);
bool contact(Object&, Object&);
bool foundOat(Object&, Object&);

const int slowEnemyBy  = 4; // slows down enemy
const int slowPlayerBy = 2; // slows down player
const int FPS          = 60; // regulate frames
const int showScore1ln = 6; // how long to show float-away score on one line
const int showScorexln = 4; // how many lines to show float-away score

int main() 
{
    bool done = false;
    char gameOver[40] = "You Died! Score: ";
    int oatWorth = 300;
    int Ticks = GetTickCount();
    srand(Ticks);
    int rMove =1;
    int r = console.getRows()-2;
    int c = console.getCols()-2;
    int score = 0;
    int lastScore = 0;
    int displayTimes  = 3;
    int displayTimes2 = 0;

    Object mover(c/2,r/2);
    Object mover2(c,0);
    Object mover3(0,r);
    Object mover4(c,r);
    Object me(0,0);
    Object Oat(rand()%c, rand()%r);
    Object ScoreDisplay(0,0);

    int slowDownEnemy = 0;
    int slowDownPlayer = 0;
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

        if (lastScore > 0)
        {
            if (displayTimes == showScore1ln)
            {
                console.setPos(ScoreDisplay.y(), ScoreDisplay.x());
                std::cout << lastScore;
                displayTimes--;
            }
            else
            {
                ScoreDisplay.x()++;
                ScoreDisplay.y()--;
                displayTimes2--;
                displayTimes = showScore1ln;
            }
        }
        else
            displayTimes2 = showScorexln;

        if (!displayTimes2)
        {
            lastScore = 0;
            displayTimes = showScore1ln;
        }

        if (slowDownPlayer == slowPlayerBy)
        {
            me.getInput();
            slowDownPlayer = 0;
        }

        if (i==20)
        {
            srand(Ticks);
            rMove = rand()%5;
            i=0;
        }
        if (slowDownEnemy == slowEnemyBy)
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
            slowDownEnemy = 0;
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
            ScoreDisplay.x() = Oat.x();
            ScoreDisplay.y() = Oat.y();
            Oat.x(rand()%c);
            Oat.y(rand()%r);
            score+=oatWorth;
            if (oatWorth > 200) console.alarm();
            lastScore = oatWorth;
            oatWorth = 300;
        }

        i++;
        slowDownEnemy++;
        slowDownPlayer++;
        oatWorth--;
        if (oatWorth < 0) oatWorth = 0;

        if (1000/FPS > GetTickCount()-Ticks)
        {
            Sleep(1000/FPS-(GetTickCount()-Ticks));
        }
    }
    console.clear();
    console.display("YOU DIED! score: ", r/2, c/2/4);
    std::cout << score;
    getchar();
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