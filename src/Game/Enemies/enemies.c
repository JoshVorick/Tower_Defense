#include "enemies.h"

void initEnemy(Enemy *enemy, int type, Grid_Tile *startGrid){
  enemy->x = startGrid->x;
  enemy->y = startGrid->y;
  enemy->health = 10;
  enemy->type = type;
  enemy->dir = DOWN;
  enemy->myGrid = startGrid;
  enemy->nextEnemy = NULL;
}

void updateEnemies(Game *game){
  Enemy *curEnemy = game->enemies;
  Enemy *prevEnemy = NULL;
  while(curEnemy != NULL){
    //Remove enemy if its dead, add to score
    if(curEnemy->health <= 0){
      game->score += 10;
      Enemy *temp = curEnemy;
      if(prevEnemy != NULL){
        prevEnemy->nextEnemy = curEnemy->nextEnemy;
        curEnemy = curEnemy->nextEnemy; //This makes it so it iterates to the next enemy correctly
      }else{
        game->enemies = curEnemy->nextEnemy;
        curEnemy = curEnemy->nextEnemy;
      }
      free(temp);
      printf("BAM!!!! \n");
    }else{
     //Move the enemy
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
      prevEnemy = curEnemy;
      curEnemy = curEnemy->nextEnemy;
    }
  }
};
