//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: immersive
#include <stdio.h>

int main() {
  float alien_population, alien_ships, earth_population, earth_technology, earth_nuclear_weapons;
  float invasion_probability;

  // Get input from the user
  printf("Enter the number of alien populations: ");
  scanf("%f", &alien_population);

  printf("Enter the number of alien ships: ");
  scanf("%f", &alien_ships);

  printf("Enter the number of Earth's population: ");
  scanf("%f", &earth_population);

  printf("Enter Earth's level of technology (1-10): ");
  scanf("%f", &earth_technology);

  printf("Enter the number of nuclear weapons on Earth: ");
  scanf("%f", &earth_nuclear_weapons);

  // Calculate the probability of invasion
  invasion_probability = (alien_population * alien_ships) / (earth_population * earth_technology * earth_nuclear_weapons);

  // Print the result
  printf("The probability of an alien invasion is %f.\n", invasion_probability);

  return 0;
}