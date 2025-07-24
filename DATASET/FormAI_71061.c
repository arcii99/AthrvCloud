//FormAI DATASET v1.0 Category: Sudoku solver ; Style: lively
#include <stdio.h>

// define N as a macro for board size
#define N 9

// utility function to print the board
void printBoard(int board[N][N]) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }
}

// utility function to check if a possible number is already in a row
int isPossibleRow(int board[N][N], int row, int num) {
  for (int i = 0; i < N; i++) {
    if (board[row][i] == num) {
      return 0; // false
    }
  }
  return 1; // true
}

// utility function to check if a possible number is already in a column
int isPossibleCol(int board[N][N], int col, int num) {
  for (int i = 0; i < N; i++) {
    if (board[i][col] == num) {
      return 0; // false
    }
  }
  return 1; // true
}

// utility function to check if a possible number is already in a 3x3 box
int isPossibleBox(int board[N][N], int row, int col, int num) {
  int startRow = row - row % 3;
  int startCol = col - col % 3;
  for (int i = startRow; i < startRow + 3; i++) {
    for (int j = startCol; j < startCol + 3; j++) {
      if (board[i][j] == num) {
        return 0; // false
      }
    }
  }
  return 1; // true
}

// utility function to check if it's possible to assign num to board[row][col]
int isPossibleNum(int board[N][N], int row, int col, int num) {
  return isPossibleRow(board, row, num) &&
         isPossibleCol(board, col, num) &&
         isPossibleBox(board, row, col, num);
}

// recursive function to solve the board
int solveBoard(int board[N][N], int row, int col) {
  
  // base case: if we've reached the end of a row, start the next row
  if (col == N) {
    row++;
    col = 0;
    
    // if we've reached the end of the board, we're done
    if (row == N) {
      return 1;
    }
  }
  
  // if the current cell is already filled, move to the next cell
  if (board[row][col] != 0) {
    return solveBoard(board, row, col + 1);
  }
  
  // try every possible number for the current cell
  for (int num = 1; num <= N; num++) {
    if (isPossibleNum(board, row, col, num)) {
      board[row][col] = num;
      if (solveBoard(board, row, col + 1)) {
        return 1;
      }
      board[row][col] = 0;
    }
  }
  
  // if no number works for this cell, backtrack
  return 0;
}

int main() {
  
  // example Sudoku puzzle
  int board[N][N] = {{9, 8, 0, 0, 2, 0, 0, 7, 3},
                     {0, 0, 6, 0, 0, 7, 0, 4, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 6, 0, 8, 0},
                     {0, 2, 0, 4, 1, 0, 0, 0, 0},
                     {5, 0, 0, 0, 0, 3, 6, 0, 0},
                     {0, 1, 0, 0, 7, 2, 5, 0, 0},
                     {0, 0, 0, 0, 0, 0, 9, 0, 0},
                     {0, 0, 2, 5, 3, 0, 0, 0, 0}};
  
  printf("Sudoku puzzle to solve:\n");
  printBoard(board);
  
  if (solveBoard(board, 0, 0)) {
    printf("Sudoku puzzle solved:\n");
    printBoard(board);
  } else {
    printf("Unable to solve Sudoku puzzle.\n");
  }
  
  return 0;
}