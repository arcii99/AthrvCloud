//FormAI DATASET v1.0 Category: Dice Roller ; Style: funny
// Welcome to the most amazing dice roller program!

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

   int dice, sides, i, roll;
   char answer;
   
   printf("Welcome to the awesome dice roller program! \n");
   printf("Do you want to roll the dice ? (y/n): ");
   
   scanf(" %c", &answer);
   
   if (answer == 'y' || answer == 'Y') {
   
       printf("Great! Let's start. \n");
       printf("Enter the number of sides you want to roll: ");
       scanf("%d", &sides);
       printf("Enter the number of dice you want to roll: ");
       scanf("%d", &dice);
       printf("Alright, let's roll %d dice with %d sides each! \n", dice, sides);
   
       srand(time(NULL));
   
       for (i = 1; i <= dice; i++) {
           roll = rand() % sides + 1;
   
           printf("Dice %d: %d \n", i, roll);
       }
   }
   
   else if (answer == 'n' || answer == 'N') {
   
       printf("Alright, bye bye then! \n");
   }
   
   else {
   
       printf("That is not a valid answer. Try again another time. \n");
   }
   
   return 0;
}