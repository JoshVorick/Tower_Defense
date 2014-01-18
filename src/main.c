/*
Some silly Tower Defense game I decided to start
Right now it sucks, I'll be honest.
Really not worth playing.
*/

#include "main.h"

//some useful funktions


int main(void){
  unsigned int fpsLimit = 16;
  int playing = TRUE;
  
  init("HOLYMOLYTOWERSDEFENDINGTHINGS!!");

  atexit(cleanup);
  
  while(playing){
    //create and init start menu variables
    int atStartMenu = TRUE;
    StartGame startGame = malloc(sizeof(StartGame));
    initStartGame(startGame);

    while(atStartMenu){
      getInput();
      processMouseStartMenu(startMenu);
      updateStartMenu(startMenu);
      drawStartMenu(startMenu);
      
      delay(fpsLimit);
      fpsLimit = SDL_GetTicks() + 16;
    }
    free(startMenu);

    //create and init game variables
    int inGame = TRUE;
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
    //free game variables
  }
}
