//Initialize SDL
void init(char *title){
  SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
  TTF_Init();
  game.screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 0 SDL_HWPALETTE | SDL_DOUBLEBUFF);
  Mix_OpenAudio(22050, AUDIO_S16SS, 2, 4096);
  SDL_WM_SetCaption(title, NULL);
};

void cleanup(){
  //funktions to free all variables
  

  //funktions to call before quitting SDL
  Mix_CloseAudio();
  TTF_Quit();
  SDL_Quit();
};
