//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  
  // Seed the random number generator
  srand(time(NULL));
  
  // Initialize variables
  int alienProb, meteorProb, invasionProb;
  double alienFactor, meteorFactor, invasionFactor;
  
  // Generate random probability factors for the variables
  alienFactor = (double)rand() / RAND_MAX;
  meteorFactor = (double)rand() / RAND_MAX;
  invasionFactor = (double)rand() / RAND_MAX;

  // Convert the probability factors into percentages
  alienProb = (int)(alienFactor * 100);
  meteorProb = (int)(meteorFactor * 100);
  invasionProb = (int)(invasionFactor * 100);

  // Print the results
  printf("Alien invasion probability: %d%\n", alienProb);
  printf("Meteor strike probability: %d%\n", meteorProb);
  printf("Combined invasion probability: %d%\n", invasionProb);
  
  // Determine the overall probability of invasion
  double overallProb = alienFactor + meteorFactor + invasionFactor;
  
  if (overallProb < 1.0) {
    printf("The probability of an invasion is low.\n");
  }
  else if (overallProb >= 1.0 && overallProb < 1.5) {
    printf("The probability of an invasion is moderate.\n");
  }
  else {
    printf("The probability of an invasion is high.\n");
  }
  
  return 0;
}