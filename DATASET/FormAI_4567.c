//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int main() {
   int i, j, count = 0;
   double probability;
   srand(time(NULL)); 

   printf("Welcome to the Alien Invasion Probability Calculator\n");
   printf("How many times would you like to run the simulation?\n");
   scanf("%d", &j);

   for (i = 0; i < j; i++) {
      int num = rand() % 100;
      if (num > 80) {
           count++;
      }
   }

   probability = (double) count / j * 100;

   printf("The probability of an alien invasion is: %.2lf%%\n", probability);

   return 0;
}