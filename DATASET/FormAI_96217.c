//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   // Seed random number generator
   srand(time(NULL));
   
   // Initialize variables
   float probability;
   int alien_spaceships;
   
   // Prompt user for number of alien spaceships
   printf("How many alien spaceships do you think will invade Earth?\n");
   scanf("%d", &alien_spaceships);
   
   // Calculate probability of invasion based on number of spaceships
   if (alien_spaceships == 0) {
      probability = 0.0;
   }
   else if (alien_spaceships <= 10) {
      probability = 0.05;
   }
   else if (alien_spaceships <= 50) {
      probability = 0.25;
   }
   else if (alien_spaceships <= 100) {
      probability = 0.50;
   }
   else {
      probability = 0.90;
   }
   
   // Generate random number to determine if invasion will occur
   float invasion_chance = (float) rand() / RAND_MAX;
   
   // Determine if invasion will occur
   if (invasion_chance <= probability) {
      printf("Alien invasion detected!\n");
   }
   else {
      printf("No alien invasion detected.\n");
   }
   
   return 0;
}