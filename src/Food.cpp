#include "Food.h"
#include<time.h>
#include<stdlib.h>

Food::Food()
{
    srand(time(NULL));
    genfood();
}

void Food::genfood()
{
    FoodPos.X = rand()% WIDTH + 1;
    FoodPos.Y = rand()% HEIGHT + 1;

}

COORD Food::getFoodPos(){

   return FoodPos;

}



