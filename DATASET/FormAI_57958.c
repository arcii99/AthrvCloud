//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: future-proof
#include <stdio.h>

#define MAX_N 50

int main() {

  int n, m, coins[MAX_N];
  
  printf("Enter the number of coins: ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    printf("Enter the denomination of coin %d: ", i + 1);
    scanf("%d", &coins[i]);
  }

  printf("Enter the amount to be paid: ");
  scanf("%d", &m);

  int ans = 0;
  for (int i = n - 1; i >= 0 && m > 0; i--) {
    int x = m / coins[i];
    ans += x;
    m -= x * coins[i];
  }

  if (m != 0) {
    printf("Sorry, exact amount cannot be paid.");
  } else {
    printf("The minimum number of coins required is: %d", ans);
  }

  return 0;
}