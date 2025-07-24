//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: peaceful
#include <stdio.h>

int coinChange(int coins[], int n, int value)
{
    int count = 0;
    for (int i = n - 1; i >= 0 && value > 0; i--)
    {
        while (value >= coins[i])
        {
            value -= coins[i];
            count++;
        }
    }
    return count;
}

int main()
{
    int coins[] = {5, 10, 25, 50};
    int n = sizeof(coins) / sizeof(coins[0]);
    int value = 56;
    int result = coinChange(coins, n, value);
    printf("Minimum coins required for target value %d: %d\n", value, result);
    return 0;
}