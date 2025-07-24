//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 10 // Change this to adjust the size of the grid
#define THRESHOLD 0.4 // Change this to adjust the threshold for percolation

// Function to print the grid
void print_grid(int grid[][GRID_SIZE]) {
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }
}

// Function to check if the grid percolates
int does_percolate(int grid[][GRID_SIZE]) {
  int top[GRID_SIZE] = {0}; // Keep track of which sites are connected to the top row
  int bottom[GRID_SIZE] = {0}; // Keep track of which sites are connected to the bottom row
  
  // Check which sites are connected to the top row
  for (int j = 0; j < GRID_SIZE; j++) {
    if (grid[0][j] == 1) {
      top[j] = 1;
    }
  }
  
  // Check which sites are connected to the bottom row
  for (int j = 0; j < GRID_SIZE; j++) {
    if (grid[GRID_SIZE - 1][j] == 1) {
      bottom[j] = 1;
    }
  }
  
  // Check if there is a path from the top to the bottom row
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      if (grid[i][j] == 1) {
        if (i > 0 && grid[i-1][j] == 1 && top[j] == 1) {
          bottom[j] = 1;
        }
        if (i < GRID_SIZE - 1 && grid[i+1][j] == 1 && bottom[j] == 1) {
          top[j] = 1;
        }
      }
    }
  }
  
  // Check if there is a path from the top to the bottom row
  for (int j = 0; j < GRID_SIZE; j++) {
    if (top[j] == 1 && bottom[j] == 1) {
      return 1;
    }
  }
  
  return 0;
}

int main() {
  int grid[GRID_SIZE][GRID_SIZE] = {0}; // Initialize the grid to all zeros

  // Seed the random number generator
  srand(time(NULL));

  // Fill the grid randomly with zeros and ones
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      if ((double) rand() / RAND_MAX < THRESHOLD) {
        grid[i][j] = 1;
      }
    }
  }

  // Print the initial grid
  printf("Initial Grid:\n");
  print_grid(grid);

  // Check if the grid percolates
  if (does_percolate(grid)) {
    printf("The grid percolates!\n");
  } else {
    printf("The grid does not percolate.\n");
  }
  
  return 0;
}