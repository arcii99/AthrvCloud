//FormAI DATASET v1.0 Category: Dice Roller ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int numDice = 0;
  int numSides = 0;
  int totalRoll = 0;
  srand(time(NULL)); // Seed random number generator

  printf("Welcome to the Dice Roller program! I can help you roll some dice and even add up the total for you.\n");

  // Take user input for number of dice and number of sides on each dice
  printf("How many dice would you like to roll? ");
  scanf("%d", &numDice);
  printf("How many sides does each die have? ");
  scanf("%d", &numSides);

  // Print out the results of each die roll and keep a running total
  printf("\nRolling %d %d-sided dice...\n", numDice, numSides);
  for(int i = 0; i < numDice; i++) {
    int roll = rand() % numSides + 1;
    printf("Die %d: %d\n", i+1, roll);
    totalRoll += roll;
  }

  // Print out the total of all the dice rolls
  printf("\nTotal roll: %d\n", totalRoll);

  printf("I hope you had fun rolling dice! Goodbye!\n");

  return 0;
}