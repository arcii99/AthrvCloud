//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  printf("Welcome to the Alien Invasion Probability Calculator!\n");
  printf("Please enter the current year:\n");
  int currentYear = 0;
  scanf("%d", &currentYear);

  if (currentYear < 2022) {
    printf("Sorry, time travel is not yet possible.\n");
    return 0;
  }

  printf("Please enter the number of known exoplanets:\n");
  int numExoplanets = 0;
  scanf("%d", &numExoplanets);

  if (numExoplanets == 0) {
    printf("Unfortunately, there are no known exoplanets to use in our calculations.\n");
    return 0;
  }

  printf("Please enter the distance (in light years) to the farthest known exoplanet:\n");
  double farthestDistance = 0.0;
  scanf("%lf", &farthestDistance);

  if (farthestDistance <= 0.0) {
    printf("Invalid input.\n");
    return 0;
  }

  srand(time(NULL));
  int randomNum = rand() % 100 + 1;

  double probability = (numExoplanets * 100) / (farthestDistance * farthestDistance * randomNum);

  printf("\nThe probability of an alien invasion in the next 100 years is:\n");
  printf("%f%%\n", probability);

  return 0;
}