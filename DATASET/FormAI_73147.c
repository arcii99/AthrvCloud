//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int alien_ships = 0;
  double alien_prob = 0.0;
  int human_population = 0;
  int num_years = 0;
  double invasion_prob = 0.0;
  
  // Taking Input from User
  printf("Enter the estimated number of alien ships: ");
  scanf("%d", &alien_ships);

  printf("Enter the probability of each ship invading (0.0 - 1.0): ");
  scanf("%lf", &alien_prob);

  printf("Enter the estimated human population: ");
  scanf("%d", &human_population);

  printf("Enter the number of years to calculate invasion probability: ");
  scanf("%d", &num_years);

  // Alien Invasion Probability Calculator
  double temp_prob = 1.0 - alien_prob;
  double temp_population = (double) human_population;
  invasion_prob = 1.0 - pow(temp_prob * (1.0 - (1.0/ temp_population)), (double) (alien_ships * num_years));

  // Generating Random Number
  srand(time(NULL));
  int random_num = rand() % 101;

  // Displaying Result
  printf("\n\nAlien Invasion Probability: %f\n", invasion_prob);

  if (random_num < (int) (invasion_prob * 100)) {
    printf("\n\nYou are doomed. The aliens are coming!!!");
  } else {
    printf("\n\nPhew! You are safe... for now.");
  }

  return 0;
}