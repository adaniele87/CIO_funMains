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
    int speed;
protected:
    int frame;
public:
    Object();
    Object(int _x, int _y, int _speed = 1);
    virtual ~Object();

    virtual void draw(void (*animation)(int&,int&,int&));

    void getInput();

    int& x(int r = -1);
    int& y(int c = -1);

    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
};