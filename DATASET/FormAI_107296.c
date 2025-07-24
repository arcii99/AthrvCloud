//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Donald Knuth
// Here's a sample implementation of a greedy algorithm that finds the minimum number of coins to make a given amount of change.

#include <stdio.h>

int main() {
    int n = 18; // amount of change we want to make
    int coins[] = {1, 5, 10, 25}; // available coin denominations
    int num_coins = sizeof(coins) / sizeof(coins[0]); // number of different coin denominations
    int count = 0; // counter for number of coins used

    // start with the highest denomination coin and work downwards
    for (int i = num_coins - 1; i >= 0; i--) {
        while (coins[i] <= n) { // keep using the current denomination until it no longer fits
            n -= coins[i];
            count++;
        }
    }

    printf("The minimum number of coins to make %d cents is %d.\n", n, count);
    return 0;
}