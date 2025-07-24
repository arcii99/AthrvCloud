//FormAI DATASET v1.0 Category: Dice Roller ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int num_of_rolls, num_of_sides, i, total = 0;
  
  // Get number of rolls and number of sides
  printf("Enter the number of rolls: ");
  scanf("%d", &num_of_rolls);
  
  printf("Enter the number of sides on the dice: ");
  scanf("%d", &num_of_sides);
  
  // Ensure valid input
  if (num_of_rolls <= 0 || num_of_sides <= 0) {
    printf("Invalid input. Exiting program.\n");
    return 0;
  }
  
  // Seed random number generator
  srand(time(NULL));
  
  // Roll the dice and print the results
  printf("Rolling the dice...\n");
  
  for (i = 1; i <= num_of_rolls; i++) {
    int roll = rand() % num_of_sides + 1;
    printf("Roll %d: %d\n", i, roll);
    total += roll;
  }
  
  // Print total of all rolls
  printf("Total: %d\n", total);
  
  return 0;
}