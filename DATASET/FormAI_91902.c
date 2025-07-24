//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int probability;
  srand(time(NULL));

  printf("Welcome to the Alien Invasion Probability Calculator!\n");

  // Gather information from user
  printf("Please enter the number of spaceships currently orbiting Earth: ");
  int numShips;
  scanf("%d", &numShips);

  printf("Please enter the number of known alien species: ");
  int numAliens;
  scanf("%d", &numAliens);

  printf("Please enter the level of technology possessed by the aliens (on a scale of 1-10): ");
  int techLevel;
  scanf("%d", &techLevel);

  printf("Please enter the likelihood of a peaceful encounter with the aliens (on a scale of 1-10): ");
  int peacefulChance;
  scanf("%d", &peacefulChance);

  // Calculate probability of invasion
  int num = rand() % 101;
  if (numShips >= 10 || numAliens >= 5 || techLevel >= 8) {
    probability = num + 50;
  } else {
    probability = num;
  }

  // Print results
  if (probability <= (10 - peacefulChance)) {
    printf("Based on the given parameters, the probability of an alien invasion is extremely low.\n");
  } else if (probability <= (50 - peacefulChance)) {
    printf("Based on the given parameters, there is a moderate chance of an alien invasion.\n");
  } else {
    printf("Based on the given parameters, an alien invasion is highly probable.\n");
  }

  printf("The calculated probability of an alien invasion is: %d%%\n", probability);
  printf("Thank you for using the Alien Invasion Probability Calculator!\n");

  return 0;
}