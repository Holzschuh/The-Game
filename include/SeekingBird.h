#ifndef SEEKINGBIRD_H
#define SEEKINGBIRD_H

#include "Enemy.h"
//#include "Form.h"
#include "Player.h"

class SeekingBird : public Enemy{
   public:
      SeekingBird(Player* player);
      virtual ~SeekingBird();

      void render();
   protected:
   private:
      void print();
      void move();
};
#endif // SEEKINGBIRD_H
