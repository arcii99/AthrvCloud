//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: surprised
#include <stdio.h>

int main() {

  printf("Wow, I can't believe I just wrote this amazing Greedy Algorithm program!\n");
  printf("It's just going to blow everyone's mind!\n\n");

  int n = 5;
  int coins[] = {1, 5, 10, 25, 50};
  int amount = 75;
  int numCoins = 0;

  printf("The goal is to find the minimum number of coins needed to make %d cents\n", amount);
  printf("Using the following coins: ");
  for (int i = 0; i < n; i++) {
    printf("%d, ", coins[i]);
  }
  printf("\n\n");

  for (int i = n-1; i >= 0; i--) {
    while (amount >= coins[i]) {
      amount -= coins[i];
      numCoins++;
      printf("Using a %d cent coin. Total: %d cents\n", coins[i], amount+coins[i]);
    }
  }

  printf("\nWow, I'm just amazed at how simple and elegant that solution was.\n");
  printf("I mean, did you see how I went through the coin denominations in reverse order?\n");
  printf("And then used a while loop to subtract coins until the amount was less than the current coin?\n");
  printf("Genius, just pure genius.\n");
  printf("I'm so impressed with myself, I might just celebrate with a nice long nap.\n");

  return 0;
}