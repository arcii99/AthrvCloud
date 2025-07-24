//FormAI DATASET v1.0 Category: Sudoku solver ; Style: future-proof
#include <stdio.h>

int board[9][9];

void printBoard() {
  int i, j;
  printf("Sudoku Board:\n");
  for (i = 0; i < 9; i++) {
    for (j = 0; j < 9; j++) {
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }
}

int isValid(int row, int col, int num) {
  int i, j;
  // check if num already exists in row or column
  for (i = 0; i < 9; i++) {
    if (board[row][i] == num || board[i][col] == num) {
      return 0;
    }
  }
  // check if num already exists in 3x3 sub-grid
  int subRow = row - row % 3;
  int subCol = col - col % 3;
  for (i = subRow; i < subRow + 3; i++) {
    for (j = subCol; j < subCol + 3; j++) {
      if (board[i][j] == num) {
        return 0;
      }
    }
  }
  // num can be placed at board[row][col]
  return 1;
}

int solveSudoku() {
  int row, col, num;
  for (row = 0; row < 9; row++) {
    for (col = 0; col < 9; col++) {
      if (board[row][col] == 0) {
        // try all numbers 1-9 until a valid one is found
        for (num = 1; num <= 9; num++) {
          if (isValid(row, col, num)) {
            board[row][col] = num;
            if (solveSudoku()) {
              return 1; // found solution
            } else {
              board[row][col] = 0; // backtrack
            }
          }
        }
        // could not find valid number
        return 0;
      }
    }
  }
  // sudoku is solved
  return 1;
}

int main() {
  // initialize board with example problem
  board[0][0] = 3; board[0][1] = 0; board[0][2] = 6; board[0][3] = 5; board[0][4] = 0; board[0][5] = 8; board[0][6] = 4; board[0][7] = 0; board[0][8] = 0;
  board[1][0] = 5; board[1][1] = 2; board[1][2] = 0; board[1][3] = 0; board[1][4] = 0; board[1][5] = 0; board[1][6] = 0; board[1][7] = 0; board[1][8] = 0;
  board[2][0] = 0; board[2][1] = 8; board[2][2] = 7; board[2][3] = 0; board[2][4] = 0; board[2][5] = 0; board[2][6] = 0; board[2][7] = 3; board[2][8] = 1;
  board[3][0] = 0; board[3][1] = 0; board[3][2] = 3; board[3][3] = 0; board[3][4] = 0; board[3][5] = 0; board[3][6] = 0; board[3][7] = 2; board[3][8] = 0;
  board[4][0] = 9; board[4][1] = 0; board[4][2] = 0; board[4][3] = 8; board[4][4] = 0; board[4][5] = 0; board[4][6] = 0; board[4][7] = 0; board[4][8] = 5;
  board[5][0] = 0; board[5][1] = 5; board[5][2] = 0; board[5][3] = 0; board[5][4] = 0; board[5][5] = 0; board[5][6] = 6; board[5][7] = 0; board[5][8] = 0;
  board[6][0] = 1; board[6][1] = 3; board[6][2] = 0; board[6][3] = 0; board[6][4] = 0; board[6][5] = 0; board[6][6] = 0; board[6][7] = 0; board[6][8] = 9;
  board[7][0] = 0; board[7][1] = 0; board[7][2] = 0; board[7][3] = 0; board[7][4] = 0; board[7][5] = 0; board[7][6] = 0; board[7][7] = 0; board[7][8] = 4;
  board[8][0] = 0; board[8][1] = 0; board[8][2] = 5; board[8][3] = 2; board[8][4] = 0; board[8][5] = 6; board[8][6] = 3; board[8][7] = 0; board[8][8] = 0;

  // print the sudoku board
  printBoard();
  
  // solve the sudoku board
  if (solveSudoku()) {
    printf("\nSolution Found:\n");
    printBoard();
  } else {
    printf("No solution found.\n");
  }

  return 0;
}