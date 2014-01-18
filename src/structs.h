#include "defs.h"

typedef struct StartMenu{
  SDL_Surface *background;
  SDL_TTF *font;
} StartMenu;

typedef struct Game{
  int time;
  SDL_Surface *background;
  SDL_TTF *font;
} Game;

typedef struct Grid{
  int x, y, isEmpty;
  SDL_Surface *image;
  struct Grid *left, *right, *up, *down;
  //width of each grid stored as constants in defs.h
} Grid;

typedef struct Tower{
  int x, y, level, kills, type;
  float health, barrelAngle;
  SDL_Surface *image; 
  SDL_Surface *barrel;
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
