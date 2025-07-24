//FormAI DATASET v1.0 Category: Dice Roller ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll the dice
int rollDice(int diceSides) {
  int roll = rand() % diceSides + 1; // Generate a random number between 1 and the number of sides on the dice
  return roll;
}

int main() {
  int diceSides, numDice, i, total = 0;
  char choice;

  srand(time(NULL)); // Seed the random number generator with the current time

  printf("Welcome to the Dice Roller program!\n");

  do {
    printf("\nEnter the number of sides on the dice: ");
    scanf("%d", &diceSides);

    printf("Enter the number of dice to roll: ");
    scanf("%d", &numDice);

    // Roll the dice
    printf("\nRolling %d %d-sided dice...\n\n", numDice, diceSides);
    for (i = 1; i <= numDice; i++) {
      int roll = rollDice(diceSides); // Roll the dice
      printf("Dice %d: %d\n", i, roll); // Print the result of the roll
      total += roll; // Add the roll to the total
    }

    // Print the total
    printf("\nTotal: %d\n", total);

    // Ask the user if they want to roll again
    printf("\nDo you want to roll again? (y/n) ");
    scanf(" %c", &choice);

    total = 0; // Reset the total

  } while (choice == 'y' || choice == 'Y');

  printf("\nThank you for using the Dice Roller program!\n");

  return 0;
}