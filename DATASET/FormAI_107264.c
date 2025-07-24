//FormAI DATASET v1.0 Category: Dice Roller ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
   int dice[6] = {1,2,3,4,5,6};
   char choice, enter;
   int roll;
   
   srand(time(0)); // Initiate seed
   
   printf("Welcome to the Dice Roller program!\n\n");

   do {
      printf("Press ENTER to roll the dice.\n");
      scanf("%c",&enter);
      
      roll = rand() % 6; // Generate random number between 0 and 5
      
      printf("You rolled a %d!\n\n", dice[roll]);
      
      printf("Would you like to roll again? (Y/N)\n");
      scanf("%s", &choice);
      
      while (getchar() != '\n'); // Clear input buffer
      
   } while (choice == 'Y' || choice == 'y');

   printf("Thank you for using the Dice Roller program!\n\n");

   return 0;
}