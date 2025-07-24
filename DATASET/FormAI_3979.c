//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

// Struct for each coin, containing its value and amount
typedef struct Coin {
    int value;
    int amount;
} Coin;

// Function to sort coins by value descending order
int compareCoins(const void *c1, const void *c2) {
    Coin *coin1 = (Coin *) c1;
    Coin *coin2 = (Coin *) c2;
    return (coin2->value - coin1->value);
}

// Function to find minimum number of coins needed to make change for a given amount
int findMinimumCoins(Coin *coins, int numCoins, int amount) {
    int numUsedCoins = 0; // Total number of coins used
    int i;

    for (i = 0; i < numCoins; i++) {
        if (amount == 0) {
            break;
        }

        if (coins[i].amount > 0 && coins[i].value <= amount) {
            int numCoinsNeeded = amount / coins[i].value; // Maximum possible number of coins that can be used
            int numCoinsUsed = (numCoinsNeeded >= coins[i].amount) ? coins[i].amount : numCoinsNeeded; // Actual number of coins used
            amount -= numCoinsUsed * coins[i].value;
            numUsedCoins += numCoinsUsed;
            coins[i].amount -= numCoinsUsed;
        }
    }

    if (amount == 0) {
        return numUsedCoins;
    } else {
        return -1; // No combination of coins exists to make change for the amount
    }
}

int main() {
    Coin coins[] = {{10, 3}, {5, 4}, {1, 10}}; // Sample coins available (10 coins of 1, 4 coins of 5, and 3 coins of 10)
    int numCoins = sizeof(coins) / sizeof(Coin);

    // Sort coins by value in descending order
    qsort(coins, numCoins, sizeof(Coin), compareCoins);

    int amount = 22; // Sample amount to make change for
    int numUsedCoins = findMinimumCoins(coins, numCoins, amount);

    if (numUsedCoins == -1) {
        printf("No combination of coins exists to make change for %d!\n", amount);
    } else {
        printf("The minimum number of coins needed to make change for %d is %d.\n", amount, numUsedCoins);
    }

    return 0;
}