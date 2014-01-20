#include "defs.h"

typedef struct StartMenu{
  int atStartMenu;
  SDL_Surface *background;
  TTF_Font *font;
} StartMenu;

typedef struct Sprite{
  SDL_Surface *image;
} Sprite;

typedef struct Grid_Tile{
  int x, y, isEmpty;
  struct Grid *left, *right, *up, *down;
  /*width of each tile stored as constants in defs.h*/
} Grid_Tile;

typedef struct Grid{
  Grid_Tile tiles;
  /*Not sure how to store tiles to make the array
  Needs to be easy to resize
  Ideas:
  2Darray that is bigger than most maps
  Use pointers somehow*/
}Grid;

typedef struct Tower{
  int level, kills, type, ticksSinceFired;
  float x, y, health, barrelAngle; 
  struct Tower *nextTower;
  /*width, cost, dmg, fireRate, sellPrice, etc will be constants in defs.h*/
} Tower;

typedef struct Enemy{
  float x, y, health, type;
  int dir; /*Direction enemy is walking in*/
  Grid *myGrid;
  struct Enemy *nextEnemy;
  /*width, goldForKilling, totalHealth, speed stored as constants in defs.h 
  Something about its path/pathfinding (pointer to struct/var with its path?)
  */
} Enemy;

typedef struct Player{
  int score, gold;
} Player;

typedef struct Game{
  int time, inGame;
  Grid *grid; /*grid of the game*/
  Tower *towers; /*Linked list*/
  Enemy *enemies; /*Linked list*/
  SDL_Surface *background;
  TTF_Font *font;
} Game;
