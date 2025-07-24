//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: lively
#include <stdio.h>

int main() {
    int n, i, j, amount;
    printf("Enter the number of coins: ");
    scanf("%d", &n);
    int coins[n];
    
    for(i = 0; i < n; i++) {
        printf("Enter coin %d value: ", i+1);
        scanf("%d", &coins[i]);
    }

    printf("Enter the amount of change: ");
    scanf("%d", &amount);

    int numCoins[n], totalCoins = 0;
    for(i = 0; i < n; i++) {
        numCoins[i] = amount / coins[i];
        amount -= numCoins[i] * coins[i];
        totalCoins += numCoins[i];
    }

    if(amount > 0) {
        printf("Cannot give exact change.\n");
    } else {
        printf("Minimum number of coins: %d\n", totalCoins);
        for(i=0; i<n; i++) {
            printf("%d coins of %d value.\n", numCoins[i], coins[i]);
        }
    }
    return 0;
}