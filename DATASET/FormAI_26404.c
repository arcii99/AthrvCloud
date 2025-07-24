//FormAI DATASET v1.0 Category: Dice Roller ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  srand(time(0)); //seeds rand with current time

  int numRolls, numSides;

  printf("Welcome to the Dice Roller!\n");

  do { //loop until user enters valid number of rolls and sides
    printf("How many rolls would you like to make? (1-100)\n");
    scanf("%d", &numRolls);
  } while (numRolls < 1 || numRolls > 100);

  do {
    printf("How many sides should the dice have? (2-100)\n");
    scanf("%d", &numSides);
  } while (numSides < 2 || numSides > 100);

  printf("Rolling %d %d-sided dice...\n", numRolls, numSides);

  int total = 0;

  for (int i = 0; i < numRolls; i++) {
    int roll = rand() % numSides + 1; //random number between 1 and numSides inclusive
    total += roll;
    printf("Roll %d: %d\n", i+1, roll);
  }

  printf("Total: %d\n", total);

  printf("Thanks for rolling with us, we hope you had fun!\n");

  return 0;
}