//FormAI DATASET v1.0 Category: Table Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int playerScore = 0;
  int computerScore = 0;
  int roundNumber = 1;

  printf("Welcome to the C Table Game!\n");

  while (roundNumber <= 10) {
    printf("Round %d\n", roundNumber);
    printf("Player's turn:\n");
    int playerRoll1 = rand() % 6 + 1;
    int playerRoll2 = rand() % 6 + 1;
    printf("Roll 1: %d\nRoll 2: %d\n", playerRoll1, playerRoll2);
    playerScore += playerRoll1 + playerRoll2;
    printf("Total score: %d\n", playerScore);

    if (playerScore >= 100) {
      printf("You win!\n");
      return 0;
    }

    printf("Computer's turn:\n");
    int computerRoll1 = rand() % 6 + 1;
    int computerRoll2 = rand() % 6 + 1;
    printf("Roll 1: %d\nRoll 2: %d\n", computerRoll1, computerRoll2);
    computerScore += computerRoll1 + computerRoll2;
    printf("Total score: %d\n", computerScore);

    if (computerScore >= 100) {
      printf("Computer wins!\n");
      return 0;
    }

    roundNumber++;
  }

  if (playerScore > computerScore) {
    printf("You win!\n");
  } else if (computerScore > playerScore) {
    printf("Computer wins!\n");
  } else {
    printf("It's a tie!\n");
  }

  return 0;
}