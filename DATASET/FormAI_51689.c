//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int prob;
   int maxProb = 100; // The maximum probability percentage
   int minProb = 0; // The minimum probability percentage
   char answer;

   srand(time(NULL)); // Sets the time as seed for random numbers

   printf("Welcome to the Alien Invasion Probability Calculator.\n\n");

   printf("How many UFO sightings have been reported in your area in the last year? ");
   int numSightings;
   scanf("%d", &numSightings);

   printf("Thanks for that information.\n");

   if (numSightings >= 10) {
      prob = maxProb;
      printf("Due to the high number of UFO sightings in your area, the probability of an alien invasion is %d%%.\n", prob);
   }
   else if (numSightings > 0) {
      prob = numSightings * 10;
      printf("Based on the number of UFO sightings in your area, the probability of an alien invasion is %d%%.\n", prob);
   }
   else {
      prob = minProb;
      printf("Since there were no UFO sightings in your area, the probability of an alien invasion is %d%%.\n", prob);
   }

   printf("\nDo you want to know how the probability was calculated? (Y/N) ");
   scanf(" %c", &answer);

   if (answer == 'Y' || answer == 'y') {
      printf("\nThe probability was calculated based on the number of UFO sightings in your area. If there were 10 or more sightings, the probability of an alien invasion is 100%%. Otherwise, the probability is 10%% times the number of sightings. If there were no sightings, the probability is 0%%.\n");
   }

   printf("\nThank you for using the Alien Invasion Probability Calculator. Stay safe!\n");

   return 0;
}