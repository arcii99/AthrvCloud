//FormAI DATASET v1.0 Category: Dice Roller ; Style: systematic
/* C program to simulate a dice roller */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int i, dice_roll, num_of_rolls;
   
   // seed the random number generator
   srand((unsigned)time(NULL));
   
   printf("Enter the number of times you want to roll the dice: ");
   scanf("%d", &num_of_rolls);
   printf("\n");
   
   // roll the dice
   for(i = 1; i <= num_of_rolls; i++) {
      dice_roll = rand() % 6 + 1; // generate a random number between 1 and 6
      printf("Roll %d: %d\n", i, dice_roll);
   }
   
   return 0;
}