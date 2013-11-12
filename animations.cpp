/*********************************************************/
/* Andrew Daniele                  adaniele1@myseneca.ca */
/* October 09, 2013                                      */
/* animations.cpp                                        */
/*                                                       */
/* write all your animation definitions here             */
/*********************************************************/
#include "animations.h"
#include "console.h"
using namespace cio;

void car(int& c, int& r, int& f)
{
    console.display("_____",   r, c+3);
    console.display("_/_| |_\\___",  r+1, c+1);
    console.display("|_____|__|__|",   r+2, c);
    console.display("\\_/   \\_/", r+3, c+2);
}

void character(int& c, int& r, int& f)
{
    switch(f)
    {
    default:
        console.display("^^", r, c);
        console.display("^^", r+1, c);  
        break;
    case 2:
        console.display(">>", r, c);
        console.display(">>", r+1, c); 
        break;
    case 3:
        console.display("VV", r, c);
        console.display("VV", r+1, c); 
        break;
    case 4:
        console.display("<<", r, c);
        console.display("<<", r+1, c); 
        break;
    }
}
void zombie(int& c, int& r, int& f)
{
    switch(f)
    {
    default:
    case 1:
    case 2:
        console.display("(}", r, c);
        console.display("|^", r+1, c);  
        break;
    case 3:
    case 4:
        console.display("{)", r, c);
        console.display("^|", r+1, c); 
        break;
    }
}

void oat(int& c, int& r, int& f)
{
    console.display("OO", r, c);
    console.display("OO", r+1, c);
}

void house(int& c, int& r, int& f)
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

void marioWalk(int& c, int& r, int& f)
{
    (f>3) && (f=0);

    int i;
    for (i = 0; i < DRAWRATE; i++)
    {
        switch(f)
        {
        case 0:
        case 2:
            console.display("_____", r, c+3);
            console.display("/     |", r+1, c+2);
            console.display("/______|_", r+2, c+1);
            console.display("@@@    |", r+3, c+1);
            console.display("@@ (  * _\\", r+4, c);
            console.display("@@    &&&", r+5, c);
            console.display("|______|", r+6, c+1);
            console.display("|       \\", r+7, c+1);
            console.display("|       |", r+8, c+1);
            console.display("|       |", r+9, c+1);
            console.display("|   __  |", r+10, c+1);
            console.display("|  /  \\ |", r+11, c+1);
            console.display("|  \\__/ /", r+12, c+1);
            console.display("--------", r+13, c+1);
            console.display("|      |", r+14, c+1);
            console.display("\\      /", r+15, c+1);
            console.display("|     |", r+16, c+2);
            console.display("|_____|___", r+17, c+2);
            console.display("|________/", r+18, c+2);
            break;
        case 1:
            console.display("_____", r, c+3);
            console.display("/     |", r+1, c+2);
            console.display("/______|_", r+2, c+1);
            console.display("@@@    |", r+3, c+1);
            console.display("@@ (  * _\\", r+4, c);
            console.display("@@    &&&", r+5, c);
            console.display("|______|", r+6, c+1);
            console.display("|       \\", r+7, c+1);
            console.display("|       |", r+8, c+1);
            console.display("|       |", r+9, c+1);
            console.display("| __    |", r+10, c+1);
            console.display("|/  \\   |", r+11, c+1);
            console.display("|\\__/   /", r+12, c+1);
            console.display("--------", r+13, c+1);
            console.display("|       \\", r+14, c+1);
            console.display("\\        \\", r+15, c+1);
            console.display("|  |     |", r+16, c+2);
            console.display("/__ |_____|___", r+17, c+1);
            console.display("\\___|________/", r+18, c+1);
            break;
        case 3:
            console.display("_____", r, c+3);
            console.display("/     |", r+1, c+2);
            console.display("/______|_", r+2, c+1);
            console.display("@@@    |", r+3, c+1);
            console.display("@@ (  * _\\", r+4, c);
            console.display("@@    &&&", r+5, c);
            console.display("|______|", r+6, c+1);
            console.display("|       \\", r+7, c+1);
            console.display("|       |", r+8, c+1);
            console.display("|       |", r+9, c+1);
            console.display("|     __|", r+10, c+1);
            console.display("|    /  \\", r+11, c+1);
            console.display("|    \\__/", r+12, c+1);
            console.display("--------", r+13, c+1);
            console.display("|       |", r+14, c+1);
            console.display("|      / \\", r+15, c+1);
            console.display("|     |   \\", r+16, c+1);
            console.display("|_____|___ \\___", r+17, c+1);
            console.display("|________/____/", r+18, c+1);
            break;
        }
    }
    f++;
}

void tree(int& c, int& r, int& f)
{
    console.display("__", r, c+1);
    console.display("/ +\\", r+1, c);
    console.display("|+ |", r+2, c);
    console.display("\\_=/", r+3, c);
    console.display("||", r+4, c+1);
}

void truck(int& c, int& r, int& f)
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
