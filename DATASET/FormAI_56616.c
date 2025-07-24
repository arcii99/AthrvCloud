//FormAI DATASET v1.0 Category: Table Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int player1_score = 0;
  int player2_score = 0;

  // Set up random number generator
  srand(time(0));

  printf("*** Shoot the Hoops ***\n");

  // Each player gets five shots
  for (int i = 0; i < 5; i++) {
    printf("\nPlayer 1, shoot! (press enter)");
    getchar();
    int shot1 = rand() % 100; // Generate random number between 0 and 99
    printf("Player 1 scored: %d\n", shot1);
    player1_score += shot1;

    printf("\nPlayer 2, shoot! (press enter)");
    getchar();
    int shot2 = rand() % 100;
    printf("Player 2 scored: %d\n", shot2);
    player2_score += shot2;
  }

  // Display final scores
  printf("\nFinal scores:\n");
  printf("Player 1: %d\n", player1_score);
  printf("Player 2: %d\n", player2_score);

  // Determine the winner
  if (player1_score > player2_score) {
    printf("\nPlayer 1 wins!\n");
  } else if (player2_score > player1_score) {
    printf("\nPlayer 2 wins!\n");
  } else {
    printf("\nIt's a tie!\n");
  }

  return 0;
}