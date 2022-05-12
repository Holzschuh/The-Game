#include "GameManager.h"
#include "gl_canvas2d.h"

GameManager::GameManager(bool* keyMap)
{
   srand(time(NULL));

   gameTime = 0;
   timeBetweenWaves = 50;
   waveFinishedTime = gameTime;
   isWaveUp = false;
   waveNumber = 1;

   player = new Player();
   this->keyMap = keyMap;
}

GameManager::~GameManager(){}

void GameManager::render(){
   Sleep(10);
   clear(BLACK);
   color(WHITE);

//   printf("\n%d", enemies.size());
   if(((gameTime - waveFinishedTime) >= timeBetweenWaves) && !isWaveUp){
      initializeWave(waveNumber);
      isWaveUp = true;
   }

   updatePlayer();
   updateEnemies();
   updatePhysics();
   killTheDead();
   updateWaveNumber();

   /// DESCOMENTE ESSA FUNÇÃO PARA VER A COLISÃO
   //printSkeletons();

   gameTime ++;
}

void GameManager::addPlayerObject(Form* form){
   playerObjects.push_back(form);
}

void GameManager::addEnemyObject(Form* form){
   enemyObjects.push_back(form);
}

void GameManager::updatePlayer(){
   player->render(keyMap);

   for(int i=player->shotsQuantity; i<player->shots.size(); i++){
      addPlayerObject(player->shots[i]);
   }
   player->shotsQuantity = player->shots.size();

   for(int i=0; i<playerObjects.size(); i++){
      playerObjects[i]->render();
   }
}

void GameManager::updateEnemies(){
   for(int i=0; i<enemyObjects.size(); i++){
      enemyObjects[i]->render();
   }

   for(int i=0; i<enemies.size(); i++){
      for(int j=enemies[i]->shotsQuantity; j<enemies[i]->shots.size(); j++){
         addEnemyObject(enemies[i]->shots[j]);
      }
      enemies[i]->shotsQuantity = enemies[i]->shots.size();
   }
}

void GameManager::updatePhysics(){
      for(int i=0; i<enemyObjects.size(); i++){
      if(enemyObjects[i]->alive){

         for(int j=0; j<playerObjects.size(); j++){
            if(playerObjects[j]->alive){
               if(collider.testCollision(transform.transformSkeleton(enemyObjects[i]),
                                         transform.transformSkeleton(playerObjects[j]))){
                  enemyObjects[i]->life--;
                  playerObjects[j]->life--;
               }
            }
         }

         if(player->alive){
            if(collider.testCollision(transform.transformSkeleton(enemyObjects[i]),
                                      transform.transformSkeleton(player))){
               //printf("asdasdasdasytdfytsfduytfsd\n");
               if(player->canBeHit){
                  if(strstr(enemyObjects[i]->tag, "Shot"))
                     enemyObjects[i]->life--;
                  player->life--;
                  player->immunityCounter = player->immunityTime;
                  printf("\n%d", player->life);
                  player->canBeHit = false;
               }
            }
         }
      }
   }
}

void GameManager::killTheDead(){
   if(player->life <= 0){
      player->life = 0;
      player->alive = false;
   }

   for(int i=0; i<enemyObjects.size(); i++){
      if(enemyObjects[i]->life <= 0){
         enemyObjects[i]->life = 0;
         enemyObjects[i]->alive = false;
      }
      if(!enemyObjects[i]->alive)
         enemyObjects.erase(enemyObjects.begin() + i);
   }

   for(int i=0; i<enemies.size(); i++){
      if(enemies[i]->life <= 0){
         enemies[i]->life = 0;
         enemies[i]->alive = false;
      }
      if(!enemies[i]->alive)
         enemies.erase(enemies.begin() + i);
   }

   for(int i=0; i<playerObjects.size(); i++){
      if(playerObjects[i]->life <= 0){
         playerObjects[i]->life = 0;
         playerObjects[i]->alive = false;
      }
      if(!playerObjects[i]->alive)
         playerObjects.erase(playerObjects.begin() + i);
   }
}

void GameManager::printSkeletons(){
   for(int i=0; i<enemyObjects.size(); i++){
      for(int j=0; j<enemyObjects[i]->skeleton->bones.size(); j++){
            CircleSkeleton* asd = transform.transformSkeleton(enemyObjects[i]);
            asd->print();
      }
   }
   for(int i=0; i<playerObjects.size(); i++){
      for(int j=0; j<playerObjects[i]->skeleton->bones.size(); j++){
         CircleSkeleton* asd = transform.transformSkeleton(playerObjects[i]);
         asd->print();
      }
   }
   for(int j=0; j<player->skeleton->bones.size(); j++){
      CircleSkeleton* asd = transform.transformSkeleton(player);
      asd->print();
   }
}

void GameManager::initializeWave(int waveNumber){
   int enemyID;
   int numberOfEnemies;

   player->immunityCounter = player->immunityTime*2;
   player->life += 2;
   if(player->life >= player->maxLife)
      player->life = player->maxLife;

   numberOfEnemies = waveNumber / 3 + 1;

   switch(waveNumber){
      case 0:
         enemies.push_back(new FleeingBird(player));
         enemies.push_back(new SeekingBird(player));
         enemies.push_back(new BlindBird(player));
         addEnemyObject(enemies[0]);
         addEnemyObject(enemies[1]);
         addEnemyObject(enemies[2]);
         break;
      case 1:
         enemies.push_back(new FleeingBird(player));
         addEnemyObject(enemies[0]);
         break;
      case 2:
         enemies.push_back(new SeekingBird(player));
         addEnemyObject(enemies[0]);
         break;
      case 3:
         enemies.push_back(new BlindBird(player));
         addEnemyObject(enemies[0]);
         break;
      default:
         for(int i=0; i<numberOfEnemies; i++){
            enemyID = rand()%3;
            if      (enemyID == 0) enemies.push_back(new FleeingBird(player));
            else if (enemyID == 1) enemies.push_back(new SeekingBird(player));
            else if (enemyID == 2) enemies.push_back(new BlindBird(player));
            addEnemyObject(enemies[i]);
         }
         break;
   }
}

void GameManager::updateWaveNumber(){
   if(enemies.size() == 0 && isWaveUp){
      waveFinishedTime = gameTime;
      isWaveUp = false;
      waveNumber++;
   }
   Point p;
   char waveText[10];
   sprintf(waveText, "Wave: %d", waveNumber);
   color(WHITE);
   text(p.floatToPoint(10,10), waveText);
}
