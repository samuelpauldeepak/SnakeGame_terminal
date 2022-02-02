#ifndef SNAKE_H
#define SNAKE_H
#include<vector>
#include<windows.h>
#include<Snake.h>
#include<Food.h>
using namespace std;

class Snake
{
    private:
        COORD pos; //COORD- coordination || pos is a position variable to store x&y
        int len; //length of the snake
        int dir; //Which direction the Snake is moving
        vector<COORD> snakebody;//to grow the snake with length;


    public:
            Snake(COORD pos);
            COORD getPos();
            void setDir(int dir);
            void moveSnake();
            bool collided();
            bool eaten(Food &fd1);
            void snakeGrow();
            vector <COORD> getSnakebody();

};

#endif // SNAKE_H
