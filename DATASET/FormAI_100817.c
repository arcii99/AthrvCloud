//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of coins for this example
#define MAX_COINS 100

// Define the coin values for this example
int coin_values[6] = {1, 5, 10, 25, 50, 100};

// Define the struct for holding the results
struct result {
    int total_coins;
    int coins[MAX_COINS];
};

// Define the function to compute the optimal set of coins
struct result compute_optimal(int value) {
    struct result res;
    res.total_coins = 0;
    int remaining_value = value;
    int i = sizeof(coin_values)/sizeof(int) - 1;
    while (i >= 0) {
        if (remaining_value >= coin_values[i]) {
            res.coins[res.total_coins] = coin_values[i];
            res.total_coins += 1;
            remaining_value -= coin_values[i];
        } else {
            i -= 1;
        }
    }
    return res;
}

int main() {
    // Define the value for which to compute the optimal set of coins
    int value = 75;
    // Compute the optimal set of coins
    struct result res = compute_optimal(value);
    // Output the result
    printf("The optimal set of coins for value %d is:\n", value);
    for (int i = 0; i < res.total_coins; i++) {
        printf("%d ", res.coins[i]);
    }
    printf("\n");
    return 0;
}