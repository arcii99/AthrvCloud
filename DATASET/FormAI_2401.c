//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   srand(time(NULL));
   int numDays, numCities, numCountries, probCount = 0, total = 0;
   double aliensPerCity, invasionProb, totalProb;
   printf("Welcome to the Alien Invasion Probability Calculator!\n\n");
   printf("Enter the total number of days in which the alien invasion could occur:\n");
   scanf("%d", &numDays);
   printf("Enter the total number of cities in the world:\n");
   scanf("%d", &numCities);
   printf("Enter the total number of countries in the world:\n");
   scanf("%d", &numCountries);
   printf("Enter the estimated number of aliens per city that would participate in the invasion:\n");
   scanf("%lf", &aliensPerCity);
   printf("\nCalculating invasion probability...\n\n");
   for (int i = 0; i < numDays; i++) {
      for (int j = 0; j < numCities; j++) {
         for (int k = 0; k < numCountries; k++) {
            if (rand() % 100 < aliensPerCity) {
               probCount++;
            }
            total++;
         }
      }
   }
   invasionProb = (double) probCount / (double) total;
   totalProb = 1 - pow(1 - invasionProb, numDays);
   printf("The probability of an alien invasion in the next %d days is %.5f%%.\n", numDays, totalProb * 100);
   return 0;
}