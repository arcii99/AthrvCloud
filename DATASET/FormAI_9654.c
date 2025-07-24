//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

   // initialize variables
   int energyShieldLevel, yearsOfExperience;
   double alienPowerFactor, probability;

   // prompt user for input
   printf("Enter your current energy shield level (1-100): ");
   scanf("%d", &energyShieldLevel);

   printf("Enter the number of years you have been defending earth: ");
   scanf("%d", &yearsOfExperience);

   // generate a random alien power factor based on years of experience
   srand(time(NULL));
   if (yearsOfExperience < 5) {
      alienPowerFactor = (double)rand()/(double)RAND_MAX * 0.6 + 0.1;
   } else if (yearsOfExperience < 10) {
      alienPowerFactor = (double)rand()/(double)RAND_MAX * 0.8 + 0.1;
   } else {
      alienPowerFactor = (double)rand()/(double)RAND_MAX * 1.0 + 0.1;
   }

   // calculate invasion probability using energy shield level and alien power factor
   probability = (100 - energyShieldLevel) * alienPowerFactor / 10;

   // display results to user
   printf("\nBased on your energy shield level and years of experience, ");
   printf("the estimated alien invasion probability is %.2f%%.\n", probability);

   return 0;
}