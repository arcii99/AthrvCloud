//FormAI DATASET v1.0 Category: Dice Roller ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice() {
  return rand() % 6 + 1;
}

int main() {

  int diceRollCount;
  printf("How many dice rolls do you want?\n");
  scanf("%d", &diceRollCount);

  srand(time(0)); // initialize random number generator

  int sum = 0;
  int i;
  for (i = 0; i < diceRollCount; i++) {
    int roll = rollDice();
    printf("Roll %d: %d\n", i+1, roll);
    sum += roll;
  }

  printf("Total: %d\n", sum);

  return 0;
}