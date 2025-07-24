//FormAI DATASET v1.0 Category: Chess engine ; Style: standalone
#include <stdio.h>

#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE];

void init_board() {
  int i, j;
  for (i = 0; i < BOARD_SIZE; i++) {
    for (j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = '-';
    }
  }
}
void print_board() {
  int i, j;
  printf("\n");
  printf("  A B C D E F G H\n");
  for (i = 0; i < BOARD_SIZE; i++) {
    printf("%d", 8 - i);
    for (j = 0; j < BOARD_SIZE; j++) {
      printf(" %c", board[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}
int main() {
  init_board();
  print_board();
  return 0;
}