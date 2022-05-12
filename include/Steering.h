#ifndef STEERING_H
#define STEERING_H

#include "Point.h"
#include "Form.h"
#include "Enemy.h"

class Enemy;

class Steering{
   public:
      float wanderAngle;

      Steering();
      virtual ~Steering();

      Point seek(Enemy* enemy);
      Point flee(Enemy* enemy);
      Point wander(Enemy* enemy);
   protected:
   private:
};

#endif // STEERING_H
