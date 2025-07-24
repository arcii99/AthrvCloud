//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(0)); // Seed random number generator
  
  int invasion = 0;
  int probes = 0;
  double probability = 0;
  
  printf("Welcome to the Alien Invasion Probability Calculator!\n\n");
  
  // Get user input
  printf("How many alien probes have been detected in the last year? ");
  scanf("%d", &probes);
  
  // Calculate probability
  probability = (double)probes / RAND_MAX;
  
  // Simulate alien invasion
  if (probability >= 0.5) {
    printf("\nWarning: High probability of alien invasion!\n");
    
    // Roll the dice
    invasion = rand() % 2;
    
    if (invasion == 1) {
      printf("\nAlien invasion confirmed! Earth is doomed!\n");
    } else {
      printf("\nFalse alarm! No alien invasion detected.\n");
    }
  } else {
    printf("\nNo immediate threat of alien invasion.\n");
  }
  
  return 0;
}