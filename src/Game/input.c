#include "input.h"

extern void addTower(Game *game, int towerType);
extern void wouldBlockPath(Grid *grid);
extern void findPath(Grid *grid);

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
            if(game->grid->blocksPath == FALSE)
              addTower(game, gBLUE1);
          case SDLK_RETURN://Enter key
            if(game->grid->blocksPath == FALSE)
              addTower(game, gGREEN1);
            break;
          case SDLK_w:
            if(game->grid->selectedTile->j > 0){
              //move selectedTile
              game->grid->selectedTile = &game->grid->tiles[game->grid->selectedTile->i][game->grid->selectedTile->j-1];
              //recalculate if adding a tower here would block the path
              wouldBlockPath(game->grid);
            }
            break;
          case SDLK_a:
            if(game->grid->selectedTile->i > 0){
              //move selectedTile
              game->grid->selectedTile = &game->grid->tiles[game->grid->selectedTile->i-1][game->grid->selectedTile->j];
              //recalc if adding a tower here would block path
              wouldBlockPath(game->grid);
            }
            break;
          case SDLK_s:
            if(game->grid->selectedTile->j < game->grid->dimensionY-1){
              //move selectedTile
              game->grid->selectedTile = &game->grid->tiles[game->grid->selectedTile->i][game->grid->selectedTile->j + 1];
              //recalculate if adding a tower here would block path
              wouldBlockPath(game->grid);
            }
            break;
          case SDLK_d:
            if(game->grid->selectedTile->i < game->grid->dimensionX-1){
              //move selectedTile
              game->grid->selectedTile = &game->grid->tiles[game->grid->selectedTile->i+1][game->grid->selectedTile->j];
              //recalculate if adding a tower here would block path
              wouldBlockPath(game->grid);
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
