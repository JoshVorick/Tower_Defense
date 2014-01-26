#include "grid.h"

void initGrid(Grid* grid, int x, int y){
  int i,j;
  for(i=0; i<grid->dimensionX; i++)
    for(j=0; j<grid->dimensionY; j++){
      grid->tiles[i][j].x = x + i*50;
      grid->tiles[i][j].y = y + j*50;
      grid->tiles[i][j].myTower = NULL;
      if(j < grid->dimensionY - 1){ 
        grid->tiles[i][j].nextInPath = &grid->tiles[i][j+1];
        grid->tiles[i][j].dirToNextInPath = DOWN;
      }else{
        grid->tiles[i][j].nextInPath = NULL;
        grid->tiles[i][j].dirToNextInPath = DOWN;
      }
    }
  grid->selectedTileX = 0;
  grid->selectedTileY = 0;
  grid->selectedTile = &grid->tiles[grid->selectedTileX][grid->selectedTileY];

  //Add a path to some tiles to test path-following code
  grid->tiles[3][0].nextInPath = &grid->tiles[4][0];
  grid->tiles[3][0].dirToNextInPath = RIGHT;
  grid->tiles[4][1].nextInPath = &grid->tiles[4][1];
  grid->tiles[4][0].dirToNextInPath = DOWN;
  grid->tiles[4][1].nextInPath = &grid->tiles[3][1];
  grid->tiles[4][1].dirToNextInPath = LEFT;
};
