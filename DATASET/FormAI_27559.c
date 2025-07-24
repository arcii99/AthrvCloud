//FormAI DATASET v1.0 Category: Dice Roller ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  int numDice;
  int numSides;
  int totalRoll = 0;

  printf("Welcome to the Dice Roller program!\n\n");

  // Get the number of dice to roll
  printf("How many dice would you like to roll? ");
  scanf("%d", &numDice);

  // Get the number of sides on each die
  printf("How many sides does each die have? ");
  scanf("%d", &numSides);

  // Roll the dice and print out the results
  printf("\nRolling %d dice with %d sides each...\n\n", numDice, numSides);
  printf("Roll results: ");

  srand(time(NULL));
  for (int i = 0; i < numDice; i++) {
    int roll = (rand() % numSides) + 1;
    totalRoll += roll;
    printf("%d ", roll);
  }

  printf("\n\nTotal roll: %d\n", totalRoll);

  return 0;
}