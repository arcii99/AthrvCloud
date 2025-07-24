//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: synchronous
#include <stdio.h>

int main() {
  int num_coins;
  scanf("%d", &num_coins);

  int coins[num_coins];
  for (int i = 0; i < num_coins; i++) {
    scanf("%d", &coins[i]);
  }

  int target;
  scanf("%d", &target);

  int *change = (int *)malloc(sizeof(int) * target);

  for (int i = 0; i < target; i++) {
    change[i] = -1;
  }
  change[0] = 0;

  for (int i = 1; i <= target; i++) {
    int min_coins = -1;

    for (int j = 0; j < num_coins; j++) {

      if (coins[j] <= i) {
        int num_needed = 1 + change[i - coins[j]];

        if (min_coins == -1 || num_needed < min_coins) {
          min_coins = num_needed;
        }
      }
    }

    change[i] = min_coins;
  }

  printf("Minimum number of coins required: %d\n", change[target]);

  return 0;
}