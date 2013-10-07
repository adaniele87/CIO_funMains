class Object
{
    int xCoord;
    int yCoord;
    int frame;
public:
    Object(int _x, int _y);

    void draw(void (*animation)(int&,int&,int&));

    int x();
    int y();

    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
};