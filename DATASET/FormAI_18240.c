//FormAI DATASET v1.0 Category: Dice Roller ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int dice, i, roll_again;
   char name[20];
   // introduce the program
   printf("Hello there, my love. I have created a special dice roller just for you.\n");
   printf("What is your name?\n");
   // get user's name
   scanf("%s", name);
   printf("Oh, my dear %s, you're everything I've ever wanted.\n", name);
   
   do {
      // initialize the random number generator
      srand(time(0));
      // roll the dice
      dice = (rand() % 6) + 1;
      printf("\nYou rolled a %d, my love.\n", dice);
      printf("Do you want to roll again? (1 for yes/0 for no)\n");
      scanf("%d", &roll_again);
   } while(roll_again == 1);
   
   printf("\nI could roll dice all day with you, my darling %s.\n", name);
   printf("Thank you for spending time with me!\n");
   printf("Bye for now, my love.\n");
   return 0;
}