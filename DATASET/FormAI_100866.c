//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: portable
#include <stdio.h>

int main(void) {
  int coins[] = {1, 5, 10, 25}; // coin denominations
  int n = sizeof(coins)/sizeof(coins[0]); // length of coins array
  int total_value = 82; // total value to make change for

  // initialize counts array to track number of each coin used
  int counts[n];
  for (int i = 0; i < n; i++) {
    counts[i] = 0;
  }

  // loop through array of coin denominations 
  for (int i = n - 1; i >= 0; i--) {
    // while the total value is still greater than or equal to the current coin denomination
    while (total_value >= coins[i]) {
      counts[i]++; // increment count for current coin
      total_value -= coins[i]; // subtract value of coin from total value
    }
  }

  // print results
  printf("The minimum number of coins to make change for $%d is:\n", total_value);
  for (int i = 0; i < n; i++) {
    printf("%d %s of $%d\n", counts[i], (counts[i] == 1 ? "coin" : "coins"), coins[i]/100);
  }

  return 0;
}