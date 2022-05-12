#ifndef BLINDBIRD_H
#define BLINDBIRD_H

#include "Enemy.h"
//#include "Form.h"
#include "Player.h"

class BlindBird : public Enemy{
   public:
      BlindBird(Player* player);
      virtual ~BlindBird();

      void render();
   protected:
   private:
      void print();
      void move();
};

#endif // BLINDBIRD_H
