//FormAI DATASET v1.0 Category: Game of Life ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

// Define the size of the grid
#define GRID_WIDTH 10
#define GRID_HEIGHT 10

// Define the states of the cells
#define DEAD 0
#define ALIVE 1

// Helper function to count the number of live neighbors
int count_live_neighbors(int grid[][GRID_HEIGHT], int x, int y) {
  int count = 0;
  for(int i = x - 1; i <= x + 1; i++) {
    for(int j = y - 1; j <= y + 1; j++) {
      if(i >= 0 && i < GRID_WIDTH && j >= 0 && j < GRID_HEIGHT && !(i == x && j == y)) {
        if(grid[i][j] == ALIVE) {
          count++;
        }
      }
    }
  }
  return count;
}

// Function to update the state of the grid
void update_grid(int grid[][GRID_HEIGHT]) {
  // Create a temporary grid to hold the new state
  int temp_grid[GRID_WIDTH][GRID_HEIGHT];

  // Iterate over each cell in the grid
  for(int i = 0; i < GRID_WIDTH; i++) {
    for(int j = 0; j < GRID_HEIGHT; j++) {
      // Count the number of live neighbors
      int live_neighbors = count_live_neighbors(grid, i, j);

      // Apply the rules of the game
      if(grid[i][j] == ALIVE) {
        if(live_neighbors < 2 || live_neighbors > 3) {
          temp_grid[i][j] = DEAD;
        } else {
          temp_grid[i][j] = ALIVE;
        }
      } else {
        if(live_neighbors == 3) {
          temp_grid[i][j] = ALIVE;
        } else {
          temp_grid[i][j] = DEAD;
        }
      }
    }
  }

  // Copy the new state back to the original grid
  for(int i = 0; i < GRID_WIDTH; i++) {
    for(int j = 0; j < GRID_HEIGHT; j++) {
      grid[i][j] = temp_grid[i][j];
    }
  }
}

// Function to print the state of the grid
void print_grid(int grid[][GRID_HEIGHT]) {
  for(int i = 0; i < GRID_WIDTH; i++) {
    for(int j = 0; j < GRID_HEIGHT; j++) {
      if(grid[i][j] == ALIVE) {
        printf("*");
      } else {
        printf(".");
      }
    }
    printf("\n");
  }
}

// Main function
int main() {
  // Create a 2D array to represent the grid
  int grid[GRID_WIDTH][GRID_HEIGHT];

  // Initialize the grid to random values
  for(int i = 0; i < GRID_WIDTH; i++) {
    for(int j = 0; j < GRID_HEIGHT; j++) {
      grid[i][j] = rand() % 2;
    }
  }

  // Print the initial state of the grid
  printf("Generation 0\n");
  print_grid(grid);
  printf("\n");

  // Iterate over generations of the grid
  for(int gen = 1; gen <= 10; gen++) {
    update_grid(grid);
    printf("Generation %d\n", gen);
    print_grid(grid);
    printf("\n");
  }

  return 0;
}