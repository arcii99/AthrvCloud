//FormAI DATASET v1.0 Category: Dice Roller ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int sides, rolls, i, roll;
   char response;

   // Seed the random number generator
   srand(time(NULL));

   printf("Welcome to the Dice Roller!\n");
   printf("===========================\n");

   do {
      // Prompt user for dice sides
      printf("Enter the number of sides for your dice: ");
      scanf("%d", &sides);

      // Prompt user for number of rolls
      printf("Enter the number of rolls: ");
      scanf("%d", &rolls);

      printf("\n");

      // Roll the dice the specified number of times
      for (i = 1; i <= rolls; i++) {
         roll = rand() % sides + 1;
         printf("Roll %d: %d\n", i, roll);
      }

      // Prompt user to roll again
      printf("\n");
      printf("Roll again? (y/n): ");
      scanf(" %c", &response);
   } while (response == 'y' || response == 'Y');

   printf("\n");
   printf("Thanks for using the Dice Roller!\n");

   return 0;
}