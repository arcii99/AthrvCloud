//FormAI DATASET v1.0 Category: Dice Roller ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll a dice
int rollDice() {
  // Generate a random number from 1 to 6
  int result = (rand() % 6) + 1;
  return result;
}

int main() {
  // Set seed for random number generation
  srand(time(NULL));

  // Welcome message
  printf("Welcome to Retro Dice Roller!\n");

  // Loop until user chooses to quit
  while (1) {
    // Prompt user to roll the dice
    printf("Press ENTER to roll the dice (or type 'q' to quit): ");
    char input[10];
    fgets(input, 10, stdin);

    // Check for quit command
    if (input[0] == 'q') {
      printf("Thanks for playing!\n");
      break;
    }

    // Roll the dice
    int result = rollDice();

    // Show the result
    printf("You rolled a %d!\n", result);
  }

  return 0;
}