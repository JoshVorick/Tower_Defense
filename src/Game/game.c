#include "game.h"

extern void initInputGame(Game *game);
extern void initGrid(Grid* grid, int x, int y);
extern void initEnemyGenerator(Game*game);
extern void addEnemies(Game *game);
extern void updateTowers(Game *game);
extern void updateEnemies(Game *game);
extern void closeFont(TTF_Font *);
extern void drawString(char *text, int x, int y, TTF_Font *font, int centerX, int centerY, SDL_Color foregroundColor, SDL_Color backgroundColor);
extern SDL_Surface *loadImage(char *name);
extern void drawImage(SDL_Surface *surface, int x, int y);
extern void freeGrid(Grid *grid);

void initGame(Game *game){
  game->totalTime = 0;
  game->levelTime = 0;
  game->inGame = TRUE;
  game->score = 0;
  game->input = malloc(sizeof(Input));
  initInputGame(game);
  initEnemyGenerator(game);
  game->towers = NULL;
  game->enemies = NULL;

  game->sprites[gGRID_TILE].image = loadImage("img/Grid_Tile.png");
  game->sprites[gENEMY1].image = loadImage("img/Alien1.png");
  game->sprites[gENEMY2].image = loadImage("img/Alien2.png");
  game->sprites[gBLUE1].image = loadImage("img/Blue1.png");
  game->sprites[gGREEN1].image = loadImage("img/Green1.png");
  game->sprites[gBACKGROUND].image = loadImage("img/GameBackground.png");

  game->font = TTF_OpenFont("fonts/blackWolf.ttf", 16);
  game->fontColor.r = 200;
  game->fontColor.g = 200;
  game->fontColor.b = 200;
  game->fontBGColor.r = 30;
  game->fontBGColor.g = 30;
  game->fontBGColor.b = 30;

  game->grid = malloc(sizeof(Grid));
  game->grid->dimensionX = 7;
  game->grid->dimensionY = 12;
  game->grid->tiles = (Grid_Tile**)malloc(game->grid->dimensionX*sizeof(Grid_Tile));
  initGrid(game->grid, 75, 50);
};

void updateGame(Game *game){
  game->totalTime += 1;
  game->levelTime += 1;
  
  addEnemies(game);

  updateTowers(game);
  updateEnemies(game);
};

void drawGame(Game *game){
  drawImage(game->sprites[gBACKGROUND].image, 0, 0);
  
  int i,j;
  
  for(i=0; i < game->grid->dimensionX; i++)
    for(j=0; j < game->grid->dimensionY; j++)
      drawImage(game->sprites[gGRID_TILE].image, game->grid->tiles[i][j].x, game->grid->tiles[i][j].y);

  Tower *curTower = game->towers;
  while(curTower != NULL){
    drawImage(game->sprites[curTower->type].image, curTower->x, curTower->y);
    curTower = curTower->nextTower;
  }

  Enemy *curEnemy = game->enemies;
  while(curEnemy != NULL){
    drawImage(game->sprites[curEnemy->type].image, curEnemy->x, curEnemy->y);
    SDL_Rect rect = {curEnemy->x, curEnemy->y, game->sprites[curEnemy->type].image->w, 4};
   SDL_FillRect(screen, &rect, 0xAAAAAA);
   rect.w = game->sprites[curEnemy->type].image->w * curEnemy->health / curEnemy->maxHealth;
   SDL_FillRect(screen, &rect, 0xFF0000);
   curEnemy = curEnemy->nextEnemy;
  }

  SDL_Rect rect = {game->grid->selectedTile->x+20, game->grid->selectedTile->y+20, 10, 10};
  SDL_FillRect(screen, &rect, SDL_MapRGBA(game->sprites[gENEMY1].image->format,100,100,100,255));
  
  char str[20];
  sprintf(str, "Press M to go to menu. Score: %d", game->score);
  
  drawString(str, 0, 15, game->font, 1, 0, game->fontColor, game->fontBGColor);
  
  SDL_Flip(screen);
};

void freeGame(Game* game){
  int i;
  for(i=0; i<NUM_SPRITES_GAME; i++)
    if(game->sprites[i].image != NULL)
      SDL_FreeSurface(game->sprites[i].image);
  
  free(game->input);
  freeGrid(game->grid);
  TTF_CloseFont(game->font);

  Enemy *curEnemy = game->enemies;
  Enemy *tempE;
  while(curEnemy != NULL){
    tempE = curEnemy;
    curEnemy = curEnemy->nextEnemy;
    free(tempE);
  }
  
  Tower *curTower = game->towers;
  Tower *tempT;
  while(curTower != NULL){
    tempT = curTower;
    curTower = curTower->nextTower;
    free(tempT);
  }
};
