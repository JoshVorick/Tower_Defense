#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#define FALSE 0
#define TRUE 1

#define BLUE1_PRICE 25
#define BLUE2_PRICE 20
#define BLUE3_PRICE 20
#define BLUE1_SELL 18
#define BLUE2_SELL 35
#define BLUE3_SELL 48
#define BLUE1_FIRERATE 20
#define BLUE2_FIRERATE 15
#define BLUE3_FIRERATE 12
#define BLUE1_DMG 5
#define BLUE2_DMG 8
#define BLUE3_DMG 10

#define GREEN1_PRICE 15
#define GREEN2_PRICE 10
#define GREEN3_PRICE 10
#define GREEN1_SELL 10
#define GREEN2_SELL 18
#define GREEN3_SELL 26
#define GREEN1_FIRERATE 30
#define GREEN2_FIRERATE 25
#define GREEN3_FIRERATE 20
#define GREEN1_DMG 5
#define GREEN2_DMG 5
#define GREEN3_DMG 5

enum towerTypes{
  BLUE,
  GREEN
};

enum enemyTypes{
  ENEMY1,
  ENEMY2
};
