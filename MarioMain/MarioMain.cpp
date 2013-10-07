#include "animations.h"
#include "console.h"
#include "object.h"
using namespace cio;

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