//FormAI DATASET v1.0 Category: Dice Roller ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int num_dice, num_sides, i, j;
  int result;

  // Get user input for number of dice and their sides
  printf("How many dice would you like to roll? ");
  scanf("%d", &num_dice);
  printf("How many sides do your dice have? ");
  scanf("%d", &num_sides);

  // Set the random seed to the current time
  srand(time(0));

  // Loop through each dice roll and generate a random result
  for (i = 1; i <= num_dice; i++) {
    result = 0;
    for (j = 1; j <= num_sides; j++) {
      result += rand() % num_sides + 1;
    }
    printf("Roll #%d: %d\n", i, result);
  }

  return 0;
}