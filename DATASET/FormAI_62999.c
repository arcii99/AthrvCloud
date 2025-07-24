//FormAI DATASET v1.0 Category: Chess engine ; Style: cheerful
#include <stdio.h>

// Chess engine structures

typedef enum { 
  empty, pawn, knight, bishop, rook, queen, king 
} piece_t;

typedef enum { 
  white, black 
} color_t;

typedef struct { 
  piece_t piece; 
  color_t color; 
} square_t;

typedef struct {
  square_t squares[8][8];
} board_t;

typedef struct {
  int x, y;
} position_t;

// Function to print the board

void print_board(board_t *board) {
  printf("  A B C D E F G H\n");

  for(int y=0; y<8; y++) {
    printf("%d ", y+1);

    for(int x=0; x<8; x++) {
      switch(board->squares[x][y].piece) {
        case empty:
          printf(". ");
          break;
        case pawn:
          printf("P ");
          break;
        case knight:
          printf("N ");
          break;
        case bishop:
          printf("B ");
          break;
        case rook:
          printf("R ");
          break;
        case queen:
          printf("Q ");
          break;
        case king:
          printf("K ");
          break;
        default:
          printf("? ");
          break;
      }
    }
    printf("\n");
  }
}

// Function to initialize the board

void init_board(board_t *board) {
  for(int x=0; x<8; x++) {
    board->squares[x][1].piece = pawn;
    board->squares[x][1].color = white;
    board->squares[x][6].piece = pawn;
    board->squares[x][6].color = black;
  }

  board->squares[0][0].piece = rook;
  board->squares[0][0].color = white;
  board->squares[1][0].piece = knight;
  board->squares[1][0].color = white;
  board->squares[2][0].piece = bishop;
  board->squares[2][0].color = white;
  board->squares[3][0].piece = queen;
  board->squares[3][0].color = white;
  board->squares[4][0].piece = king;
  board->squares[4][0].color = white;
  board->squares[5][0].piece = bishop;
  board->squares[5][0].color = white;
  board->squares[6][0].piece = knight;
  board->squares[6][0].color = white;
  board->squares[7][0].piece = rook;
  board->squares[7][0].color = white;

  board->squares[0][7].piece = rook;
  board->squares[0][7].color = black;
  board->squares[1][7].piece = knight;
  board->squares[1][7].color = black;
  board->squares[2][7].piece = bishop;
  board->squares[2][7].color = black;
  board->squares[3][7].piece = queen;
  board->squares[3][7].color = black;
  board->squares[4][7].piece = king;
  board->squares[4][7].color = black;
  board->squares[5][7].piece = bishop;
  board->squares[5][7].color = black;
  board->squares[6][7].piece = knight;
  board->squares[6][7].color = black;
  board->squares[7][7].piece = rook;
  board->squares[7][7].color = black;
}

// Function to move a piece

void move_piece(board_t *board, position_t from, position_t to) {
  board->squares[to.x][to.y] = board->squares[from.x][from.y];
  board->squares[from.x][from.y].piece = empty;
}

int main() {
  board_t board;
  position_t from, to;

  init_board(&board);
  print_board(&board);

  from.x = 4;
  from.y = 1;
  to.x = 4;
  to.y = 3;

  move_piece(&board, from, to);
  print_board(&board);

  return 0;
}