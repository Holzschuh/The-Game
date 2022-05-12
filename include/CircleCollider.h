#ifndef CIRCLECOLLIDER_H
#define CIRCLECOLLIDER_H

#include "Form.h"
#include "CircleSkeleton.h"
#include <vector>

class CircleCollider
{
   public:
      CircleCollider();
      virtual ~CircleCollider();

      bool testCollision(CircleSkeleton* skeleton1, CircleSkeleton* skeleton2);


   protected:
   private:
      bool testCollision(Circle* circle1, Circle* circle2);
};

#endif // CIRCLECOLLIDER_H
