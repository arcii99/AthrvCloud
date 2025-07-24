//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: shape shifting
#include <stdio.h>

int main() {
  int numSightings;
  float invasionProbability;

  printf("Welcome to the Alien Invasion Probability Calculator!\n");
  printf("Please enter the number of UFO sightings in the past year: ");
  scanf("%d", &numSightings);

  if(numSightings > 0 && numSightings < 5) {
    invasionProbability = numSightings * 0.2;
  } else if(numSightings >= 5 && numSightings < 10) {
    invasionProbability = numSightings * 0.3;
  } else if(numSightings >= 10) {
    invasionProbability = numSightings * 0.5;
  } else {
    printf("Invalid input\n");
    return 0;
  }

  printf("\nBased on %d UFO sightings, the probability of an alien invasion is %.2f%%\n", numSightings, invasionProbability);
  printf("Stay vigilant, and keep watching the skies!\n");

  return 0;
}