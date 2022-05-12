#include "BlindBird.h"
#include "gl_canvas2d.h"


BlindBird::BlindBird(Player* player){
   strcat(tag, "BlindBird");
   size = 30;
//   size = 200;
   life = 2;


   points[0].x = size * (0);
   points[0].y = size * (-0.25);

   points[1].x = size * (0.25);
   points[1].y = size * (-0.5);

   points[2].x = size * (0.5);
   points[2].y = size * (0);

   points[3].x = size * (0.25);
   points[3].y = size * (0.5);

   points[4].x = size * (0);
   points[4].y = size * (0.25);

   points[5].x = size * (-0.5);
   points[5].y = size * (0.5);

   points[6].x = size * (-0.4);
   points[6].y = size * (0);

   points[7].x = size * (-0.5);
   points[7].y = size * (-0.5);

   angle = 3.1415*0.5;
   scale = 1;

   position.x = rand()%TELA_X;
   position.y = rand()%TELA_Y;
//   position.x = 800;
//   position.y = 500;
   shotSpeed = 0;
   speed = 3;

   direction.x = rand()%100 - 50;
   direction.y = rand()%100 - 50;
   direction.normalize();

   shotCooldown = 0.3;
   shotCounter = 0;
   shotReloader = 0.01;
   shotStartPosition = size * 0.5;

   steering = new Steering();
   maxSteeringForce = 0.3;

   updateTime = (rand()%100 + 50) * 0.01;
   updateCounter = updateTime;

   formColor = new Color(BROWN_DARK);

   this->player = player;
   skeleton = new CircleSkeleton(this);
}

BlindBird::~BlindBird(){}

void BlindBird::print(){

   int i;
   Point copyPoints[8];
   Point copyPoints2[8];
   for(i=0; i<8; i++){
      copyPoints[i] = transformPoint(points[i], this);
   }

   color(formColor);
   polygonFill(copyPoints, 8);
   replicate(copyPoints, 8);

   color(RED_LIGHT);
   circleFill(position, size * 0.1, DIV);
   replicateCircle(position, size * 0.1, 1);

   stayOnScreen();

}

void BlindBird::move(){
   Point steeringForce;
   Point newDirection;
   Point xAxis(1,0);

   if(updateCounter >= updateTime){
      target = player->position;
      updateCounter = 0;
   }

   direction.normalize();
   if(shotCounter <= 0){
      shots.push_back(new Shot(this, this->target - this->position));
      shotCounter = shotCooldown;
   }

   steeringForce = steering->wander(this);
   direction =  (direction * speed) + steeringForce;
   direction.normalize();
   angle = direction.angleWithVector(xAxis);
   position = position + direction*speed;
}

void BlindBird::render(){
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
