#include "../include/Game.h"
#include <time.h>
#include <conio.h>
#include <windows.h>

class Game;

Game::Game(int w, int h) : width(w), height(h), quit(false), up1('w'), up2('i'), down1('s'),
down2('k'), score1(0), score2(0)
{
    srand(time(NULL));
    mBall = new Ball;
    //Set starting positions for the Paddles, in case of uneven width paddle 2 needs to
    //be shifted one block to the right
    int startX1 = -3; //right calculation: (w / (-2)) + 1
    int startX2 = 3; //right calculation: (-1 * startX1) - 1
    if(width % 2 == 1)
        startX2++;
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
    //After a goal, everything goes to its original position
    mBall->reset();
    mPaddle1->Reset();
    mPaddle2->Reset(); 
}

int Game::topLimit()
{
    if(height % 2 == 0)
        return height / 2;
    return (height / 2) + 1;
}
int Game::rightLimit()
{
    if(width % 2 == 0)
        return width / 2;
    return (width / 2) + 1;   
}

void Game::clearScreen() // Use Direct implementation of "cls" to clear screen without flickering!
	{
		HANDLE hOut;
		COORD Position;

		hOut = GetStdHandle(STD_OUTPUT_HANDLE);

		Position.X = 0;
		Position.Y = 0;
		SetConsoleCursorPosition(hOut, Position);
	}


void Game::Draw()
{
    //system("cls");
    clearScreen();
    //Drawing upper wall
    char wall = '#'; //xB2
    char paddle = '|'; //xDB
    for(int i = 0; i < width + 2; i++)
        std::cout << wall;
    std::cout << std::endl;

    //Setting field's limits, for uneven sizes right shift is needed
    int xTop = rightLimit();
    int xBottom = -((width)/2);
    
    int yTop = topLimit();
    int yBottom = -(height / 2);


    //Iterate through all the field, filling with correspondent values
    for(int i = yTop; i > yBottom; i-- )
    {
        for(int j = xBottom; j < xTop; j++)
        {
            //Draws left wall
            if(j == xBottom)
                std::cout << wall;

            //Draws the ball
            if(mBall->getCurrentX() == j && mBall->getCurrentY() == i)
                std::cout << "O";

            //Draws both players with a length of three pieces    
            else if(mPaddle1->getCurrentX() == j && mPaddle1->getCurrentY() == i)
                std::cout << paddle;
            else if(mPaddle2->getCurrentX() == j && mPaddle2->getCurrentY() == i)
                std::cout << paddle;
            else if(mPaddle1->getCurrentX() == j && mPaddle1->getCurrentY() + 1 == i)
                std::cout << paddle;
            else if(mPaddle2->getCurrentX() == j && mPaddle2->getCurrentY() + 1 == i)
                std::cout << paddle;
            else if(mPaddle1->getCurrentX() == j && mPaddle1->getCurrentY() -1 == i)
                std::cout << paddle;
            else if(mPaddle2->getCurrentX() == j && mPaddle2->getCurrentY() -1 == i)
                std::cout << paddle;

            else   
                std::cout << " ";

            //Draws right wall
            if(j == xTop - 1)
                std::cout << wall;

        }
        std::cout << std::endl;
    }
    //Draws bottom wall
    for(int i = 0; i < width + 2; i++)
        std::cout << wall;
    std::cout << std::endl;
    std::cout << score1 << " - " << score2;
    
}

void Game::Input()
{
    mBall->Move();
    if(_kbhit()) //if keyboard hit
    {
        char current = _getch(); //get current char pressed
        //Check if both characters can move up
        if(current == up1 && mPaddle1->getCurrentY() < topLimit() - 1)
            mPaddle1->moveUp();
        if(current == up2 && mPaddle2->getCurrentY() < topLimit() - 1)
            mPaddle2->moveUp();
        //Check if both characters can move down
        int yBottom = -(height / 2);
        if(current == down1 && mPaddle1->getCurrentY() > yBottom + 1)
            mPaddle1->moveDown();
        if(current == down2 && mPaddle2->getCurrentY() > yBottom + 1)
            mPaddle2->moveDown();
        //If the ball isn't moving, press any key to start
        if(mBall->getDirection() == STOP)
            mBall->randomDirection();
        //Quit the game if somebody presses q
        if(current == 'q')
            quit = true;
    }
}

void Game::Logic()
{
    int ballx = mBall->getCurrentX();
    int player1x = mBall->getCurrentX();
    //TODO: solve bounce problem with paddles

    if(ballx == player1x + 1)
        if (mBall->getCurrentY() == mPaddle1->getCurrentY())
            mBall->changeDirection(EAST);

    if(mBall->getCurrentY() == topLimit())
    {
        eDir current_dir = mBall->getDirection() == NEAST ? SEAST : SWEST;
        mBall->changeDirection(current_dir);
    }
    if(mBall->getCurrentY() == -(height/2))
    {
        eDir current_dir = mBall->getDirection() == SEAST ? NEAST : NWEST;
        mBall->changeDirection(current_dir);
    }
    if(mBall->getCurrentX() == rightLimit() + 1)
    {
        ScoreUp(mPaddle1);
    }
    if(mBall->getCurrentX() == -(width/2) - 1)
    {
        ScoreUp(mPaddle2);
    }
}

void Game::Run()
{
    while(!quit)
    {
        Draw();
        Input();
        Logic();
    }
}