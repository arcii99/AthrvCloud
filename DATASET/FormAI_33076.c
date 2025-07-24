//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: ephemeral
#include <stdio.h>

/* This function implements the Greedy Algorithm approach to find the minimum number of coins needed to make a given amount of money. */

int greedy_algo(int coins[], int n, int amount) 
{
    int count = 0, i;
    for (i = 0; i < n; i++) {
        while (amount >= coins[i]) {
            amount -= coins[i];
            count++;
        }
    }
    return count;
}

int main(void) 
{
    int coins[] = {1, 5, 10, 25};  /* Array of coins available */
    int n = sizeof(coins)/sizeof(coins[0]);  /* Length of the array */
    int amount = 50;  /* Amount of money we want to make */
    int min_coins = greedy_algo(coins, n, amount);

    /* Print the minimum number of coins needed */
    printf("Minimum number of coins needed to make $%d is %d\n", amount, min_coins);

    return 0;
}