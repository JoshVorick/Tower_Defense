#include "input.h"

extern void addTower(Game *game, int towerType);

void initInputGame(Game *game){
  int i;
  for(i=0; i<NUM_KEYS_GAME; i++)
    game->input->keys[i] = FALSE;
};

void getInputGame(Game *game){
  SDL_Event event;

  while(SDL_PollEvent(&event)){
    switch(event.type){
      case SDL_QUIT:
        exit(0);
        break;
      case SDL_KEYDOWN:
        switch(event.key.keysym.sym){
          case SDLK_ESCAPE:
            exit(0);
            break;
          case SDLK_SPACE:
            //if selectedGrid.isEmpty == TRUE
            addTower(game, gBLUE1);
          default:
            break;
        }
        game->input->keys[NUM_KEYS_GAME - 1] = TRUE;
        break;
    }
  }
};
