//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: peaceful
#include <stdio.h>

int main()
{
    int coins[] = { 25, 10, 5, 1 };  // available denominations
    int amount, numCoins = 0;
    int i;
    
    printf("Enter the amount of change: ");
    scanf("%d", &amount);
    
    for (i = 0; i < 4; i++) {
        while (amount >= coins[i]) {
            amount -= coins[i];  // subtract the largest possible denomination
            numCoins++;  // add one coin of that denomination
        }
    }
    
    printf("Minimum number of coins needed: %d\n", numCoins);
    
    return 0;
}