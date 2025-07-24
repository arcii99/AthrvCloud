//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Welcome message
  printf("Welcome to the Alien Invasion Probability Calculator!\n");
  
  // Get user input for number of planets
  int numPlanets;
  printf("How many planets are in your sector? ");
  scanf("%d", &numPlanets);
  
  // Get user input for level of technology
  int techLevel;
  printf("On a scale of 1 to 10, what is your technology level? ");
  scanf("%d", &techLevel);
  
  // Get user input for average planet distance
  double avgDistance;
  printf("What is the average distance between planets in your sector (in light years)? ");
  scanf("%lf", &avgDistance);
  
  // Get user input for average planet population
  long long avgPopulation;
  printf("What is the average population of planets in your sector? ");
  scanf("%lld", &avgPopulation);
  
  // Calculate probability of alien invasion
  double invasionProbability = (double)numPlanets / (techLevel * avgDistance * avgPopulation);
  
  // Check if probability is below the accepted threshold
  if (invasionProbability < 0.01) {
    printf("Congratulations! Your sector has a low probability of alien invasion (%0.3f%%)\n", invasionProbability * 100);
  } else {
    printf("Warning! Your sector has a high probability of alien invasion (%0.3f%%)\n", invasionProbability * 100);
  }
  
  // Goodbye message
  printf("Thank you for using the Alien Invasion Probability Calculator. Stay vigilant!\n");
  
  return 0;
}