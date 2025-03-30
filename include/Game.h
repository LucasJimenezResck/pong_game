#ifndef Game_H
#define Game_H
#include "ball.h"
#include "paddle.h"

class Game
{
private:
    int height, width;
    int score1, score2;
    Ball* mBall;
    Paddle* mPaddle1;
    Paddle* mPaddle2;


};
#endif