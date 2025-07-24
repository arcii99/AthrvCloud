//FormAI DATASET v1.0 Category: Dice Roller ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int num_dice, num_sides, i;
  char response;

  srand(time(NULL)); // seed the random number generator

  do {
    printf("How many dice would you like to roll? ");
    scanf("%d", &num_dice);

    printf("How many sides are on each die? ");
    scanf("%d", &num_sides);

    printf("Rolling %d %d-sided dice...\n", num_dice, num_sides);

    for (i = 1; i <= num_dice; i++) {
      int roll = (rand() % num_sides) + 1;
      printf("Die %d: %d\n", i, roll);
    }

    printf("Roll again? (y/n) ");
    scanf(" %c", &response);
  } while (response == 'y');

  return 0;
}