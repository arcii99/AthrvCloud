//FormAI DATASET v1.0 Category: Chess AI ; Style: shocked
#include <stdio.h>

#define BOARD_SIZE 8

enum Color {WHITE, BLACK};
enum Piece {EMPTY, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING};


struct Tile {
  enum Piece piece;
  enum Color color;
};

struct Board {
  struct Tile tiles[BOARD_SIZE][BOARD_SIZE];
  enum Color turn;
  int wKingRow;
  int wKingCol;
  int bKingRow;
  int bKingCol;
};

void initBoard(struct Board *board) {
  // Initialize the board
  board->turn = WHITE;

  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      // Set the piece
      if (i == 0 || i == 7) {
        if (j == 0 || j == 7) {
          board->tiles[i][j].piece = ROOK;
        } else if (j == 1 || j == 6) {
          board->tiles[i][j].piece = KNIGHT;
        } else if (j == 2 || j == 5) {
          board->tiles[i][j].piece = BISHOP;
        } else if (j == 3) {
          board->tiles[i][j].piece = QUEEN;
        } else {
          board->tiles[i][j].piece = KING;
        }
      } else if (i == 1 || i == 6) {
        board->tiles[i][j].piece = PAWN;
      } else {
        board->tiles[i][j].piece = EMPTY;
      }

      // Set the color
      if ((i + j) % 2 == 0) {
        board->tiles[i][j].color = BLACK;
      } else {
        board->tiles[i][j].color = WHITE;
      }
    }
  }

  board->wKingRow = 7;
  board->wKingCol = 4;
  board->bKingRow = 0;
  board->bKingCol = 4;
}

void printBoard(struct Board *board) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      switch (board->tiles[i][j].piece) {
        case EMPTY:
          printf(".");
          break;
        case PAWN:
          printf("P");
          break;
        case KNIGHT:
          printf("N");
          break;
        case BISHOP:
          printf("B");
          break;
        case ROOK:
          printf("R");
          break;
        case QUEEN:
          printf("Q");
          break;
        case KING:
          printf("K");
          break;
      }
    }
    printf("\n");
  }
}

int main(void) {
  struct Board board;
  initBoard(&board);
  printBoard(&board);
  return 0;
}