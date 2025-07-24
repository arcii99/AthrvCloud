//FormAI DATASET v1.0 Category: Dice Roller ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int sides, diceCount, i;
   
   printf("Enter the number of sides on the die: ");
   scanf("%d", &sides);
   
   printf("Enter the number of dice to roll: ");
   scanf("%d", &diceCount);
   
   srand(time(0));
   
   for (i = 0; i < diceCount; i++) {
      printf("Dice #%d: %d\n", i+1, (rand() % sides) + 1);
   }
   
   return 0;
}