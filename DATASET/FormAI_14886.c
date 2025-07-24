//FormAI DATASET v1.0 Category: Dice Roller ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice() {
  // Generates a random number between 1 and 6 (inclusive) and returns it
  int num = rand() % 6 + 1;
  return num;
}

int main() {
  int numRolls, i;
  int dice1, dice2;
  int sum, total = 0;

  srand(time(NULL)); // Initializes random seed

  printf("--- Dice Roller ---\n");
  printf("How many rolls? ");
  scanf("%d", &numRolls);

  for (i = 0; i < numRolls; i++) {
    dice1 = rollDice();
    dice2 = rollDice();
    sum = dice1 + dice2;
    total += sum;
    printf("Roll %d: %d + %d = %d\n", i + 1, dice1, dice2, sum);
  }

  printf("Total: %d\n", total);

  return 0;
}