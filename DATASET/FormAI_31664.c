//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int board[5][5];   /* Declare 5x5 bingo board */
  int called[75];    /* Track called numbers */
  int count = 0;     /* Count called numbers */
  int number;        /* Current called number */
  int row, col;      /* Current cell */
  int win;           /* Winning combination */
  
  /* Seed random number generator */
  srand(time(NULL));
  
  /* Initialize board with zeros */
  for (row = 0; row < 5; row++) {
    for (col = 0; col < 5; col++) {
      board[row][col] = 0;
    }
  }
  
  /* Initialize called numbers with zeros */
  for (int i = 0; i < 75; i++) {
    called[i] = 0;
  }
  
  /* Game loop */
  while(1) {
    /* Generate random number */
    number = rand() % 75 + 1;

    /* Check if number has already been called */
    if (called[number-1]) {
      continue;
    }

    /* Mark number as called */
    called[number-1] = 1;

    /* Increment count */
    count++;
    
    /* Print called number */
    printf("Call: %d\n", number);
    
    /* Check if number is on board */
    for (row = 0; row < 5; row++) {
      for (col = 0; col < 5; col++) {
        if (board[row][col] == number) {
          board[row][col] = -1;
        }
      }
    }
    
    /* Print current board */
    printf("B   I   N   G   O\n");
    
    for (row = 0; row < 5; row++) {
      for (col = 0; col < 5; col++) {
        if (board[row][col] == -1) {
          printf("X ");
        } else {
          printf("%d ", board[row][col]);
        }
      }
      printf("\n");
    }
    
    /* Check for win */
    win = 0;
    
    /* Horizontal */
    if (board[0][0] == -1 && board[0][1] == -1 && board[0][2] == -1 && board[0][3] == -1 && board[0][4] == -1) {
      win = 1;
    }
    if (board[1][0] == -1 && board[1][1] == -1 && board[1][2] == -1 && board[1][3] == -1 && board[1][4] == -1) {
      win = 1;
    }
    if (board[2][0] == -1 && board[2][1] == -1 && board[2][2] == -1 && board[2][3] == -1 && board[2][4] == -1) {
      win = 1;
    }
    if (board[3][0] == -1 && board[3][1] == -1 && board[3][2] == -1 && board[3][3] == -1 && board[3][4] == -1) {
      win = 1;
    }
    if (board[4][0] == -1 && board[4][1] == -1 && board[4][2] == -1 && board[4][3] == -1 && board[4][4] == -1) {
      win = 1;
    }
    
    /* Vertical */
    if (board[0][0] == -1 && board[1][0] == -1 && board[2][0] == -1 && board[3][0] == -1 && board[4][0] == -1) {
      win = 1;
    }
    if (board[0][1] == -1 && board[1][1] == -1 && board[2][1] == -1 && board[3][1] == -1 && board[4][1] == -1) {
      win = 1;
    }
    if (board[0][2] == -1 && board[1][2] == -1 && board[2][2] == -1 && board[3][2] == -1 && board[4][2] == -1) {
      win = 1;
    }
    if (board[0][3] == -1 && board[1][3] == -1 && board[2][3] == -1 && board[3][3] == -1 && board[4][3] == -1) {
      win = 1;
    }
    if (board[0][4] == -1 && board[1][4] == -1 && board[2][4] == -1 && board[3][4] == -1 && board[4][4] == -1) {
      win = 1;
    }

    /* Diagonal */
    if (board[0][0] == -1 && board[1][1] == -1 && board[2][2] == -1 && board[3][3] == -1 && board[4][4] == -1) {
      win = 1;
    }
    if (board[0][4] == -1 && board[1][3] == -1 && board[2][2] == -1 && board[3][1] == -1 && board[4][0] == -1) {
      win = 1;
    }

    /* Check for win */
    if (win) {
      printf("BINGO!\n");
      break;
    }
    
    /* Check for draw */
    if (count == 75) {
      printf("DRAW!\n");
      break;
    }
    
    /* Wait for input */
    getchar();
  }
  
  return 0;
}