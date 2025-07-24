//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: automated
#include <stdio.h>

#define MAX_N 100

// Greedy algorithm to find the minimum number of coins needed to make change for a given amount
int find_minimum_coins(int coins[], int n, int amount)
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        while (amount >= coins[i])
        {
            amount -= coins[i];
            count++;
        }
    }

    return count;
}

int main(void)
{
    int coins[] = {1, 5, 10, 25};
    int n = 4;
    int amount;

    printf("Enter an amount in cents: ");
    scanf("%d", &amount);

    printf("Minimum number of coins needed to make change: %d\n", find_minimum_coins(coins, n, amount));

    return 0;
}