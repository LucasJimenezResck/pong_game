#ifndef ball_H
#define ball_H
#include <iostream>
#include "../include/GlobalDefs.h"

class Ball
{
private:
    int currentX, currentY;
    eDir direction;
public:
    Ball();
    Ball(int posX, int posY);
    void reset();
    void changeDirection(eDir dir);
    int getCurrentX();
    int getCurrentY();
    eDir getDirection();
    void randomDirection();
    void Move();
    friend std::ostream& operator<<(std::ostream & o, const Ball& c);


};
#endif