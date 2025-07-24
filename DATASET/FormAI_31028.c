//FormAI DATASET v1.0 Category: Dice Roller ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int numDice, numSides, i, j, total = 0;

  printf("Welcome to the Dice Roller!\n");

  // Get number of dice
  printf("How many dice would you like to roll? ");
  scanf("%d", &numDice);

  // Get number of sides on dice
  printf("How many sides does each die have? ");
  scanf("%d", &numSides);

  // Seed random numbers with current time
  srand(time(NULL));

  // Roll dice and display results
  printf("\nRolling...\n");
  for (i = 1; i <= numDice; i++) {
    int dieRoll = rand() % numSides + 1;
    total += dieRoll;
    printf("Die %d: %d\n", i, dieRoll);
  }

  // Display total
  printf("\nTotal: %d\n", total);

  // Optional: roll again
  printf("\nWould you like to roll again? (Y/N) ");
  char answer;
  scanf(" %c", &answer);
  if (answer == 'Y' || answer == 'y') {
    main(); // Call main function again to roll again
  }

  return 0;
}