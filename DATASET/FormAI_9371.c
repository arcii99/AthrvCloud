//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: mind-bending
#include <stdio.h>

// function to find the minimum number of coins needed to make change
void findCoins(int V[], int n, int amount)
{
    int i, j, coins[n], count = 0;

    // loop through the different types of coins in descending order
    for(i = n - 1; i >= 0; i--)
    {
        // calculate the maximum number of coins of this type that can be used
        j = amount / V[i];

        // add this number of coins to the total count
        count += j;

        // save the number of coins for this type
        coins[i] = j;

        // adjust the amount left to make change for
        amount -= j * V[i];
    }

    // display the result
    printf("Minimum number of coins needed to make change: %d\n", count);

    printf("Breakdown of coins:\n");

    for(i = n - 1; i >= 0; i--)
    {
        printf("%d x %d = %d\n", V[i], coins[i], V[i] * coins[i]);
    }
}

int main()
{
    int V[] = {25, 10, 5, 1}; // types of coins available
    int n = 4; // number of types of coins
    int amount = 67; // amount to make change for

    findCoins(V, n, amount);

    return 0;
}