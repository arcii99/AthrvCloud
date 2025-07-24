//FormAI DATASET v1.0 Category: Chess engine ; Style: beginner-friendly
#include <stdio.h>

void printBoard(char board[8][8]) {
  printf("  a b c d e f g h\n");
  for(int i = 0; i < 8; i++) {
    printf("%d ", i+1);
    for(int j = 0; j < 8; j++) {
      printf("%c ", board[i][j]);
    }
    printf("%d\n", i+1);
  }
  printf("  a b c d e f g h\n");
}

int main() {
  char board[8][8] = {
    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
  };

  printBoard(board);
  return 0;
}