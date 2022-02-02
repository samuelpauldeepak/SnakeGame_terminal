#ifndef FOOD_H
#define FOOD_H
#include<windows.h>
#define HEIGHT 25
#define WIDTH 70



class Food
{
   private:
       COORD FoodPos;
   public:

     Food();
     void genfood();
     COORD getFoodPos();
};

#endif // FOOD_H
