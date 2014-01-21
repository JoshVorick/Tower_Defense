#include "input.h"

void initInput(Input *input){
  int i;
  for(i=0; i<100; i++)
    input->keys[i] = FALSE;
};

void getInput(Input *input){
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
          default:
            break;
        }
        input->keys[NUM_KEYS - 1] = TRUE;
        break;
    }
  }
};
