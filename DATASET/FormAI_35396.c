//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// The main function
int main() {
  int population_density, government_involvement, proximity_to_ufos;
  float invasion_probability;

  // Seed the random number generator
  srand(time(0));

  // Get input from the user
  printf("Enter population density (people per square km): ");
  scanf("%d", &population_density);
  printf("Enter government involvement level (1-10): ");
  scanf("%d", &government_involvement);
  printf("Enter proximity to known UFO sightings (km): ");
  scanf("%d", &proximity_to_ufos);

  // Calculate the invasion probability
  invasion_probability = (float)population_density * ((float)government_involvement / 10.0) / ((float)proximity_to_ufos + 1.0);
  invasion_probability = (100.0 * invasion_probability) + ((float)rand() / (RAND_MAX / 10.0));

  // Output the result
  printf("Your chance of surviving an alien invasion is %.2f%%!\n", 100.0 - invasion_probability);

  return 0;
}