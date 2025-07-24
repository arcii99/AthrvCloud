//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: peaceful
#include <stdio.h>

/* Program to calculate the minimum number of coins required to make change for a given amount */

int main()
{
    /* Initializing the variables */
    int amount, coin_num = 0;
    int denom[6] = {1, 5, 10, 25, 50, 100};
    int coins[6] = {0};
    /* We will go through the denominations in reverse order */
    for (int i = 5; i >= 0; i--)
    {
        /* If the denomination is less than the amount remaining */
        while(amount >= denom[i])
        {
            /* Subtract the denomination from the amount remaining */
            amount -= denom[i];
            /* Add one coin of the denomination used */
            coins[i]++;
            /* Increment the total number of coins used */
            coin_num++;
        }
    }
    /* Printing the coins used */
    printf("Coins used: ");
    for (int i = 5; i >= 0; i--)
    {
        printf("%d %ds", coins[i], denom[i]);
        if (i != 0)
            printf(", ");
    }
    printf("\nNumber of coins used: %d\n", coin_num);
    return 0;
}