//FormAI DATASET v1.0 Category: Dice Roller ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll dice and return the result
int rollDice(int sides) {
  return (rand() % sides) + 1;
}

int main() {
  // Seed the random number generator with the current time
  srand(time(NULL));

  int numDice = 0;
  int numSides = 0;

  // Get user input for the number of dice and the number of sides on each die
  printf("Enter the number of dice to roll: ");
  scanf("%d", &numDice);

  printf("Enter the number of sides per die: ");
  scanf("%d", &numSides);

  // Roll the dice and print the results
  int total = 0;
  printf("Rolling %d %d-sided dice...\n", numDice, numSides);
  for (int i = 0; i < numDice; i++) {
    int roll = rollDice(numSides);
    printf("Die #%d: %d\n", i+1, roll);
    total += roll;
  }

  // Print the total of all the rolls
  printf("Total: %d\n", total);

  return 0;
}