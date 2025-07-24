//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: expert-level
#include <stdio.h>

#define MAX_COINS 10 // Maximum number of coins that we can use

void printCoins(int coins[], int n)
{
    printf("Coins used: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", coins[i]);
    }
    printf("\n");
}

void findCoins(int denomination[], int n, int amount)
{
    int usedCoins[MAX_COINS]; // Array to hold the coins used
    int i = n - 1; // Index of the highest denomination

    while (amount > 0 && i >= 0) {
        if (denomination[i] <= amount) {
            amount -= denomination[i]; // Deduct the denomination from the amount
            usedCoins[i] = denomination[i]; // Add the denomination to the usedCoins array
        } else {
            i--; // Move to the next lower denomination
        }
    }

    if (amount == 0) {
        printf("Minimum number of coins required: %d\n", n - i - 1);
        printCoins(&usedCoins[i + 1], n - i - 1);
    } else {
        printf("Cannot find coins for the given amount.\n");
    }
}

int main()
{
    int denomination[] = {1, 2, 5, 10, 20, 50, 100, 200}; // Array of available coin denominations
    int n = sizeof(denomination) / sizeof(denomination[0]); // Size of the denomination array
    int amount = 347;

    printf("Available coin denominations: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", denomination[i]);
    }
    printf("\n");

    printf("Amount to be paid: %d\n", amount);

    findCoins(denomination, n, amount);

    return 0;
}