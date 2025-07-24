//FormAI DATASET v1.0 Category: Chess engine ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BOARD_SIZE 8

enum {EMPTY, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING};
enum {WHITE=0, BLACK=1};

struct piece {
  short unsigned int type;
  short unsigned int color;
};

struct square {
  unsigned char row;
  unsigned char col;
};

struct move {
  struct square src;
  struct square dest;
};

struct board {
  struct piece squares[BOARD_SIZE][BOARD_SIZE];
  struct move last_move;
  short unsigned int to_move;
};

void init_board(struct board *b);
void print_board(struct board *b);
void move_piece(struct board *b, struct move m);
int is_check(struct board *b, int color);

int main(int argc, char *argv[]) {
  struct board b;

  init_board(&b);
  print_board(&b);

  return 0;
}

void init_board(struct board *b) {
  int i, j;

  /* Initialize all squares to empty */
  memset(b->squares, EMPTY, BOARD_SIZE * BOARD_SIZE);

  /* Set up pawns */
  for(i = 0; i < BOARD_SIZE; i++) {
    b->squares[1][i].type = PAWN;
    b->squares[1][i].color = WHITE;
    b->squares[6][i].type = PAWN;
    b->squares[6][i].color = BLACK;
  }

  /* Set up other pieces */
  b->squares[0][0].type = ROOK;
  b->squares[0][0].color = WHITE;
  b->squares[0][7].type = ROOK;
  b->squares[0][7].color = WHITE;
  b->squares[7][0].type = ROOK;
  b->squares[7][0].color = BLACK;
  b->squares[7][7].type = ROOK;
  b->squares[7][7].color = BLACK;

  b->squares[0][1].type = KNIGHT;
  b->squares[0][1].color = WHITE;
  b->squares[0][6].type = KNIGHT;
  b->squares[0][6].color = WHITE;
  b->squares[7][1].type = KNIGHT;
  b->squares[7][1].color = BLACK;
  b->squares[7][6].type = KNIGHT;
  b->squares[7][6].color = BLACK;

  b->squares[0][2].type = BISHOP;
  b->squares[0][2].color = WHITE;
  b->squares[0][5].type = BISHOP;
  b->squares[0][5].color = WHITE;
  b->squares[7][2].type = BISHOP;
  b->squares[7][2].color = BLACK;
  b->squares[7][5].type = BISHOP;
  b->squares[7][5].color = BLACK;

  b->squares[0][3].type = QUEEN;
  b->squares[0][3].color = WHITE;
  b->squares[7][3].type = QUEEN;
  b->squares[7][3].color = BLACK;

  b->squares[0][4].type = KING;
  b->squares[0][4].color = WHITE;
  b->squares[7][4].type = KING;
  b->squares[7][4].color = BLACK;

  /* Set other variables */
  b->last_move.src.row = b->last_move.dest.row = b->to_move = 0;
  b->last_move.src.col = b->last_move.dest.col = 0;
}

void print_board(struct board *b) {
  int i, j;

  for(i = 0; i < BOARD_SIZE; i++) {
    for(j = 0; j < BOARD_SIZE; j++) {
      switch(b->squares[i][j].color) {
      case WHITE:
        switch(b->squares[i][j].type) {
        case EMPTY:
          printf(". ");
          break;
        case PAWN:
          printf("P ");
          break;
        case KNIGHT:
          printf("N ");
          break;
        case BISHOP:
          printf("B ");
          break;
        case ROOK:
          printf("R ");
          break;
        case QUEEN:
          printf("Q ");
          break;
        case KING:
          printf("K ");
          break;
        }
        break;
      case BLACK:
        switch(b->squares[i][j].type) {
        case EMPTY:
          printf(". ");
          break;
        case PAWN:
          printf("p ");
          break;
        case KNIGHT:
          printf("n ");
          break;
        case BISHOP:
          printf("b ");
          break;
        case ROOK:
          printf("r ");
          break;
        case QUEEN:
          printf("q ");
          break;
        case KING:
          printf("k ");
          break;
        }
        break;
      }
    }
    printf("\n");
  }
}

void move_piece(struct board *b, struct move m) {
  /* TODO */
}

int is_check(struct board *b, int color) {
  /* TODO */
  return 0;
}