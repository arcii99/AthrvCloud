//FormAI DATASET v1.0 Category: Game of Life ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

// Fill the grid with randomly generated cells
void fillGrid(int grid[][COLS]) {
  // Use the time function to seed the random generator
  srand(time(NULL));
  int i, j;
  for(i = 0; i < ROWS; i++) {
    for(j = 0; j < COLS; j++) {
      grid[i][j] = rand() % 2;
    }
  }
}

// Print the grid to the console
void printGrid(int grid[][COLS]) {
  int i, j;
  for(i = 0; i < ROWS; i++) {
    for(j = 0; j < COLS; j++) {
      // Use '#' to represent a live cell and '.' to represent a dead cell
      if(grid[i][j]) {
        printf("#");
      }
      else {
        printf(".");
      }
    }
    printf("\n");
  }
}

// Check if a cell is in the grid and is live
int isLive(int grid[][COLS], int row, int col) {
  if(row < 0 || row >= ROWS || col < 0 || col >= COLS) {
    // The cell is outside the grid, so it is dead
    return 0;
  }
  return grid[row][col];
}

// Compute the next generation of cells based on the current generation
void nextGeneration(int grid[][COLS]) {
  int i, j, row, col, numLiveNeighbors;
  int temp[ROWS][COLS];
  // Copy the grid into the temp array
  for(i = 0; i < ROWS; i++) {
    for(j = 0; j < COLS; j++) {
      temp[i][j] = grid[i][j];
    }
  }
  // Compute the next generation
  for(i = 0; i < ROWS; i++) {
    for(j = 0; j < COLS; j++) {
      numLiveNeighbors = 0;
      // Check each of the cell's neighbors
      for(row = i - 1; row <= i + 1; row++) {
        for(col = j - 1; col <= j + 1; col++) {
          if(!(row == i && col == j) && isLive(grid, row, col)) {
            numLiveNeighbors++;
          }
        }
      }
      if(grid[i][j] && (numLiveNeighbors < 2 || numLiveNeighbors > 3)) {
        // The cell is currently live, but it will die in the next generation
        temp[i][j] = 0;
      }
      else if(!grid[i][j] && numLiveNeighbors == 3) {
        // The cell is currently dead, but it will become live in the next generation
        temp[i][j] = 1;
      }
    }
  }
  // Copy the temp array back into the grid
  for(i = 0; i < ROWS; i++) {
    for(j = 0; j < COLS; j++) {
      grid[i][j] = temp[i][j];
    }
  }
}

int main() {
  int grid[ROWS][COLS];
  fillGrid(grid);
  // Run 20 generations of the game
  int i;
  for(i = 0; i < 20; i++) {
    printf("Generation %d:\n", i + 1);
    printGrid(grid);
    nextGeneration(grid);
    printf("\n");
  }
  return 0;
}