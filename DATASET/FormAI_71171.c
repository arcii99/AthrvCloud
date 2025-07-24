//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: intelligent
#include <stdio.h>

int main() {
  // initialize the number of coins and their values
  int num_coins = 5;
  int coins[] = {1, 5, 10, 25, 50};

  // initialize the amount of change to make
  int target = 78;

  // initialize variables for the algorithm
  int num_needed = 0;
  int total_amount = 0;

  // loop through all the coins, starting with the largest
  for (int i = num_coins - 1; i >= 0; i--) {
    // calculate the number of coins needed for this denomination
    int current_num_needed = (target - total_amount) / coins[i];

    // update the total number of coins needed
    num_needed += current_num_needed;

    // update the total amount of change so far
    total_amount += current_num_needed * coins[i];
  }

  // print out the result
  printf("Number of coins needed: %d\n", num_needed);

  return 0;
}