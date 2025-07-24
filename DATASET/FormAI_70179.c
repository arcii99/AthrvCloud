//FormAI DATASET v1.0 Category: Sudoku solver ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>

#define MAX 9

void printBoard(int board[][MAX]) {
  printf("-------------------------\n");
  for(int i = 0; i < MAX; i++) {
    printf("| ");
    for(int j = 0; j < MAX; j++) {
      printf("%d ", board[i][j]);
      if((j+1) % 3 == 0) printf("| ");
    }
    printf("\n");
    if((i+1) % 3 == 0) printf("-------------------------\n");
  }
}

int validValue(int board[][MAX], int row, int col, int value) {
  for(int i = 0; i < MAX; i++) {
    if(value == board[row][i]) return 0;
    if(value == board[i][col]) return 0;
  }
  int r = row - (row % 3), c = col - (col % 3);
  for(int i = r; i < r+3; i++) {
    for(int j = c; j < c+3; j++) {
      if(value == board[i][j]) return 0;
    }
  }
  return 1;
}

int solveBoard(int board[][MAX], int row, int col) {
  if(col == MAX) {
    row += 1;
    col = 0;
  }
  if(row == MAX) {
    return 1;
  }
  if(board[row][col] != 0) {
    return solveBoard(board, row, col+1);
  }
  for(int i = 1; i <= MAX; i++) {
    if(validValue(board, row, col, i)) {
      board[row][col] = i;
      if(solveBoard(board, row, col+1)) {
        return 1;
      }
      board[row][col] = 0;
    }
  }
  return 0;
}

int main() {
  int board[MAX][MAX] = {{0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0}};
  // initialize board with numbers
  solveBoard(board, 0, 0);
  printBoard(board);
  return 0;
}