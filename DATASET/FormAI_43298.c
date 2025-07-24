//FormAI DATASET v1.0 Category: Table Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Define variables
  int player1_score = 0;
  int player2_score = 0;
  int roll, round_score;
  char choice;

  // Loop for each round
  while (player1_score < 100 && player2_score < 100) {
    // Player 1's turn
    printf("Player 1, it's your turn.\n");
    printf("Press 'r' to roll the dice or 'h' to hold.\n");
    choice = getchar();
    getchar(); // Consume newline character
    round_score = 0;
    while (choice == 'r') {
      // Roll the dice
      roll = rand() % 6 + 1;
      printf("You rolled a %d.\n", roll);
      if (roll == 1) {
        printf("You lose all points for this round.\n");
        round_score = 0;
        break;
      }
      round_score += roll;
      printf("Your round score is %d.\n", round_score);
      if (player1_score + round_score >= 100) {
        break;
      }
      printf("Press 'r' to roll again or 'h' to hold.\n");
      choice = getchar();
      getchar(); // Consume newline character
    }
    player1_score += round_score;
    printf("Player 1's score is now %d.\n", player1_score);

    // Player 2's turn
    printf("Player 2, it's your turn.\n");
    printf("Press 'r' to roll the dice or 'h' to hold.\n");
    choice = getchar();
    getchar(); // Consume newline character
    round_score = 0;
    while (choice == 'r') {
      // Roll the dice
      roll = rand() % 6 + 1;
      printf("You rolled a %d.\n", roll);
      if (roll == 1) {
        printf("You lose all points for this round.\n");
        round_score = 0;
        break;
      }
      round_score += roll;
      printf("Your round score is %d.\n", round_score);
      if (player2_score + round_score >= 100) {
        break;
      }
      printf("Press 'r' to roll again or 'h' to hold.\n");
      choice = getchar();
      getchar(); // Consume newline character
    }
    player2_score += round_score;
    printf("Player 2's score is now %d.\n", player2_score);
  }

  // Determine the winner
  if (player1_score >= 100) {
    printf("Congratulations, Player 1! You win!\n");
  } else {
    printf("Congratulations, Player 2! You win!\n");
  }

  return 0;
}