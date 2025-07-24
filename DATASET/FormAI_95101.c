//FormAI DATASET v1.0 Category: Random ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Welcome message
  printf("Welcome to the randomizer program!\n");

  // Seed the random number generator
  srand(time(0));
  
  // Prompt user for input
  int min, max;
  printf("Please enter a minimum value: ");
  scanf("%d", &min);
  printf("Please enter a maximum value: ");
  scanf("%d", &max);

  // Ensure that minimum < maximum
  if (min >= max) {
    printf("Error: Maximum value must be greater than minimum value.\n");
    return 1;
  }

  // Calculate range of values
  int range = max - min + 1;

  // Generate random number within range
  int randomNum = (rand() % range) + min;

  // Display results
  printf("Your random number between %d and %d is: %d\n", min, max, randomNum);

  // Option for rerun
  char rerun;
  printf("Would you like to generate another random number? (y/n): ");
  scanf(" %c", &rerun);
  
  if(rerun == 'y' || rerun == 'Y') {
    // Recursive call to main function
    main();
  }
  else {
    // Exit message
    printf("Thank you for using the randomizer program!");
    return 0;
  }
}