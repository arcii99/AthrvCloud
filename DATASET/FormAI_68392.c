//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Ken Thompson
#include <stdio.h>

int main() {

  int coins[10] = {1, 5, 10, 25, 50, 100, 500, 1000, 5000, 10000};

  int len = sizeof(coins)/sizeof(coins[0]);

  int amount;
  printf("Enter the amount: ");
  scanf("%d", &amount);

  int count = 0;

  for (int i = len - 1; i >= 0; i--) {
    while (amount >= coins[i]) {
      amount -= coins[i];
      count++;
    }
  }

  printf("The minimum number of coins needed is %d.\n", count);

  return 0;
}