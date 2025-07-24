//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: complex
#include <stdio.h>
#include <stdlib.h>

int main() {
   int n, m;
   printf("Enter the number of coins: ");
   scanf("%d", &n);
   int coins[n];
   printf("Enter the value of each coin:\n");

   for(int i=0; i<n; i++) {
      scanf("%d", &coins[i]);
   }

   printf("Enter the amount you want to make change of: ");
   scanf("%d", &m);

   int numCoins = 0;
   int result[n];
   int i = n-1;

   while(i >= 0) {
      while(m >= coins[i]) {
         m -= coins[i];
         result[numCoins] = coins[i];
         numCoins++;
      }
      i--;
   }

   printf("The minimum number of coins needed to make change of %d is: %d \n", m, numCoins);
   printf("The coins needed are: ");

   for(int i=0; i<numCoins; i++) {
      printf("%d ", result[i]);
   }

   return 0;
}