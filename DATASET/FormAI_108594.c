//FormAI DATASET v1.0 Category: Chess engine ; Style: authentic
#include <stdio.h>
#include <string.h>

#define BOARD_SIZE 8
#define WHITE_PAWN 'P'
#define WHITE_KNIGHT 'N'
#define WHITE_BISHOP 'B'
#define WHITE_ROOK 'R'
#define WHITE_QUEEN 'Q'
#define WHITE_KING 'K'
#define BLACK_PAWN 'p'
#define BLACK_KNIGHT 'n'
#define BLACK_BISHOP 'b'
#define BLACK_ROOK 'r'
#define BLACK_QUEEN 'q'
#define BLACK_KING 'k'

char board[BOARD_SIZE][BOARD_SIZE];

void initialize_board(void) {
  // Setting up the chess board:
  // R - White rook
  // N - White knight
  // B - White bishop
  // Q - White queen
  // K - White king
  // P - White pawn
  // r - Black rook
  // n - Black knight
  // b - Black bishop
  // q - Black queen
  // k - Black king
  char initial_board[BOARD_SIZE][BOARD_SIZE] =
      {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
       {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
       {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
       {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
       {' ', '.', ' ', '.', ' ', '.', ' ', ' '},
       {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
       {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
       {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};
  memcpy(board, initial_board, sizeof(board));
}

void print_board(void) {
  printf("  a b c d e f g h \n");
  printf("  ---------------\n");
  for (int row = 0; row < BOARD_SIZE; row++) {
    printf("%d|", BOARD_SIZE - row);
    for (int col = 0; col < BOARD_SIZE; col++) {
      printf("%c|", board[row][col]);
    }
    printf("%d\n", BOARD_SIZE - row);
    printf(" |---------------|\n");
  }
  printf("  a b c d e f g h \n");
}

int main(void) {
  initialize_board();
  print_board();
  return 0;
}