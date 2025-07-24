//FormAI DATASET v1.0 Category: Sudoku solver ; Style: innovative
#include <stdio.h>

#define GRID_SIZE 9
#define EMPTY_CELL 0

void print_grid(int grid[GRID_SIZE][GRID_SIZE]) {
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }
}

int is_valid(int grid[GRID_SIZE][GRID_SIZE], int row, int column, int value) {
  // Check if value already exists in row
  for (int j = 0; j < GRID_SIZE; j++) {
    if (grid[row][j] == value) {
      return 0;
    }
  }

  // Check if value already exists in column
  for (int i = 0; i < GRID_SIZE; i++) {
    if (grid[i][column] == value) {
      return 0;
    }
  }

  // Check if value already exists in 3x3 box
  int box_row = row - row % 3;
  int box_col = column - column % 3;
  for (int i = box_row; i < box_row + 3; i++) {
    for (int j = box_col; j < box_col + 3; j++) {
      if (grid[i][j] == value) {
        return 0;
      }
    }
  }

  return 1;
}

int solve_sudoku(int grid[GRID_SIZE][GRID_SIZE], int row, int column) {
  // If we reach the end of the grid, return true
  if (row == GRID_SIZE) {
    return 1;
  }

  // If we reach the end of a row, move to next row
  if (column == GRID_SIZE) {
    return solve_sudoku(grid, row + 1, 0);
  }

  // If the cell is already filled, move to next column
  if (grid[row][column] != EMPTY_CELL) {
    return solve_sudoku(grid, row, column + 1);
  }

  // Try all possible values for the current cell
  for (int value = 1; value <= GRID_SIZE; value++) {
    if (is_valid(grid, row, column, value)) {
      grid[row][column] = value;

      if (solve_sudoku(grid, row, column + 1)) {
        return 1;
      }

      // If solution is not found, backtrack and try another value
      grid[row][column] = EMPTY_CELL;
    }
  }

  // If no value works, backtrack
  return 0;
}

int main() {
  int grid[GRID_SIZE][GRID_SIZE] = {
    {3, 0, 6, 5, 0, 8, 4, 0, 0},
    {5, 2, 0, 0, 0, 0, 0, 0, 0},
    {0, 8, 7, 0, 0, 0, 0, 3, 1},
    {0, 0, 3, 0, 0, 0, 0, 2, 0},
    {9, 0, 0, 8, 0, 0, 0, 0, 5},
    {0, 5, 0, 0, 0, 0, 6, 0, 0},
    {1, 3, 0, 0, 0, 0, 2, 5, 0},
    {0, 0, 0, 0, 0, 0, 0, 7, 4},
    {0, 0, 5, 2, 0, 6, 3, 0, 0}
  };

  if (solve_sudoku(grid, 0, 0)) {
    printf("Solved Sudoku:\n");
    print_grid(grid);
  } else {
    printf("Unable to find solution!\n");
  }

  return 0;
}