#include "defs.h"

typedef struct StartMenu{
  int atStartMenu;
  SDL_Surface *background;
  SDL_TTF *font;
} StartMenu;

typedef struct Game{
  int time, inGame;
  SDL_Surface *background;
  SDL_TTF *font;
} Game;

typedef struct Sprite{
  SDL_Surface *image;
} Sprite;

typedef struct Grid{
  int x, y, isEmpty;
  struct Grid *left, *right, *up, *down;
  //width of each grid stored as constants in defs.h
} Grid;

typedef struct Tower{
  int x, y, level, kills, type;
  float health, barrelAngle; 
  //width, cost, dmg, fireRate, sellPrice, etc will be constants in defs.h
} Tower;

typedef struct Enemy{
  float x, y, health, type;
  int dir; //Direction enemy is walking in
  Grid *myGrid;
  //width, goldForKilling, totalHealth, speed stored as constants in defs.h 
  //Something about its path/pathfinding (pointer to struct/var with its path?)
} Enemy;

typedef struct Player{
  int score, gold;
} Player;
