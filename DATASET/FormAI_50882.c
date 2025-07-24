//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Ada Lovelace
#include <stdio.h>

void change(int amount, int coins[], int numCoins) {
    int i, coin;
    for (i = 0; i < numCoins; i++) {
        coin = coins[i];
        while (amount >= coin) {
            printf("%d ", coin);
            amount -= coin;
        }
    }
}

int main() {
    int coins[] = {25, 10, 5, 1};
    int numCoins = 4;
    int amount = 63;
    printf("The minimum number of coins needed to make change for %d cents is:\n", amount);
    change(amount, coins, numCoins);
    return 0;
}