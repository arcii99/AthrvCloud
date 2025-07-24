//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Alien Invasion Probability Calculator */

int main(void) {
  srand(time(NULL)); // Set seed for random number generator

  int population, defense_budget, alien_technology;
  float invasion_prob;

  printf("Welcome to the Alien Invasion Probability Calculator!\n\n");

  // Get input from user
  printf("Enter the population of your city/town: ");
  scanf("%d", &population);
  printf("Enter your city/town's defense budget: ");
  scanf("%d", &defense_budget);
  printf("Enter your city/town's level of alien technology (0-100): ");
  scanf("%d", &alien_technology);

  // Generate a random number between 0 and 99 to represent alien threat level
  int alien_threat = rand() % 100;

  // Calculate invasion probability
  invasion_prob = (alien_threat + (100 - alien_technology)) / (float)population;

  // Print results
  printf("\nBased on your inputs, the probability of an alien invasion is: %.2f%%\n\n", invasion_prob * 100);

  // Determine if defense budget is sufficient
  if (defense_budget >= population * 1000) {
    printf("Your defense budget is sufficient to repel the alien invasion. Good luck!\n");
  } else {
    printf("Your defense budget is not sufficient to repel the alien invasion. You may want to consider increasing it.\n");
  }

  return 0;
}