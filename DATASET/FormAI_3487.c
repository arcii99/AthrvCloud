//FormAI DATASET v1.0 Category: Table Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int player1Pos = 0;
  int player2Pos = 0;
  int numMoves = 0;
  srand(time(0));

  printf("Welcome to the Table Game!\n");
  printf("Player 1 starts at position 0, and Player 2 starts at position 0.\n");

  while (player1Pos < 100 && player2Pos < 100) {
    printf("\n");
    printf("Player 1's turn:\n");
    int move = rand() % 6 + 1;
    printf("You rolled a %d.\n", move);
    player1Pos += move;
    printf("You moved %d spaces.\n", move);
    if (player1Pos >= 100) {
      printf("You won!\n");
      return 0;
    }
    printf("You are now at position %d.\n", player1Pos);

    printf("\n");
    printf("Player 2's turn:\n");
    move = rand() % 6 + 1;
    printf("You rolled a %d.\n", move);
    player2Pos += move;
    printf("You moved %d spaces.\n", move);
    if (player2Pos >= 100) {
      printf("You won!\n");
      return 0;
    }
    printf("You are now at position %d.\n", player2Pos);

    numMoves++;
    printf("\n");
    printf("Number of moves taken: %d.\n", numMoves);
    printf("\n");
  }

  return 0;
}