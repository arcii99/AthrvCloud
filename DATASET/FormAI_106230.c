//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 // grid size
#define THRESHOLD 0.6 // percolation threshold
#define BLOCK '#'
#define EMPTY ' '

int createGrid(char grid[N][N]) {
  int i, j;
  
  // initialize grid to empty blocks
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      grid[i][j] = EMPTY;
    }
  }

  // randomly fill grid with blocks
  srand(time(NULL));
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      if ((double) rand() / (double) RAND_MAX < THRESHOLD) {
        grid[i][j] = BLOCK;
      }
    }
  }

  // add top and bottom walls
  for (j = 0; j < N; j++) {
    grid[0][j] = BLOCK;
    grid[N-1][j] = BLOCK;
  }

  return 0;
}

int printGrid(char grid[N][N]) {
  int i, j;

  // print grid
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      printf("%c ", grid[i][j]);
    }
    printf("\n");
  }

  return 0;
}

int percolate(char grid[N][N], int i, int j) {
  grid[i][j] = EMPTY;

  // check if percolation is possible in each direction
  if (i-1 >= 0 && grid[i-1][j] == EMPTY) {
    percolate(grid, i-1, j);
  }
  if (j+1 < N && grid[i][j+1] == EMPTY) {
    percolate(grid, i, j+1);
  }
  if (i+1 < N && grid[i+1][j] == EMPTY) {
    percolate(grid, i+1, j);
  }
  if (j-1 >= 0 && grid[i][j-1] == EMPTY) {
    percolate(grid, i, j-1);
  }

  return 0;
}

int simulation(char grid[N][N]) {
  int i, j, percolates = 0;

  // check if percolation is possible from top to bottom
  for (j = 0; j < N; j++) {
    if (grid[0][j] == EMPTY) {
      percolate(grid, 0, j);
    }
  }

  // check if system percolates
  for (j = 0; j < N; j++) {
    if (grid[N-1][j] == EMPTY) {
      percolates = 1;
      break;
    }
  }

  return percolates;
}

int main() {
  char grid[N][N];
  int percolates;
  
  createGrid(grid);
  printGrid(grid);
  printf("\n");
  
  percolates = simulation(grid);
  
  if (percolates) {
    printf("The system percolates!\n");
  } else {
    printf("The system does not percolate.\n");
  }

  return 0;
}