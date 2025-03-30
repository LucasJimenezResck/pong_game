#ifndef Game_H
#define Game_H
#include "ball.h"
#include "paddle.h"

class Game
{
private:
    int height, width;
    int score1, score2;
    char up1, up2, down1, down2;
    bool quit;
    Ball* mBall;
    Paddle* mPaddle1;
    Paddle* mPaddle2;
public:
    Game(int w, int h);
    ~Game();
    void ScoreUp(Paddle* p);
    void Draw();
    void Input();
    void Logic();
    int topLimit();
    int rightLimit();

};
#endif