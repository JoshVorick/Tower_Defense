#include "towers.h"

Enemy* findEnemyInRange(int x, int y, int radius, Enemy *curEnemy);
void blueTowerShoot(Enemy *enemy, int level);
void greenTowerShoot(Enemy *enemy, int level);

void updateTowers(Game *game){
  //Loop through each tower
  Tower *curTower = game->towers;
  while(curTower != NULL){
    
    switch(curTower->type){
    case BLUE:
      if(curTower->ticksSinceFired >= BLUE1_FIRERATE){
        Enemy *gonnaGetShot = findEnemyInRange(curTower->x, curTower->y, BLUE1_RANGE, game->enemies);
        blueTowerShoot(gonnaGetShot, curTower->level);
        //if killed, get gold, increment towers' kills and player's score
      }
      break;
   
    case GREEN:
      if(curTower->ticksSinceFired >= GREEN1_FIRERATE){
        Enemy *gonnaGetShot = findEnemyInRange(curTower->x, curTower->y,GREEN1_RANGE, game->enemies);
        greenTowerShoot(gonnaGetShot, curTower->level);
      }
      break;
    }
    //Do something about aiming the barrel and stuff
    curTower = curTower->nextTower;
  }
};

Enemy* findEnemyInRange(int x, int y, int radius, Enemy *curEnemy){
  while(curEnemy != NULL){
    if((curEnemy->x - x)*(curEnemy->x - x) + (curEnemy->y - y)*(curEnemy->y - y) <= radius*radius)
      return curEnemy;
    else
      curEnemy = curEnemy-> nextEnemy;
  }
  return NULL;
};

void blueTowerShoot(Enemy *enemy, int level){
  enemy->health -= BLUE1_DMG;
};

void greenTowerShoot(Enemy *enemy, int level){
  enemy->health -= GREEN1_DMG;
};
