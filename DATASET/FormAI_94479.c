//FormAI DATASET v1.0 Category: Dice Roller ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice(int sides) {
  return (rand() % sides) + 1;
}

int main(void) {
  int num_dice, sides, roll, sum = 0;

  srand((unsigned) time(NULL));

  printf("Welcome to the Dice Roller!\n\n");

  do {
    printf("Enter the number of dice to roll: ");
    scanf("%d", &num_dice);
  } while (num_dice < 1);

  do {
    printf("Enter the number of sides on each die: ");
    scanf("%d", &sides);
  } while (sides < 2);

  printf("\nRolling %d %d-sided dice...\n\n", num_dice, sides);

  printf("Roll results:");

  for (int i = 0; i < num_dice; i++) {
    roll = roll_dice(sides);
    printf(" %d", roll);
    sum += roll;
  }

  printf("\n\nTotal: %d", sum);

  return 0;
}