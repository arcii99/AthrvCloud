//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: real-life
#include <stdio.h>

int main() {
   int denominations[5] = {1, 5, 10, 25, 50};
   int amount;
   printf("Enter the amount: ");
   scanf("%d", &amount);
   int coins[5] = {0, 0, 0, 0, 0};
   int i = 4; 
   while (amount > 0) {
      if (amount >= denominations[i]) {
         amount -= denominations[i];
         coins[i]++;
      }
      else {
         i--;
      }
   }

   printf("You will need:\n");
   printf("%d pennies;\n", coins[0]);
   printf("%d nickels;\n", coins[1]);
   printf("%d dimes;\n", coins[2]);
   printf("%d quarters;\n", coins[3]);
   printf("%d half-dollars.\n", coins[4]);

   return 0;
}