//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Initialize the variables
  int aliens, cities, probability;
  int maxAliens = 1000000;
  int maxCities = 1000;

  // Get the input from the user
  printf("Enter the number of aliens: ");
  scanf("%d", &aliens);

  printf("Enter the number of cities: ");
  scanf("%d", &cities);

  // Calculate the probability of an invasion
  probability = (aliens * cities * 100) / (maxAliens * maxCities);

  // Print the result
  printf("The probability of an invasion is %d%%\n", probability);

  // Determine if the invasion will occur or not
  int invasion = rand() % 100 + 1;
  if (invasion <= probability) {
    printf("The aliens have invaded!\n");
  } else {
    printf("The aliens did not invade.\n");
  }

  return 0;
}