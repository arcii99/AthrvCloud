//FormAI DATASET v1.0 Category: Sudoku solver ; Style: scientific
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 9 // Each sudoku puzzle is 9x9

// Struct for cell in Sudoku grid
typedef struct {
  int row;
  int col;
} Cell;

//Function prototypes
void printGrid(int grid[N][N]);
bool findEmpty(Cell *cell, int grid[N][N]);
bool isValid(Cell cell, int num, int grid[N][N]);
bool solveSudoku(int grid[N][N]);

// Function to print the Sudoku grid
void printGrid(int grid[N][N]) {
  int i, j;
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }
}

// Function to find an unassigned cell, returns true if all cells are assigned
bool findEmpty(Cell *cell, int grid[N][N]) {
  int row, col;
  for (row = 0; row < N; row++) {
    for (col = 0; col < N; col++) {
      if (grid[row][col] == 0) {
        cell->row = row;
        cell->col = col;
        return true;
      }
    }
  }
  return false;
}

// Function to check if a num is valid in the given cell
bool isValid(Cell cell, int num, int grid[N][N]) {
  int	i, row = cell.row, col = cell.col,
      boxRowStart = row - row % 3, // Starting row of 3x3 box
      boxColStart = col - col % 3; // Starting column of 3x3 box

  // Check column and row for repeated num
  for (i = 0; i < N; i++) {
    if (grid[row][i] == num || grid[i][col] == num) {
      return false;
    }
  }

  // Check the 3x3 box for repeated num
  for (i = 0; i < 3; i++) {
    if (grid[boxRowStart + i][boxColStart + i] == num) {
      return false;
    }
  }

  return true; // It has a valid num
}

bool solveSudoku(int grid[N][N]) {
  Cell cell;

  // if there is no empty cell, the Sudoku is solved
  if (!findEmpty(&cell, grid)) {
    return true;
  }

  int num;
  for (num = 1; num <= N; num++) { // Try all valid numbers
    if (isValid(cell, num, grid)) { // Check with the cell
      grid[cell.row][cell.col] = num; // Set num in cell

      if (solveSudoku(grid)) { // Recursively solve if next cell can be filled
        return true;
      }

      // If solution not reached, backtrack by unsetting the cell
      grid[cell.row][cell.col] = 0;
    }
  }

  return false; // No solution found
}

// Driver Program
int main() {
  // Sample Sudoku grid, where 0 represents unassigned cells
  int grid[N][N] = {
    {0, 0, 0, 0, 0, 0, 0, 9, 0},
    {0, 0, 0, 3, 0, 8, 4, 0, 0},
    {0, 8, 0, 0, 0, 0, 6, 7, 0},
    {2, 0, 0, 0, 0, 0, 9, 0, 8},
    {0, 1, 5, 0, 0, 0, 0, 0, 0},
    {0, 6, 0, 9, 0, 0, 0, 0, 0},
    {8, 0, 0, 0, 0, 5, 0, 6, 0},
    {0, 0, 3, 0, 0, 0, 0, 0, 9},
    {5, 0, 0, 0, 0, 0, 2, 0, 0}
  };

  if (solveSudoku(grid)) {
    printGrid(grid);
  } else {
    printf("No solution found!");
  }

  return 0;
}