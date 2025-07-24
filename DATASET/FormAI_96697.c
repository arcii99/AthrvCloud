//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: funny
/* Welcome to the Percolation Simulator! 
 * Get ready for some wild, wacky, and watery fun!
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 10 // Change this value to adjust the size of the grid
#define PERCOLATION_THRESHOLD 0.5 // Change this value to adjust the threshold for percolation

int main() {
  // Let's get this party started by setting up our grid and randomly filling it with water or air
  int grid[GRID_SIZE][GRID_SIZE];
  srand(time(NULL)); // Seed the random number generator with the current time

  printf("Initializing grid with water and air...\n");
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      grid[i][j] = rand() % 2; // 0 represents air, 1 represents water
    }
  }

  // Now we need to check if the water can percolate through the grid
  // We'll start at the top and check each cell to see if it's connected to the bottom
  // If we find a connected path, the water can percolate!

  printf("Checking for percolation...\n");
  int connected_to_bottom[GRID_SIZE][GRID_SIZE] = {0}; // We'll use this array to keep track of which cells are connected to the bottom

  // First we'll check the top row. If a cell contains water, we'll recursively check its neighbors to see if they're also 
  // connected to the bottom
  for (int j = 0; j < GRID_SIZE; j++) {
    if (grid[0][j] == 1) {
      connected_to_bottom[0][j] = 1;
      printf("Water found at (%d,%d)! Checking neighbors...\n", 0, j);
      check_neighbors(0, j, grid, connected_to_bottom);
    }
  }

  // Now let's check the bottom row to see if any cells are connected to the top
  int water_can_percolate = 0;
  for (int j = 0; j < GRID_SIZE; j++) {
    if (connected_to_bottom[GRID_SIZE-1][j] == 1) {
      water_can_percolate = 1;
      break;
    }
  }

  // Finally, let's print out the results!
  if (water_can_percolate) {
    printf("Hooray! The water can percolate through the grid!\n");
    printf("Time to get your swim trunks and jump in!\n");
  } else {
    printf("Oh no! The water can't percolate through the grid!\n");
    printf("Looks like it's time to start digging a new well...\n");
  }

  return 0;
}

// This function recursively checks neighboring cells to see if they're connected to the bottom
void check_neighbors(int i, int j, int grid[GRID_SIZE][GRID_SIZE], int connected_to_bottom[GRID_SIZE][GRID_SIZE]) {
  if (i > 0 && grid[i-1][j] == 1 && connected_to_bottom[i-1][j] == 0) {
    connected_to_bottom[i-1][j] = 1;
    printf("Water found at (%d,%d)! Checking neighbors...\n", i-1, j);
    check_neighbors(i-1, j, grid, connected_to_bottom);
  }
  if (i < GRID_SIZE-1 && grid[i+1][j] == 1 && connected_to_bottom[i+1][j] == 0) {
    connected_to_bottom[i+1][j] = 1;
    printf("Water found at (%d,%d)! Checking neighbors...\n", i+1, j);
    check_neighbors(i+1, j, grid, connected_to_bottom);
  }
  if (j > 0 && grid[i][j-1] == 1 && connected_to_bottom[i][j-1] == 0) {
    connected_to_bottom[i][j-1] = 1;
    printf("Water found at (%d,%d)! Checking neighbors...\n", i, j-1);
    check_neighbors(i, j-1, grid, connected_to_bottom);
  }
  if (j < GRID_SIZE-1 && grid[i][j+1] == 1 && connected_to_bottom[i][j+1] == 0) {
    connected_to_bottom[i][j+1] = 1;
    printf("Water found at (%d,%d)! Checking neighbors...\n", i, j+1);
    check_neighbors(i, j+1, grid, connected_to_bottom);
  }
}