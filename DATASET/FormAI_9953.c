//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Sherlock Holmes
#include <stdio.h>

int main() {
  int earth_population, alien_population, invasion_probability;
  printf("Welcome to the Alien Invasion Probability Calculator.\n");
  
  // Get user input for earth population and alien population
  printf("Enter the current population of Earth: ");
  scanf("%d", &earth_population);
  printf("Enter the estimated alien population: ");
  scanf("%d", &alien_population);

  // Calculate percentage of aliens in comparison to Earth population
  double alien_percent = ((double) alien_population / earth_population) * 100;

  // Determine probability of invasion based on alien population percentage
  if (alien_percent >= 50) {
    invasion_probability = 100;
  } else if (alien_percent >= 25) {
    invasion_probability = 75;
  } else if (alien_percent >= 10) {
    invasion_probability = 50;
  } else if (alien_percent >= 5) {
    invasion_probability = 25;
  } else {
    invasion_probability = 0;
  }

  // Output invasion probability to user
  printf("\nBased on the estimated alien population of %d and the current Earth population of %d,\n", alien_population, earth_population);
  printf("the probability of an alien invasion is %d%%.\n", invasion_probability);

  return 0;
}