//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: post-apocalyptic
#include <stdio.h>

int main()
{
  int coins[] = {1, 5, 10, 25};
  int amount = 99;
  int num_coins = 0;
  
  for(int i = 3; i >= 0 && amount > 0; i--) {
    while(amount >= coins[i]) {
      num_coins++;
      amount -= coins[i];
    }
  }
  
  printf("Minimum number of coins needed: %d\n", num_coins);
  
  return 0;
}