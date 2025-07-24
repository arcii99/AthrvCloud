//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: peaceful
#include <stdio.h>

int main() {
   int amount, coinCount = 0;
   int coins[5] = {50, 25, 10, 5, 1};
   int i;

   printf("Please enter a dollar amount: $");
   scanf("%d", &amount);

   for(i = 0; i < 5; i++) {
      while(amount >= coins[i]) {
         coinCount++;
         amount -= coins[i];
      }
   }

   printf("You need %d coins to make $%.2f\n", coinCount, (float) coinCount / 100);

   return 0;
}