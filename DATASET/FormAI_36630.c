//FormAI DATASET v1.0 Category: Dice Roller ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int dice;
   char response;

   printf("Welcome to the Energetic Dice Roller! Press y to roll the dice: ");
   scanf("%c", &response);

   while (response == 'y' || response == 'Y') {
       srand(time(0)); 
       dice = rand() % 6 + 1;

       switch (dice) {
           case 1:
               printf("\n*********\n*       *\n*   o   *\n*       *\n*********\n");
               break;
           case 2:
               printf("\n*********\n* o     *\n*       *\n*     o *\n*********\n");
               break;
           case 3:
               printf("\n*********\n* o     *\n*   o   *\n*     o *\n*********\n");
               break;
           case 4:
               printf("\n*********\n* o   o *\n*       *\n* o   o *\n*********\n");
               break;
           case 5:
               printf("\n*********\n* o   o *\n*   o   *\n* o   o *\n*********\n");
               break;
           case 6:
               printf("\n*********\n* o   o *\n* o   o *\n* o   o *\n*********\n");
               break;
           default:
               printf("Error. Invalid number generated.");
       }

       printf("\nRoll again? Press y to roll again or any other key to exit: ");
       fflush(stdin);
       scanf("%c", &response);
   }

   printf("Thank you for using the Energetic Dice Roller!");

   return 0;
}