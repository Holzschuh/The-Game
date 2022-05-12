#include "Enemy.h"
#include "gl_canvas2d.h"
#include "math.h"



Enemy::Enemy(){
   shotsQuantity = 0;
   strcpy(tag, "Enemy");
   shotColor = new Color(RED_LIGHT);
   formColor = new Color(RED_DARK);
   maxSteeringForce = 1;
}

Enemy::~Enemy()
{
   //dtor
}


void Enemy::print(){
}

void Enemy::render(){
}
