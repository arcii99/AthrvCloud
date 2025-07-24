//FormAI DATASET v1.0 Category: Dice Roller ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  int numDice = 0;
  int numSides = 0;
  int i = 0;
  int result = 0;

  // get number of dice
  printf("Enter number of dice to roll: ");
  scanf("%d", &numDice);

  // get number of sides on dice
  printf("Enter number of sides on dice: ");
  scanf("%d", &numSides);

  // seed random number generator
  srand(time(0));

  printf("Rolling %d dice with %d sides each:\n", numDice, numSides);

  // roll dice and display result
  for (i = 1; i <= numDice; i++) {
    result = rand() % numSides + 1;
    printf("Dice %d: %d\n", i, result);
  }

  return 0;
}