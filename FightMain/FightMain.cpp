#include "console.h"
using namespace cio;

const int FPS  = 250;

const int PUNCH = 100;
const int FALL  = 200;

struct Object
{
    int x;
    int y;
    int frame;
    Object(int _x, int _y)
    {
        x     = _x;
        y     = _y;
        frame =  0;
    }
};

void drawPerson(int,int,int&);
void drawEnemy(int&,int&,int&);

int main()
{
    int r   = console.getRows();
    int c   = console.getCols();
    int key = 0;
    int finishHim = 0; // down right space
    bool finished = false;
    Object person(0, r-3);
    Object enemy(37, r-3);

    bool running = true;
    while(running)
    {
        console.clear();
        drawEnemy(enemy.x, enemy.y, enemy.frame);
        drawPerson(person.x, person.y, person.frame);

        key = console.getKey();

        switch(key)
        {
        case RIGHT:
            person.x++;
            if (finishHim == 1)
                finishHim++;
            break;
        case LEFT:
            person.x--;
            break;
        case SPACE:
            person.frame = PUNCH;
            drawPerson(person.x, person.y, person.frame);
            if (finishHim == 2)
                finishHim++;

            if (person.x == enemy.x-2 && enemy.frame != 1)
            {
                enemy.frame = FALL;
                drawEnemy(enemy.x, enemy.y, enemy.frame);
                finishHim = 5;
            }
            else if (finishHim == 3)
            {
                int i = person.x+1;
                while (i++ < enemy.x)
                {
                    console.clear();
                    drawEnemy(enemy.x, enemy.y, enemy.frame);
                    drawPerson(person.x, person.y, person.frame);
                    for (int j = 0; j < FPS; j++)
                        console.display("=))", person.y, i+1); 
                }
                enemy.frame = FALL;
                drawEnemy(enemy.x, enemy.y, enemy.frame);
                finishHim = 5;
            }
            break;
        case DOWN:
            if (finishHim == 0)
                finishHim++;
            break;
        }
    }

    return 0;
}

void drawPerson(int c, int r, int& frame)
{
    switch(frame)
    {
    case 0:
        console.display("(^}", r, c);
        console.display("|L", r+1, c);
        console.display("||", r+2, c);
        frame++;
        break;
    case 1:
        console.display("(^}", r, c);
        console.display("|L", r+1, c);
        console.display("|\\", r+2, c);
        frame=0;
        break;
    case PUNCH:
        for (int i = 0; i < FPS; i++)
        {
            console.display("(^}", r, c);
            console.display("||=", r+1, c);
            console.display("||", r+2, c);
        }
        frame=0;
        break;
    default:
        frame = 0;
        console.display("(^}", r, c);
        console.display("|L", r+1, c);
        console.display("||", r+2, c);
        frame++;
        break;
    }
}

void drawEnemy(int& c, int& r, int& frame)
{
    switch(frame)
    {
    case 0:
        console.display("{^)", r, c);
        console.display("7|", r+1, c+1);
        console.display("||", r+2, c+1);
        break;
    case 1:
        console.display(">-|0", r, c);
        break;
    case FALL:
        for (int i = 0; i < FPS; i++)
        {
            console.display("{^)", r, c+2);
            console.display("=|=", r+1, c+2);
            console.display("//", r+2, c+2);   
        }
        console.display(">-|0", r+2, c+2);
        r     = r+2;
        c     = c+2;
        frame =   1;
        break;
    default:
        frame = 0;
        break;
    }
}