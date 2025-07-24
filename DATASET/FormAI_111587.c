//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int chance = 0; // chance of alien invasion
   int numYears = 0; // number of years being analyzed
   int currYear = 2021; // current year

   srand(time(NULL)); // seed random number generator

   printf("Welcome to the Alien Invasion Probability Calculator\n\n");

   printf("Please enter the number of years you'd like to analyze: ");
   scanf("%d", &numYears);

   printf("\nAnalyzing probability of alien invasion over the next %d years...\n", numYears);
   printf("Year   | Probability of Invasion\n");
   printf("--------------------------------\n");

   for (int i = 0; i < numYears; i++) {
      chance = rand() % 101; // generate random number between 0-100 for chance of invasion
      printf("%d     | %d%%\n", currYear++, chance);
   }

   printf("\nAnalysis complete. Stay vigilant!\n");

   return 0;
}