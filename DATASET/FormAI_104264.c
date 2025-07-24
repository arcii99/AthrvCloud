//FormAI DATASET v1.0 Category: Checkers Game ; Style: visionary
#include <stdio.h>

// function to print the board
void printBoard(int board[8][8]) {
  printf(" |0|1|2|3|4|5|6|7|\n"); // column numbers
  for (int i = 0; i < 8; i++) {
    printf("%d|", i); // row numbers
    for (int j = 0; j < 8; j++) {
      printf("%d|", board[i][j]); // print the cell contents
    }
    printf("\n");
  }
}

// function to initialize the board
void initBoard(int board[8][8]) {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if ((i + j) % 2 == 0) {
        if (i < 3) {
          board[i][j] = 1; // player 1
        } else if (i > 4) {
          board[i][j] = 2; // player 2
        } else {
          board[i][j] = 0; // empty
        }
      } else {
        board[i][j] = -1; // invalid cell
      }
    }
  }
}

// function to move a piece
void movePiece(int board[8][8], int i, int j, int x, int y) {
  int temp = board[i][j];
  board[i][j] = board[x][y];
  board[x][y] = temp;
}

// function to check if a move is valid
int validMove(int board[8][8], int i, int j, int x, int y, int player) {
  if (board[x][y] != 0 || (i + j) % 2 == 1 || (x + y) % 2 == 1) {
    return 0;
  }
  if (player == 1) { // player 1, move up
    if (board[i][j] == 1 && x > i) {
      return 0;
    }
    if (x - i == 2) { // capture
      if (board[i+1][j-1] == 2 || board[i+1][j+1] == 2) {
        return 1;
      } else {
        return 0;
      }
    } else if (x - i == 1) { // move
      return 1;
    }
  } else { // player 2, move down
    if (board[i][j] == 2 && x < i) {
      return 0;
    }
    if (i - x == 2) { // capture
      if (board[i-1][j-1] == 1 || board[i-1][j+1] == 1) {
        return 1;
      } else {
        return 0;
      }
    } else if (i - x == 1) { // move
      return 1;
    }
  }
  return 0;
}

int main() {
  int board[8][8];
  initBoard(board);
  printBoard(board);
  return 0;
}