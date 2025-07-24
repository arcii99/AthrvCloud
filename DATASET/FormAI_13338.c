//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: portable
#include <stdio.h>

int main() {
   int num;
   int coins[] = {1, 5, 10, 25, 50};
   int coin_counts[5] = {0, 0, 0, 0, 0};
   int i, count = 0;

   printf("Enter the amount to be converted: ");
   scanf("%d", &num);

   for (i = 4; i >= 0; i--) {
      while (num >= coins[i]) {
         num -= coins[i];
         coin_counts[i]++;
         count++;
      }
   }

   printf("The minimum number of coins needed is: %d\n", count);
   printf("Coin breakdown:\n");
   printf("Pennies: %d\n", coin_counts[0]);
   printf("Nickels: %d\n", coin_counts[1]);
   printf("Dimes: %d\n", coin_counts[2]);
   printf("Quarters: %d\n", coin_counts[3]);
   printf("Half-dollars: %d\n", coin_counts[4]);

   return 0;
}