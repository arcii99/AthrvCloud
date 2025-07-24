//FormAI DATASET v1.0 Category: Chess AI ; Style: unmistakable
#include <stdio.h>

#define BOARD_SIZE 8

int board[BOARD_SIZE][BOARD_SIZE];

void init_board() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = 0;
    }
  }
}

void print_board() {
  printf("    A B C D E F G H\n");
  printf("   +---------------+\n");
  for (int i = 0; i < BOARD_SIZE; i++) {
    printf("%d  |", i + 1);
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == 0) {
        printf("  ");
      } else if (board[i][j] == 1) {
        printf("P ");
      } else if (board[i][j] == 2) {
        printf("R ");
      } else if (board[i][j] == 3) {
        printf("N ");
      } else if (board[i][j] == 4) {
        printf("B ");
      } else if (board[i][j] == 5) {
        printf("Q ");
      } else if (board[i][j] == 6) {
        printf("K ");
      }
    }
    printf("| %d\n", i + 1);
  }
  printf("   +---------------+\n");
  printf("    A B C D E F G H\n");
}

int main() {
  init_board();
  print_board();
  return 0;
}