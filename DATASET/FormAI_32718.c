//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int iterations, aliens, invasion_prob;
  // Ask for user input
  printf("Welcome to the Alien Invasion Probability Calculator!\n");
  printf("How many times would you like to run the simulation? ");
  scanf("%d", &iterations);
  printf("\nHow many aliens are you predicting will invade? ");
  scanf("%d", &aliens);

  srand(time(NULL)); // Set seed for random numbers
  
  // Run simulation for given number of iterations
  for (int i = 0; i < iterations; i++) {
    int random_num = rand() % 101; // Generate a random number between 0 and 100
    if (random_num <= aliens) {
      invasion_prob++; // Increment invasion probability if the random number is less than or equal to the number of predicted aliens
    }
  }

  // Print out results
  printf("\nOut of %d simulations, the probability of an alien invasion with %d aliens is %d%%", iterations, aliens, invasion_prob/iterations*100);

  return 0;
}