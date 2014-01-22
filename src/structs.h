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

typedef struct Grid_Tile{
  int x, y, isEmpty;
  struct Grid *left, *right, *up, *down;
  /*width of each tile stored as constants in defs.h*/
} Grid_Tile;

typedef struct Grid{
  Grid_Tile **tiles;
  int dimensionX, dimensionY;
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
  Sprite sprites[NUM_SPRITES_GAME];
  SDL_Color fontColor, fontBGColor;
  Input *input;
  Grid *grid; /*grid of the game*/
  Tower *towers; /*Linked list*/
  Enemy *enemies; /*Linked list*/
  TTF_Font *font;
} Game;
