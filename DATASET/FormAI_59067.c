//FormAI DATASET v1.0 Category: Dice Roller ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice(int numSides) {
  int result = (rand() % numSides) + 1;
  return result;
}

int main() {
  srand(time(NULL)); //seed the random number generator with current time
  int numDice, numSides, i, total = 0;

  printf("Welcome to the Dice Roller!\n");

  //get number of dice to roll
  printf("How many dice would you like to roll? ");
  scanf("%d", &numDice);

  //get number of sides for each die
  printf("How many sides does each die have? ");
  scanf("%d", &numSides);

  //roll each die and display the result
  printf("Rolling %d %d-sided dice...\n", numDice, numSides);
  for(i=1; i<=numDice; i++) {
    int rollResult = rollDice(numSides);
    printf("Die %d: %d\n", i, rollResult);
    total += rollResult;
  }

  //display the total result
  printf("Total: %d\n", total);

  return 0;
}