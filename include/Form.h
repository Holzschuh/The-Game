#ifndef FORM_H
#define FORM_H

#include <vector>
#include "Color.h"
#include "Matrix2d.h"
#include "CircleSkeleton.h"
#include "Point.h"
#include "String.h"

#define DIV 20

class CircleSkeleton;

using namespace std;

class Form{
   public:

      float shotStartPosition;
      char tag[20];
      float timeInc = 0.01;
      float angle;
      float rotSpeed;
      float maxRotSpeed;
      float rotAcceleration;
      Point position;
      Point direction;
      Point target;
      float speed;
      float maxSpeed;
      float acceleration;
      float deceleration;
      Point scaleSpeed;
      float scale;
      float size;
      float shotSpeed;

      CircleSkeleton *skeleton;
      Color *formColor;
      Color *shotColor;

      bool alive;

      int toughness;
      int life;
      int maxLife;

/// CONSTRUTORES
      Form();
      virtual ~Form();

/// MÉTODOS

      Point transformPoint(const Point& point, Form* form);
      CircleSkeleton* transformSkeleton(Form* form);
      void replicate(Point* points, int numberOfPoints);
      void replicateCircle(Point p, float radius, bool fill);
      void stayOnScreen();
      void setColor(float r, float g, float b);
      void setColor(Color* c);

      virtual void print();
      virtual void render();

//      virtual void move();



    protected:
    private:

};

#endif // FORM_H
