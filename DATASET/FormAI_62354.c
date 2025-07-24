//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: complex
#include <stdio.h>

int main() {
   int coins[4] = {25, 10, 5, 1};
   
   int change, count = 0, i = 0;
   printf("Enter the amount of change in cents: ");
   scanf("%d", &change);
   
   while(change > 0) {
      if(change >= coins[i]) {
         count++;
         change -= coins[i];
      } else {
         i++;
      }
   }
   
   printf("Total number of coins: %d", count);

   return 0;
}