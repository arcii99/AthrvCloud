//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: automated
#include <stdio.h>

int main() {
    int coins[] = {25, 10, 5, 1};
    int numCoins = sizeof(coins) / sizeof(int);
    int amount, i, count = 0;

    // Prompt user for input
    printf("Enter an amount in cents: ");
    scanf("%d", &amount);

    // Determine which coins to use
    for (i = 0; i < numCoins; i++) {
        while (amount >= coins[i]) {
            amount -= coins[i];
            count++;
        }
    }

    // Output results
    printf("The minimum number of coins needed is: %d\n", count);

    return 0;
}