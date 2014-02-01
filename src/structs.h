#include "defs.h"

typedef struct Sprite{
  SDL_Surface *image;
} Sprite;

typedef struct StartMenu{
  int atStartMenu;
  Sprite sprites[NUM_SPRITES_STARTMENU];
  SDL_Color fontColor, fontBGColor;
  TTF_Font *font;
} StartMenu;

typedef struct Tower{
  int dmg, kills, type, fireRate, ticksSinceFired, range;
  float x, y, health; 
  struct Tower *nextTower;
  SDL_Color color;
  /*width, cost, dmg, fireRate, sellPrice, etc will be constants in defs.h*/
} Tower;

typedef struct Grid_Tile{
  int x, y, dirToNextInPath, i, j; //x and y -> pixel coor, i and j -> place in grid array
  Tower *myTower; //pointer to the tower on this grid
  struct Grid_Tile *nextInPath; //points to next tile enemies will take
  struct Grid_Tile *next; //Used to form linkd list of tiles to make pathfinding simpler
} Grid_Tile;

typedef struct Grid{
  Grid_Tile **tiles;
  Grid_Tile *selectedTile, *startTile, *endTile;
  int blocksPath; //stores whether a tower placed at selectedTile would block the path
  int dimensionX, dimensionY;
}Grid;

typedef struct Enemy{
  float x, y, speed;
  int type, health, maxHealth, score, dir; /*Direction enemy is walking in*/
  SDL_Color color;
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
  int totalTime, levelTime, inGame, score, selectedTowerType;
  int rStored, gStored, bStored; //RGB resources for buying towers
  int rRatio, gRatio, bRatio; //Ratio of R:G:B to be used when next tower is bought
  int keys[NUM_GAME_KEYS];
  Sprite sprites[NUM_SPRITES_GAME];
  SDL_Color fontColor, fontBGColor;
  Grid *grid; /*grid of the game*/
  Tower *towers; /*Linked list*/
  Enemy *enemies;
  EnemyGenerator enemyGenerator;
  TTF_Font *font;
} Game;
