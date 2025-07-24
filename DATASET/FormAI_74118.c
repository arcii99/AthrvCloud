//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: intelligent
#include <stdio.h>

int main() {
    int coins[4] = {25, 10, 5, 1}; // types of coins available
    int amount, numCoins = 0;

    printf("Enter amount in cents: ");
    scanf("%d", &amount);

    for(int i = 0; i < 4; i++) {
        while(amount >= coins[i]) {
            amount -= coins[i];
            numCoins++;
            printf("Used a %d cent coin\n", coins[i]);
        }
    }

    printf("Minimum number of coins: %d\n", numCoins);

    return 0;
}