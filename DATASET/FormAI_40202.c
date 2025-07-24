//FormAI DATASET v1.0 Category: Chess engine ; Style: scalable
#include <stdio.h>

int main() {

  printf("Hello, welcome to my Chess engine!\n");

  char board[8][8] = {{'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                      {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'}, 
                      {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
                      {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
                      {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
                      {'.', ' ', '.', ' ', ' ', '.', ' ', '.'},
                      {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                      {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}};

  for(int i=0; i<8; i++) {
    printf("   +---+---+---+---+---+---+---+---+\n");
    printf(" %d | %c | %c | %c | %c | %c | %c | %c | %c |\n", 8-i, board[i][0], board[i][1], board[i][2], board[i][3], board[i][4], board[i][5], board[i][6], board[i][7]);
  }
  printf("   +---+---+---+---+---+---+---+---+\n");
  printf("     a   b   c   d   e   f   g   h\n");

  return 0;
}