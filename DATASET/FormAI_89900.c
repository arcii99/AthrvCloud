//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Claude Shannon
#include <stdio.h>

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int minCoins(int coins[], int n, int value) {
    int count = 0;
    while (value > 0) {
        int maxCoin = 0;
        for (int i = 0; i < n; i++) {
            if (coins[i] <= value) {
                maxCoin = coins[i];
            } else {
                break;
            }
        }
        value -= maxCoin;
        count++;
    }
    return count;
}

int main() {
    int coins[] = {1, 5, 10, 25};
    int n = sizeof(coins) / sizeof(coins[0]);
    int value = 73;
    printf("Coins used: ");
    printArray(coins, n);
    printf("Value to make change for: %d\n", value);
    printf("Minimum number of coins needed: %d\n", minCoins(coins, n, value));
    return 0;
}