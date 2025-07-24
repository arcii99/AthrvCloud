//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int num_of_alien_ships;
   double chance_of_invasion;
   
   srand(time(NULL)); // seed the random number generator with current time
   
   printf("Welcome to the Alien Invasion Probability Calculator!\n\n");
   
   printf("Enter the number of alien ships detected: ");
   scanf("%d", &num_of_alien_ships);
   
   if (num_of_alien_ships <= 0) {
      printf("\nError: Invalid input. Please enter a positive integer.\n");
      return 0;
   }
   
   chance_of_invasion = ((double)rand() / (double)RAND_MAX) * 100; // generate a random probability of invasion between 0 and 100
   
   printf("\nCalculating...\n\n");
   
   printf("Based on the number of alien ships detected, there is a %.2f%% chance of an invasion.\n", chance_of_invasion);
   
   if (chance_of_invasion <= 50) {
      printf("This is a relatively low probability of invasion. It might be a false alarm.\n");
   } else if (chance_of_invasion > 50 && chance_of_invasion <= 80) {
      printf("This is a moderate probability of invasion. Exercise caution and prepare for potential hostilities.\n");
   } else {
      printf("This is a high probability of invasion. Evacuate immediately and seek shelter.\n");
   }
   
   return 0;
}