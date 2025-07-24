//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: shape shifting
#include <stdio.h>

int main() {
  int amount, totalCoins = 0;
  int denominations[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
  
  printf("Enter amount (in paisa): ");
  scanf("%d", &amount);
  
  int n = sizeof(denominations) / sizeof(denominations[0]);
  
  for (int i = n - 1; i >= 0; i--) {
    while (amount >= denominations[i]) {
      amount -= denominations[i];
      totalCoins++;
    }
  }
  
  printf("Minimum coins required: %d", totalCoins);
  
  return 0;
}