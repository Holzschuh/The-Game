#include "Form.h"
#include "gl_canvas2d.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


Form::Form(){
   size = 1;
   direction.x = 1;
   direction.y = 1;
   speed = 2;
   deceleration = 0.004;
   formColor = new Color(WHITE);
   shotColor = new Color(WHITE);
   alive = true;
}
Form::~Form(){}

Point Form::transformPoint(const Point& point, Form* form){
   Point dot;
   Matrix2d ansMatrix(IDENTITY);

   Matrix2d translateMatrix(IDENTITY);
   translateMatrix.toTranslate(form->position);
   ansMatrix = translateMatrix;

   Matrix2d rotateMatrix(IDENTITY);
   rotateMatrix.toRotate(form->angle);
   ansMatrix = ansMatrix * rotateMatrix;

   Matrix2d scaleMatrix(IDENTITY);
   scaleMatrix.toScale(form->scale, form->scale);
   ansMatrix = ansMatrix * scaleMatrix;

   dot = ansMatrix * point;

   return dot;
}



void Form::replicate(Point* points, int numberOfPoints){
   int i;

   Point pointsL[numberOfPoints];
   Point pointsR[numberOfPoints];
   Point pointsU[numberOfPoints];
   Point pointsD[numberOfPoints];
   Point pointsUR[numberOfPoints];
   Point pointsUL[numberOfPoints];
   Point pointsDR[numberOfPoints];
   Point pointsDL[numberOfPoints];

   for(i=0; i<numberOfPoints; i++){
      pointsL[i] = points[i];
      pointsL[i].x -= TELA_X;

      pointsR[i] = points[i];
      pointsR[i].x += TELA_X;

      pointsU[i] = points[i];
      pointsU[i].y += TELA_Y;

      pointsD[i] = points[i];
      pointsD[i].y -= TELA_Y;

      pointsUR[i] = points[i];
      pointsUR[i].x += TELA_X;
      pointsUR[i].y += TELA_Y;

      pointsUL[i] = points[i];
      pointsUL[i].x -= TELA_X;
      pointsUL[i].y += TELA_Y;

      pointsDR[i] = points[i];
      pointsDR[i].x += TELA_X;
      pointsDR[i].y -= TELA_Y;

      pointsDL[i] = points[i];
      pointsDL[i].x -= TELA_X;
      pointsDL[i].y -= TELA_Y;
   }
   polygonFill(pointsL, numberOfPoints);
   polygonFill(pointsR, numberOfPoints);
   polygonFill(pointsU, numberOfPoints);
   polygonFill(pointsD, numberOfPoints);
   polygonFill(pointsUR, numberOfPoints);
   polygonFill(pointsUL, numberOfPoints);
   polygonFill(pointsDR, numberOfPoints);
   polygonFill(pointsDL, numberOfPoints);

//   for(i=0; i<numberOfPoints; i++){
//      if(points[i].x >= TELA_X - 50){
//         Point pointsL[numberOfPoints];
//         pointsL[i] = points[i];
//         pointsL[i].x -= TELA_X;
//         polygonFill(pointsL, numberOfPoints);
//      }
//      if(points[i].x <= 50){
//         Point pointsR[numberOfPoints];
//         pointsR[i] = points[i];
//         pointsR[i].x += TELA_X;
//         polygonFill(pointsR, numberOfPoints);
//      }
//      if(points[i].y <= 50){
//         Point pointsU[numberOfPoints];
//         pointsU[i] = points[i];
//         pointsU[i].y += TELA_Y;
//         polygonFill(pointsU, numberOfPoints);
//      }
//      if(points[i].y >= TELA_Y - 50){
//         Point pointsD[numberOfPoints];
//         pointsD[i] = points[i];
//         pointsD[i].y -= TELA_Y;
//         polygonFill(pointsD, numberOfPoints);
//      }
//      if(points[i].x <= 50 && points[i].y <= 50){
//         Point pointsUR[numberOfPoints];
//         pointsUR[i] = points[i];
//         pointsUR[i].x += TELA_X;
//         pointsUR[i].y += TELA_Y;
//         polygonFill(pointsUR, numberOfPoints);
//      }
//      if(points[i].x <= 50 && points[i].y <= 50){
//         Point pointsUL[numberOfPoints];
//         pointsUL[i] = points[i];
//         pointsUL[i].x -= TELA_X;
//         pointsUL[i].y += TELA_Y;
//         polygonFill(pointsUL, numberOfPoints);
//
//      }
//      if(points[i].x <= 50 && points[i].y <= 50){
//         Point pointsDR[numberOfPoints];
//         pointsDR[i] = points[i];
//         pointsDR[i].x += TELA_X;
//         pointsDR[i].y -= TELA_Y;
//         polygonFill(pointsDR, numberOfPoints);
//      }
//      if(points[i].x <= 50 && points[i].y <= 50){
//         Point pointsDL[numberOfPoints];
//         pointsDL[i] = points[i];
//         pointsDL[i].x -= TELA_X;
//         pointsDL[i].y -= TELA_Y;
//         polygonFill(pointsDL, numberOfPoints);
//      }
//   }
}

void Form::replicateCircle(Point center, float radius, bool fill){
   if(center.x >= TELA_X - 50){
      Point centerL;
      centerL = center;
      centerL.x -= TELA_X;
      circleFill(centerL, radius, DIV);
   }
   if(center.x <= 50){
      Point centerR;
      centerR = center;
      centerR.x += TELA_X;
      circleFill(centerR, radius, DIV);
   }
   if(center.y <= 50){
      Point centerU;
      centerU = center;
      centerU.y += TELA_Y;
      circleFill(centerU, radius, DIV);
   }
   if(center.y >= TELA_Y - 50){
      Point centerD;
      centerD = center;
      centerD.y -= TELA_Y;
      circleFill(centerD, radius, DIV);
   }
   if(center.x <= 50 && center.y <= 50){
      Point centerUR;
      centerUR = center;
      centerUR.x += TELA_X;
      centerUR.y += TELA_Y;
      circleFill(centerUR, radius, DIV);
   }
   if(center.x <= 50 && center.y <= 50){
      Point centerUL;
      centerUL = center;
      centerUL.x -= TELA_X;
      centerUL.y += TELA_Y;
      circleFill(centerUL, radius, DIV);

   }
   if(center.x <= 50 && center.y <= 50){
      Point centerDR;
      centerDR = center;
      centerDR.x += TELA_X;
      centerDR.y -= TELA_Y;
      circleFill(centerDR, radius, DIV);
   }
   if(center.x <= 50 && center.y <= 50){
      Point centerDL;
      centerDL = center;
      centerDL.x -= TELA_X;
      centerDL.y -= TELA_Y;
      circleFill(centerDL, radius, DIV);
   }
}

void Form::stayOnScreen(){
   if(position.x < 0) position.x = TELA_X;
   if(position.x > TELA_X) position.x = 0;
   if(position.y < 0) position.y = TELA_Y;
   if(position.y > TELA_Y) position.y = 0;
}

void Form::setColor(Color* c){
   this->formColor->r = c->r;
   this->formColor->g = c->g;
   this->formColor->b = c->b;
}

void Form::setColor(float r, float g, float b){
   this->formColor->r = r;
   this->formColor->g = g;
   this->formColor->b = b;
}

CircleSkeleton* Form::transformSkeleton(Form* form){
   CircleSkeleton* copySkeleton = new CircleSkeleton();
   for(int i=0; i<form->skeleton->bones.size(); i++){
//   for(int i=0; i<1; i++){
      copySkeleton->bones.push_back(new Circle(transformPoint(form->skeleton->bones[i]->center, form),
                                                              form->skeleton->bones[i]->radius));
//      printf("\nasdasd");

   }
   return copySkeleton;
}

void Form::render(){}
void Form::print(){}
