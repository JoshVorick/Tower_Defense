#include "input.h"

extern int addTower(Game *game, int towerType);
extern void wouldBlockPath(Grid *grid);
extern void findPath(Grid *grid);
extern void freeGame(Game *game);

void initInputGame(Game *game){
};

void getInputGame(Game *game){
  SDL_Event event;

  while(SDL_PollEvent(&event)){
    switch(event.type){
      case SDL_QUIT:
        freeGame(game);
        exit(0);
        break;
      case SDL_KEYDOWN:
        switch(event.key.keysym.sym){
          case SDLK_ESCAPE:
            freeGame(game);
            exit(0);
            break;
          case SDLK_m:
            game->inGame = FALSE;
            break;
          
          case SDLK_1:
            game->selectedTowerType = gBLUE1;
            break;
          case SDLK_2:
            game->selectedTowerType = gGREEN1;
            break;

          case SDLK_q:
            if(game->rRatio < 255)
              game->rRatio += 1;
            break;
          case SDLK_a:
            if(game->rRatio > 1)
              game->rRatio -= 1;
            break;
          case SDLK_w:
            if(game->gRatio < 255)
              game->gRatio += 1;
            break;
          case SDLK_s:
            if(game->gRatio > 1)
              game->gRatio -= 1;
            break;
          case SDLK_e:
            if(game->bRatio < 255)
              game->bRatio += 1;
            break;
          case SDLK_d:
            if(game->bRatio > 1)
              game->bRatio -= 1;
            break;
          
          case SDLK_SPACE:
            if(addTower(game, game->selectedTowerType) == TRUE)//returns true if tower was added
              findPath(game->grid);
            break;

          case SDLK_k:
            if(game->grid->selectedTile->j > 0){
              //move selectedTile
              game->grid->selectedTile = &game->grid->tiles[game->grid->selectedTile->i][game->grid->selectedTile->j-1];
              //recalculate if adding a tower here would block the path
              wouldBlockPath(game->grid);
            }
            break;
          case SDLK_h:
            if(game->grid->selectedTile->i > 0){
              //move selectedTile
              game->grid->selectedTile = &game->grid->tiles[game->grid->selectedTile->i-1][game->grid->selectedTile->j];
              //recalc if adding a tower here would block path
              wouldBlockPath(game->grid);
            }
            break;
          case SDLK_j:
            if(game->grid->selectedTile->j < game->grid->dimensionY-1){
              //move selectedTile
              game->grid->selectedTile = &game->grid->tiles[game->grid->selectedTile->i][game->grid->selectedTile->j + 1];
              //recalculate if adding a tower here would block path
              wouldBlockPath(game->grid);
            }
            break;
          case SDLK_l:
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
        break;
    }
  }
};
