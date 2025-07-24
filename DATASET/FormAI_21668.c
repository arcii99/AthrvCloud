//FormAI DATASET v1.0 Category: Checkers Game ; Style: synchronous
#include <stdio.h>

// Board constants
#define ROWS 8
#define COLUMNS 8

// Piece constants
#define EMPTY 0
#define BLACK 1
#define RED 2
#define KING_BLACK 3
#define KING_RED 4

// Function prototypes
void initializeBoard(int board[ROWS][COLUMNS]);
void printBoard(int board[ROWS][COLUMNS]);
int isValidMove(int board[ROWS][COLUMNS], int currentRow, int currentColumn, int newRow, int newColumn);

// Main function
int main(void) {
  // Initialize board
  int board[ROWS][COLUMNS];
  initializeBoard(board);

  // Print board
  printBoard(board);

  return 0;
}

// Function definitions
void initializeBoard(int board[ROWS][COLUMNS]) {
  // Initialize all positions with empty pieces
  for (int row = 0; row < ROWS; row++) {
    for (int column = 0; column < COLUMNS; column++) {
      board[row][column] = EMPTY;
    }
  }

  // Place black pieces
  for (int row = 0; row < 3; row++) {
    for (int column = 0; column < COLUMNS; column += 2) {
      if (row % 2 == 0) {
        board[row][column + 1] = BLACK;
      } else {
        board[row][column] = BLACK;
      }
    }
  }

  // Place red pieces
  for (int row = ROWS - 3; row < ROWS; row++) {
    for (int column = 0; column < COLUMNS; column += 2) {
      if (row % 2 == 0) {
        board[row][column + 1] = RED;
      } else {
        board[row][column] = RED;
      }
    }
  }
}

void printBoard(int board[ROWS][COLUMNS]) {
  printf("   1 2 3 4 5 6 7 8\n");
  printf("  -----------------\n");
  for (int row = 0; row < ROWS; row++) {
    printf("%d ", row + 1);
    for (int column = 0; column < COLUMNS; column++) {
      switch (board[row][column]) {
        case EMPTY:
          printf("| ");
          break;
        case BLACK:
          printf("|B");
          break;
        case RED:
          printf("|R");
          break;
        case KING_BLACK:
          printf("|K");
          break;
        case KING_RED:
          printf("|K");
          break;
      }
    }
    printf("|\n");
    printf("  -----------------\n");
  }
}

int isValidMove(int board[ROWS][COLUMNS], int currentRow, int currentColumn, int newRow, int newColumn) {
  // Check if new position is outside the board
  if (newRow < 0 || newRow >= ROWS || newColumn < 0 || newColumn >= COLUMNS) {
    return 0;
  }

  // Check if new position already has a piece
  if (board[newRow][newColumn] != EMPTY) {
    return 0;
  }

  // Check if new position is diagonal and one space away
  if (abs(newRow - currentRow) != 1 || abs(newColumn - currentColumn) != 1) {
    return 0;
  }

  // Check if black piece is moving up
  if (board[currentRow][currentColumn] == BLACK && newRow > currentRow) {
    return 0;
  }

  // Check if red piece is moving down
  if (board[currentRow][currentColumn] == RED && newRow < currentRow) {
    return 0;
  }

  // Move is valid
  return 1;
}