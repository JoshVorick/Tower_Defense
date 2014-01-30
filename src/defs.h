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

#define NUM_SPRITES_GAME 6 
#define NUM_SOUNDS_GAME 0
#define NUM_TOWERS 2
#define NUM_ENEMIES 2

enum gameSprites{
  gBACKGROUND,
  gGRID_TILE,
  gENEMY1,
  gENEMY2,
  gBLUE1,
  gGREEN1,
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
#define BLUE1_SELL 18
#define BLUE1_FIRERATE 100 
#define BLUE1_DMG 15 
#define BLUE1_RANGE 450

#define GREEN1_PRICE 15
#define GREEN1_SELL 18
#define GREEN1_FIRERATE 30
#define GREEN1_DMG 5 
#define GREEN1_RANGE 300

#define ENEMY1_SPEED 0.4
#define ENEMY1_HEALTH 100
#define ENEMY1_GOLD 5
#define ENEMY1_SCORE 100
#define ENEMY1_R 10
#define ENEMY1_G 5
#define ENEMY1_B 15

#define ENEMY2_SPEED 0.2
#define ENEMY2_HEALTH 200
#define ENEMY2_GOLD 8
#define ENEMY2_SCORE 150
#define ENEMY2_R 15
#define ENEMY2_G 20
#define ENEMY2_B 5
