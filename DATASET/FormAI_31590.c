//FormAI DATASET v1.0 Category: Random ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Welcome Message
  printf("Welcome to my Random Number Generator!\n");

  // Seed the random number generator
  srand(time(NULL));

  // Get number of random numbers to generate
  int numRand;
  printf("How many random numbers do you want to generate? ");
  scanf("%d", &numRand);

  // Generate and print the random numbers
  printf("Your random numbers are:\n");
  for(int i = 0; i < numRand; i++) {
    printf("%d\n", rand());
  }

  // Get range for random numbers
  int range;
  printf("What range do you want your random numbers to be in? ");
  scanf("%d", &range);

  // Generate and print the random numbers within specified range
  printf("Your random numbers within the range of 0 to %d are:\n", range);
  for(int i = 0; i < numRand; i++) {
    printf("%d\n", rand() % (range + 1));
  }

  // Goodbye Message
  printf("Thank you for using my Random Number Generator!\n");

  return 0;
}