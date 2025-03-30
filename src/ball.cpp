#include "../include/ball.h"
#include <iostream>
#include <stdlib.h>
using namespace std;
class Ball;

Ball::Ball() : originalX(0), originalY(0), currentX(0),
currentY(0), direction(STOP)
{}

Ball::Ball(int posX, int posY) :  originalX(posX), originalY(posY), currentX(posX),
currentY(posY), direction(STOP)
{

}
void Ball::reset()
{
    currentX = originalX;
    currentY = originalY;
    direction = STOP;
}

void Ball::changeDirection(eDir dir)
{
    direction = dir;
}

int Ball::getCurrentX() {return currentX;}
int Ball::getCurrentY() {return currentY;}
eDir Ball::getDirection() {return direction;}

void Ball::Move()
{
    switch (direction)
    {
        case STOP:
            break;
        case NEAST:
            currentX++;
            currentY++;
            break;
        case EAST:
            currentX++;
            break;
        case SEAST:
            currentX++;
            currentY--;
            break;
        case SWEST:
            currentX--;
            currentY--;
            break;
        case WEST:
            currentX--;
            break;
        case NWEST:
            currentX--;
            currentY++;
            break;
        default:
            break;

    }
}

std::ostream& operator<<(std::ostream & o, const Ball& c)
{
    o << "Ball [" << c.currentX << ", " << c.currentY << "][" << c.direction << "]" << endl;
    return o;
}
void Ball::randomDirection()
{
    direction = (eDir) ((rand() % 6) + 1);
}