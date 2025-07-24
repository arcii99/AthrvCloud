//FormAI DATASET v1.0 Category: Dice Roller ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int sides, rolls, i;
  char response;

  printf("Welcome to the Dice Roller program!\n\n");

  do {
    printf("Enter the number of sides on your die: ");
    scanf("%d", &sides);

    printf("Enter the number of times you want to roll the die: ");
    scanf("%d", &rolls);

    // seed the random number generator
    srand(time(NULL));

    printf("\nRolling the %d-sided die %d times...\n\n", sides, rolls);

    for(i = 0; i < rolls; i++) {
      printf("Roll #%d: %d\n", i + 1, (rand() % sides) + 1);
    }

    printf("\nRoll again? (y/n): ");
    scanf(" %c", &response);

  } while(response == 'y' || response == 'Y');

  printf("Thanks for using the Dice Roller program!\n");

  return 0;
}