//FormAI DATASET v1.0 Category: Checkers Game ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

void initializeBoard(char board[][BOARD_SIZE]);
void printBoard(char board[][BOARD_SIZE]);
void movePiece(char board[][BOARD_SIZE], int fromRow, int fromCol, int toRow, int toCol);
int isValidMove(char board[][BOARD_SIZE], int fromRow, int fromCol, int toRow, int toCol, int isKing);
int isCaptureMove(char board[][BOARD_SIZE], int fromRow, int fromCol, int toRow, int toCol);

int main() {
  char board[BOARD_SIZE][BOARD_SIZE];

  // initialize the board
  initializeBoard(board);

  // print the initial board
  printf("Initial board:\n");
  printBoard(board);

  // test a valid move
  movePiece(board, 2, 1, 3, 0);
  printf("\nAfter move 2,1 to 3,0:\n");
  printBoard(board);

  // test an invalid move
  movePiece(board, 3, 0, 5, 2);
  printf("\nAfter move 3,0 to 5,2:\n");
  printBoard(board);

  // test a capture move
  movePiece(board, 2, 3, 4, 1);
  printf("\nAfter move 2,3 to 4,1:\n");
  printBoard(board);

  return 0;
}

void initializeBoard(char board[][BOARD_SIZE]) {
  int row, col;

  // initialize all squares to empty
  for (row = 0; row < BOARD_SIZE; row++) {
    for (col = 0; col < BOARD_SIZE; col++) {
      board[row][col] = '-';
    }
  }

  // place black pieces
  for (row = 0; row < 3; row++) {
    for (col = 0; col < BOARD_SIZE; col++) {
      if ((row + col) % 2 == 1) {
        board[row][col] = 'b';
      }
    }
  }

  // place white pieces
  for (row = BOARD_SIZE - 3; row < BOARD_SIZE; row++) {
    for (col = 0; col < BOARD_SIZE; col++) {
      if ((row + col) % 2 == 1) {
        board[row][col] = 'w';
      }
    }
  }
}

void printBoard(char board[][BOARD_SIZE]) {
  int row, col;

  printf("  ");
  for (col = 0; col < BOARD_SIZE; col++) {
    printf("%d ", col);
  }
  printf("\n");

  for (row = 0; row < BOARD_SIZE; row++) {
    printf("%d ", row);
    for (col = 0; col < BOARD_SIZE; col++) {
      printf("%c ", board[row][col]);
    }
    printf("\n");
  }
}

void movePiece(char board[][BOARD_SIZE], int fromRow, int fromCol, int toRow, int toCol) {
  // check if move is valid
  if (!isValidMove(board, fromRow, fromCol, toRow, toCol, board[fromRow][fromCol] == 'w' && toRow == BOARD_SIZE - 1 || board[fromRow][fromCol] == 'b' && toRow == 0)) {
    printf("Invalid move.\n");
    return;
  }

  // move the piece
  board[toRow][toCol] = board[fromRow][fromCol];
  board[fromRow][fromCol] = '-';

  // check if capture move
  if (isCaptureMove(board, fromRow, fromCol, toRow, toCol)) {
    board[(fromRow + toRow)/2][(fromCol + toCol)/2] = '-';
  }
}

int isValidMove(char board[][BOARD_SIZE], int fromRow, int fromCol, int toRow, int toCol, int isKing) {
  if (board[fromRow][fromCol] == '-') {
    return 0;
  } else if (board[toRow][toCol] != '-') {
    return 0;
  }

  int moveRow = toRow - fromRow;
  int moveCol = toCol - fromCol;

  if (!isKing) {
    if (board[fromRow][fromCol] == 'w' && moveRow < 0) {
      return 0;
    } else if (board[fromRow][fromCol] == 'b' && moveRow > 0) {
      return 0;
    }
  }

  if (abs(moveRow) != abs(moveCol)) {
    return 0;
  }

  if (abs(moveRow) == 1) {
    return 1;
  }

  int i, j;
  for (i = fromRow + 1, j = fromCol + 1; i < toRow; i++, j++) {
    if (board[i][j] != '-') {
      return 0;
    }
  }

  for (i = fromRow + 1, j = fromCol - 1; i < toRow; i++, j--) {
    if (board[i][j] != '-') {
      return 0;
    }
  }

  for (i = fromRow - 1, j = fromCol + 1; i > toRow; i--, j++) {
    if (board[i][j] != '-') { 
      return 0;
    }
  }
     
  for (i = fromRow - 1, j = fromCol - 1; i > toRow; i--, j--) {
    if (board[i][j] != '-') {
      return 0;
    } 
  }

  return 1;
}

int isCaptureMove(char board[][BOARD_SIZE], int fromRow, int fromCol, int toRow, int toCol) {
  int captureRow = fromRow + (toRow - fromRow)/2;
  int captureCol = fromCol + (toCol - fromCol)/2;

  if (board[captureRow][captureCol] == 'w' || board[captureRow][captureCol] == 'W') {
    return board[fromRow][fromCol] == 'b' || board[fromRow][fromCol] == 'B';
  } else if (board[captureRow][captureCol] == 'b' || board[captureRow][captureCol] == 'B') {
    return board[fromRow][fromCol] == 'w' || board[fromRow][fromCol] == 'W';
  }

  return 0;
}