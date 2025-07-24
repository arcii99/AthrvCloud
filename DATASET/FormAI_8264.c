//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 // Size of grid
#define P 0.6 // Probability of cell being open

int grid[N][N];
int open[N][N];

void initialize_grid() {
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      grid[i][j] = 0;
      open[i][j] = 0;
    }
  }
}

void open_random_cells() {
  srand(time(NULL)); // Seed the random number generator
  
  for(int i = 0; i < N * N; i++) {
    int row = rand() % N;
    int col = rand() % N;
    
    if(open[row][col] == 0) { // If cell is not already open
      float r = (float) rand() / RAND_MAX;
      if(r < P) { // Cell is open
        open[row][col] = 1;
        grid[row][col] = 1;
      }
    }
  }
}

int percolates() {
  // Check if any cell in top row is open
  for(int i = 0; i < N; i++) {
    if(open[0][i] == 1) {
      grid[0][i] = 2;
      return 1;
    }
  }
  
  // Check if any open cell is connected to top row
  for(int i = 1; i < N; i++) {
    for(int j = 0; j < N; j++) {
      if(open[i][j] == 1) {
        if(grid[i-1][j] == 2 || grid[i][j-1] == 2 || grid[i][j+1] == 2) {
          grid[i][j] = 2;
          return 1;
        }
      }
    }
  }
  
  return 0; // Does not percolate
}

int main() {
  initialize_grid();
  open_random_cells();
  
  if(percolates()) {
    printf("Percolates!\n");
  } else {
    printf("Does not percolate.\n");
  }
  
  return 0;
}