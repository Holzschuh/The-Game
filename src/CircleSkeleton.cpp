#include "CircleSkeleton.h"
#include "gl_canvas2d.h"

CircleSkeleton::CircleSkeleton(Form* form){
   if(strstr(form->tag, "Shot")){
      bones.push_back(new Circle(form->size*0.5));
      bones.push_back(new Circle(form->size*0.5));
   }
   else if(strstr(form->tag, "FleeingBird")){
      bones.push_back(new Circle(form->size*0.75));
      bones.push_back(new Circle(form->size*0.5 ));
      Point p;


      bones.push_back(new Circle(p.floatToPoint(-form->size*0.5 + form->size*0.0625 ,
                                                -form->size*0.5 + form->size*0.0625), form->size*0.0625));
      bones.push_back(new Circle(p.floatToPoint( form->size*0.5 - form->size*0.0625 ,
                                                -form->size*0.5 + form->size*0.0625), form->size*0.0625));
      bones.push_back(new Circle(p.floatToPoint(-form->size*0.5 + form->size*0.0625 ,
                                                 form->size*0.5 - form->size*0.0625), form->size*0.0625));
      bones.push_back(new Circle(p.floatToPoint( form->size*0.5 - form->size*0.0625 ,
                                                 form->size*0.5 - form->size*0.0625), form->size*0.0625));
   }
   else if(strstr(form->tag, "SeekingBird")){
      bones.push_back(new Circle(form->size*0.56));
      Point p;

      bones.push_back(new Circle(p.floatToPoint( form->size*0.125, 0              ), form->size*0.2));
      bones.push_back(new Circle(p.floatToPoint(-form->size*0.25 , form->size*0.25), form->size*0.2));
      bones.push_back(new Circle(p.floatToPoint(-form->size*0.25 ,-form->size*0.25), form->size*0.2));
   }
   else if(strstr(form->tag, "BlindBird")){
      bones.push_back(new Circle(form->size*0.6));
      bones.push_back(new Circle(form->size*0.25));
      Point p;

      bones.push_back(new Circle(p.floatToPoint( form->size*0.35 , 0 ), form->size*0.12));

      bones.push_back(new Circle(p.floatToPoint( form->size*0.22 ,-form->size*0.35 ), form->size*0.1));
      bones.push_back(new Circle(p.floatToPoint( form->size*0.22 , form->size*0.35 ), form->size*0.1));
      bones.push_back(new Circle(p.floatToPoint(-form->size*0.4  ,-form->size*0.35 ), form->size*0.1));
      bones.push_back(new Circle(p.floatToPoint(-form->size*0.4  , form->size*0.35 ), form->size*0.1));
   }
   else if(strstr(form->tag, "Player")){
      bones.push_back(new Circle(form->size*1.5));
      Point p;
                                                /// CENTER                              /// RADIUS
      bones.push_back(new Circle(p.floatToPoint(-form->size*0.25 ,  0                ), form->size*0.5  ));
      bones.push_back(new Circle(p.floatToPoint( form->size*0.5  ,  0                ), form->size*0.25 ));
      bones.push_back(new Circle(p.floatToPoint(-form->size*0.75 ,  form->size*0.5   ), form->size*0.25 ));
      bones.push_back(new Circle(p.floatToPoint(-form->size*0.75 , -form->size*0.5   ), form->size*0.25 ));
      bones.push_back(new Circle(p.floatToPoint(-form->size*0.87 ,  form->size*0.83  ), form->size*0.125));
      bones.push_back(new Circle(p.floatToPoint(-form->size*0.87 , -form->size*0.83  ), form->size*0.125));



   }
}

CircleSkeleton::CircleSkeleton(){}

CircleSkeleton::~CircleSkeleton()
{
   //dtor
}

void CircleSkeleton::print(){
   color(CYAN);
   for(int i=0; i<bones.size(); i++){
      if(i==0) {
         color(CYAN);
         circle(bones[i]->center, bones[i]->radius, DIV);
      }
      else{
         color(MAGENTA);
         circleFill(bones[i]->center, bones[i]->radius, DIV);

      }
   }
}
