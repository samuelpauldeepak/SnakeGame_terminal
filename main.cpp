#include<iostream>
#include<conio.h>
#include<windows.h>
#include<vector>
#include<Snake.h>
#include<Food.h>
#define UpKey 72
#define DownKey 80
#define LeftKey 75
#define RightKey 77
using namespace std;
#define HEIGHT 25
#define WIDTH 70



Snake sn1({WIDTH/2,HEIGHT/2});
Food fd1;

void board()
{
  vector<COORD> snakebody = sn1.getSnakebody();

 for(int i=0;i<=HEIGHT+1;i++){
     cout<<"\t\t\t\t";

     for(int j=0;j<=WIDTH+1;j++){
         if(i==0||j==0 ||i==HEIGHT+1||j==WIDTH+1){
             cout<<"#";
         }


             else if(i==fd1.getFoodPos().Y && j==fd1.getFoodPos().X){
                cout<<'*';
             }
         else
            {
             bool snakepos = false;
             for(int k=0;k< snakebody.size();k++)
                {

                  if(i== snakebody[k].Y && j== snakebody[k].X){
                    cout<<"o";
                    snakepos = true;
                    break;
                  }
                }
                if(!snakepos){
                    cout<<" ";
                }
            }
     }
     cout<<endl;

   }
}


int main(){

    while(true){
    Sleep(100);
    board();
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,0});
   if(kbhit()){
      switch(getch()){
   case UpKey : sn1.setDir('u'); break;
   case DownKey : sn1.setDir('d');break;
   case LeftKey : sn1.setDir('l');break;
   case RightKey : sn1.setDir('r');break;

      }
   }
   sn1.moveSnake();

   if(sn1.eaten(fd1)){

       sn1.snakeGrow();
       fd1.genfood();

   }

   if(sn1.collided()){
      cout<<"*****************Game Over******************";
      break;
   }

    }
    return 0;
}
