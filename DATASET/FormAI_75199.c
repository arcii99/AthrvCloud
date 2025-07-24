//FormAI DATASET v1.0 Category: Dice Roller ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
   srand(time(NULL)); // Seed the random number generator with the current time

   int numRolls, numDice, numSides;
   printf("Enter the number of dice to roll: ");
   scanf("%d", &numDice);
   printf("Enter the number of sides on the dice: ");
   scanf("%d", &numSides);
   printf("Enter the number of times to roll the dice: ");
   scanf("%d", &numRolls);

   printf("Rolling %d %d-sided dice %d times:\n", numDice, numSides, numRolls);

   int total = 0;
   for (int i = 0; i < numRolls; i++)
   {
      int roll = 0;
      for (int j = 0; j < numDice; j++)
      {
         roll += rand() % numSides + 1;
      }
      printf("%d\n", roll);
      total += roll;
   }

   printf("Total: %d\n", total);

   return 0;
}