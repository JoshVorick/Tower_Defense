#include "towers.h"

Enemy* findEnemyInRange(int x, int y, int radius, Enemy *curEnemy);
void blueTowerShoot(Enemy *enemy, int level);
void greenTowerShoot(Enemy *enemy, int level);
extern void drawImage(SDL_Surface *surface, int x, int y);

void updateTowers(Game *game){
  //Loop through each tower
  Tower *curTower = game->towers;
  while(curTower != NULL){
    curTower->ticksSinceFired++; 
    switch(curTower->type){
    case gBLUE1:
      if(curTower->ticksSinceFired >= BLUE1_FIRERATE){
        Enemy *gonnaGetShot = findEnemyInRange(curTower->x, curTower->y, BLUE1_RANGE, game->enemies);
        if(gonnaGetShot != NULL){
          blueTowerShoot(gonnaGetShot, curTower->level);
          curTower->ticksSinceFired = 0;
        }
      }
      break;
   
    case gGREEN1:
      if(curTower->ticksSinceFired >= GREEN1_FIRERATE){
        Enemy *gonnaGetShot = findEnemyInRange(curTower->x + game->sprites[curTower->type].image->w/2, curTower->y + game->sprites[curTower->type].image->w/2,GREEN1_RANGE, game->enemies);
        if(gonnaGetShot != NULL)
          greenTowerShoot(gonnaGetShot, curTower->level);
        curTower->ticksSinceFired = 0;
      }
      break;
    }
    //Do something about aiming the barrel and stuff
    curTower = curTower->nextTower;
  }
};

int addTower(Game *game, int towerType){
  if(game->grid->blocksPath == TRUE)
    return FALSE;
  double total = (game->rRatio + game->gRatio + game->bRatio)/300.0;
  if(game->rStored < game->rRatio / total || game->gStored < game->gRatio/total || game->bStored < game->bRatio/total)
    return FALSE;
  
  game->rStored -= (int)(game->rRatio / total);
  game->gStored -= (int)(game->gRatio / total);
  game->bStored -= (int)(game->bRatio / total);

  Tower *newTower = malloc(sizeof(Tower));
  newTower->x = game->grid->selectedTile->x;
  newTower->y = game->grid->selectedTile->y;
  newTower->health = 100;
  newTower->barrelAngle = 0;
  newTower->level = 1;
  newTower->type = towerType;
  newTower->kills = 0;
  newTower->ticksSinceFired = 0;
    
  game->grid->selectedTile->myTower = newTower;
    
  //add to list of tower
  newTower->nextTower = game->towers;
  game->towers = newTower;

  return TRUE;
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

void drawTower(Sprite *sprites, Tower *tower){
  drawImage(sprites[tower->type].image, tower->x, tower->y);
};
