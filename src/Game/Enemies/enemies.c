#include "enemies.h"

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
