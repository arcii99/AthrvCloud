//FormAI DATASET v1.0 Category: Dice Roller ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* This is a cheerful C dice roller program! */

int main() {
  int dice1, dice2, sum;
  char choice = 'y';

  printf("\nWelcome to the Cheerful C Dice Roller!\n");

  /* Loop for re-rolling dice */
  while (choice == 'y') {
    printf("\nRolling dice...\n");
    srand(time(0)); 
    dice1 = (rand() % 6) + 1;
    dice2 = (rand() % 6) + 1;
    sum = dice1 + dice2;

    printf("\nDice 1: %d", dice1);
    printf("\nDice 2: %d", dice2);
    printf("\nSum: %d\n", sum);

    printf("\nDo you want to roll again? (y/n) ");
    scanf("%c", &choice);

    /* Clear input buffer */
    fflush(stdin);
  }

  printf("\nThank you for using the Cheerful C Dice Roller!\n");

  return 0;
}