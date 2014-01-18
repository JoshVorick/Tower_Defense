/*
Some silly Tower Defense game I decided to start
Right now it sucks, I'll be honest.
Really not worth playing.
*/

#include "main.h"

//some useful funktions
extern void init(char*);
extern void cleanup(void);
extern void getInput(void);
extern void initStartGame(StartMenu *startMenu);
extern void processMouseStartMenu(StartMenu *startMenu);
extern void updateStartMenu(StartMenu *startMenu);
extern void drawStartMenu(StartMenu *startMenu);
extern void freeStartMenu(StartMenu *startMenu);
extern void initGame(Game *game);
extern void processMouseGame(Game *game);
extern void updateTowers(Game *game);
extern void updateEnemies(Game *game);
extern void drawGame(Game *game);
extern void freeGame(Game *game); //A free game!? Where?! Oh! Its right here!!

main(void){
  unsigned int fpsLimit = 16;
  int playing = TRUE;
  
  init("HOLYMOLYTOWERSDEFENDINGTHINGS!!");

  atexit(cleanup);
  
  while(playing){
    //create and init start menu variables
    StartMenu startMenu = malloc(sizeof(StartMenu)); 
    initStartMenu(startMenu);

    while(startMenu.atStartMenu){
      getInput();
      processMouseStartMenu(startMenu);
      updateStartMenu(startMenu);
      drawStartMenu(startMenu);
      
      delay(fpsLimit);
      fpsLimit = SDL_GetTicks() + 16;
    }
    free(startMenu);

    //create and init game variables
    Game game = malloc(sizeof(Game));
    initGame(game);
  
    while(inGame){
      getInput();
      processMouseGame(game);
      updateTowers(game);
      updateEnemies(game);
      drawGame(game);

      delay(fpsLimit);
      fpsLimit = SDL_GetTicks() + 16;
    }
    free(game);
  }
}
