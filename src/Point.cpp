/// Nome: Rafael Holzschuh de Araujo
/// Matrícula: 201311194

#include "Point.h"
#include <iostream>
#include <math.h>
#include "gl_canvas2d.h"

using namespace std;

/// CONSTRUTORES
Point::Point(){h = 1;}
Point::~Point(){}
Point::Point(float a, float b){
   x = a;
   y = b;
   h = 1;
}

/// MÉTODOS

Point Point::operator +(const float& n){
   Point ans;
   ans.x = this->x + n;
   ans.y = this->y + n;
   return ans;
}


Point Point::operator +(const Point& p){
   Point ans;
   ans.x = this->x + p.x;
   ans.y = this->y + p.y;
   return ans;
}

Point Point::operator - (){
   Point ans;
   ans.x = -x;
   ans.y = -y;
   return ans;
}

Point Point::operator - (const Point& p){
   Point ans;
   ans.x = this->x - p.x;
   ans.y = this->y - p.y;
   return ans;
}

Point Point::operator ^(const float& exp){
   Point ans;
   ans.x = pow(this->x, exp);
   ans.y = pow(this->y, exp);
   return ans;
}

Point Point::operator * (const float& a){
   Point ans;
   ans.x = this->x * a;
   ans.y = this->y * a;
   return ans;
}

float Point::operator * (const Point& p){
   float ans;
   ans = (float)(this->x * p.x + this->y * p.y);
   return ans;
}

void Point::normalize(){
   float s = this->vectorSize();
   this->x = this->x / s;
   this->y = this->y / s;
}
float Point::vectorSize(){
   return (float)sqrt(pow(this->x, 2) + pow(this->y, 2));
}

Point Point::midPoint(Point p){
   Point ans;
   ans.x = (this->x + p.x) * 0.5;
   ans.y = (this->y + p.y) * 0.5;
   return ans;
}

float Point::angleWithVector(Point vec){
   float angle;

   angle = (float)acosf(*this * vec);
   if(this->y < vec.y) angle *= -1;

   return angle;
}

float Point::distance(Point p){
   return sqrt(pow(this->x - p.x, 2) + pow(this->y - p.y, 2));
}

void Point::print(){
   circle(*this, 5, 10);
   return;
}

void Point::setPoint(float x, float y){
   this->x = x;
   this->y = y;
}

Point Point::floatToPoint(float x, float y){
   Point ans(x,y);
   return ans;
}
