//FormAI DATASET v1.0 Category: Dice Roller ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice() {
  return (rand() % 6) + 1;
}

int main() {
  srand(time(NULL));

  int numRolls;
  printf("How many times would you like to roll the dice? ");
  scanf("%d", &numRolls);

  int rolls[numRolls];
  for (int i = 0; i < numRolls; i++) {
    rolls[i] = rollDice();
  }

  printf("\n");

  for (int i = 0; i < numRolls; i++) {
    printf("Roll %d: %d\n", i+1, rolls[i]);
  }

  return 0;
}