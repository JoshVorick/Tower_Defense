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
  game->sprites[gALIEN1].image = loadImage("img/Alien1.png");
  game->sprites[gALIEN2].image = loadImage("img/Alien2.png");
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
  int i;
  for(i=0; i<game->grid->dimensionX; i++)
    game->grid->tiles[i] = (Grid_Tile*)malloc(game->grid->dimensionY*sizeof(Grid_Tile));

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
    curEnemy = curEnemy->nextEnemy;
  }
  
  char str[20];
  sprintf(str, "PRESS ESC TO EXIT %06d", game->score);
  
  drawString(str, 0, 0, game->font, 1, 1, game->fontColor, game->fontBGColor);
  
  SDL_Flip(screen);
};

void freeGame(Game* game){
  //free game variables
  free(game->input);
  TTF_CloseFont(game->font);
  int i;
  for(i=0; i<NUM_SPRITES_GAME; i++)
    if(game->sprites != NULL)
      SDL_FreeSurface(game->sprites[i].image);
};
