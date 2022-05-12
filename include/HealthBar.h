#ifndef HEALTHBAR_H
#define HEALTHBAR_H
#include "Player.h"


class HealthBar
{
   public:
      float startingPosition;
      float height;
      float width;
      float unityHeight;
      float unityWidth;
      float safeDistance;
      int maxHealth;

      HealthBar(int life);
      virtual ~HealthBar();

      void print(int life);
   protected:
   private:
};

#endif // HEALTHBAR_H
