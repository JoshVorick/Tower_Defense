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

#define NUM_SPRITES_GAME 8 
#define NUM_SOUNDS_GAME 0
#define NUM_TOWERS 4
#define NUM_ENEMIES 2
#define NUM_GAME_KEYS 20

enum gameSprites{
  gBACKGROUND,
  GRID_TILE,
  ENEMY1,
  ENEMY2,
  TRIANGLE,
  SQUARE,
  PENTAGON,
  HEXAGON
};

enum directions{
  LEFT,
  DOWN,
  UP,
  RIGHT
};

enum gameKeys{
  H,
  J,
  K,
  L,
  LEFT_ARROW,
  DOWN_ARROW,
  UP_ARROW,
  RIGHT_ARROW,
  ONE,
  TWO,
  THREE,
  FOUR,
  Q,
  W,
  E,
  A,
  S,
  D,
  SHIFT,
  SPACE
};

#define FALSE 0
#define TRUE 1

#define TRIANGLE_PRICE 300
#define TRIANGLE_SELL 230
#define TRIANGLE_FIRERATE 100 
#define TRIANGLE_DMG 15 
#define TRIANGLE_RANGE 200

#define SQUARE_PRICE 400
#define SQUARE_SELL 280
#define SQUARE_FIRERATE 30
#define SQUARE_DMG 20
#define SQUARE_RANGE 300

#define PENTAGON_PRICE 500
#define PENTAGON_SELL 400
#define PENTAGON_FIRERATE 30
#define PENTAGON_DMG 25 
#define PENTAGON_RANGE 400

#define HEXAGON_PRICE 600
#define HEXAGON_SELL 500
#define HEXAGON_FIRERATE 30
#define HEXAGON_DMG 30 
#define HEXAGON_RANGE 500

#define ENEMY1_SPEED 0.4
#define ENEMY1_HEALTH 100
#define ENEMY1_SCORE 100
#define ENEMY1_R 10
#define ENEMY1_G 5
#define ENEMY1_B 15

#define ENEMY2_SPEED 0.2
#define ENEMY2_HEALTH 200
#define ENEMY2_SCORE 150
#define ENEMY2_R 15
#define ENEMY2_G 20
#define ENEMY2_B 10
