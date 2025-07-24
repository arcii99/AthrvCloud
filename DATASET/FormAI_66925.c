//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: introspective
#include <stdio.h>

int main() {
  int amount, coins_used = 0, coin_count[3] = {0}; // Array to store number of each coin type used
  scanf("%d", &amount); // Get input amount from user
  int coin_types[] = {10, 5, 1}; // Array of coin types
  for (int i = 0; i < 3; i++) { // Iterate through each coin type
    while (amount >= coin_types[i]) { // While the amount is greater than current coin type
      amount -= coin_types[i]; // Subtract the coin type from the amount
      coin_count[i]++; // Increment the count of the current coin type used
      coins_used++; // Increment the total count of coins used
    }
  }
  printf("Minimum number of coins required: %d\n", coins_used);
  printf("Number of 10 cent coins used: %d\n", coin_count[0]);
  printf("Number of 5 cent coins used: %d\n", coin_count[1]);
  printf("Number of 1 cent coins used: %d\n", coin_count[2]);
  return 0;
}