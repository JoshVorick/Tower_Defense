#include "grid.h"

void initGrid(Grid* grid, int x, int y){
  int i,j;
  for(i=0; i<grid->dimensionX; i++)
    for(j=0; j<grid->dimensionY; j++){
      grid->tiles[i][j].x = x + i*50;
      grid->tiles[i][j].y = y + j*50;
      grid->tiles[i][j].i = i;
      grid->tiles[i][j].j = j;
      grid->tiles[i][j].myTower = NULL;
      if(j < grid->dimensionY - 1){ 
        grid->tiles[i][j].nextInPath = &grid->tiles[i][j+1];
        grid->tiles[i][j].dirToNextInPath = DOWN;
      }else{
        grid->tiles[i][j].nextInPath = NULL;
        grid->tiles[i][j].dirToNextInPath = DOWN;
      }
    }
  grid->selectedTile = &grid->tiles[0][0];
  grid->blocksPath = FALSE;
  grid->startTile = &grid->tiles[3][0];
  grid->endTile = &grid->tiles[3][grid->dimensionY-1];
};
