//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: shocked
#include<stdio.h>

int main() {

  int coins[] = {25, 10, 5, 1};    // coins available
  int num_coins = 4;               // number of coins
  int total_change = 67;           // total change required
  int i, count = 0;

  printf("Minimum number of coins needed to make change: ");

  for(i = 0; i < num_coins; i++) {
    while(total_change >= coins[i]) {    // check if the coin can be used
      total_change -= coins[i];           // subtract coin value from total
      count++;                            // increment coin count
      printf("%d ", coins[i]);            // print the coin value
    }
  }

  printf("\nTotal number of coins needed: %d\n", count);    // print total coins used

  return 0;
}