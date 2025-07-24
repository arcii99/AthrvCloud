//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // Initialize random seed
  int invasionProbability = rand() % 101; // Generate a random number from 0 to 100
  
  printf("Welcome to the Alien Invasion Probability Calculator!\n");
  printf("Based on our calculations, there is a %d%% chance of an alien invasion.\n", invasionProbability);
  
  if (invasionProbability == 0) {
    printf("Well, it looks like we're safe for now.\n");
  } else if (invasionProbability > 0 && invasionProbability <= 25) {
    printf("It's unlikely, but we should still prepare just in case.\n");
  } else if (invasionProbability > 25 && invasionProbability <= 50) {
    printf("Things are looking ominous. We need to start preparing for an attack.\n");
  } else if (invasionProbability > 50 && invasionProbability <= 75) {
    printf("This is getting serious. We need to evacuate major cities and set up a defensive perimeter.\n");
  } else {
    printf("This is not a drill. An alien invasion is imminent. We need to mobilize all available resources and fight for our survival!\n");
  }
  
  return 0;
}