//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: retro
#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of coins: ");
    scanf("%d", &n);

    int coins[n];
    printf("Enter the denominations of coins: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }

    int amount;
    printf("Enter the amount: ");
    scanf("%d", &amount);

    int change = 0;
    printf("Coins used: ");

    // Using Greedy Algorithm to find change
    for (int i = n - 1; i >= 0; i--) {
        while (amount - coins[i] >= 0) {
            amount -= coins[i];
            change++;
            printf("%d ", coins[i]);
        }
    }

    printf("\nTotal number of coins used: %d\n", change);

    return 0;
}