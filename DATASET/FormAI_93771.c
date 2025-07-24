//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int invasion_probability;
  srand(time(NULL)); // seed for random number generator

  printf("Welcome to the Alien Invasion Probability Calculator!\n\n");

  // generate random probability between 0 and 100
  invasion_probability = rand() % 101;

  printf("The current probability of an alien invasion is %d percent.\n", invasion_probability);

  // determine likelihood of invasion based on probability
  if (invasion_probability < 25) {
    printf("There is a low probability of an alien invasion.\n");
  } else if (invasion_probability >= 25 && invasion_probability <= 75) {
    printf("There is a moderate probability of an alien invasion.\n");
  } else {
    printf("There is a high probability of an alien invasion.\n");
  }

  printf("\nThank you for using the Alien Invasion Probability Calculator!\n");

  return 0;
}