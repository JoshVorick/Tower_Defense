#include "towers.h"

Enemy* findEnemyInRange(int x, int y, int radius, Enemy *curEnemy);
void blueTowerShoot(Enemy *enemy, int level);
void greenTowerShoot(Enemy *enemy, int level);
extern void drawImage(SDL_Surface *surface, int x, int y);

void updateTowers(Game *game){
  //Loop through each tower
  Tower *curTower = game->towers;
  while(curTower != NULL){
    
    switch(curTower->type){
    case gBLUE1:
      if(curTower->ticksSinceFired >= BLUE1_FIRERATE){
        Enemy *gonnaGetShot = findEnemyInRange(curTower->x, curTower->y, BLUE1_RANGE, game->enemies);
        blueTowerShoot(gonnaGetShot, curTower->level);
        //if killed, get gold, increment towers' kills and player's score
      }
      break;
   
    case gGREEN1:
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

void addTower(Game *game, int towerType){
  int areAllFourEmpty = FALSE; //checks if all four blocks tower will go on are blank
  int i,j;
  for(i=0; i < game->grid->dimensionX-1; i++){ //-1 because edge blocks won't work
    for(j=0;j < game->grid->dimensionY-1; j++){
      if(game->grid->selectedTile == &game->grid->tiles[i][j])
        if(game->grid->tiles[i][j].hasTower == FALSE &&
            game->grid->tiles[i+1][j].hasTower == FALSE &&
            game->grid->tiles[i][j+1].hasTower == FALSE &&
            game->grid->tiles[i+1][j+1].hasTower == FALSE){
          areAllFourEmpty = TRUE;
        }
    }
  }
  if(areAllFourEmpty){  
    Tower *newTower = malloc(sizeof(Tower));
    newTower->x = game->grid->selectedTile->x;
    newTower->y = game->grid->selectedTile->y;
    newTower->health = 100;
    newTower->barrelAngle = 0;
    newTower->level = 1;
    newTower->type = towerType;
    newTower->kills = 0;
    newTower->ticksSinceFired = 0;
    newTower->nextTower = game->towers;
    game->towers = newTower;
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

void drawTower(Sprite *sprites, Tower *tower){
  drawImage(sprites[tower->type].image, tower->x, tower->y);
};
