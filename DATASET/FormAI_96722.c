//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Linus Torvalds
#include <stdio.h>

int main() {
  int n, i, j, k, max_p, max_c, min_c;
  int prices[] = {10, 8, 7, 6, 5};

  n = sizeof(prices) / sizeof(prices[0]);

  max_p = -1;
  for (i = 0; i < n; i++) {
    max_c = -1;
    for (j = i + 1; j < n; j++) {
      if (prices[j] > max_c) {
        max_c = prices[j];
        k = j;
      }
    }
    if (max_c - prices[i] > max_p) {
      max_p = max_c - prices[i];
      min_c = i;
    }
  }

  printf("Buy at $%d and sell at $%d for a profit of $%d\n",
         prices[min_c], prices[min_c] + max_p, max_p);

  return 0;
}