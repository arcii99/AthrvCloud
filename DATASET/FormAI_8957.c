//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Dennis Ritchie
/*
 * Greedy algorithm for coin change problem
 * Written in the style of Dennis Ritchie
 */

#include <stdio.h>

int coins[] = { 25, 10, 5, 1 };
int nCoins = 4;

int makeChange(int amount);

int main() {
    int amount = 73;
    int nCoins = makeChange(amount);
    
    printf("Number of coins required to make %d cents is %d\n", amount, nCoins);
    
    return 0;
}

int makeChange(int amount) {
    int count = 0;
    int i;
    for (i = 0; i < nCoins; i++) {
        while (amount >= coins[i]) {
            amount -= coins[i];
            count++;
        }
    }
    return count;
}