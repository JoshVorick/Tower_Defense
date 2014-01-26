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
            if(game->grid->selectedTile->myTower == NULL)
              addTower(game, gBLUE1);
          case SDLK_RETURN://Enter key
            if(game->grid->selectedTile->myTower == NULL)
              addTower(game, gGREEN1);
            break;
          case SDLK_w:
            if(game->grid->selectedTileY > 0){
              game->grid->selectedTileY -= 1;
              game->grid->selectedTile = &game->grid->tiles[game->grid->selectedTileX][game->grid->selectedTileY];
            }
            break;
          case SDLK_a:
            if(game->grid->selectedTileX > 0){
              game->grid->selectedTileX -= 1;
              game->grid->selectedTile = &game->grid->tiles[game->grid->selectedTileX][game->grid->selectedTileY];
            }
            break;
          case SDLK_s:
            if(game->grid->selectedTileY < game->grid->dimensionY-1){
              game->grid->selectedTileY += 1;
              game->grid->selectedTile = &game->grid->tiles[game->grid->selectedTileX][game->grid->selectedTileY];
            }
            break;
          case SDLK_d:
            if(game->grid->selectedTileX < game->grid->dimensionX-1){
              game->grid->selectedTileX += 1;
              game->grid->selectedTile = &game->grid->tiles[game->grid->selectedTileX][game->grid->selectedTileY];
            }
            break;
          default:
            break;
        }
        game->input->keys[NUM_KEYS_GAME - 1] = TRUE;
        break;
    }
  }
};
