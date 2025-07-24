//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // initialize random seed with current time

  int numHumans = 0;
  int numAliens = 0;
  int numAttacks = 0;

  printf("Welcome to the Alien Invasion Probability Calculator!\n\n");
  printf("How many humans are currently living on Earth?\n");
  scanf("%d", &numHumans);
  printf("How many aliens are currently living in the universe?\n");
  scanf("%d", &numAliens);
  printf("How many times has Earth been attacked by aliens in the past?\n");
  scanf("%d", &numAttacks);

  float invasionProbability = (float) numHumans * numAliens * (numAttacks + 1) / 1000000;
  // probability formula based on number of humans, aliens, and past attacks

  printf("\nThe probability of Earth being invaded by aliens is %f percent.\n", invasionProbability);

  if (invasionProbability < 1) {
    printf("It's highly unlikely that an alien invasion will occur anytime soon.\n");
  } else if (invasionProbability > 99.9) {
    printf("It's almost guaranteed that Earth will be invaded by aliens.\n");
  } else {
    printf("There's a chance that Earth may be invaded by aliens in the future.\n");
  }

  return 0;
}