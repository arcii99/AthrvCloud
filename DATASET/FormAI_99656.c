//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
   //Seed the random number generator
   srand(time(NULL));

   //Declare and initialize variables
   int numPlanets = 0;
   double meanHabitability = 0.0;

   //Get the number of planets to calculate for
   printf("How many planets would you like to calculate the invasion probability for?\n");
   scanf("%d", &numPlanets);

   //Get the mean habitability of the planets
   printf("What is the mean habitability of the planets (a number between 0 and 1)?\n");
   scanf("%lf", &meanHabitability);

   //Calculate the invasion probability for each planet and print it out
   for(int i=1; i<=numPlanets; i++){
      double invasionProbability = (double) rand()/RAND_MAX;
      invasionProbability *= (1 - meanHabitability);
      invasionProbability = 1 - invasionProbability;
      printf("The invasion probability for planet %d is %f\n", i, invasionProbability);
   }
   
   return 0;
}