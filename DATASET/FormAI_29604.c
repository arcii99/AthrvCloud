//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Ada Lovelace
#include <stdio.h>

int main() {
    int coins[] = {25, 10, 5, 1};
    int numCoins = sizeof(coins) / sizeof(coins[0]);
    int usedCoins[numCoins];
    int amount;
    int i;

    printf("Enter amount: ");
    scanf("%d", &amount);

    for (i = 0; i < numCoins; i++) {
        usedCoins[i] = 0;
    }

    while (amount > 0) {
        for (i = 0; i < numCoins; i++) {
            if (coins[i] <= amount) {
                amount -= coins[i];
                usedCoins[i]++;
                break;
            }
        }
    }

    printf("Coins used:\n");
    for (i = 0; i < numCoins; i++) {
        printf("%d: %d\n", coins[i], usedCoins[i]);
    }

    return 0;
}