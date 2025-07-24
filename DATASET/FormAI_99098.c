//FormAI DATASET v1.0 Category: Dice Roller ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  printf("Welcome to our romantic dice roller game!\n\n");

  int dice1, dice2, sum;
  char choice;

  do {
    printf("Press any key to roll the dice...\n");
    scanf("%c", &choice);
    srand(time(0));
    dice1 = (rand() % 6) + 1;
    dice2 = (rand() % 6) + 1;
    sum = dice1 + dice2;

    printf("\nYou rolled \nDice 1: %d \nDice 2: %d \nSum: %d\n", dice1, dice2, sum);

    if (sum == 7 || sum == 11) {
      printf("\nCongratulations! You've just rolled a lucky number! You win!\n");
    } else if (sum == 2 || sum == 3 || sum == 12) {
      printf("\nSorry! You rolled craps! You lose!\n");
    } else {
      printf("\nKeep rolling!\n");
    }

    printf("\nDo you want to roll again? (Y/N): ");
    scanf(" %c", &choice);

  } while (choice == 'Y' || choice == 'y');

  printf("\nThank you for playing our romantic dice roller game! Goodbye!\n");

  return 0;
}