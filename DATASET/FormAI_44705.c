//FormAI DATASET v1.0 Category: Dice Roller ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   printf("Welcome to the Dice Roller!\n");
   srand(time(NULL));  // Seed the random number generator with the current time
   char choice;

   do {
      int diceType, numDice, rollSum = 0;
      printf("\nEnter the type of dice you want to roll (4, 6, 8, 10, 12, or 20): ");
      scanf("%d", &diceType);

      printf("Enter the number of dice you want to roll: ");
      scanf("%d", &numDice);

      printf("Your rolls are: ");
      for (int i = 0; i < numDice; i++) {
         int roll = rand() % diceType + 1;  // Roll the dice
         rollSum += roll;  // Keep track of the total sum of rolls
         printf("%d ", roll);
      }
      printf("\nTotal roll sum: %d\n", rollSum);

      printf("Do you want to roll again? (y/n): ");
      scanf(" %c", &choice);
   } while (choice == 'y' || choice == 'Y');

   printf("Thanks for using the Dice Roller!\n");
   return 0;
}