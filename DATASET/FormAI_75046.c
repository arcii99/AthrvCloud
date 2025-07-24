//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int alienProbability, humanProbability, randomNumber;
	
  // Seed the random number generator with the current time
  srand(time(NULL));
  
  // Generate a random number between 1 to 100 to simulate the probability of an alien invasion
  randomNumber = rand() % 100 + 1;
	
  // Calculate the probability of an alien invasion
  alienProbability = randomNumber * 0.75;
  
  // Calculate the probability of humans successfully defending against an alien invasion
  humanProbability = 100 - alienProbability;
  
  // Display the results
  printf("ALIEN INVASION PROBABILITY CALCULATOR\n\n");
  printf("The probability of an alien invasion is %d%%.\n", alienProbability);
  printf("The probability of humans successfully defending against an alien invasion is %d%%.\n", humanProbability);

  // Determine the likelihood of the alien invasion
  if (alienProbability < 25) {
    printf("\nIt is unlikely that an alien invasion will occur. Carry on with your normal activities.\n");
  }
  else if (alienProbability >= 25 && alienProbability < 50) {
    printf("\nThere is a moderate chance of an alien invasion occurring. Stay alert and prepare for possible invasion.\n");
  }
  else if (alienProbability >= 50 && alienProbability < 75) {
    printf("\nThere is a high chance of an alien invasion occurring. Prepare yourselves for the worst and implement a contingency plan.\n");
  }
  else {
    printf("\nAn alien invasion is imminent. Proceed with caution and initiate full-scale evacuation protocols.\n");
  }
	
  return 0;
}