#pragma once

#include <iostream>
#include <random>
#include <list>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <sstream>  // For creating the string buffer
#include <thread>   // For adding a delay to see the effect
#include <chrono>

#include "Point.h"

class Snake
{

public:
    Snake();

    void add(Point dir);

    void deleateLast();

    bool movable(Point dir);

    void moveSnake(Point dir);

    void gameover();

    void startGame();

    void printGame();

    

private:
    int x = 0, y = 0;
    Point apple{};
    std::list<Point> snakeBodyArr{};

};