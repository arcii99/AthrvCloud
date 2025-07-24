//FormAI DATASET v1.0 Category: Dice Roller ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random numbers between 1 and 6
int roll_dice() {
  int result;
  srand(time(NULL)); // Seed the random number generator with current time
  result = (rand() % 6) + 1;
  return result;
}

// Main function
int main() {
  int rolls, i, result, total;

  // Prompt user for number of rolls
  printf("Please enter the number of times you would like to roll the dice: ");
  scanf("%d", &rolls);

  // Roll the dice and display the results
  printf("Rolling the dice %d times...\n", rolls);
  printf("Results:\n");

  for (i = 0; i < rolls; i++) {
    result = roll_dice();
    printf("Roll %d: %d\n", i + 1, result);
    total += result;
  }

  // Display the total of all the rolls
  printf("Total: %d\n", total);

  return 0;
}