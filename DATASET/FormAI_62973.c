//FormAI DATASET v1.0 Category: Dice Roller ; Style: Donald Knuth
// Donald Knuth inspired C Dice Roller program

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int num_dice_sides, num_dice_rolls, i, j, roll_result; // Variables declaration
   
   srand(time(NULL)); // Seed random number generator with current time
   
   printf("Enter the number of sides on the dice: ");
   scanf("%d", &num_dice_sides); // Accept input for number of sides on the dice 
   
   printf("Enter the number of rolls: ");
   scanf("%d", &num_dice_rolls); // Accept input for number of rolls
   
   printf("Rolling %d %d-sided dice:\n", num_dice_rolls, num_dice_sides);
   
   for (i = 0; i < num_dice_rolls; i++) { // Loop for rolling the dice
      printf("Roll %d: [ ", i+1);
      for (j = 0; j < num_dice_sides; j++) { // Loop for displaying individual values of the dice
         roll_result = rand() % num_dice_sides + 1;
         printf("%d ", roll_result);
      }
      printf("]\n");
   }
   
   return 0;
}