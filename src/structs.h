#include "defs.h"

typedef struct Input{
  int keys[100];
} Input;

typedef struct Sprite{
  SDL_Surface *image;
} Sprite;

typedef struct StartMenu{
  int atStartMenu;
  Sprite sprites[NUM_SPRITES_STARTMENU];
  SDL_Color fontColor, fontBGColor;
  Input *input;
  TTF_Font *font;
} StartMenu;

typedef struct Tower{
  int level, kills, type, ticksSinceFired;
  float x, y, health, barrelAngle; 
  struct Tower *nextTower;
  /*width, cost, dmg, fireRate, sellPrice, etc will be constants in defs.h*/
} Tower;

typedef struct Grid_Tile{
  int x, y, dirToNextInPath;
  Tower *myTower; //pointer to the tower on this grid
  struct Grid_Tile *nextInPath; //points to next tile enemies will take
} Grid_Tile;

typedef struct Grid{
  Grid_Tile **tiles;
  Grid_Tile *selectedTile;
  int dimensionX, dimensionY;
}Grid;

typedef struct Enemy{
  float x, y, health;
  int type, dir; /*Direction enemy is walking in*/
  Grid_Tile *myGrid;
  struct Enemy *nextEnemy;
  /*width, goldForKilling, totalHealth, speed stored as constants in defs.h 
  Something about its path/pathfinding (pointer to struct/var with its path?)
  */
} Enemy;

typedef struct EnemyGenerator{
  int tBetweenEnemy;
}EnemyGenerator;

typedef struct Game{
  int totalTime, levelTime, inGame, score;
  Sprite sprites[NUM_SPRITES_GAME];
  SDL_Color fontColor, fontBGColor;
  Input *input;
  Grid *grid; /*grid of the game*/
  Tower *towers; /*Linked list*/
  Enemy *enemies;
  EnemyGenerator enemyGenerator;
  TTF_Font *font;
} Game;
