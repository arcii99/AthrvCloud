//FormAI DATASET v1.0 Category: Physics simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define ROWS 6
#define COLS 6
#define MIN_WEIGHT 1
#define MAX_WEIGHT 10
#define MAX_STEPS 50

// Function prototypes
void generateGrid(int grid[][COLS]);
void printGrid(int grid[][COLS]);
void simulateGravity(int grid[][COLS], int steps);
void applyGravity(int grid[][COLS]);
int getEmptyRow(int grid[][COLS], int col, int row);
int getWeightedCount(int grid[][COLS]);

// Main function
int main() {
  int grid[ROWS][COLS];
  int steps;

  generateGrid(grid);
  printf("Initial grid:\n");
  printGrid(grid);

  printf("Enter number of simulation steps (maximum %d): ", MAX_STEPS);
  scanf("%d", &steps);

  // Limit number of steps to prevent infinite loops
  if (steps > MAX_STEPS) {
    printf("Maximum allowed steps is %d. Running simulation with %d steps.\n", MAX_STEPS, MAX_STEPS);
    steps = MAX_STEPS;
  }

  simulateGravity(grid, steps);

  printf("\nFinal grid:\n");
  printGrid(grid);

  return 0;
}

// Function to randomly generate weights on the grid
void generateGrid(int grid[][COLS]) {
  int i, j;

  // Seed random number generator
  srandom(time(NULL));

  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      grid[i][j] = MIN_WEIGHT + (random() % (MAX_WEIGHT - MIN_WEIGHT + 1));
    }
  }
}

// Function to print the grid
void printGrid(int grid[][COLS]) {
  int i, j;

  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }
}

// Function to simulate gravity on the grid
void simulateGravity(int grid[][COLS], int steps) {
  int i;

  for (i = 0; i < steps; i++) {
    applyGravity(grid);
    printf("\nStep %d:\n", i + 1);
    printGrid(grid);
  }
}

// Function to apply gravity on the grid
void applyGravity(int grid[][COLS]) {
  int i, j;

  for (i = ROWS - 1; i >= 0; i--) {
    for (j = 0; j < COLS; j++) {
      if (grid[i][j] != 0) {
        int emptyRow = getEmptyRow(grid, j, i);
        
        if (emptyRow != -1) {
          grid[emptyRow][j] = grid[i][j];
          grid[i][j] = 0;
        }
      }
    }
  }
}

// Function to get the row number of the first empty cell
int getEmptyRow(int grid[][COLS], int col, int row) {
  int i;

  // Check if current cell is already the bottom cell in its column
  if (row == ROWS - 1) {
    return -1;
  }

  for (i = row + 1; i < ROWS; i++) {
    if (grid[i][col] == 0) {
      return i;
    }
  }

  return -1;
}

// Function to get the count of cells with weight greater than their surrounding cells
int getWeightedCount(int grid[][COLS]) {
  int i, j, count = 0;

  for (i = 1; i < ROWS - 1; i++) {
    for (j = 1; j < COLS - 1; j++) {
      if (grid[i][j] > grid[i - 1][j] && grid[i][j] > grid[i + 1][j] && grid[i][j] > grid[i][j - 1] && grid[i][j] > grid[i][j + 1]) {
        count++;
      }
    }
  }

  return count;
}