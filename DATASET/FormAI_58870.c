//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: creative
#include <stdio.h>

void coinChange(int coins[], int n, int amount) {
   int i, j;
   int coinList[100] = {0};

   for(i=0; i<n; i++) {
      while(amount>=coins[i]) {
         amount -= coins[i];
         coinList[j++] = coins[i];
      }
   }

   printf("The minimum number of coins needed to make up the amount: %d\n", j);

   printf("The coins are: ");
   for(i=0; i<j; i++) {
      printf("%d ", coinList[i]);
   }
}

int main() {
   int coins[10] = {1, 2, 5, 10, 20, 50, 100, 500, 1000, 2000};
   int n = sizeof(coins)/sizeof(coins[0]);
   int amount = 93;

   coinChange(coins, n, amount);
   
   return 0;
}