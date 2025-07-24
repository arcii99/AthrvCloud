//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int prob = 0; // initialize probability variable
   srand(time(NULL)); // seed random number generator with current time
   
   printf("Welcome to the Alien Invasion Probability Calculator!\n");
   printf("Please answer the following questions to calculate the likelihood of an alien invasion.\n\n");

   // ask user for inputs and calculate probability
   printf("What is the population of Earth (in billions)? ");
   int pop = 0;
   scanf("%d", &pop);
   prob += (pop * 10); // population has a direct impact on probability
   
   printf("Have there been any recent sightings of unidentified flying objects (UFOs)? (0 = No, 1 = Yes): ");
   int ufo = 0;
   scanf("%d", &ufo);
   if (ufo == 1) {
      prob += 20; // recent UFO sightings increase probability
   }
   
   printf("Do humans possess the technology to detect or communicate with alien life forms? (0 = No, 1 = Yes): ");
   int tech = 0;
   scanf("%d", &tech);
   if (tech == 1) {
      prob -= 10; // advanced technology decreases probability
   }
   
   printf("On a scale of 1 to 10, how likely do you believe an alien invasion is to occur? ");
   int belief = 0;
   scanf("%d", &belief);
   prob += (belief * 5); // individual belief has a moderate impact on probability
   
   // print out final probability and likelihood of invasion
   printf("\n\nCalculating probability...\n");
   sleep(3); // wait for 3 seconds to simulate calculation time
   printf("The likelihood of an alien invasion is %d%%.\n", prob);
   if (prob >= 50) {
      printf("Based on the inputs given, an alien invasion is considered highly probable.\n");
   } else {
      printf("Based on the inputs given, an alien invasion is considered unlikely at this time.\n");
   }
   
   return 0;
}