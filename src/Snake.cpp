#include <Snake.h>
#define HEIGHT 25
#define WIDTH 70

Snake::Snake(COORD pos){
this->pos=pos;
len=1;
snakebody.push_back(pos);

}
COORD Snake::getPos(){
 return pos;
}

void Snake::setDir(int dir){
  this->dir=dir;
}

void Snake::moveSnake(){
  switch(dir){
  case 'u': pos.Y--; break;
  case 'd': pos.Y++; break;
  case 'l': pos.X--; break;
  case 'r': pos.X++; break;
  }

  snakebody.push_back(pos);
  if(snakebody.size() > len)
  {
      snakebody.erase(snakebody.begin());

  }

}

bool Snake::collided(){
   if(pos.X==0 ||pos.X==WIDTH+1 || pos.Y==0 || pos.Y==HEIGHT+1)
    return true;
   return false;

}

bool Snake::eaten(Food &fd1){

   if(pos.X == fd1.getFoodPos().X && pos.Y == fd1.getFoodPos().Y)
    return true;

return false;
}


 void Snake::snakeGrow(){

   len++;

 }

 vector<COORD> Snake::getSnakebody(){

  return snakebody;

 }





