//FormAI DATASET v1.0 Category: Dice Roller ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice() {
  // generate a random integer between 1 and 6
  return rand() % 6 + 1;
}

int main() {
  // seed the random number generator
  srand(time(NULL));

  int numRolls = 0;  // number of times user wishes to roll the dice
  int total = 0;     // sum of all dice rolls
  int i;             // loop variable

  printf("Welcome to the Dice Roller program!\n");

  // get user input for number of rolls
  while (numRolls <= 0) {
    printf("How many times would you like to roll the dice? ");
    scanf("%d", &numRolls);
  }

  // perform the rolls
  printf("Rolling the dice %d time%s...\n\n", numRolls, numRolls > 1 ? "s" : "");

  for (i = 0; i < numRolls; i++) {
    int roll = rollDice();
    total += roll;

    // print the result of each roll
    printf("Roll #%d: %d\n", i + 1, roll);
  }

  // print the total
  printf("\nTotal: %d\n", total);
  
  return 0;
}