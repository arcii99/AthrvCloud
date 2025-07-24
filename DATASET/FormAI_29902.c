//FormAI DATASET v1.0 Category: Dice Roller ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {

   int num, sides, rolls, i, j;
   char ans;
   
   printf("Welcome to the mind-bending dice roller program!\n\n");
   printf("How many sides are on your die? ");
   scanf("%d", &sides);
   printf("\nHow many rolls would you like to make? ");
   scanf("%d", &rolls);
   
   printf("\nAre you ready? (y/n)\n\n");
   scanf(" %c", &ans);
   
   if (ans == 'y' || ans == 'Y') {
       printf("\nRolling the dice...\n");
       srand(time(NULL)); //Seed the random number generator
       for (i = 0; i < rolls; i++) {
           num = rand() % sides + 1; //Generate a random number between 1 and the number of dice sides
           printf("\nRoll %d: %d", i+1, num);
           for (j = 0; j < num; j++) {
               printf("*");
           }
       }
   } else {
       printf("\nOkay, come back soon!");
   }
   
   printf("\n\nThanks for using the mind-bending dice roller program!\n");
   return 0;
}