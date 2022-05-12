#include "SeekingBird.h"
#include "gl_canvas2d.h"


SeekingBird::SeekingBird(Player* player){
   strcat(tag, "SeekingBird");
   size = 30;
//   size = 200;
   life = 2;

   points[0].x = size * (-0.5);
   points[0].y = size * (-0.25);

   points[1].x = size * (-0.25);
   points[1].y = size * (-0.5);

   points[2].x = size * (0.5);
   points[2].y = size * (0);

   points[3].x = size * (-0.25);
   points[3].y = size * (0.5);

   points[4].x = size * (-0.5);
   points[4].y = size * (0.25);

   angle = 3.1415*0.5;
   scale = 1;

   position.x = rand()%TELA_X;
   position.y = rand()%TELA_Y;
//   position.x = 300;
//   position.y = 300;
   shotSpeed = 5;
   speed = 6;

   direction.x = rand()%100 - 50;
   direction.y = rand()%100 - 50;
   direction.normalize();

   shotCooldown = 0.3;
   shotCounter = 0;
   shotReloader = 0.01;
   shotStartPosition = size * 0.5;

   steering = new Steering();
   maxSteeringForce = 0.3;

   updateTime = (rand()%100 + 50) * 0.007;
   updateCounter = updateTime;

   formColor = new Color(YELLOW);

   this->player = player;
   skeleton = new CircleSkeleton(this);
}

SeekingBird::~SeekingBird(){}

void SeekingBird::print(){

   int i;
   Point copyPoints[5];
   Point center;

   for(i=0; i<5; i++){
      copyPoints[i] = transformPoint(points[i], this);
   }

   color(formColor);
   polygonFill(copyPoints, 5);
   replicate(copyPoints, 5);

   stayOnScreen();

}

void SeekingBird::move(){
   Point steeringForce;
   Point newDirection;
   Point xAxis(1,0);

   if(updateCounter >= updateTime){
      target = player->position;

      updateCounter = 0;
   }
//   color(BROWN_LIGHT);
//   circle(target, 200, DIV);

      direction.normalize();

   steeringForce = steering->seek(this);
   direction =  (direction * speed) + steeringForce;
   direction.normalize();
   angle = direction.angleWithVector(xAxis);
   position = position + direction*speed;
}

void SeekingBird::render(){
   shotCounter -= shotReloader;
   if(shotCounter <= 0)
      shotCounter = 0;

   for(int i=0; i<shots.size(); i++){
      if(!(shots[i]->alive))
         shots.erase(shots.begin() + i);
   }
   updateCounter += timeInc;
   move();
   print();
}
