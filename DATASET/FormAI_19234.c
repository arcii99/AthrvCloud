//FormAI DATASET v1.0 Category: Dice Roller ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int numRolls, maxRoll, i, roll;
  srand(time(NULL)); //seed RNG with time

  printf("How many dice would you like to roll?\n");
  scanf("%d", &numRolls);

  printf("What is the maximum roll of each die?\n");
  scanf("%d", &maxRoll);

  printf("\nRolling %d %d-sided dice...\n\n", numRolls, maxRoll);

  for (i = 1; i <= numRolls; i++) {
    roll = (rand() % maxRoll) + 1; //generate random number between 1 and maxRoll
    printf("Die %d: %d\n", i, roll);
  }

  return 0;
}