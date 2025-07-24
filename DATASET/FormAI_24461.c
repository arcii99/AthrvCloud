//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int probability = 0;
  srand(time(NULL)); // Seed random number generator
  
  printf("Welcome to the Alien Invasion Probability Calculator! \n");

  // Calculate probability
  probability = rand() % 101; // Generate a random number from 0 to 100
  if(probability >= 0 && probability <= 25) {
    printf("The chance of an alien invasion is very low, but not impossible. Probability: %d%%\n", probability);
  } else if(probability > 25 && probability <= 50) {
    printf("The chance of an alien invasion is moderate. Probability: %d%%\n", probability);
  } else if(probability > 50 && probability <= 75) {
    printf("The chance of an alien invasion is high. Probability: %d%%\n", probability);
  } else if(probability > 75 && probability <= 100) {
    printf("The chance of an alien invasion is very high. Prepare your defenses immediately! Probability: %d%%\n", probability);
  }
  
  printf("Thank you for using the Alien Invasion Probability Calculator! \n");
  return 0;
}