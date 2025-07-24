//FormAI DATASET v1.0 Category: Checkers Game ; Style: grateful
#include <stdio.h>

// Grid dimensions
#define SIZE 8

// Constants for pieces
#define EMPTY 0
#define BLACK 1
#define WHITE 2

// Board representation
int board[SIZE][SIZE];

// Helper function to print the board
void printBoard() {
  printf("   ");
  for (int i = 0; i < SIZE; i++) {
    printf("%d ", i);
  }
  printf("\n");
  printf("  +");
  for (int i = 0; i < SIZE; i++) {
    printf("-+");
  }
  printf("\n");

  for (int row = 0; row < SIZE; row++) {
    printf("%d |", row);
    for (int col = 0; col < SIZE; col++) {
      switch (board[row][col]) {
        case EMPTY:
          printf(" |");
          break;
        case BLACK:
          printf("B|");
          break;
        case WHITE:
          printf("W|");
          break;
      }
    }
    printf("\n");
    printf("  +");
    for (int i = 0; i < SIZE; i++) {
      printf("-+");
    }
    printf("\n");
  }
}

// Check if a position is on the board
int isValidPosition(int row, int col) {
  return row >= 0 && row < SIZE && col >= 0 && col < SIZE;
}

// Check if a piece can move to a position
int isValidMove(int piece, int startRow, int startCol, int endRow, int endCol) {
  if (!isValidPosition(endRow, endCol)) {
    return 0;
  }
  if (board[endRow][endCol] != EMPTY) {
    return 0;
  }
  int rowDiff = endRow - startRow;
  int colDiff = endCol - startCol;
  int absRowDiff = rowDiff < 0 ? -rowDiff : rowDiff;
  int absColDiff = colDiff < 0 ? -colDiff : colDiff;
  if (rowDiff == 0 || colDiff == 0) {
    return 0;
  }
  if (absRowDiff != absColDiff) {
    return 0;
  }
  int direction = rowDiff > 0 ? 1 : -1;
  int oppPiece = piece == BLACK ? WHITE : BLACK;
  int row = startRow + direction;
  int col = startCol + direction;
  int foundOppPiece = 0;
  while (isValidPosition(row, col)) {
    if (board[row][col] == oppPiece) {
      foundOppPiece = 1;
    } else if (board[row][col] == piece) {
      return foundOppPiece;
    } else {
      break;
    }
    row += direction;
    col += direction;
  }
  row = startRow + direction;
  col = startCol - direction;
  foundOppPiece = 0;
  while (isValidPosition(row, col)) {
    if (board[row][col] == oppPiece) {
      foundOppPiece = 1;
    } else if (board[row][col] == piece) {
      return foundOppPiece;
    } else {
      break;
    }
    row += direction;
    col -= direction;
  }
  return 0;
}

// Make a move
int makeMove(int piece, int startRow, int startCol, int endRow, int endCol) {
  if (!isValidMove(piece, startRow, startCol, endRow, endCol)) {
    return 0;
  }
  board[startRow][startCol] = EMPTY;
  board[endRow][endCol] = piece;
  int rowDiff = endRow - startRow;
  int colDiff = endCol - startCol;
  int direction = rowDiff > 0 ? 1 : -1;
  int oppPiece = piece == BLACK ? WHITE : BLACK;
  int row = startRow + direction;
  int col = startCol + direction;
  while (isValidPosition(row, col)) {
    if (board[row][col] == oppPiece) {
      board[row][col] = piece;
    } else {
      break;
    }
    row += direction;
    col += direction;
  }
  row = startRow + direction;
  col = startCol - direction;
  while (isValidPosition(row, col)) {
    if (board[row][col] == oppPiece) {
      board[row][col] = piece;
    } else {
      break;
    }
    row += direction;
    col -= direction;
  }
  return 1;
}

// Check if a player can move
int canMove(int piece) {
  for (int row = 0; row < SIZE; row++) {
    for (int col = 0; col < SIZE; col++) {
      if (board[row][col] == piece) {
        for (int rowDiff = -1; rowDiff <= 1; rowDiff++) {
          for (int colDiff = -1; colDiff <= 1; colDiff++) {
            if (rowDiff != 0 || colDiff != 0) {
              int newRow = row + rowDiff;
              int newCol = col + colDiff;
              if (isValidMove(piece, row, col, newRow, newCol)) {
                return 1;
              }
            }
          }
        }
      }
    }
  }
  return 0;
}

// The main function
int main() {
  // Initialize the board
  for (int row = 0; row < SIZE; row++) {
    for (int col = 0; col < SIZE; col++) {
      if (row < 3 && (row+col) % 2 == 0) {
        board[row][col] = WHITE;
      } else if (row > 4 && (row+col) % 2 == 0) {
        board[row][col] = BLACK;
      } else {
        board[row][col] = EMPTY;
      }
    }
  }

  // Print the startboard
  printf("Welcome to the checkers game!\n\n");
  printBoard();

  // The main loop
  int turn = BLACK;
  while (1) {
    printf("\n");
    if (turn == BLACK) {
      printf("Black's turn\n");
    } else {
      printf("White's turn\n");
    }
    int canPlayerMove = canMove(turn);
    if (!canPlayerMove) {
      printf("No possible moves. The other player wins!\n");
      break;
    }
    int startRow, startCol, endRow, endCol;
    printf("Enter the piece you want to move, and the position you want to move it to. (e.g. 2 3 3 4)\n");
    scanf("%d %d %d %d", &startRow, &startCol, &endRow, &endCol);
    if (!makeMove(turn, startRow, startCol, endRow, endCol)) {
      printf("Invalid move. Try again.\n");
      continue;
    }
    printBoard();
    if (turn == BLACK) {
      turn = WHITE;
    } else {
      turn = BLACK;
    }
  }
  return 0;
}