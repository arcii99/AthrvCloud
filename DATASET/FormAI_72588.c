//FormAI DATASET v1.0 Category: Dice Roller ; Style: intelligent
#include <stdio.h> // For standard input/output functions
#include <stdlib.h> // For random number generation functions
#include <time.h> // For the time function

int main() {
  int num_dice, num_sides, i, roll, total = 0;

  // Get number of dice and number of sides from user
  printf("How many dice do you want to roll? ");
  scanf("%d", &num_dice);
  printf("How many sides does each die have? ");
  scanf("%d", &num_sides);

  // Set the seed for the random number generator using the current time
  srand(time(NULL));

  // Roll the dice and print the results
  printf("Rolling %d %d-sided dice...\n\n", num_dice, num_sides);
  for (i = 1; i <= num_dice; i++) {
    roll = rand() % num_sides + 1;
    printf("Die %d: %d\n", i, roll);
    total += roll;
  }
  printf("\nTotal: %d\n", total);

  return 0;
}