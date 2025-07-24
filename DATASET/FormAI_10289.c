//FormAI DATASET v1.0 Category: Sudoku solver ; Style: multivariable
#include <stdio.h>
#include <stdbool.h>

#define SIZE 9

int grid[SIZE][SIZE];

// Function to print the Sudoku grid
void printGrid() {
  printf("Sudoku Grid:\n");
  for(int i = 0; i < SIZE; i++) {
    for(int j = 0; j < SIZE; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

// Function to check if the given value can be placed in the given cell
bool isSafe(int row, int col, int num) {

  // Check if the value already exists in the row
  for(int i = 0; i < SIZE; i++) {
    if(grid[row][i] == num) {
      return false;
    }
  }

  // Check if the value already exists in the column
  for(int i = 0; i < SIZE; i++) {
    if(grid[i][col] == num) {
      return false;
    }
  }

  // Check if the value already exists in the 3x3 box
  int boxRowStart = row - row % 3;
  int boxColStart = col - col % 3;
  for(int i = boxRowStart; i < boxRowStart + 3; i++) {
    for(int j = boxColStart; j < boxColStart + 3; j++) {
      if(grid[i][j] == num) {
        return false;
      }
    }
  }

  // If the value does not exist in the row, column or 3x3 box, return true
  return true;
}

// Function to solve the Sudoku puzzle
bool solveSudoku() {
  int row, col;

  // Check if there are any empty cells in the grid
  bool foundEmpty = false;
  for(int i = 0; i < SIZE; i++) {
    for(int j = 0; j < SIZE; j++) {
      if(grid[i][j] == 0) {
        row = i;
        col = j;
        foundEmpty = true;
        break;
      }
    }
    if(foundEmpty) {
      break;
    }
  }

  // If there are no empty cells, the puzzle is already solved
  if(!foundEmpty) {
    return true;
  }

  // Try placing a value in the empty cell
  for(int i = 1; i <= SIZE; i++) {
    if(isSafe(row, col, i)) {
      grid[row][col] = i;
      if(solveSudoku()) {
        return true;
      } else {
        grid[row][col] = 0;
      }
    }
  }

  // If no value can be placed in the empty cell, backtrack
  return false;
}

int main() {
  // Initialize the Sudoku grid with 0 values
  for(int i = 0; i < SIZE; i++) {
    for(int j = 0; j < SIZE; j++) {
      grid[i][j] = 0;
    }
  }

  // Set the initial values of the Sudoku grid
  grid[0][1] = 2;
  grid[0][2] = 4;
  grid[0][5] = 7;
  grid[0][6] = 5;
  grid[1][3] = 6;
  grid[1][4] = 7;
  grid[1][5] = 1;
  grid[1][7] = 8;
  grid[2][2] = 7;
  grid[2][3] = 2;
  grid[2][5] = 6;
  grid[2][6] = 4;
  grid[2][8] = 3;
  grid[3][0] = 7;
  grid[3][1] = 5;
  grid[3][2] = 1;
  grid[3][4] = 9;
  grid[3][5] = 4;
  grid[3][6] = 3;
  grid[3][7] = 6;
  grid[4][1] = 8;
  grid[4][2] = 3;
  grid[4][6] = 1;
  grid[4][7] = 5;
  grid[5][1] = 9;
  grid[5][2] = 6;
  grid[5][3] = 4;
  grid[5][4] = 5;
  grid[5][6] = 2;
  grid[5][7] = 3;
  grid[6][0] = 1;
  grid[6][2] = 2;
  grid[6][3] = 9;
  grid[6][5] = 5;
  grid[6][6] = 7;
  grid[6][8] = 4;
  grid[7][1] = 7;
  grid[7][3] = 8;
  grid[7][4] = 1;
  grid[7][5] = 2;
  grid[7][7] = 9;
  grid[8][2] = 5;
  grid[8][3] = 6;
  grid[8][6] = 8;
  grid[8][7] = 2;

  // Print the initial Sudoku grid
  printGrid();

  // Solve the Sudoku puzzle
  if(solveSudoku()) {
    printf("Sudoku puzzle solved:\n");
    printGrid();
  } else {
    printf("Sudoku puzzle could not be solved");
  }

  return 0;
}