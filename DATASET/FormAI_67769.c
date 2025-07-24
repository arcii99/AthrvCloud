//FormAI DATASET v1.0 Category: Chess engine ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Constants for the Chess Board */

#define BOARD_SIZE 8
#define KING 'K'
#define QUEEN 'Q'
#define BISHOP 'B'
#define KNIGHT 'N'
#define ROOK 'R'
#define PAWN 'P'
#define EMPTY '.'

/* Structure for Chess Pieces */

struct Piece {
  char type;
  char color;
};

/* Function to initialize the Chess Board with standard starting pieces */

void init_board(struct Piece board[BOARD_SIZE][BOARD_SIZE]) {
  int i, j;

  /* Set Pawns */
  for(i=0; i<BOARD_SIZE; i++) {
    board[1][i].type = PAWN;
    board[1][i].color = 'b';
    board[6][i].type = PAWN;
    board[6][i].color = 'w';
  }

  /* Set Rooks */
  board[0][0].type = ROOK;
  board[0][0].color = 'b';
  board[0][7].type = ROOK;
  board[0][7].color = 'b';
  board[7][0].type = ROOK;
  board[7][0].color = 'w';
  board[7][7].type = ROOK;
  board[7][7].color = 'w';

  /* Set Knights */
  board[0][1].type = KNIGHT;
  board[0][1].color = 'b';
  board[0][6].type = KNIGHT;
  board[0][6].color = 'b';
  board[7][1].type = KNIGHT;
  board[7][1].color = 'w';
  board[7][6].type = KNIGHT;
  board[7][6].color = 'w';

  /* Set Bishops */
  board[0][2].type = BISHOP;
  board[0][2].color = 'b';
  board[0][5].type = BISHOP;
  board[0][5].color = 'b';
  board[7][2].type = BISHOP;
  board[7][2].color = 'w';
  board[7][5].type = BISHOP;
  board[7][5].color = 'w';

  /* Set Queens */
  board[0][3].type = QUEEN;
  board[0][3].color = 'b';
  board[7][3].type = QUEEN;
  board[7][3].color = 'w';

  /* Set Kings */
  board[0][4].type = KING;
  board[0][4].color = 'b';
  board[7][4].type = KING;
  board[7][4].color = 'w';

  /* Set Empty Spaces */
  for(i=2; i<6; i++) {
    for(j=0; j<BOARD_SIZE; j++) {
      board[i][j].type = EMPTY;
      board[i][j].color = ' ';
    }
  }
}

/* Function to print the Chess Board */

void print_board(struct Piece board[BOARD_SIZE][BOARD_SIZE]) {
  int i, j;
  for(i=0; i<BOARD_SIZE; i++) {
    printf("\n");
    for(j=0; j<BOARD_SIZE; j++) {
      printf("%c ", board[i][j].type);
    }
  }
  printf("\n");
}

/* The main function */

int main() {
  struct Piece board[BOARD_SIZE][BOARD_SIZE];
  init_board(board);
  print_board(board);
  return 0;
}