//FormAI DATASET v1.0 Category: Dice Roller ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  srand(time(0)); // Random seed based on current time
  int dice, rollResult, total = 0; // Initializing dice, roll result and total score variables
  char choice; // Initializing play again choice variable

  printf("Welcome to the C Dice Roller game!\n\n"); // Game title and introduction
  printf("Press enter to roll the dice...\n");

  do { // Loop to repeat game until player decides to quit

    getchar(); // Wait for user input before rolling dice

    dice = (rand() % 6) + 1; // Generate random number between 1 and 6

    printf("\nYou rolled a %d!\n", dice); // Display roll result
    total += dice; // Add roll result to total score
    printf("Your total score so far is: %d\n", total); // Display current total score

    if (total >= 20) { // Check if player has won
      printf("\nCongratulations, you've won the game!\n");
      break; // Exit game loop
    }

    printf("\nWould you like to roll again? (Y/N): "); // Ask player if they want to roll again
    scanf(" %c", &choice); // Get player's play again choice

  } while (choice == 'Y' || choice == 'y'); // Loop as long as player chooses to play again

  printf("\nThanks for playing the C Dice Roller game!\n"); // Game over message

  return 0;
}