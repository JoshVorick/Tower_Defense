#include "game.h"

extern void initInput(Input *input);
extern void initGrid(Grid* grid, int x, int y);
extern void closeFont(TTF_Font *);
extern void drawString(char *text, int x, int y, TTF_Font *font, int centerX, int centerY, SDL_Color foregroundColor, SDL_Color backgroundColor);
extern SDL_Surface *loadImage(char *name);
extern void drawImage(SDL_Surface *surface, int x, int y);

void initGame(Game *game){
  game->time = 0;
  game->inGame = TRUE;
  game->input = malloc(sizeof(Input));
  initInput(game->input);
  game->towers = NULL;
  game->enemies = NULL;

  game->sprites[gGRID_TILE].image = loadImage("img/Grid.png");
  game->sprites[gALIEN1].image = loadImage("img/Alien1.png");
  game->sprites[gALIEN2].image = loadImage("img/Alien2.png");
  game->sprites[gBLUE1].image = loadImage("img/Blue1.png");
  game->sprites[gBLUE2].image = loadImage("img/Blue2.png");
  game->sprites[gBLUE3].image = loadImage("img/Blue3.png");
  game->sprites[gGREEN1].image = loadImage("img/Green1.png");
  game->sprites[gGREEN2].image = loadImage("img/Green2.png");
  game->sprites[gGREEN3].image = loadImage("img/Green3.png");
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

void processInputGame(Game *game){
  int i;
  for(i=0; i<NUM_KEYS; i++)
    if(game->input->keys[i])
      game->inGame = FALSE;
};

void drawGame(Game *game){
  drawImage(game->sprites[gBACKGROUND].image, 0, 0);
  
  int i,j;
  for(i=0; i < game->grid->dimensionX; i++)
    for(j=0; j < game->grid->dimensionY; j++)
      drawImage(game->sprites[gGRID_TILE].image, game->grid->tiles[i][j].x, game->grid->tiles[i][j].y);

  char *str = "PRESS ANY KEY TO GO TO MENU, ESC TO EXIT";
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
