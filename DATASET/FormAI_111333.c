//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int i, j, count = 0;
  double probability = 0.0;

  srand(time(0));

  // Display welcome message
  printf("\n");
  printf("-----------------------------------------------------\n");
  printf("    Welcome to the Alien Invasion Probability Calculator\n");
  printf("-----------------------------------------------------\n");
  printf("\n");

  // Prompt user for number of simulations to run
  printf("How many simulations would you like to run? ");
  scanf("%d", &count);

  // Run simulations
  for (i = 1; i <= count; i++) {
    int num_aliens = rand() % 10 + 1; // Generate a random number of aliens between 1 and 10

    if (num_aliens >= 3) { // If there are 3 or more aliens, there is a risk of invasion
      int invasion_chance = rand() % 100 + 1; // Generate a random number between 1 and 100

      if (invasion_chance <= 60) { // If the toal chance of invasion is less than or equal to 60%, there is a chance of invasion
        probability++; // Increase the probability of invasion
      }
    }
  }

  // Calculate probability of invasion based on simulations
  probability = probability / count * 100;

  // Display the results
  printf("\n");
  printf("-----------------------------------------------------\n");
  printf("                 CALCULATION RESULT                   \n");
  printf("-----------------------------------------------------\n");
  printf("\n");
  printf("Based on %d simulations, the probability of an alien invasion was %.2f%%.\n", count, probability);
  printf("\n");

  return 0;
}