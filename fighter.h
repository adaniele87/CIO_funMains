#include "object.h"

class Fighter : public Object
{
    bool punching;
public:
    Fighter();
    Fighter(int,int,int = 1);
    void getInput();
    void draw();
};