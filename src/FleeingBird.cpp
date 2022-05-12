#include "FleeingBird.h"
#include "gl_canvas2d.h"


FleeingBird::FleeingBird(Player* player){
   strcat(tag, "FleeingBird");
   size = 30;
//   size = 200;
   life = 2;

   points[0].x = size * (-0.5);
   points[0].y = size * (-0.5);

   points[1].x = size * (0.5);
   points[1].y = size * (-0.5);

   points[2].x = size * (0.5);
   points[2].y = size * (0.5);

   points[3].x = size * (-0.5);
   points[3].y = size * (0.5);

   angle = 3.1415*0.5;
   scale = 1;

   position.x = rand()%TELA_X;
   position.y = rand()%TELA_Y;
//   position.x = 600;
//   position.y = 300;
   shotSpeed = 5;
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

FleeingBird::~FleeingBird(){}

void FleeingBird::print(){

   int i;
   Point copyPoints[4];
   Point center;

   for(i=0; i<4; i++){
      copyPoints[i] = transformPoint(points[i], this);
   }
   center = copyPoints[1].midPoint(copyPoints[2]);

   color(RED_LIGHT);
   circleFill(center, size * 0.15, DIV);
   replicateCircle(center, size * 0.15, 1);

   color(formColor);
   polygonFill(copyPoints, 4);
   replicate(copyPoints, 4);

   stayOnScreen();

}

void FleeingBird::move(){
   Point steeringForce;
   Point newDirection;
   Point xAxis(1,0);

   if(updateCounter >= updateTime){
      target = player->position;

      updateCounter = 0;
   }

//   color(MAGENTA);
//   circle(target, 300, DIV*2);

      direction.normalize();
   if(position.distance(target) <= 300 ){
      if(shotCounter <= 0){
         shots.push_back(new Shot(this, this->target - this->position));
         shotCounter = shotCooldown;
      }

      steeringForce = steering->flee(this);
      direction =  (direction * speed) + steeringForce;
   }

   direction.normalize();
   angle = direction.angleWithVector(xAxis);
   position = position + direction*speed;
}

void FleeingBird::render(){
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
