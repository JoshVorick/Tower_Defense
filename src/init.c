#include "init.h"

/*Initialize SDL*/
void init(char *title){
  SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
  TTF_Init();
  screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 0, SDL_HWPALETTE | SDL_DOUBLEBUF);
  if(screen == NULL)
    printf("ERROR: %s\n", SDL_GetError());
  Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 4096);
  SDL_WM_SetCaption(title, NULL);
  printf("PANCAKES\n");
};

void cleanup(){
  /*funktions to free all variables*/
  

  /*funktions to call before quitting SDL*/
  Mix_CloseAudio();
  TTF_Quit();
  SDL_Quit();
};
