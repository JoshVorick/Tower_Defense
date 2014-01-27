#include "input.h"

extern void freeStartMenu(StartMenu *startMenu);

void initInputStartMenu(StartMenu *startMenu){
  int i;
  for(i=0; i<NUM_KEYS_STARTMENU; i++)
    startMenu->input->keys[i] = FALSE;
};

void getInputStartMenu(StartMenu *startMenu){
  SDL_Event event;

  while(SDL_PollEvent(&event)){
    switch(event.type){
      case SDL_QUIT:
        freeStartMenu(startMenu);
        exit(0);
        break;
      case SDL_KEYDOWN:
        switch(event.key.keysym.sym){
          case SDLK_ESCAPE:
            freeStartMenu(startMenu);
            exit(0);
            break;
          default:
            break;
        }
        startMenu->atStartMenu = FALSE;
        break;
    }
  }
};
