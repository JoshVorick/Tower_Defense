#include "startMenu.h"

extern void initInput(Input *input);
extern void drawString(char *text, int x, int y, TTF_Font *font, int centerX, int centerY, SDL_Color foregroundColor, SDL_Color backgroundColor);

void initStartMenu(StartMenu *startMenu){
  //assign variables
  startMenu->atStartMenu = TRUE;
  startMenu->input = malloc(sizeof(Input));
  initInput(startMenu->input);
  startMenu->font = TTF_OpenFont("fonts/blackWolf.ttf", 16);  
  startMenu->fontColor.r = 55;
  startMenu->fontColor.g = 255;
  startMenu->fontColor.b = 55;
  startMenu->fontBGColor.r = 100;
  startMenu->fontBGColor.g = 0;
  startMenu->fontBGColor.b = 0;

  //load images
  startMenu->background = NULL;
};

void processInputStartMenu(StartMenu *startMenu){
  //figure out where mouse is and what to do about it
  int i;
  for(i=0; i<NUM_KEYS; i++)
    if(startMenu->input->keys[i])
      startMenu->atStartMenu = FALSE;
};

void drawStartMenu(StartMenu *startMenu){
  //draw stuff yo!
  char *str = "Press any key to start game!";
  drawString(str, 0, 0, startMenu->font, 1, 1, startMenu->fontColor, startMenu->fontBGColor);
};

void freeStartMenu(StartMenu *startMenu){
  //Set the variables free!!
  free(startMenu->input);
  TTF_CloseFont(startMenu->font);
};
