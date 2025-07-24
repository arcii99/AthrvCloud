//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define ALIEN_PROBABILITY 0.25

int main() {
  // Get user input
  int num_planets;
  printf("Enter the number of planets in the galaxy: ");
  scanf("%d", &num_planets);

  int num_inhabited_planets;
  printf("Enter the number of inhabited planets in the galaxy: ");
  scanf("%d", &num_inhabited_planets);

  // Calculate the probability of an alien invasion
  double probability = ALIEN_PROBABILITY * ((double)num_planets / (double)num_inhabited_planets);

  // Display the results
  printf("The probability of an alien invasion is %.2lf%%\n", probability * 100);

  return 0;
}