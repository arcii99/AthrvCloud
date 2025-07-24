//FormAI DATASET v1.0 Category: Dice Roller ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // initialize random number
  srand(time(0));

  int numRolls, diceSides, results[numRolls];
  float averageResult = 0;

  printf("Welcome to the Genius Dice Rolling Program!\n");

  // prompt user for number of rolls
  printf("How many times would you like to roll the dice?\n");
  scanf("%d", &numRolls);

  // prompt user for number of sides on dice
  printf("How many sides does the dice have?\n");
  scanf("%d", &diceSides);
  
  // roll the dice and store results
  for (int i = 0; i < numRolls; i++) {
    results[i] = rand() % diceSides + 1;
    averageResult += results[i];
  }
  averageResult /= numRolls;

  // print out the results
  printf("Here are your %d dice rolls:\n", numRolls);
  for (int i = 0; i < numRolls; i++) {
    printf("%d ", results[i]);
  }

  // print out the average result
  printf("\n\nThe average roll was: %.2f\n", averageResult);

  return 0;
}