//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define GRID_SIZE 20

// global variables
int grid[GRID_SIZE][GRID_SIZE];
int num_groups = 0;

// print grid
void print_grid() {
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }
}

// check if cell is inside the grid
bool in_grid(int row, int col) {
  return row >= 0 && row < GRID_SIZE && col >= 0 && col < GRID_SIZE;
}

// create a new group
void new_group(int row, int col) {
  num_groups++;
  grid[row][col] = num_groups;
}

// merge two groups
void merge_groups(int row1, int col1, int row2, int col2) {
  int group1 = grid[row1][col1];
  int group2 = grid[row2][col2];
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      if (grid[i][j] == group2) {
        grid[i][j] = group1;
      }
    }
  }
  num_groups--;
}

// simulate percolation
void simulate_percolation() {
  srand(time(NULL)); // seed random number generator
  while (num_groups > 1) {
    // randomly choose a cell
    int row = rand() % GRID_SIZE;
    int col = rand() % GRID_SIZE;
    // if cell is empty, create a new group
    if (grid[row][col] == 0) {
      new_group(row, col);
    }
    else {
      // randomly choose a neighbor
      int neighbors[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
      int r = rand() % 4;
      int n_row = row + neighbors[r][0];
      int n_col = col + neighbors[r][1];
      // if neighbor is inside the grid and not empty, merge groups
      if (in_grid(n_row, n_col) && grid[n_row][n_col] != 0 && grid[n_row][n_col] != grid[row][col]) {
        merge_groups(row, col, n_row, n_col);
      }
    }
  }
}

int main() {
  // initialize grid to all zeroes
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      grid[i][j] = 0;
    }
  }
  // simulate percolation
  simulate_percolation();
  // print final grid
  print_grid();
  return 0;
}