//FormAI DATASET v1.0 Category: Dice Roller ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {

  // seed random number generator
  srand(time(NULL));

  // welcome message
  printf("Welcome to the Dice Roller program!\n\n");

  // loop until user decides to exit
  while (1) {
    // prompt user to roll dice
    printf("Press ENTER to roll the dice, or enter 'q' to quit...\n");
    char input = getchar();

    // exit loop if user chooses to quit
    if (input == 'q') {
      printf("Thanks for playing!\n");
      break;
    }

    // roll two six-sided dice
    int dice1 = (rand() % 6) + 1;
    int dice2 = (rand() % 6) + 1;

    // display results and total
    printf("\nDice 1: %d\n", dice1);
    printf("Dice 2: %d\n", dice2);
    printf("Total: %d\n\n", dice1 + dice2);
  }

  return 0;
}