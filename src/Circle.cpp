#include "Circle.h"

Circle::Circle()
{
   //ctor
}

Circle::Circle(Point center, float radius){
   this->center = center;
   this->radius = radius;
}

Circle::Circle(float radius){
   this->radius = radius;
}

Circle::~Circle()
{
   //dtor
}
