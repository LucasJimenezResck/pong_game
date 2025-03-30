#include "../include/Game.h"
#include <time.h>
#include <conio.h>

class Game;

Game::Game(int w, int h) : width(w), height(h), quit(false), up1('w'), up2('i'), down1('s'),
down2('k'), score1(0), score2(0)
{
    srand(time(NULL));
    mBall = new Ball;
    int startX1 = (w / (-2)) + 1;
    int startX2 = (-1 * startX1) -1;
    mPaddle1 = new Paddle(startX1, 0);
    mPaddle2 = new Paddle(startX2, 0);

}
Game::~Game()
{
    delete mBall, mPaddle1, mPaddle2;
}

void Game::ScoreUp(Paddle* p)
{
    if(p == mPaddle1)
        score1++;
    else if(p == mPaddle2)
        score2++;
    
    mBall->reset();
    mPaddle1->Reset();
    mPaddle2->Reset(); 
}

void Game::Draw()
{
    system("cls");
    for(int i = 0; i < width + 2; i++)
        std::cout << "\xB2";
    std::cout << std::endl;
    //TODO: fix i-values for uneven field heights: due to division of integers
    //when e.g. height=21 value is still set to 20
    for(int i = -(height/2); i< (height/2); i++ )
    {
        for(int j = -(width/2); j < (width/2); j++)
        {
            if(j == -(width/2))
                std::cout << "\xB2";

            if(mBall->getCurrentX() == j && mBall->getCurrentY() == i)
                std::cout << "O";

            else if(mPaddle1->getCurrentX() == j && mPaddle1->getCurrentY() == i)
                std::cout << "\xDB";
            else if(mPaddle2->getCurrentX() == j && mPaddle2->getCurrentY() == i)
                std::cout << "\xDB";
            else   
                std::cout << " ";

            
            if(j == (width/2) - 1)
                std::cout << "\xB2";

        }
        std::cout << std::endl;
    }

    for(int i = 0; i < width + 2; i++)
        std::cout << "\xB2";
    
}