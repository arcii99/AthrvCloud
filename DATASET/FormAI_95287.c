//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

int greedyCoinChange(int coins[], int size, int amount);

int main() {
    int coins[] = {1, 5, 10, 25}; // US coin denominations
    int size = 4; // number of coin types
    int amount = 62; // amount to make change for

    int numCoins = greedyCoinChange(coins, size, amount);

    printf("Minimum number of coins required: %d\n", numCoins);

    return 0;
}

int greedyCoinChange(int coins[], int size, int amount) {
    int numCoins = 0;
    int i = size - 1; // start with the largest denomination

    while (amount > 0) {
        if (amount >= coins[i]) {
            amount -= coins[i];
            numCoins++;
        } else {
            i--; // move to the next smallest denomination
        }
    }

    return numCoins;
}