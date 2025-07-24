//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Romeo and Juliet
#include<stdio.h>

void findMinCoins(int coins[], int n, int V) {
    int result = 0;
    int i;
    for (i = n - 1; i >= 0; i--) {
        while (V >= coins[i]) {
            V = V - coins[i];
            result++;
        }
    }
    printf("Minimum number of coins required: %d", result);
}

int main() {
    int coins[] = {1, 5, 10, 25, 50};
    int n = sizeof(coins) / sizeof(coins[0]);
    int V = 67;
    findMinCoins(coins, n, V);
    return 0;
}