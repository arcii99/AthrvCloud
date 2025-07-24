//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int alienShips;
  double invasionProbability;
  int defenseForce;

  printf("Welcome to the Alien Invasion Probability Calculator!\n");

  printf("Please enter the number of alien ships: ");
  scanf("%d", &alienShips);

  printf("Please enter the size of your defense force: ");
  scanf("%d", &defenseForce);

  srand(time(NULL)); // Initialize random number generator with current time

  invasionProbability = ((double)rand() / RAND_MAX) * (1.0 - (double)defenseForce/(double)alienShips);

  printf("The probability of an alien invasion is: %f\n", invasionProbability);

  if (invasionProbability < 0.5) {
    printf("There is a low probability of an alien invasion, but be vigilant!\n");
  } else if (invasionProbability < 0.8) {
    printf("There is a moderate probability of an alien invasion. Make sure your defense force is ready!\n");
  } else {
    printf("There is a high probability of an alien invasion. Prepare for battle!\n");
  }

  return 0;
}