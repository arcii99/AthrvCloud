//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: excited
#include <stdio.h>

int main() {
  int coins[] = {25, 10, 5, 1};
  int num_coins = sizeof(coins) / sizeof(coins[0]);
  int change = 99;
  int num_used_coins[num_coins];

  for (int i = 0; i < num_coins; i++) {
    num_used_coins[i] = 0;
  }

  for (int i = 0; i < num_coins; i++) {
    while (change >= coins[i]) {
      change -= coins[i];
      num_used_coins[i]++;
    }
  }

  printf("Change breakdown:\n");
  for (int i = 0; i < num_coins; i++) {
    printf("%d: %d\n", coins[i], num_used_coins[i]);
  }

  return 0;
}