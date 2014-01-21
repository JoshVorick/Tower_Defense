#include "game.h"

extern void initInput(Input *input);
extern void closeFont(TTF_Font *);
extern void drawString(char *text, int x, int y, TTF_Font *font, int centerX, int centerY, SDL_Color foregroundColor, SDL_Color backgroundColor);

void initGame(Game *game){
  game->time = 0;
  game->inGame = TRUE;
  game->input = malloc(sizeof(Input));
  initInput(game->input);
  game->towers = NULL;
  game->enemies = NULL;
  game->background = NULL;
  game->font = TTF_OpenFont("fonts/blackWolf.ttf", 16);
  game->fontColor.r = 200;
  game->fontColor.g = 200;
  game->fontColor.b = 200;
  game->fontBGColor.r = 30;
  game->fontBGColor.g = 30;
  game->fontBGColor.b = 30;
};

void processInputGame(Game *game){
  int i;
  for(i=0; i<NUM_KEYS; i++)
    if(game->input->keys[i])
      game->inGame = FALSE;
};

void drawGame(Game *game){
  char *str = "PRESS ANY KEY TO GO TO MENU, ESC TO EXIT";
  drawString(str, 0, 0, game->font, 1, 1, game->fontColor, game->fontBGColor);
};

void freeGame(Game* game){
  //free game variables
  free(game->input);
  TTF_CloseFont(game->font);
};
