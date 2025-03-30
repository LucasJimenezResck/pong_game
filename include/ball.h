#ifndef ball_H
#define ball_H
#include <iostream>
enum eDir {STOP = 0, NEAST, EAST, SEAST, SWEST, WEST, NWEST};

class Ball
{
private:
    int currentX, currentY;
    int originalX, originalY;
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