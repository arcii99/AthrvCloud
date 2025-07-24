//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: standalone
#include <stdio.h>

// Define maximum number of coins in the solution
#define MAX_COINS 100

// Function to find minimum number of coins required to make a desired change
int findMinCoins(int coins[], int n, int target) {
    int change[MAX_COINS];
    int i, j, min, temp;

    // Initialize change array
    change[0] = 0;

    // Compute minimum number of coins required for each possible change
    for (i = 1; i <= target; i++) {
        min = target;
        for (j = 0; j < n; j++) {
            if (coins[j] <= i) {
                temp = change[i - coins[j]] + 1;
                if (temp < min)
                    min = temp;
            }
        }
        change[i] = min;
    }

    // Return minimum number of coins required to make the target change
    return change[target];
}

int main() {
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
    int n = sizeof(coins) / sizeof(coins[0]);
    int target = 4876;

    printf("Target change: %d\n", target);
    printf("Minimum number of coins required: %d\n", findMinCoins(coins, n, target));

    return 0;
}