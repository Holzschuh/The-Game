#ifndef Enemy_H
#define Enemy_H

#include "Point.h"
#include "Matrix2d.h"
#include "Form.h"
#include "Player.h"

#include "Steering.h"

class Steering;
class Player;

class Enemy : public Form{
   public:
      Point points[8];
      Point velocity;
      float maxSteeringForce;
      float updateCounter;
      float updateTime;
      Steering *steering;
      Player* player;
      vector<Shot*> shots;
      float shotCooldown;
      float shotCounter;
      float shotReloader;
      int shotsQuantity;

      Enemy();
      virtual ~Enemy();

      Point getCopyPoints(const Point&);

      virtual void print();
      virtual void render();

   protected:
   private:
//      void truncateSpeed();

};

#endif // Enemy_H
