//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: calm
/* This program demonstrates a Greedy Algorithm implementation in C
that finds the minimum number of coins required to make change for
a given amount of money. */

#include <stdio.h>

#define NUM_COIN_TYPES 4 // number of coin types available
#define NUM_DENOMS 3    // number of distinct denominations

int main() {
    // array of available coins in decreasing order
    int coins[NUM_COIN_TYPES] = {25, 10, 5, 1};

    int denominations[NUM_DENOMS] = {1, 5, 25}; // denominations allowed

    int num_coins[NUM_DENOMS] = {0}; // number of each coin required

    int amount; // total amount for which change is to be made

    printf("Enter the total amount for which change is to be made: ");
    scanf("%d", &amount);

    int remaining_amount = amount;

    // iterate through each coin type in array
    for (int i = 0; i < NUM_COIN_TYPES; i++) {
        // if remaining amount is greater than or equal to the coin value
        while (remaining_amount >= coins[i]) {
            remaining_amount -= coins[i];
            // increment coin count for the current coin type
            for (int j = 0; j < NUM_DENOMS; j++) {
                if (coins[i] == denominations[j]) {
                    num_coins[j]++;
                }
            }
        }
    }

    // print out the number of coins required for each denomination
    printf("Coins required:\n");
    for (int i = 0; i < NUM_DENOMS; i++) {
        printf("%d cents: %d\n", denominations[i], num_coins[i]);
    }

    return 0;
}