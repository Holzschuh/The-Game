#ifndef CIRCLE_H
#define CIRCLE_H

#include "Point.h"

class Circle{
   public:
      Point center;
      float radius;
      Circle();
      Circle(float radius);
      Circle(Point center, float radius);
      virtual ~Circle();
   protected:
   private:
};

#endif // CIRCLE_H
