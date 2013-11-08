/*********************************************************/
/* Andrew Daniele                  adaniele1@myseneca.ca */
/* October 09, 2013                                      */
/* object.h                                              */
/*                                                       */
/* For the time being, an object holds X and Y           */
/* coordinates of where it is in the console window and  */
/* the current frame of the main animation (ie. walking).*/
/* An object can draw an animation and move in the four  */
/* directions: up, down, left, right.                    */
/*********************************************************/

class Object
{
    int xCoord;
    int yCoord;
    int frame;
public:
    Object(int _x, int _y);
    virtual ~Object();

    void draw(void (*animation)(int&,int&,int&));

    int& x(int r = -1);
    int& y(int c = -1);

    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
};