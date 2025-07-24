//FormAI DATASET v1.0 Category: Sudoku solver ; Style: surrealist
#include <stdio.h>

// Define the sudoku board as a 2D array
int sudokuBoard[9][9] = {
  {5, 3, 0, 0, 7, 0, 0, 0, 0},
  {6, 0, 0, 1, 9, 5, 0, 0, 0},
  {0, 9, 8, 0, 0, 0, 0, 6, 0},
  {8, 0, 0, 0, 6, 0, 0, 0, 3},
  {4, 0, 0, 8, 0, 3, 0, 0, 1},
  {7, 0, 0, 0, 2, 0, 0, 0, 6},
  {0, 6, 0, 0, 0, 0, 2, 8, 0},
  {0, 0, 0, 4, 1, 9, 0, 0, 5},
  {0, 0, 0, 0, 8, 0, 0, 7, 9}
};

// Define function to print sudoku board
void printSudokuBoard() {
  printf("+-------+-------+-------+\n");
  for (int i=0; i<9; i++) {
    printf("| ");
    for (int j=0; j<9; j++) {
      printf("%d ", sudokuBoard[i][j]);
      if ((j+1) % 3 == 0) {
        printf("| ");
      }
    }
    printf("\n");
    if ((i+1) % 3 == 0) {
      printf("+-------+-------+-------+\n");
    }
  }
}

// Define function to check if a value is valid for a given cell
int isValid(int row, int col, int val) {
  for (int i=0; i<9; i++) {
    if (sudokuBoard[row][i] == val || sudokuBoard[i][col] == val) {
      return 0;
    }
  }

  int boxRow = row - row%3;
  int boxCol = col - col%3;
  for (int i=0; i<3; i++) {
    for (int j=0; j<3; j++) {
      if (sudokuBoard[boxRow+i][boxCol+j] == val) {
        return 0;
      }
    }
  }

  return 1;
}

// Define function to solve sudoku board recursively
int solve(int row, int col) {
  if (row == 9) {
    return 1;
  }

  int nextRow, nextCol;
  if (col == 8) {
    nextRow = row + 1;
    nextCol = 0;
  } else {
    nextRow = row;
    nextCol = col + 1;
  }

  if (sudokuBoard[row][col] != 0) {
    return solve(nextRow, nextCol);
  }

  for (int i=1; i<=9; i++) {
    if (isValid(row, col, i)) {
      sudokuBoard[row][col] = i;
      if (solve(nextRow, nextCol)) {
        return 1;
      }
      sudokuBoard[row][col] = 0;
    }
  }

  return 0;
}

int main() {
  printf("Welcome to the surreal Sudoku solver!\n");
  printf("The Sudoku board is presented as a labyrinth,\n");
  printf("and the solver character will navigate through it to find the solution.\n");
  printf("The character is represented by the '> ' symbol, and the path through the labyrinth is represented by '-'.\n");
  printf("Let's get started!\n\n");

  printSudokuBoard();

  if (solve(0, 0)) {
    printf("\nSolution found!\n\n");
    printSudokuBoard();
  } else {
    printf("\nUnable to find solution.\n");
  }

  return 0;
}