//FormAI DATASET v1.0 Category: Dice Roller ; Style: excited
// Woohoo! Let's roll some dice!
// Prepare for an exciting adventure of random numbers.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Initialise the random number generator
  srand(time(0));
  
  // Declare variables for number of dice and number of sides
  int numDice, numSides;
  printf("Welcome to the Dice Roller!\n");
  printf("Please enter how many dice you would like to roll: ");
  scanf("%d", &numDice);
  printf("Please enter how many sides each die should have: ");
  scanf("%d", &numSides);
  
  // Make sure the input is valid
  if (numDice < 1 || numSides < 2) {
    printf("Invalid input. At least 1 die with 2 sides required.\n");
    return 0;
  }
  
  // Roll the dice and print out the results
  printf("Rolling %d dice with %d sides each:\n", numDice, numSides);
  int total = 0;
  for (int i = 0; i < numDice; i++) {
    int roll = rand() % numSides + 1;
    printf("Die %d: %d\n", i + 1, roll);
    total += roll;
  }
  printf("Total: %d\n", total);
  
  // Woohoo! That was an exciting rollercoaster ride of randomness.
  return 0;
}