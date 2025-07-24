//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: futuristic
#include <stdio.h>

int minCoins(int coins[], int n, int amount) {
    int count = 0;
    for (int i = n - 1; i >= 0; i--) {
        while (amount >= coins[i]) {
            amount -= coins[i];
            count++;
        }
    }
    return count;
}

int main() {
    int coins[] = {50, 25, 10, 5, 1};
    int n = sizeof(coins) / sizeof(coins[0]);

    int amount;
    printf("Enter amount: ");
    scanf("%d", &amount);

    int min_coins = minCoins(coins, n, amount);
    printf("Minimum coins required = %d\n", min_coins);

    return 0;
}