//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

  // Initialize random number generator
  srand(time(NULL));

  // Define probabilities
  float probability_mothership = 0.05; // Probability of a mothership appearing
  float probability_fighter = 0.2; // Probability of a fighter appearing

  // Ask user for input
  printf("Enter the number of days to simulate: ");
  int days;
  scanf("%d", &days);

  // Initialize variable for tracking total number of invasions
  int invasion_count = 0;

  // Simulate invasions for each day
  for (int i = 1; i <= days; i++) {

    // Check if a mothership appears
    float mothership_roll = (float) rand() / RAND_MAX;
    if (mothership_roll < probability_mothership) {
      printf("Day %d: Mothership has appeared!\n", i);
      invasion_count++;
    }

    // Check if a fighter appears
    float fighter_roll = (float) rand() / RAND_MAX;
    if (fighter_roll < probability_fighter) {
      printf("Day %d: Fighter has appeared!\n", i);
      invasion_count++;
    }
  }

  // Print results
  printf("\nSimulation complete.\n");
  printf("Total number of invasions: %d\n", invasion_count);

  // Return success
  return 0;
}