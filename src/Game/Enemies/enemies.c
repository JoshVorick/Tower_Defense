#include "enemies.h"

void initEnemy(Enemy *enemy, int type, Grid_Tile *startGrid, Sprite sprites[]){
  enemy->x = startGrid->x - sprites[type].image->w/2 + sprites[gGRID_TILE].image->w/2;
  enemy->y = startGrid->y - sprites[type].image->h/2;
  enemy->type = type;
  enemy->dir = DOWN;
  enemy->myGrid = startGrid;
  enemy->nextEnemy = NULL;

  switch(type){
    case gENEMY1:
      enemy->speed = ENEMY1_SPEED;
      enemy->health = ENEMY1_HEALTH;
      enemy->maxHealth = ENEMY1_HEALTH;
      break;
    case gENEMY2:
      enemy->speed = ENEMY1_SPEED;
      enemy->health = ENEMY1_HEALTH;
      enemy->maxHealth = ENEMY1_HEALTH;
      break;
    default:
      break;
  }
}

void updateEnemies(Game *game){
  Enemy *curEnemy = game->enemies;
  Enemy *prevEnemy = NULL;
  while(curEnemy != NULL){
    //Remove enemy if its dead, add to score
    if(curEnemy->health <= 0){
      game->score += 10;
      Enemy *temp = curEnemy;
      if(prevEnemy != NULL){//If curEnemy is not first in list
        prevEnemy->nextEnemy = curEnemy->nextEnemy;
        curEnemy = curEnemy->nextEnemy; //iterate to next enemy
      }else{//If curEnemy IS first in list
        game->enemies = curEnemy->nextEnemy;
        curEnemy = curEnemy->nextEnemy;//iterate to next enemy
      }
      free(temp);
      printf("BAM!!!! \n");
    }else{
      //If Enemy reached the end, confuse it for now
      if(curEnemy->myGrid == NULL)
        curEnemy->myGrid = &game->grid->tiles[3][0];

      //Move the enemy
      switch(curEnemy->dir){
      case LEFT:
        curEnemy->x -= curEnemy->speed;
        //If its reached middle of grid, start moving towards next grid in path 
        if(curEnemy->x + game->sprites[curEnemy->type].image->w/2 <= curEnemy->myGrid->x + game->sprites[gGRID_TILE].image->w/2){
          curEnemy->dir = curEnemy->myGrid->dirToNextInPath;
          curEnemy->myGrid = curEnemy->myGrid->nextInPath;
        }
        break;
      case RIGHT:
        curEnemy->x += curEnemy->speed;
        //If its reached middle of grid, start moving towards next grid in path 
        if(curEnemy->x + game->sprites[curEnemy->type].image->w/2 >= curEnemy->myGrid->x + game->sprites[gGRID_TILE].image->w/2){
          curEnemy->dir = curEnemy->myGrid->dirToNextInPath;
          curEnemy->myGrid = curEnemy->myGrid->nextInPath;
        }
        break;
      case UP:
        curEnemy->y -= curEnemy->speed;
        //If its reached middle of grid, start moving towards next grid in path 
        if(curEnemy->y + game->sprites[curEnemy->type].image->h/2 <= curEnemy->myGrid->y + game->sprites[gGRID_TILE].image->w/2){
          curEnemy->dir = curEnemy->myGrid->dirToNextInPath;
          curEnemy->myGrid = curEnemy->myGrid->nextInPath;
        }
        break;
      case DOWN:
        curEnemy->y += curEnemy->speed;
        //If its reached middle of grid, start moving towards next grid in path 
        if(curEnemy->y + game->sprites[curEnemy->type].image->h/2 >= curEnemy->myGrid->y + game->sprites[gGRID_TILE].image->w/2){
          curEnemy->dir = curEnemy->myGrid->dirToNextInPath;
          curEnemy->myGrid = curEnemy->myGrid->nextInPath;
        }
        break;
      }

      //iterate to next enemy
      prevEnemy = curEnemy;
      curEnemy = curEnemy->nextEnemy;
    }
  }
};
