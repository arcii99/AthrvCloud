//FormAI DATASET v1.0 Category: Chess AI ; Style: peaceful
#include <stdio.h>

// Function to initialize the chess board
void initialize_board(char board[8][8]) {
  char start_row[8] = {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'};
  for (int i = 0; i < 8; i++) {
    board[0][i] = start_row[i];
    board[1][i] = 'P';
    board[6][i] = 'p';
    board[7][i] = start_row[i] + 32;
    for (int j = 2; j < 6; j++) board[j][i] = '.';
  }
}

// Function to print the chess board
void print_board(char board[8][8]) {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
}

int main() {
  char board[8][8];
  initialize_board(board);
  print_board(board);
  return 0;
}