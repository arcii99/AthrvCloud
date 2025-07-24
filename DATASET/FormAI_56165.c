//FormAI DATASET v1.0 Category: Checkers Game ; Style: shocked
#include <stdio.h>

#define BOARD_SIZE 8

int board[BOARD_SIZE][BOARD_SIZE];

void initializeBoard() {
  int i, j;
  for(i = 0; i < BOARD_SIZE; i++) {
    for(j = 0; j < BOARD_SIZE; j++) {
      if(i < BOARD_SIZE/2 - 1) {
        if((i+j)%2 == 0) {
          board[i][j] = 1;
        }
        else {
          board[i][j] = 0;
        }
      }
      else if(i > BOARD_SIZE/2) {
        if((i+j)%2 == 0) {
          board[i][j] = -1;
        }
        else {
          board[i][j] = 0;
        }
      }
      else {
        board[i][j] = 0;
      }
    }
  }
}

void printBoard() {
  int i, j;
  printf("\n");
  for(i = 0; i < BOARD_SIZE; i++) {
    for(j = 0; j < BOARD_SIZE; j++) {
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }
}

int main() {
  initializeBoard();
  printBoard();

  return 0;
}