#include "grid.h"

void initGrid(Grid* grid, int x, int y){
  int i,j;
  for(i=0; i<grid->dimensionX; i++)
    for(j=0; j<grid->dimensionY; j++){
      grid->tiles[i][j].x = x + i*50;
      grid->tiles[i][j].y = y + j*50;
      grid->tiles[i][j].hasTower = FALSE;
      if(j < grid->dimensionY - 1)  
        grid->tiles[i][j].nextInPath = &grid->tiles[i][j+1];
      else
        grid->tiles[i][j].nextInPath = NULL;
    }
  grid->selectedTile = &grid->tiles[0][0];
};
