//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

// function to implement Greedy algorithm for Coin Change Problem
void coinChangeGreedy(int coins[], int n, int amount) {
    if (amount == 0) {
        printf("No coins needed!");
        return;
    }
    
    int i = n - 1;
    while (i >= 0) {
        // If current coin is less than or equal to amount,
        // then use that coin and decrement the amount by coin value
        if (coins[i] <= amount) {
            printf("%d ", coins[i]);
            amount -= coins[i];
        }
        else {  // Move to the next smaller coin
            i--;
        }
    }
    return;
}

int main() {
    int coins[] = {1, 5, 10, 25};
    int n = sizeof(coins) / sizeof(coins[0]);
    
    int amount;
    printf("Enter the amount: ");
    scanf("%d", &amount);
    
    printf("Minimum number of coins required to make change for %d: ", amount);
    coinChangeGreedy(coins, n, amount);
    
    return 0;
}