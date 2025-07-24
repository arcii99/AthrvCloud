//FormAI DATASET v1.0 Category: Dice Roller ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int sides, numDice, total = 0, i;

  printf("Enter the number of sides on each die: ");
  scanf("%d", &sides);

  printf("Enter the number of dice to roll: ");
  scanf("%d", &numDice);

  srand((unsigned) time(NULL));

  printf("Rolling %d d%d...\n", numDice, sides);

  for (i = 0; i < numDice; i++) {
    int roll = rand() % sides + 1;

    total += roll;

    printf("Die %d: %d\n", i + 1, roll);
  }

  printf("Total: %d\n", total);

  return 0;
}