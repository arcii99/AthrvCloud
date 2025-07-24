//FormAI DATASET v1.0 Category: Dice Roller ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int numRolls, numDice, i, j, total = 0;
   printf("How many dice would you like to roll? ");
   scanf("%d", &numDice);
   printf("How many times would you like to roll the dice? ");
   scanf("%d", &numRolls);
   printf("\nRolling %d dice %d times...\n", numDice, numRolls);
   srand(time(NULL));
   for (i = 0; i < numRolls; i++) {
      printf("\nRoll %d: ", (i + 1));
      int rollSum = 0;
      for (j = 0; j < numDice; j++) {
         int roll = rand() % 6 + 1;
         printf("%d ", roll);
         rollSum += roll;
      }
      printf("- Sum: %d", rollSum);
      total += rollSum;
   }
   printf("\n\nTotal rolls: %d", total);
   return 0;
}