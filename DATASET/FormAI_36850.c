//FormAI DATASET v1.0 Category: Dice Roller ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
   int i, n;
   int roll;
   srand(time(0)); // Set random seed using time of day
   printf("Enter the number of dice rolls: ");
   scanf("%d", &n); // Get input from user
   for( i = 0 ; i < n ; i++ ) {
      roll = (rand() % 6) + 1; // Generate random number between 1-6
      printf("Roll %d: %d\n", i+1, roll); // Print result
   }
   return 0;
}