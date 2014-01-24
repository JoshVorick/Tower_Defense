#include "enemyGenerator.h"

extern void initEnemy(Enemy *enemy, int type, Grid_Tile *startGrid);

void initEnemyGenerator(Game *game){
  game->enemyGenerator.tBetweenEnemy = 150;
};

void addEnemies(Game *game){
  if(game->levelTime % game->enemyGenerator.tBetweenEnemy == 0){
    Enemy *newEnemy = malloc(sizeof(Enemy));
    if(rand() % 2 == 0)
      initEnemy(newEnemy, gALIEN1, &game->grid->tiles[3][0]);
    else
      initEnemy(newEnemy, gALIEN2, &game->grid->tiles[3][0]);
    newEnemy->nextEnemy = game->enemies;
    game->enemies = newEnemy;
  }
};
