//FormAI DATASET v1.0 Category: Dice Roller ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int sides, rolls, i, j;

  srand(time(NULL)); // Seed the random number generator with current time

  printf("Welcome to the Dice Roller program!\n");
  printf("Please enter the number of sides on the dice: ");
  scanf("%d", &sides);

  printf("Please enter the number of times you want to roll the dice: ");
  scanf("%d", &rolls);

  // Roll the dice
  for (i = 1; i <= rolls; i++) {
    printf("Roll %d: ", i);
    for (j = 1; j <= 2; j++) { // Roll two dice
      printf("%d ", (rand() % sides) + 1);
    }
    printf("\n");
  }

  printf("Thank you for using the Dice Roller program!\n");

  return 0;
}