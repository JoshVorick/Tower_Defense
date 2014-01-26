#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"

#define SCREEN_WIDTH 500
#define SCREEN_HEIGHT 732

#define NUM_SPRITES_STARTMENU 1
#define NUM_SOUNDS_STARTMENU 0
#define NUM_KEYS_STARTMENU 5

enum startMenuSprites{
  sBACKGROUND
};

#define NUM_SPRITES_GAME 9
#define NUM_SOUNDS_GAME 0
#define NUM_TOWERS 2
#define NUM_ENEMIES 2

enum gameSprites{
  gBACKGROUND,
  gGRID_TILE,
  gALIEN1,
  gALIEN2,
  gBLUE1,
  gBLUE2,
  gBLUE3,
  gGREEN1,
  gGREEN2,
  gGREEN3
};

#define NUM_KEYS_GAME 10//keys 0-3 are for movement
                        //keys 4 is for selecton (enter/space)
                        // key 5-8 are undefined*/
                        // key 9 is for any other random key
enum keys{
  UP,
  DOWN,
  LEFT,
  RIGHT,
  SELECT,
  PAUSE,
  MENU,
  OTHER_KEY
};

#define FALSE 0
#define TRUE 1

#define BLUE1_PRICE 25
#define BLUE2_PRICE 20
#define BLUE3_PRICE 20
#define BLUE1_SELL 18
#define BLUE2_SELL 35
#define BLUE3_SELL 48
#define BLUE1_FIRERATE 180 
#define BLUE2_FIRERATE 165
#define BLUE3_FIRERATE 150
#define BLUE1_DMG 15 
#define BLUE2_DMG 18
#define BLUE3_DMG 25
#define BLUE1_RANGE 250
#define BLUE2_RANGE 250
#define BLUE3_RANGE 250

#define GREEN1_PRICE 15
#define GREEN2_PRICE 10
#define GREEN3_PRICE 10
#define GREEN1_SELL 10
#define GREEN2_SELL 18
#define GREEN3_SELL 26
#define GREEN1_FIRERATE 30
#define GREEN2_FIRERATE 20
#define GREEN3_FIRERATE 20
#define GREEN1_DMG 15
#define GREEN2_DMG 15
#define GREEN3_DMG 15
#define GREEN1_RANGE 300
#define GREEN2_RANGE 300
#define GREEN3_RANGE 350

#define ENEMY1_SPEED 0.30
