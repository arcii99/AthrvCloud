//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: brave
#include <stdio.h>
#include <stdlib.h>

// Define a struct to hold the details of each coin
struct Coin {
    int value; // Value of the coin
    int count; // Number of coins of this value available
};

// Function to sort coins by value in descending order
int compareCoins(const void* a, const void* b) {
    struct Coin* coin1 = (struct Coin*)a;
    struct Coin* coin2 = (struct Coin*)b;
    return coin2->value - coin1->value;
}

// Function to calculate minimum number of coins required to make change
int minCoins(struct Coin* coins, int numCoins, int amount) {
    // Sort the coins in descending order based on value
    qsort(coins, numCoins, sizeof(struct Coin), compareCoins);

    int totalCoins = 0;
    for (int i = 0; i < numCoins && amount > 0; i++) {
        struct Coin* coin = &coins[i];
        int numSelected = amount / coin->value;
        if (numSelected > coin->count) {
            numSelected = coin->count;
        }
        amount -= numSelected * coin->value;
        totalCoins += numSelected;
    }

    // If amount is not zero after selecting coins, return -1 to indicate no solution
    if (amount > 0) {
        return -1;
    }

    return totalCoins;
}

int main() {
    // Create an array of coins with their values and counts
    struct Coin coins[4];
    coins[0].value = 25;
    coins[0].count = 2;
    coins[1].value = 10;
    coins[1].count = 1;
    coins[2].value = 5;
    coins[2].count = 3;
    coins[3].value = 1;
    coins[3].count = 10;

    // Calculate the minimum number of coins required to make change for $0.72
    int minNumCoins = minCoins(coins, 4, 72);

    // If a solution was found, print it
    if (minNumCoins >= 0) {
        printf("Minimum number of coins required: %d\n", minNumCoins);
    } else {
        printf("No solution found.\n");
    }

    return 0;
}