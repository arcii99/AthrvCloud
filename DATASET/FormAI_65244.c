//FormAI DATASET v1.0 Category: Chess AI ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  printf("Welcome to the Chess AI that will beat you in a blink of an eye!\n");
  printf("Just kidding, I might take a while\n\n");
  
  /* Initializing the chess board */
  char board[8][8] = {
    {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
  };

  /* PRINT THE BOARD */
  printf("Blacks: r, n, b, q, k, p\n");
  printf("Whites: R, N, B, Q, K, P\n");
  printf("-------------------------\n");
  for (int i=0; i<8; i++) {
    printf("|");
    for (int j=0; j<8; j++) {
      printf("%c|", board[i][j]);
    }
    printf("\n-------------------------\n");
  }

  printf("\n\n I'm working on making the pieces move, stay tuned!\n\n");
  return 0;
}