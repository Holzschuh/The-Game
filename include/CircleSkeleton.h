#ifndef CIRCLESKELETON_H
#define CIRCLESKELETON_H

#include <stdio.h>
#include "Form.h"
#include "Circle.h"
#include "String.h"
#include <vector>

class Form;

class CircleSkeleton
{
   public:
      vector<Circle*> bones;

      CircleSkeleton(Form* form);
      CircleSkeleton();
      virtual ~CircleSkeleton();
      void print();
   protected:
   private:
};

#endif // CIRCLESKELETON_H
