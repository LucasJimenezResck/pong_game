#include "../include/paddle.h"

class Paddle;

Paddle::Paddle() : originalX(0), originalY(0), currentX(0),
currentY(0)
{}

Paddle::Paddle(int posX, int posY) : originalX(posX), originalY(posY), currentX(posX),
currentY(posY)
{}

int Paddle::getCurrentX()
{
    return currentX;
}
int Paddle::getCurrentY()
{
    return currentY;
}

void Paddle::moveUp()
{
    currentY++;
}
void Paddle::moveDown()
{
    currentY--;
}

std::ostream& operator<<(std::ostream & o, const Paddle& c)
{
    o << "Paddle [" << c.currentX << ", " << c.currentY << "]" << std::endl;
    return o;
}