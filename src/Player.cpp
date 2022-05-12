#include "Player.h"
#include "gl_canvas2d.h"

using namespace std;

Player::~Player(){}

Player::Player(){
   strcpy(tag, "Player");
   size = 15;
   maxLife = 5;
//   size = 100;

   points[0].x = -size;
   points[0].y = -size;

   points[1].x = size;
   points[1].y = 0;

   points[2].x = -size;
   points[2].y = size;

   position.x = 480;
   position.y = 520;

   shotStartPosition = size;

   scale = 1.f;
   angle = 3.1415/2;
   acceleration = 0.05;
   deceleration = 0.01;
   rotSpeed = 0.05;

   direction.x = 1;
   direction.y = 0;
   target = direction;

   maxSpeed = 3;
   speed = 0;

   shotSpeed = 8;
   shotsQuantity = 0;
   shotCooldown = 1;
   shotCounter = 0;
   shotReloader = 0.02;
//   shotReloader = 0.4;
   keyUnpressedTimeCounter = 10;

   alive = true;
   life = maxLife;
   canBeHit = false;
   immunityTime = 100;
   immunityCounter = 0;

   formColor = new Color(GREEN_LIGHT);
   shotColor = new Color(BLUE);
   healthBar = new HealthBar(life);

   skeleton = new CircleSkeleton(this);
}

void Player::print(){
   int i;

   Point copyPoints[3];

   for(i=0; i<3; i++){
      copyPoints[i] = transformPoint(points[i], this);
   }
   color(GREEN_LIGHT);
   polygonFill(copyPoints, 3);
   replicate(copyPoints, 3);

   if(dashing)
      color(GREY_LIGHT);
   else
      color(GREY_DARK);
   circleFill(copyPoints[1] - direction*5*scale, 3*scale, DIV);

}

void Player::move(bool keyLeft, bool keyRight, bool keyUp, bool keyDown,
                  bool keyShoot, bool keySpecial, bool keyBrake){

   dashing = false;
   if(keyUp){
      if(keyUnpressedTimeCounter < 0.3 && keyUnpressedTimeCounter != 0){
         speed += acceleration * 2.5;
         maxSpeed = 4;
         dashing = true;
      }
      else{
         speed += acceleration;
         maxSpeed = 3;
         keyUnpressedTimeCounter = 0;
      }
   }
   else{
      keyUnpressedTimeCounter += timeInc;
   }


   if(keyDown)  speed -= acceleration;
   fixSpeed();

   if(keyLeft)  angle += rotSpeed;
   if(keyRight) angle -= rotSpeed;

   if(keyShoot && shotCounter == 0){
      shots.push_back(new Shot(this, this->direction));
      shotCounter = shotCooldown;
   }
   if(keySpecial) ;

   if(keyBrake)
      deceleration = 0.1;
   else
      deceleration = 0.01;

   direction.x = cos(angle);
   direction.y = sin(angle);
   position = position + direction * speed;

   stayOnScreen();
}

void Player::fixSpeed(){
   if(speed > 0) speed -= deceleration;
   if(speed < 0) speed += deceleration;

   if(speed >=  maxSpeed) speed = maxSpeed;
   if(speed <= -maxSpeed) speed = -maxSpeed;

   if(speed <= deceleration && speed >= -deceleration) speed = 0;
}

void Player::render(bool* keyMap){

   if(alive){
      move(keyMap[0],keyMap[1],keyMap[2],keyMap[3],keyMap[4],keyMap[5],keyMap[6]);
      target = direction + position;
   }
   else{
      scale *= 0.99;
      angle += 0.1;
   }

   shotCounter -= shotReloader;
   if(shotCounter <= 0)
      shotCounter = 0;

   immunityCounter--;
   if(immunityCounter <= 0){
      immunityCounter = 0;
      canBeHit = true;
   }
   else
      canBeHit = false;

   if(!alive || immunityCounter % 4 == 0)
      print();

   healthBar->print(life);
}








