#ifndef SHOT_H
#define SHOT_H

#include "Form.h"
#include "Circle.h"
#include "Player.h"

class Player;
class Form;

class Shot : public Form{
   public:

      float lifeTimeCounter;
      float lifeTime;
      float cooldown;
      float damage;
      Point center;
      float radius;

      Shot();
      Shot(Form* form, Point direction);
      virtual ~Shot();

      void render();
      virtual void move();
      virtual void print();

   protected:
   private:
};

#endif // SHOT_H
