//FormAI DATASET v1.0 Category: Dice Roller ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   
   int num_rolls, dice_sides, roll_num;
   int total = 0;
    
   srand(time(0)); // Seed the random number generator
   
   printf("Welcome to the Dice Roller Program!\n");
    
   // Prompt user for number of rolls and dice sides
   printf("How many times would you like to roll the dice? ");
   scanf("%d", &num_rolls);
   printf("How many sides does each dice have? ");
   scanf("%d", &dice_sides);
    
   printf("\nRolling the dice %d times...\n", num_rolls);
    
   // Roll the dice and add up the total score
   for (roll_num = 1; roll_num <= num_rolls; roll_num++) {
       int roll = rand() % dice_sides + 1;
       printf("Roll %d: %d\n", roll_num, roll);
       total += roll;
   }
    
   printf("\nTotal score: %d\n", total);
    
   return 0;
}