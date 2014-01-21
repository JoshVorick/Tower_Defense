/*
Some silly Tower Defense game I decided to start
Right now it sucks, I'll be honest.
Really not worth playing.
*/

#include "main.h"

//some useful funktions
extern void init(char*);
extern void cleanup(void);
extern void getInput(Input *input);
extern void initStartMenu(StartMenu *startMenu);
extern void processInputStartMenu(StartMenu *startMenu);
extern void drawStartMenu(StartMenu *startMenu);
extern void freeStartMenu(StartMenu *startMenu);
extern void initGame(Game *game);
extern void processInputGame(Game *game);
extern void updateTowers(Game *game);
extern void updateEnemies(Game *game);
extern void drawGame(Game *game);
extern void freeGame(Game *game); //A free game!? Where?! Oh! Its right here!!

int main(void){
  unsigned int fpsLimit = 16;
  int playing = TRUE;
  
  init("HOLYTOWERSDEFENDINGTHINGS!!");

  atexit(cleanup);
  
  while(playing){
    //create and init start menu variables
    StartMenu *startMenu = malloc(sizeof(StartMenu)); 
    initStartMenu(startMenu);
    
    while(startMenu->atStartMenu){
      SDL_FillRect(screen, NULL, 0);
      
      getInput(startMenu->input);
      processInputStartMenu(startMenu);
      drawStartMenu(startMenu);

      unsigned int ticks = SDL_GetTicks();
      if(ticks < fpsLimit)
         SDL_Delay(fpsLimit - ticks);
      SDL_Flip(screen);
     
      fpsLimit = SDL_GetTicks() + 16;
    }
    
    freeStartMenu(startMenu);   
    
    //create and init game variables
    Game *game = malloc(sizeof(Game));
    initGame(game);
   
    while(game->inGame){
      SDL_FillRect(screen, NULL, 0);
      
      getInput(game->input);
      processInputGame(game);
      updateTowers(game);
      updateEnemies(game);
      drawGame(game);

      unsigned int ticks = SDL_GetTicks();
      if(ticks < fpsLimit)
         SDL_Delay(fpsLimit - ticks);
      SDL_Flip(screen);

      fpsLimit = SDL_GetTicks() + 16;
    }

    freeGame(game);
  }
  exit(0);
}
