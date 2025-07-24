//FormAI DATASET v1.0 Category: Table Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int player1_score = 0;
  int player2_score = 0;
  int target_score;
  int current_player = 1;
  srand(time(0));  // Seed the random number generator with the current time

  printf("Welcome to the Dice Rolling Game!\n");
  printf("Player 1, please enter the target score:\n");
  scanf("%d", &target_score);

  // Game loop
  while (1) {
    printf("\nPlayer %d's turn.\n", current_player);
    printf("Press enter to roll the dice.\n");
    getchar();  // Wait for user to press enter
    int roll1 = rand() % 6 + 1;
    int roll2 = rand() % 6 + 1;
    int roll_total = roll1 + roll2;
    printf("You rolled a %d and a %d, for a total of %d.\n", roll1, roll2, roll_total);

    // Update the score and check for a win
    if (current_player == 1) {
      player1_score += roll_total;
      if (player1_score >= target_score) {
        printf("\nCongratulations, Player 1! You have won!\n");
        break;
      }
    } else {
      player2_score += roll_total;
      if (player2_score >= target_score) {
        printf("\nCongratulations, Player 2! You have won!\n");
        break;
      }
    }

    // Display the current scores
    printf("Current scores: Player 1 - %d, Player 2 - %d\n", player1_score, player2_score);

    // Switch to the other player's turn
    current_player = (current_player == 1) ? 2 : 1;
  }

  return 0;
}