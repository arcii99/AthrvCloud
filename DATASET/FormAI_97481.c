//FormAI DATASET v1.0 Category: Game of Life ; Style: inquisitive
// Welcome to the Game of Life!
// This is a C program that simulates the life of cells in a grid.
// The rules are as follows:
// - Any live cell with less than two live neighbors dies, as if by underpopulation.
// - Any live cell with two or three live neighbors lives on to the next generation.
// - Any live cell with more than three live neighbors dies, as if by overpopulation.
// - Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

#include <stdio.h>
#include <stdlib.h>

// Define the size of the grid
#define ROWS 10
#define COLS 10

// Define the symbols used to represent live and dead cells
#define LIVE '*'
#define DEAD ' '

// Define a function to randomly initialize the grid
void init_grid(char grid[ROWS][COLS]) {
  int i, j;
  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      grid[i][j] = rand() % 2 ? LIVE : DEAD;
    }
  }
}

// Define a function to print the grid to the console
void print_grid(char grid[ROWS][COLS]) {
  int i, j;
  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      printf("%c ", grid[i][j]);
    }
    printf("\n");
  }
}

// Define a function to count the number of live neighbors for a cell
int count_live_neighbors(char grid[ROWS][COLS], int r, int c) {
  int i, j, count = 0;
  for (i = r - 1; i <= r + 1; i++) {
    for (j = c - 1; j <= c + 1; j++) {
      if (i >= 0 && i < ROWS && j >= 0 && j < COLS && !(i == r && j == c)) {
        count += grid[i][j] == LIVE;
      }
    }
  }
  return count;
}

// Define a function to update the grid based on the rules of the Game of Life
void update_grid(char grid[ROWS][COLS]) {
  int i, j, live_neighbors;
  char new_grid[ROWS][COLS];
  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      live_neighbors = count_live_neighbors(grid, i, j);
      if (grid[i][j] == LIVE) {
        if (live_neighbors < 2 || live_neighbors > 3) {
          new_grid[i][j] = DEAD;
        } else {
          new_grid[i][j] = LIVE;
        }
      } else {
        if (live_neighbors == 3) {
          new_grid[i][j] = LIVE;
        } else {
          new_grid[i][j] = DEAD;
        }
      }
    }
  }
  // Copy the updated grid back into the original grid
  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      grid[i][j] = new_grid[i][j];
    }
  }
}

int main() {
  char grid[ROWS][COLS];
  // Initialize the grid
  init_grid(grid);
  // Print the initial state of the grid
  printf("Initial state:\n");
  print_grid(grid);
  // Update the grid for 10 generations
  int i;
  for (i = 1; i <= 10; i++) {
    update_grid(grid);
    printf("Generation %d:\n", i);
    print_grid(grid);
  }
  return 0;
}