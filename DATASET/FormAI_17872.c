//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   srand(time(NULL)); // initialize random seed
   
   printf("Welcome to the Alien Invasion Probability Calculator!\n\n");
   
   // get input from user
   printf("Enter the number of planets in our galaxy: ");
   int numPlanets;
   scanf("%d", &numPlanets);
   printf("Enter the number of planets capable of supporting life: ");
   int numLifePlanets;
   scanf("%d", &numLifePlanets);
   
   // calculate probability of alien invasion
   double probability = (double)numLifePlanets / numPlanets;
   probability *= ((double)rand() / RAND_MAX);
   probability *= 100; // convert to percentage
   
   // print results
   printf("\nBased on our calculations, there is a %f%% chance of an alien invasion.\n", probability);
   printf("Please take necessary precautions to defend our planet.\n\n");
   
   return 0;
}