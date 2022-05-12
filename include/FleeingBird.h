#ifndef FLEEINGBIRD_H
#define FLEEINGBIRD_H

#include "Enemy.h"
//#include "Form.h"
#include "Player.h"

class FleeingBird : public Enemy{
   public:
      FleeingBird(Player* player);
      virtual ~FleeingBird();

      void render();
   protected:
   private:
      void print();
      void move();
};

#endif // FLEEINGBIRD_H
