//FormAI DATASET v1.0 Category: Dice Roller ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Get input for number of dice and number of sides
  int numDice, numSides;
  printf("How many dice do you want to roll? ");
  scanf("%d", &numDice);
  printf("How many sides does each die have? ");
  scanf("%d", &numSides);

  // Initialize random number generator
  srand(time(NULL));

  // Roll the dice and display the results
  int total = 0;
  printf("Rolling %d %d-sided dice...\n", numDice, numSides);
  printf("Results: ");
  for (int i = 0; i < numDice; i++) {
    int roll = rand() % numSides + 1;
    printf("%d ", roll);
    total += roll;
  }
  printf("\nTotal: %d\n", total);

  return 0;
}