//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: creative
#include <stdio.h>

int main() {
   int coins[] = {1, 5, 10, 25, 50}; // array of coin values
   int n = sizeof(coins)/sizeof(coins[0]); // size of array
   int amount, count = 0, i;

   printf("Enter the amount to be paid (in cents): ");
   scanf("%d", &amount);

   printf("Coins used to pay %d cents:\n", amount); 

   for (i = n - 1; i >= 0; i--) { // looping through the coins array in reverse order
      while (amount >= coins[i]) { // check if the current coin value can be used
         amount -= coins[i];
         count++; // increment the count of coins used
         printf("%d ", coins[i]); // print the current coin value
      }
   }

   printf("\nTotal number of coins used: %d\n", count); // print total coins used
   return 0;
}