//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: excited
#include <stdio.h>

/* A program to find the minimum number of coins needed to give a certain amount of change */

int main(void) {

  printf("Welcome to the Coin Exchange!\n\n");

  int coin_values[] = {25, 10, 5, 1};   // Array of each coin's value
  int num_coins[4] = {0};               // Array to store the number of each coin needed
  int total_change;                     // User-entered amount of change to give
  int i;                                // Index variable for loops
  int current_value;                    // Current coin value being used
  int coins_used = 0;                   // To track total number of coins used

  printf("Please enter the amount of change to give (in cents): ");
  scanf("%d", &total_change);

  printf("\nCalculating the best way to give %d cents in change...\n\n", total_change);

  for (i = 0; i < 4; i++) {

    current_value = coin_values[i];    // Starting with the highest coin value

    while (total_change >= current_value) {
      total_change -= current_value;   // Subtract the value of the coin from the remaining change
      num_coins[i]++;                  // Increment the number of this coin used
      coins_used++;                    // Increment total number of coins used
    }
  }

  printf("The best way to give %d cents in change is:\n", total_change);

  for (i = 0; i < 4; i++) {
    if (num_coins[i] > 0) {
      printf("\t%d x %d cent coin(s)\n", num_coins[i], coin_values[i]);
    }
  }

  printf("\nThis requires a total of %d coins.\n", coins_used);

  printf("\nThank you for using the Coin Exchange!");

  return 0;
}