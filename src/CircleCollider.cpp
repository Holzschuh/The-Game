#include "CircleCollider.h"
#include <math.h>

CircleCollider::CircleCollider(){
   //ctor
}

CircleCollider::~CircleCollider(){
   //dtor
}

bool CircleCollider::testCollision(CircleSkeleton* skeleton1, CircleSkeleton* skeleton2){
   if(testCollision(skeleton1->bones[0], skeleton2->bones[0])){
//      printf("aaa... ");
      for(int i=1; i<skeleton1->bones.size(); i++){
         for(int j=1; j<skeleton2->bones.size(); j++){
            if (testCollision(skeleton1->bones[i], skeleton2->bones[j])){
               return true;
            }
         }
      }
   }
   return false;
}

bool CircleCollider::testCollision(Circle* circle1, Circle* circle2){
   float distance;
   distance = pow(circle2->center.x - circle1->center.x, 2) + pow(circle2->center.y - circle1->center.y,2);
   return (distance <= pow((circle1->radius + circle2->radius), 2));

}


