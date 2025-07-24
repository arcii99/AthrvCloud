//FormAI DATASET v1.0 Category: Dice Roller ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice(int sides) {
  int result;
  result = rand() % sides + 1;
  return result;
}

int main() {
  int numDice, sides, rollNum;

  srand(time(NULL));

  printf("Welcome to the Dice Roller! How many dice would you like to roll?\n");
  scanf("%d", &numDice);

  printf("How many sides does each die have?\n");
  scanf("%d", &sides);

  printf("How many times would you like to roll?\n");
  scanf("%d", &rollNum);

  printf("Rolling %d dice with %d sides each %d times:\n", numDice, sides, rollNum);

  for (int i = 1; i <= rollNum; i++) {
    printf("Roll %d:", i);

    for (int j = 1; j <= numDice; j++) {
      printf(" %d", rollDice(sides));
    }

    printf("\n");
  }

  printf("Thanks for rolling with us!\n");

  return 0;
}