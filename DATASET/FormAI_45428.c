//FormAI DATASET v1.0 Category: Dice Roller ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll a dice with specified number of sides
int roll_dice(int num_sides) {
  int result = (rand() % num_sides) + 1;
  return result;
}

int main() {
  int num_rolls, num_sides;

  // Ask user for number of rolls and sides on dice
  printf("Enter number of rolls: ");
  scanf("%d", &num_rolls);
  printf("Enter number of sides on dice: ");
  scanf("%d", &num_sides);

  // Seed the random number generator
  srand(time(NULL));

  // Roll the dice num_rolls times and print results
  for (int i = 0; i < num_rolls; i++) {
    int roll = roll_dice(num_sides);
    printf("Roll %d: %d\n", i+1, roll);
  }

  return 0;
}