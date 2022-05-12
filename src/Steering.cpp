#include "Steering.h"
#include "gl_canvas2d.h"


Steering::Steering(){
   wanderAngle = 0;
}
Steering::~Steering(){}

Point Steering::seek(Enemy* enemy){
   Point steeringForce;
   Point desiredDirection;
   Point speed;


   desiredDirection = enemy->target - enemy->position;
   speed = enemy->direction * enemy->speed;

//   color(GREEN_LIGHT);
//   line(enemy->position, enemy->position + enemy->direction * 50);
//   line(enemy->position, enemy->target->position);

   steeringForce = desiredDirection - speed;
   steeringForce.normalize();
   steeringForce = steeringForce * enemy->maxSteeringForce;

   return steeringForce;

}

Point Steering::flee(Enemy* enemy){
   Point steeringForce;
   Point desiredDirection;
   Point speed;


   desiredDirection = enemy->position - enemy->target;
   speed = enemy->direction * enemy->speed;

//   color(GREEN_LIGHT);
//   line(enemy->position, enemy->position + enemy->direction * 50);
//   line(enemy->position, enemy->target->position);

   steeringForce = desiredDirection - speed;
   steeringForce.normalize();
   steeringForce = steeringForce * enemy->maxSteeringForce;

   return steeringForce;

}

Point Steering::wander(Enemy* enemy){
   Point steeringForce;
   Point circleCenter;
   Point displacement;

   float circleDistance = 10;
   float circleRadius = 20;

   wanderAngle += (rand()%16 - rand()%16) * 0.02;
   circleCenter = enemy->direction * circleDistance;
   displacement = displacement.floatToPoint(circleRadius*cos(wanderAngle), circleRadius*sin(wanderAngle));

   steeringForce = circleCenter + displacement;
   steeringForce.normalize();
   steeringForce = steeringForce * enemy->maxSteeringForce;
   return steeringForce;
}
