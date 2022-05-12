#ifndef PLAYER_H
#define PLAYER_H


#include "Form.h"
#include "Matrix2d.h"
#include "Shot.h"
#include "HealthBar.h"
#include <math.h>

class Shot;
class HealthBar;

class Player : public Form{
   public:
      Point points[3];
      vector<Shot*> shots;
      float shotCooldown;
      float shotCounter;
      float shotReloader;
      float keyUnpressedTimeCounter;
      int shotsQuantity;

      bool canBeHit;
      bool dashing;
      int immunityTime;
      int immunityCounter;
      HealthBar *healthBar;

      Player();
      virtual ~Player();


      void render(bool* keyMap);
//      Point getCopyPoints(const Point&);

   protected:
   private:
      virtual void print();
      void move(bool, bool, bool, bool, bool, bool, bool);
      void fixSpeed();
};
#endif // PLAYER_H
