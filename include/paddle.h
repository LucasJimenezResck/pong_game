#ifndef paddle_H
#define paddle_H
#include <iostream>

class Paddle
{
private:
    int currentX, currentY;
    int originalX, originalY;
public:
    Paddle();
    Paddle(int posX, int posY);
    inline void Reset(){ currentX = originalX; currentY = originalY;};
    int getCurrentX();
    int getCurrentY();
    void moveUp();
    void moveDown();
    friend std::ostream& operator<<(std::ostream & o, const Paddle& c);
};
#endif