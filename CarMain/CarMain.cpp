#include "console.h"
using namespace cio;

struct Object
{
    int x;
    int y;
    Object(int _x, int _y)
    {
        x = _x;
        y = _y;
    }
};

void drawCar(int,int);
void drawHouse(int,int);
void drawTree(int,int);
void drawTruck(int,int);

int main()
{
    const int r = console.getRows();
    const int c = console.getCols();
    int i = 0;
    int  truckCode    = 0; // up up down right enter
    bool truckEnabled = false;

    Object  car  (0,   r-4);
    Object  house(400, r-9);
    Object  truck(0,   r-8);

    Object* tree[20] = {'\0'};
    tree[0] = new Object(26, r-5);
    tree[1] = new Object(54, r-5);
    tree[2] = new Object(68, r-5);
    tree[3] = new Object(100, r-5);
    tree[4] = new Object(-23, r-5);
    tree[5] = new Object(156, r-5);
    tree[6] = new Object(127, r-5);
    tree[7] = new Object(159, r-5);
    tree[8] = new Object(170, r-5);
    tree[9] = new Object(179, r-5);
    tree[10] = new Object(380, r-5);
    tree[11] = new Object(393, r-5);
    tree[12] = new Object(415, r-5);

    int key  = 0;

    bool running = true;
    while(running)
    {
        console.clear();
        drawHouse(house.x, house.y);
        for (i = 0; tree[i]; i++)
            drawTree(tree[i]->x, tree[i]->y);

        switch (truckEnabled)
        {
        case false:
            drawCar(car.x, car.y);
            break;
        case true:
            drawTruck(car.x, truck.y);
            break;
        }

        key = console.getKey();
        switch(key)
        {
        case RIGHT:
            car.x++;
            if (truckCode == 3)
                truckCode++;
            else
                truckCode = 0;
            break;
        case LEFT:
            car.x--;
            break;
        case UP:
            if (truckCode < 2)
                truckCode++;
            else
                truckCode = 0;
            break;
        case DOWN:
            if (truckCode == 2)
                truckCode++;
            else
                truckCode = 0;
            break;
        case ENTER:
            if (truckCode == 4)
                truckEnabled = true;
            else
                truckCode = 0;
            break;
        case 'a':
            truckEnabled = false;
            break;
        default:
            truckCode = 0;
        }

        if (car.x > c-28 )
        {
            car.x = c-28;
            house.x--;
            for (i = 0; tree[i]; i++)
                tree[i]->x--;
        }
        if (car.x < 0)
        {
            car.x = 0;
            house.x++;
            for (i = 0; tree[i]; i++)
                tree[i]->x++;
        }
    }

    return 0;
}

void drawCar(int c, int r)
{
    console.display("_____",   r, c+3);
    console.display("_/_| |_\\___",  r+1, c+1);
    console.display("|_____|__|__|",   r+2, c);
    console.display("\\_/   \\_/", r+3, c+2);
}

void drawHouse(int c, int r)
{
    console.display("/\\", r, c+5);
    console.display("/  \\", r+1, c+4);
    console.display("/\\/ ++ \\", r+2, c+1);
    console.display("/__\\_____\\/\\", r+3, c);
    console.display("|  |     /__\\", r+4, c);
    console.display("| _|  __ |  |", r+5, c);
    console.display("||=  |  | |=|", r+6, c);
    console.display("||=  |* | |=|", r+7, c);
    console.display("-------------", r+8, c);
}

void drawTree(int c, int r)
{
    console.display("__", r, c+1);
    console.display("/ +\\", r+1, c);
    console.display("|+ |", r+2, c);
    console.display("\\_=/", r+3, c);
    console.display("||", r+4, c+1);
}

void drawTruck(int c, int r)
{
    console.display("||____", r, c+11);
    console.display("________| |   \\", r+1, c+3);
    console.display("/        | | /  \\", r+2, c+2);
    console.display("/_________| |_____\\_", r+3, c+1);
    console.display("| ===        | -   | |", r+4, c);
    console.display("|____________|_____|_|", r+5, c);
    console.display("\\ \\/ /     \\ \\/ /", r+6, c+2);
    console.display("\\__/       \\__/", r+7, c+3);
}