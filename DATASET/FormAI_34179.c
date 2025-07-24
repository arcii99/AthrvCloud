//FormAI DATASET v1.0 Category: Dice Roller ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int dice1, dice2, totalPoints, rollCount;
   char choice;
   srand(time(NULL));
   printf("Welcome to the Dice Roller Game!\n");

   do {
      totalPoints = 0;
      rollCount = 0;
      printf("\nPress enter to roll your dice!\n");
      getchar();

      do {
         dice1 = rand() % 6 + 1;
         dice2 = rand() % 6 + 1;
         totalPoints += dice1 + dice2;
         printf("\nRoll %d: %d + %d = %d\n", ++rollCount, dice1, dice2, totalPoints);
         if (totalPoints == 7) {
            printf("\nYou rolled a 7! Sorry, you lose :(\n");
            break;
         }
         if (totalPoints == 12) {
            printf("\nYou rolled a 12! Congratulations, you win :D\n");
            break;
         }
      } while (totalPoints < 7 || totalPoints > 12);

      printf("\nWould you like to play again? (y/n): ");
      scanf(" %c", &choice);
   } while (choice == 'y' || choice == 'Y');

}