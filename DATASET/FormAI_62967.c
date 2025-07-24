//FormAI DATASET v1.0 Category: Game of Life ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40

void printGrid(int grid[ROWS][COLS]) {
  for(int i=0; i<ROWS; i++) {
    for(int j=0; j<COLS; j++) {
      if(grid[i][j] == 1) {
        printf(" # ");
      } else {
        printf(" . ");
      }
    }
    printf("\n");
  }
}

int countNeighbors(int grid[ROWS][COLS], int x, int y) {
  int count = 0;

  // check top row
  if(x > 0) {
    if(grid[x-1][y] == 1) count++;
    if(y > 0 && grid[x-1][y-1] == 1) count++;
    if(y < COLS-1 && grid[x-1][y+1] == 1) count++;
  }

  // check bottom row
  if(x < ROWS-1) {
    if(grid[x+1][y] == 1) count++;
    if(y > 0 && grid[x+1][y-1] == 1) count++;
    if(y < COLS-1 && grid[x+1][y+1] == 1) count++;
  }

  // check middle row
  if(y > 0 && grid[x][y-1] == 1) count++;
  if(y < COLS-1 && grid[x][y+1] == 1) count++;

  return count;
}


void updateGrid(int grid[ROWS][COLS]) {
  int newGrid[ROWS][COLS];

  for(int i=0; i<ROWS; i++) {
    for(int j=0; j<COLS; j++) {
      int neighbors = countNeighbors(grid, i, j);

      if(grid[i][j] == 1) {
        if(neighbors < 2 || neighbors > 3) {
          newGrid[i][j] = 0;
        } else {
          newGrid[i][j] = 1;
        }
      } else {
        if(neighbors == 3) {
          newGrid[i][j] = 1;
        } else {
          newGrid[i][j] = 0;
        }
      }
    }
  }

  // copy new grid values to original grid
  for(int i=0; i<ROWS; i++) {
    for(int j=0; j<COLS; j++) {
      grid[i][j] = newGrid[i][j];
    }
  }
}

int main() {
  int grid[ROWS][COLS];

  // initialize grid randomly
  srand(time(NULL));
  for(int i=0; i<ROWS; i++) {
    for(int j=0; j<COLS; j++) {
      grid[i][j] = rand() % 2;
    }
  }

  // main game loop
  while(1) {
    system("clear");  // clear terminal window
    printGrid(grid);
    updateGrid(grid);
  }

  return 0;
}