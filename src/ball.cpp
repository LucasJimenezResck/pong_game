#include "../include/ball.h"
#include <iostream>
#include <stdlib.h>
using namespace std;
class Ball;

Ball::Ball() : currentX(int(START_X_BALL)), currentY(int(START_Y_BALL)), direction(STOP)
{}

Ball::Ball(int posX, int posY) : currentX(posX), currentY(posY), direction(STOP)
{}
void Ball::reset()
{
    currentX = (int) START_X_BALL;
    currentY = (int) START_Y_BALL;
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