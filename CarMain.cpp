#include "animations.h"
#include "console.h"
#include "object.h"
using namespace cio;

int main()
{
    bool running = true;
    int c = console.getCols();
    int i = 0;
    int r = console.getRows();
    int key = 0;

    Object  Car  (0,   r-4);
    Object  House(400, r-9);
    Object  Truck(0,   r-8);

    Object* Tree[20] = {'\0'};
    Tree[0]  = new Object(26,  r-5);
    Tree[1]  = new Object(54,  r-5);
    Tree[2]  = new Object(68,  r-5);
    Tree[3]  = new Object(100, r-5);
    Tree[4]  = new Object(-23, r-5);
    Tree[5]  = new Object(156, r-5);
    Tree[6]  = new Object(127, r-5);
    Tree[7]  = new Object(159, r-5);
    Tree[8]  = new Object(170, r-5);
    Tree[9]  = new Object(179, r-5);
    Tree[10] = new Object(380, r-5);
    Tree[11] = new Object(393, r-5);
    Tree[12] = new Object(415, r-5);

    while (running)
    {
        console.clear();
        
        //draws all images
        House.draw(house);
        for (i = 0; Tree[i]; i++)
        {
            Tree[i]->draw(tree);
        }
        Car.draw(car);

        key = console.getKey();

        switch(key)
        {
        case RIGHT:
            if (Car.x() <= c-28)
            {
                Car.moveRight();
            }
            else
            {
                for (i = 0; Tree[i]; i++)
                {
                    Tree[i]->moveLeft();
                }
                House.moveLeft();
            }
            break;

        case LEFT:
            if (Car.x() >= 0)
            {
                Car.moveLeft();
            }
            else
            {
                for (i = 0; Tree[i]; i++)
                {
                    Tree[i]->moveRight();
                }
                House.moveRight();
            }
            break;

        }
    }
    return 0;
}