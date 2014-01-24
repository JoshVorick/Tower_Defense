#include "enemies.h"

void initEnemy(Enemy *enemy, int type, Grid_Tile *startGrid){
  enemy->x = startGrid->x;
  enemy->y = startGrid->y;
  enemy->health = 100;
  enemy->type = type;
  enemy->dir = DOWN;
  enemy->myGrid = startGrid;
  enemy->nextEnemy = NULL;
}

void updateEnemies(Game *game){
  Enemy *curEnemy = game->enemies;
  while(curEnemy != NULL){
    switch(curEnemy->dir){
    case LEFT:
      curEnemy->x += ENEMY1_SPEED;
      break;
    case RIGHT:
      curEnemy->x -= ENEMY1_SPEED;
      break;
    case UP:
      curEnemy->y -= ENEMY1_SPEED;
      break;
    case DOWN:
      curEnemy->y += ENEMY1_SPEED;
      break;
    }
    curEnemy = curEnemy->nextEnemy;
  }
};
