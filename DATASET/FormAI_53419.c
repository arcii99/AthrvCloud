//FormAI DATASET v1.0 Category: Table Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Welcome to C Table Game!\n");
  printf("This game is the perfect combination of chance and strategy. Let's see how well you do!\n\n");

  int player1 = rand() % 6 + 1;
  int player2 = rand() % 6 + 1;
  int total1 = player1;
  int total2 = player2;
  int round = 1;

  printf("Round %d:\n", round);
  printf("Player 1 rolled a %d\n", player1);
  printf("Player 2 rolled a %d\n", player2);

  if (player1 == player2) {
    printf("It's a tie! Roll again.\n");
    player1 = rand() % 6 + 1;
    player2 = rand() % 6 + 1;
    total1 += player1;
    total2 += player2;
    printf("Player 1 rolled a %d\n", player1);
    printf("Player 2 rolled a %d\n", player2);
  }

  while (total1 < 100 && total2 < 100) {
    round++;
    printf("\nRound %d:\n", round);

    if (total1 >= total2) {
      player2 = rand() % 6 + 1;
      total2 += player2;
      printf("Player 2 rolled a %d\n", player2);

      if (player2 == 1) {
        total2--;
        printf("Uh-oh! Player 2 rolled a 1 and lost a point.\n");
      }

      else {
        printf("Player 2 gained %d points for a total of %d\n", player2, total2);
      }

      if (total2 >= 100) {
        printf("Player 2 wins!\n");
        break;
      }
    }

    if (total2 >= total1) {
      player1 = rand() % 6 + 1;
      total1 += player1;
      printf("Player 1 rolled a %d\n", player1);

      if (player1 == 1) {
        total1--;
        printf("Uh-oh! Player 1 rolled a 1 and lost a point.\n");
      }

      else {
        printf("Player 1 gained %d points for a total of %d\n", player1, total1);
      }

      if (total1 >= 100) {
        printf("Player 1 wins!\n");
        break;
      }
    }
  }

  printf("\nThanks for playing C Table Game! See you next time!");
  return 0;
}