//FormAI DATASET v1.0 Category: Dice Roller ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int dice, roll_1, roll_2, roll_3;

  // Asks the user how many times they want to roll the dice
  printf("How many times would you like to roll the dice? : ");
  scanf("%d", &dice);

  // Generates the seed for the random number generator
  srand((unsigned)time(NULL));

  // Rolling the dice
  for (int i = 0; i < dice; i++) {
    // Generating random numbers for each roll
    roll_1 = (rand() % 6) + 1;
    roll_2 = (rand() % 6) + 1;
    roll_3 = (rand() % 6) + 1;

    // Displaying the results
    printf("Roll %d: %d %d %d\n", i+1, roll_1, roll_2, roll_3);
  }

  return 0;
}