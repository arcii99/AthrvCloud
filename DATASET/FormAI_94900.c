//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: imaginative
#include <stdio.h>

int main() {
    int coins[] = {1, 5, 10, 25}; // Available denominations of coins
    int amount = 97; // The amount of change we need to make
    int usedCoins[4] = {0}; // Array to keep track of the number of times each coin denomination is used
    
    // Greedy algorithm to determine the minimum number of coins needed
    int i;
    for (i = 3; i >= 0; i--) {
        while (amount >= coins[i]) {
            usedCoins[i]++;
            amount -= coins[i];
        }
    }
    
    // Output the result
    printf("Minimum number of coins: %d\n", usedCoins[0] + usedCoins[1] + usedCoins[2] + usedCoins[3]);
    printf("Used coins distribution: %d x $0.25 + %d x $0.10 + %d x $0.05 + %d x $0.01\n", usedCoins[3], usedCoins[2], usedCoins[1], usedCoins[0]);
    
    return 0;
}