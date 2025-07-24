//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: mathematical
#include <stdio.h>

int main() {
    int coins[5] = {1, 5, 10, 25, 50}; // values of available coins
    int amount, numCoins = 0, i = 4; // i starts from the highest value coin
    
    printf("Enter the amount of change: ");
    scanf("%d", &amount);
    
    while (amount > 0) {
        if (amount >= coins[i]) {
            amount -= coins[i]; // subtract the highest value coin
            numCoins++; // increment the count of coins used
        } else {
            i--; // check the next lower value coin
        }
    }
    
    printf("Minimum number of coins required: %d\n", numCoins);
    
    return 0;
}