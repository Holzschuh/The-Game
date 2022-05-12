#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "CircleCollider.h"
#include "Point.h"
#include "Form.h"
#include "Player.h"
#include "Enemy.h"
#include "Matrix2d.h"
#include "BlindBird.h"
#include "FleeingBird.h"
#include "SeekingBird.h"
#include <vector>
#include <iostream>
#include <time.h>


using namespace std;

class GameManager{
   public:
      GameManager(bool* keyMap);
      virtual ~GameManager();

      void render();
   protected:
   private:
      vector<Enemy*> enemies;
      vector<Form*> enemyObjects;
      vector<Form*> playerObjects;
      bool* keyMap;
      Player* player;
      Form transform;
      int gameTime;
      int timeBetweenWaves;
      int waveFinishedTime;
      int waveNumber;
      bool isWaveUp;

      CircleCollider collider;

      void addPlayerObject(Form* form);
      void addEnemyObject(Form* form);
      void restart();

      void updatePlayer();
      void updateEnemies();
      void updatePhysics();
      void killTheDead();
      void printSkeletons();

      void updateWaveNumber();
      void initializeWave(int waveNumber);
};

#endif // GAMEMANAGER_H
