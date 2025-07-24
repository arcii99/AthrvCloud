//FormAI DATASET v1.0 Category: Dice Roller ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int main() {
   int numOfDice, numOfSides, i;
   int minDiceVal, maxDiceVal, rollTotal;
   srand(time(0)); // Seed the random number generator

   printf("Enter the number of dice to roll: ");
   scanf("%d", &numOfDice);

   printf("Enter the number of sides on the dice: ");
   scanf("%d", &numOfSides);

   minDiceVal = 1 * numOfDice;
   maxDiceVal = numOfSides * numOfDice;

   printf("\nRolling %d D%d:\n", numOfDice, numOfSides);

   for (i = 1; i <= numOfDice; i++) {
      int roll = rand() % numOfSides + 1;
      printf("%d\n", roll);
      rollTotal += roll;
   }

   printf("\nTotal Roll Value: %d \n", rollTotal);
   printf("Minimum Roll Value: %d\n", minDiceVal);
   printf("Maximum Roll Value: %d\n", maxDiceVal);
   return 0;
}