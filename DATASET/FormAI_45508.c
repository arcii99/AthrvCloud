//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int invasionProbability;
   srand ( time(NULL) ); // seeding random number generator
   
   // randomly generate a number between 1 to 10 for invasion probability percentage 
   invasionProbability = rand() % 10 + 1; 
   
   printf("Welcome to the Alien Invasion Probability Calculator!\n");
   printf("Based on top-secret classified information, we predict that there is a %d0%% chance of an alien invasion.\n", invasionProbability);
   
   if(invasionProbability >= 7) {
      printf("Oh no! The probability of an alien invasion is high. Please take necessary precautions and alert the authorities.\n");
   } else {
      printf("Phew! The probability of an alien invasion is low. No need to panic (yet).\n");
   }
   
   return 0;
}