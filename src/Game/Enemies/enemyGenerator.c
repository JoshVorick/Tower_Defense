#include "enemyGenerator.h"

extern void initEnemy(Enemy *enemy, int type, Grid_Tile *startGrid, Sprite sprites[]);

void initEnemyGenerator(Game *game){
  game->enemyGenerator.tBetweenEnemy = 15;
};

void addEnemies(Game *game){
  if(game->levelTime % game->enemyGenerator.tBetweenEnemy == 0){
    Enemy *newEnemy = malloc(sizeof(Enemy));
    initEnemy(newEnemy,gALIEN1 + rand()%NUM_ENEMIES, &game->grid->tiles[3][0], game->sprites);
    
    //add new enemy to end of list
    if(game->enemies == NULL)
      game->enemies = newEnemy;
    else{
      Enemy *curEnemy = game->enemies;
      while(curEnemy->nextEnemy != NULL){
        curEnemy = curEnemy->nextEnemy;
      }
      curEnemy->nextEnemy = newEnemy;
    }
  }
};
