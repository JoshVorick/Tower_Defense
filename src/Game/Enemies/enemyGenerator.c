#include "enemyGenerator.h"

extern void initEnemy(Enemy *enemy, int type, Grid_Tile *startGrid, Sprite sprites[]);

void initEnemyGenerator(Game *game){
  game->enemyGenerator.healthScale = 1.1;
  game->enemyGenerator.RGBScale = 0.9;
  game->enemyGenerator.wave = 0;
  game->enemyGenerator.maxWave = MAX_WAVES;
  
  int i,j;
  for(i=0;i<NUM_ENEMIES;i++){
    for(j=0; j<MAX_WAVES; j++){
      game->enemyGenerator.info[i][j][START_DELAY] = 180*i + 3;
      game->enemyGenerator.info[i][j][GROUP_DELAY] = 240;
      game->enemyGenerator.info[i][j][NUM_GROUPS] = 3;// - i;
      game->enemyGenerator.info[i][j][NUM_PER_GROUP] = 2;//1 + 1*i + j;
      game->enemyGenerator.info[i][j][DELAY_WITHIN_GROUP] = 60;// - 30*i;
      game->enemyGenerator.info[i][j][LOOP_AFTER] = MAX_WAVES;
    }
  } 
};

void addEnemies(Game *game){
  if(game->enemyGenerator.wave >= game->enemyGenerator.maxWave)
    return;  

  int doneSpawning = 0;//will get changed to NUM_ENEMIES-1 if all are done
  
  int i;
  for(i=0; i<NUM_ENEMIES; i++){
    //Check to see is an enemy of type i should spawn this tick
    int timeSinceStart= game->levelTime - game->enemyGenerator.info[i][game->enemyGenerator.wave][START_DELAY]-1;
    int cycleTime = game->enemyGenerator.info[i][game->enemyGenerator.wave][GROUP_DELAY] + game->enemyGenerator.info[i][game->enemyGenerator.wave][DELAY_WITHIN_GROUP] * game->enemyGenerator.info[i][game->enemyGenerator.wave][NUM_PER_GROUP];
    if(timeSinceStart > 0 && //Is it after thge delay time??
        timeSinceStart % cycleTime < cycleTime - game->enemyGenerator.info[i][game->enemyGenerator.wave][GROUP_DELAY] && //Is it during a time that isn't the delay period??
        (timeSinceStart % cycleTime) % game->enemyGenerator.info[i][game->enemyGenerator.wave][DELAY_WITHIN_GROUP] == 1 &&
        timeSinceStart < cycleTime * game->enemyGenerator.info[i][game->enemyGenerator.wave][NUM_GROUPS]) //Is the wave still going??
    {
      Enemy *newEnemy = malloc(sizeof(Enemy));
      initEnemy(newEnemy, ENEMY1 + i, game->grid->startTile, game->sprites);
    
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
    }else if(timeSinceStart > cycleTime * game->enemyGenerator.info[i][game->enemyGenerator.wave][NUM_GROUPS]){
      doneSpawning++;
    }
  }
  if(doneSpawning == NUM_ENEMIES - 1){
    game->levelTime = 0;
    game->enemyGenerator.wave++;
  }
};
