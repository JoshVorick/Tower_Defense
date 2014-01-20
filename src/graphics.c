#include "graphics.h"

SDL_Surface *loadImage(char *name){
  //load image all fancy-shmancy-like
  return SDL_DisplayFormat(IMG_Load(name));  
};

void drawImage(SDL_Surface *image, int x, int y){
  SDL_Rect dest;
  dest.x = x;
  dest.y = y;
  dest.w = image->w;
  dest.h = image->h;

  SDL_BlitSurface(image, NULL, screen, &dest);
};

void freeSprites(){
  int i;
  for(i=0;i<NUM_SPRITES;i++){
    if(sprites[i].image != NULL)
      SDL_FreeSurface(sprites[i].image);
  }
};

void loadAllSprite(){
  //loadSprite(INDEX, "location");
};
