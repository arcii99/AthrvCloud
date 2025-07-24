//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: artistic
#include <stdio.h>

/* This program demonstrates the greedy algorithm for the
 * change-making problem - to find the minimum number of coins
 * needed to make up a given amount of money */

int main(void)
{
    /* Input the amount to be made up */
    int amount;
    printf("Enter the amount to be made up: ");
    scanf("%d", &amount);

    /* Define the denominations of coins */
    int denominations[] = {1, 2, 5, 10, 20, 50, 100};

    /* Define the array to hold the number of coins used */
    int num_coins[sizeof(denominations)/sizeof(denominations[0])] = {0};

    /* Define the variable to hold the remaining amount */
    int remaining_amount = amount;

    /* Loop through the denominations and use the largest possible 
     * denomination to make up the remaining amount */
    for (int i = sizeof(denominations)/sizeof(denominations[0])-1; i >= 0; i--)
    {
        if (remaining_amount >= denominations[i])
        {
            num_coins[i] = remaining_amount / denominations[i];
            remaining_amount %= denominations[i];
        }
    }

    /* Print the results */
    printf("Amount: %d\n", amount);
    printf("Coins used:\n");
    for (int i = sizeof(denominations)/sizeof(denominations[0])-1; i >= 0; i--)
    {
        if (num_coins[i] > 0)
        {
            printf("%d x %d\n", num_coins[i], denominations[i]);
        }
    }

    return 0;
}