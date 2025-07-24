//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants
#define ROWS 20
#define COLS 40
#define BLOCK '#'
#define SPACE ' '

// Define function to randomly fill grid with BLOCK or SPACE characters
void fillGrid(char grid[ROWS][COLS], float density) {
  for(int i = 0; i < ROWS; i++) {
    for(int j = 0; j < COLS; j++) {
      if((float)rand() / (float)RAND_MAX <= density) {
        grid[i][j] = BLOCK;
      } else {
        grid[i][j] = SPACE;
      }
    }
  }
}

// Define function to print grid
void printGrid(char grid[ROWS][COLS]) {
  for(int i = 0; i < ROWS; i++) {
    for(int j = 0; j < COLS; j++) {
      printf("%c", grid[i][j]);
    }
    printf("\n");
  }
}

// Define function to simulate percolation
int simulatePercolation(char grid[ROWS][COLS]) {
  // Define variables
  int open[ROWS][COLS] = {{0}};
  int topOpen = 0;
  int bottomOpen = 0;

  // Set top row to open
  for(int j = 0; j < COLS; j++) {
    if(grid[0][j] == SPACE) {
      open[0][j] = 1;
      topOpen = 1;
    }
  }

  // Iterate through grid and check if each block is connected to a block above it using depth-first search
  for(int i = 1; i < ROWS; i++) {
    for(int j = 0; j < COLS; j++) {
      if(grid[i][j] == BLOCK) {
        continue;
      }

      if(j > 0 && open[i - 1][j - 1] == 1) {
        open[i][j] = 1;
      } else if(open[i - 1][j] == 1) {
        open[i][j] = 1;
      } else if(j < COLS - 1 && open[i - 1][j + 1] == 1) {
        open[i][j] = 1;
      }

      if(i == ROWS - 1 && open[i][j] == 1) {
        bottomOpen = 1;
      }
    }
  }

  // Return 1 if there is a path from top to bottom, else 0
  if(topOpen && bottomOpen) {
    return 1;
  } else {
    return 0;
  }
}

// Main function
int main() {
  // Initialize random number generator
  srand(time(NULL));

  // Define variables
  char grid[ROWS][COLS];
  float density = 0.5;
  int runs = 100;
  int percolationCount = 0;

  // Iterate through simulations
  for(int i = 0; i < runs; i++) {
    fillGrid(grid, density);
    percolationCount += simulatePercolation(grid);
  }

  // Print results
  printf("Simulation results:\n");
  printf("Density: %.2f\n", density);
  printf("Runs: %d\n", runs);
  printf("Percolation count: %d\n", percolationCount);
  printf("Percolation probability: %.2f\n", (float)percolationCount / (float)runs);

  // Return exit code 0
  return 0;
}