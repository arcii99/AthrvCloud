//FormAI DATASET v1.0 Category: Dice Roller ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice() {
  int roll = rand() % 6 + 1;

  return roll;
}

int main() {
  srand(time(NULL));
  int dice1, dice2, sum;
  char choice;

  do {
    printf("Rolling the dice...\n");
    dice1 = rollDice();
    dice2 = rollDice();
    sum = dice1 + dice2;

    printf("Dice 1: %d\n", dice1);
    printf("Dice 2: %d\n", dice2);
    printf("Sum: %d\n", sum);

    printf("Press 'Y' to roll again or any other key to exit: ");
    scanf(" %c", &choice);
  } while (choice == 'Y' || choice == 'y');

  printf("Thank you for rolling the dice!\n");
  return 0;
}