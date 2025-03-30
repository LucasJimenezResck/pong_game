#include <iostream>
#include <vector>
#include <string>
#include "../include/Game.h"

using namespace std;

int main(void)
{
/*
    Ball p;
    Paddle Pr(-10, 0);
    Paddle Pl(10, 0);
    
    std::cout << p << std::endl;
    p.randomDirection();
    p.Move();
    cout << p << endl;
    p.randomDirection();
    p.Move();
    cout << p << endl;
    p.randomDirection();
    p.Move();
    cout << p << endl;
    p.reset();
    cout << p << endl;


    cout << Pl << endl;
    Pl.moveUp();

    cout << Pl << endl;
    Pl.moveUp();
    cout << Pl << endl;
    Pl.Reset();
    cout << Pl << endl;

*/
    Game myGame(40, 20);
    myGame.Draw();
    return 0;
}
