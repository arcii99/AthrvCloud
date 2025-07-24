//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Dennis Ritchie
#include <stdio.h>

int main () {
   int coins[] = {25, 10, 5, 1}; // Coin denominations
   int numCoins[] = {0, 0, 0, 0}; // Number of coins for each denomination
   int change = 68; // Amount of change to make

   // Loop through each coin denomination
   for (int i = 0; i < 4; i++) {
      int coinCount = change / coins[i]; // Get number of coins for current denomination
      numCoins[i] = coinCount; // Add coin count to array
      change = change - (coinCount * coins[i]); // Subtract coin value from change remaining
   }

   // Print out the number of each coin needed
   printf("Number of quarters: %d\n", numCoins[0]);
   printf("Number of dimes: %d\n", numCoins[1]);
   printf("Number of nickels: %d\n", numCoins[2]);
   printf("Number of pennies: %d\n", numCoins[3]);

   return 0;
}