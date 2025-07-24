//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
   int daysUntilInvasion = (rand() % 30) + 1;
   double alienTechnologyLevel = (double)(rand() % 1000) / 1000;
   double probabilityOfSurvival = ((double)daysUntilInvasion * alienTechnologyLevel) / 100;
   char* advice;

   if(probabilityOfSurvival < 20.0) {
      advice = "You are doomed! Hide under your bed and pray for mercy!";
   }
   else if(probabilityOfSurvival < 50.0) {
      advice = "It's not looking good. Stock up on supplies and prepare for the worst.";
   }
   else if(probabilityOfSurvival < 80.0) {
      advice = "You might have a chance. Create a plan and stick to it.";
   }
   else {
      advice = "You are a survivor! Congratulations, your civilization will live on.";
   }

   printf("Days until invasion: %d\nAlien technology level: %.3lf\nProbability of survival: %.2lf%%\nAdvice: %s\n", daysUntilInvasion, alienTechnologyLevel, probabilityOfSurvival, advice);

   return 0;
}