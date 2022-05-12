#include "Shot.h"
#include "gl_canvas2d.h"
#include "string.h"
#define PU_NORMAL 0


Shot::Shot(){}
Shot::~Shot(){}

Shot::Shot(Form* form, Point direction){
   size = 11;
   strcpy(tag, form->tag);
   strcat(tag, "Shot");
//   printf("\n%s", tag);
   direction.normalize();
   scale = form->scale;
   this->direction = direction;
   direction.normalize();
   position = form->position + direction * form->shotStartPosition;
   speed = form->shotSpeed;
   life = 1;
   lifeTime = 2;
   lifeTimeCounter = 0;
   alive = true;
   setColor(form->shotColor);

   radius = size * 0.5;

   skeleton = new CircleSkeleton(this);
}

void Shot::print(){
//   float radius = size + sin(lifeTimeCounter*30)*3;
   Point copyCenter = transformPoint(center, this);

   color(formColor);

   circleFill(copyCenter, radius, DIV);
   replicateCircle(copyCenter, radius, true);
}

void Shot::move(){
//   printf("\n%f\n%f\n", direction.x, direction.y);
//   line(position, position + direction * 300);

   position = position + direction * speed;

   stayOnScreen();

}

void Shot::render(){

   move();
   print();

   lifeTimeCounter += timeInc;
//   printf("\n%f", speed);


   if(lifeTimeCounter >= lifeTime || life <= 0){
      alive = false;
   }


}
