//FormAI DATASET v1.0 Category: Checkers Game ; Style: safe
#include<stdio.h>
#include<stdlib.h>

#define BLACK 'B'
#define WHITE 'W'

// Size of the board
#define BOARD_SIZE 8

// Board cell values
#define EMPTY '-'
#define INVALID 'x'

// Piece types
#define KING 'K'
#define NORMAL 'N'

// Board array
char board[BOARD_SIZE][BOARD_SIZE];

// Function to initialize the board
void init_board() {
  int i, j;
  for (i = 0; i < BOARD_SIZE; i++) {
    for (j = 0; j < BOARD_SIZE; j++) {
      if ((i + j) % 2 == 0) {
        if (i < 3) {
          board[i][j] = BLACK;
        }
        else if (i > 4) {
          board[i][j] = WHITE;
        }
        else {
          board[i][j] = EMPTY;
        }
      }
      else {
        board[i][j] = INVALID;
      }
    }
  }
}

int main() {

  // Initialize the board
  init_board();

  // Print the initial board
  int i, j;
  for (i = 0; i < BOARD_SIZE; i++) {
    for (j = 0; j < BOARD_SIZE; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }

  return 0;
}