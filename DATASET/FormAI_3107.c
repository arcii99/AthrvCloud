//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: ultraprecise
#include <stdio.h>

int main() {
  int numAliens, worldPop, years;
  float alienProb, invasionProb;

  // Gather user input
  printf("Enter the estimated number of aliens: ");
  scanf("%d", &numAliens);
  printf("Enter the estimated world population: ");
  scanf("%d", &worldPop);
  printf("Enter the estimated number of years until potential invasion: ");
  scanf("%d", &years);

  // Calculate alien probability and invasion probability
  alienProb = (float)numAliens / worldPop;
  invasionProb = alienProb / (float)years;

  // Output results to user
  printf("\nBased on the estimated number of aliens and world population, the probability of an alien species existing on Earth is %f", alienProb);
  printf("\nBased on the estimated number of years until potential invasion, the probability of an alien invasion on Earth is %f", invasionProb);

  return 0;
}