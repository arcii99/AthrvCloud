//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: surrealist
#include<stdio.h>
#include<limits.h>

// Function to find the minimum number of coins needed to make change
int findMinimumCoins(int coins[], int n, int amount)
{
    int i, count = 0, remAmount;
    // Traverse through all denomination coins
    for(i=n-1; i>=0; i--)
    {
        // Find the number of coins needed for the current denomination coins[i]
        count += amount/coins[i];
        remAmount = amount % coins[i];
        amount = remAmount;
    }
    return count;
}

int main()
{
    int coins[] = {1, 5, 10, 25};
    int n = sizeof(coins)/sizeof(coins[0]);
    int amount = 67;
    printf("Minimum number of coins needed to make change for amount %d is %d", amount, findMinimumCoins(coins, n, amount));
    return 0;
}