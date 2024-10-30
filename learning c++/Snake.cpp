#include "Snake.h"

using namespace std;


#define KB(x) ((uint64_t)1024 * x)



const int width = 10, height = 10;
Point dir = Point(0,0);

Snake::Snake(){
    
    random_device rd;  // Obtain a random number from hardware
    mt19937 generator(rd());  // Use Mersenne Twister as generator

    // Define a distribution (e.g., uniform distribution between 1 and 100)
    uniform_int_distribution<int> distribution(0, width);

    /*x = distribution(generator);
    y = distribution(generator);*/

    x = 1;
    y = 1;

    //apple = Point(distribution(generator), distribution(generator));

    apple = Point(3, 3);
    snakeBodyArr.push_front(Point(x,y));
}

void Snake::add(Point dir) {
    x += dir.getX();
    y += dir.getY();
    snakeBodyArr.push_front(Point(x, y));

}

void Snake::deleateLast(){
    snakeBodyArr.pop_back();
}

bool Snake::movable(Point dir) {

    Point comp = Point(x + dir.getX(), y + dir.getY());
    for (Point p : snakeBodyArr)
    {
        if (p.compare(comp))
        {
            return false;
        }
    }
    return true;
}

void Snake::gameover() {
    system("cls");
    cout << "!!!Game Over!!!" << endl;
    cout << "Score: " << snakeBodyArr.size() << endl;
}

void Snake::moveSnake(Point dir) {
    if (movable(dir))
    {
        if (x >= width)
        {
            x = 0;
        }
        if (x < 0)
        {
            x = width-1;
        }
        if (y >= height)
        {
            y = 0;
        }
        if (y < 0)
        {
            y = height-1;
        }
        add(dir);
        deleateLast();
        
    }
    else
    {
        gameover();
    }
}

void Snake::printGame() {
    ostringstream buffer;
    for (int i = 0; i <= height; ++i) {

        for (int j = 0; j <= width; ++j) {

            if (i == 0 || j == 0)
            {
                buffer << "0";
            }
            if (i == width || j == height)
            {
                buffer << "0";
            }
            bool isSnake = false;

            // Check if current position contains snake body
            for (Point p : snakeBodyArr) {
                if (i == p.getY() && j == p.getX()) {
                    buffer << "*";
                    isSnake = true;
                    break;  // Exit once we found a snake part
                }
            }

            // If no snake at this position, check for apple or print empty space
            if (!isSnake) {
                if (i == apple.getY() && j == apple.getX()) {
                    buffer << "$";
                }
                else {
                    buffer << " ";
                }
            }
        }
        buffer << "\n";  // New line after each row
    }
    cout << buffer.str() << endl;

    //ostringstream buffer;  // Create a string buffer

    //for (int i = 0; i < height; ++i) {
    //    for (int j = 0; j < width; ++j) {
    //        for (Point p : snakeBodyArr)
    //        {
    //            if (i == p.getY() && j == p.getX())
    //            {
    //                buffer << "*";
    //            }
    //        }
    //       if (i == apple.getY() && j == apple.getX())
    //       {
    //           buffer << "$";
    //       }
    //       else
    //       {
    //           buffer << " ";
    //       }
    //    }
    //    buffer << "\n";  // New line after each row
    //}
    //auto output = buffer.str();
    //cout << buffer.str() << endl;
     
    /*for (Point p : snakeBodyArr)
    {
    cout << p.getX() << " " << p.getY() << endl;
    }*/
}

void clearScreen() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  // Get console handle
    COORD coord = { 0, 0 };  // Set cursor position to top-left
    DWORD count;

    // Get the console screen buffer size
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    DWORD consoleSize = csbi.dwSize.X * csbi.dwSize.Y;

    // Fill the console with spaces
    FillConsoleOutputCharacter(hConsole, ' ', consoleSize, coord, &count);

    // Reset cursor position
    SetConsoleCursorPosition(hConsole, coord);
}

void Snake::startGame() {
    char ch{};

    while (true) {
            printGame();
        
        // keyListener
        if (_kbhit()) {  // Check if a key was pressed
            ch = _getch();  // Get the key
        }

        // movemet
        switch (ch)
        {
        case 'w':
            dir = Point(0, -1);
            if (movable(dir))
            {
                moveSnake(dir);
            }
            break;
        case 's':
            dir = Point(0, 1);
            if (movable(dir))
            {
                moveSnake(dir);
            }
            break;
        case 'a':
            dir = Point(-1, 0);
            if (movable(dir))
            {
                moveSnake(dir);
            }
            break;
        case 'd':
            dir = Point(1, 0);
            if (movable(dir))
            {
                moveSnake(dir);
            }
            break;

        default:
            if (movable(dir))
            {
                moveSnake(dir);
            }
            break;
        } // movemnt

       
        //eating apple
        
            if (snakeBodyArr.front().compare(apple))
            {
                add(dir);

                bool match = false;

                //generating new apple
                while (!match)
                {
                    random_device rd;  // Obtain a random number from hardware
                    mt19937 generator(rd());  // Use Mersenne Twister as generator

                    uniform_int_distribution<int> distribution(0, width);

                    int ax = distribution(generator);
                    int ay = distribution(generator);
                    for (Point p : snakeBodyArr)
                    {
                        if (Point(ax, ay).compare(p))
                        {
                            break;
                            match = false;
                        }
                        else
                        {
                            match = true;
                        }
                    }
                    if (match)
                    {
                        apple = Point(ax, ay);
                    }
                }
            }


            this_thread::sleep_for(chrono::milliseconds(500));

            clearScreen();
            // Clear the console (platform dependent, example for Windows)
        
        
    }
}