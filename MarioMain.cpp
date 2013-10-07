#include "console.h"
using namespace cio;

const int FPS = 15;

class Object
{
    int xCoord;
    int yCoord;
    int frame;
public:
    Object(int _x, int _y)
    {
        xCoord = _x;
        yCoord = _y;
        frame = 0;
    }

    void draw(void (*animation)(int&,int&,int&))
    {
        (*animation)(xCoord, yCoord, frame);
    }

    int x(){ return xCoord; }
    int y(){ return yCoord; }

    void moveLeft() { xCoord--; }
    void moveRight(){ xCoord++; }
    void moveUp()   { yCoord--; }
    void moveDown() { yCoord++; }
};

void marioWalking(int&,int&,int&);

int main()
{
    int r = console.getRows();
    int c = console.getCols();
    int key = 0;
    Object mario(0, r-19);
    
    while (true)
    {
        console.clear();
        mario.draw(marioWalking);
        console >> key;

        switch(key)
        {
        case LEFT:
            mario.moveLeft();
            break;
        case RIGHT:
            mario.moveRight();
            break;
        }
    }
    return 0;
}

void marioWalking(int& c, int& r, int& frame)
{
    (frame>3) && (frame=0);

    int i;
    for (i = 0; i < FPS; i++)
    {
        switch(frame)
        {
        case 0:
        case 2:
            console.display("   _____", r, c);
            console.display("  /     |", r+1, c);
            console.display(" /______|_", r+2, c);
            console.display(" @@@    |", r+3, c);
            console.display("@@ (  * _\\", r+4, c);
            console.display("@@    &&&", r+5, c);
            console.display(" |______|", r+6, c);
            console.display(" |       \\", r+7, c);
            console.display(" |       |", r+8, c);
            console.display(" |       |", r+9, c);
            console.display(" |   __  |", r+10, c);
            console.display(" |  /  \\ |", r+11, c);
            console.display(" |  \\__/ /", r+12, c);
            console.display(" --------", r+13, c);
            console.display(" |      |", r+14, c);
            console.display(" \\      /", r+15, c);
            console.display("  |     |", r+16, c);
            console.display("  |_____|___", r+17, c);
            console.display("  |________/", r+18, c);
            break;
        case 1:
            console.display("   _____", r, c);
            console.display("  /     |", r+1, c);
            console.display(" /______|_", r+2, c);
            console.display(" @@@    |", r+3, c);
            console.display("@@ (  * _\\", r+4, c);
            console.display("@@    &&&", r+5, c);
            console.display(" |______|", r+6, c);
            console.display(" |       \\", r+7, c);
            console.display(" |       |", r+8, c);
            console.display(" |       |", r+9, c);
            console.display(" | __    |", r+10, c);
            console.display(" |/  \\   |", r+11, c);
            console.display(" |\\__/   /", r+12, c);
            console.display(" --------", r+13, c);
            console.display(" |       \\", r+14, c);
            console.display(" \\        \\", r+15, c);
            console.display("  |  |     |", r+16, c);
            console.display(" /__ |_____|___", r+17, c);
            console.display(" \\___|________/", r+18, c);
            break;
        case 3:
            console.display("   _____", r, c);
            console.display("  /     |", r+1, c);
            console.display(" /______|_", r+2, c);
            console.display(" @@@    |", r+3, c);
            console.display("@@ (  * _\\", r+4, c);
            console.display("@@    &&&", r+5, c);
            console.display(" |______|", r+6, c);
            console.display(" |       \\", r+7, c);
            console.display(" |       |", r+8, c);
            console.display(" |       |", r+9, c);
            console.display(" |     __|", r+10, c);
            console.display(" |    /  \\", r+11, c);
            console.display(" |    \\__/", r+12, c);
            console.display(" --------", r+13, c);
            console.display(" |       |", r+14, c);
            console.display(" |      / \\", r+15, c);
            console.display(" |     |   \\", r+16, c);
            console.display(" |_____|___ \\___", r+17, c);
            console.display(" |________/____/", r+18, c);
            break;
        }
    }
    frame++;
}