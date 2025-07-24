//FormAI DATASET v1.0 Category: Chess AI ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 8
#define COLS 8

//initialize chess board
char board[ROWS][COLS] = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
                          {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                          {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
                          {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
                          {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
                          {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
                          {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                          {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};

// Print board
void printBoard() {
  for (int i = 0; i < ROWS; i++) {
    printf("---------------------------------\n|");
    for (int j = 0; j < COLS; j++) {
      printf(" %c |", board[i][j]);
    }
    printf("\n");
  }
  printf("---------------------------------\n");
}

// Check if move is legal
int isLegalMove(int currRow, int currCol, int destRow, int destCol) {
  char piece = board[currRow][currCol];
  int sign;
  if (piece == 'P') {
    sign = 1;
  } else {
    sign = -1;
  }

  // Check for valid column move
  if (currCol == destCol) {
    return 0;
  }

  // Check for valid row move
  if (currRow + sign != destRow) {
    return 0;
  }

  // Check for valid piece movement
  if (piece == 'P') {
    if (destCol == currCol + 1 || destCol == currCol - 1) {
      return 1;
    }
    if (destCol != currCol + 2) {
      return 0;
    }
    if (board[currRow + sign][currCol + 1] != ' ') {
      return 0;
    }
  } else if (piece == 'K') {
    if (destCol == currCol + 2 || destCol == currCol - 2) {
      return 1;
    }
    return 0;
  }

  return 0;
}

// Generate random move
void generateMove(int *currRow, int *currCol, int *destRow, int *destCol) {
  do {
    *currRow = rand() % ROWS;
    *currCol = rand() % COLS;
    *destRow = rand() % ROWS;
    *destCol = rand() % COLS;
  } while (!isLegalMove(*currRow, *currCol, *destRow, *destCol));
}

// Main function
int main() {
  srand(time(NULL));
  int currRow, currCol, destRow, destCol;

  printf("Starting position:\n");
  printBoard();

  for (int i = 0; i < 10; i++) {
    generateMove(&currRow, &currCol, &destRow, &destCol);
    printf("Move %d:\n", i + 1);
    printf("From (%d, %d) to (%d, %d)\n", currRow, currCol, destRow, destCol);
    board[destRow][destCol] = board[currRow][currCol];
    board[currRow][currCol] = ' ';
    printBoard();
  }

  return 0;
}