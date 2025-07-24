//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: complete
#include <stdio.h>
#include <stdlib.h>

int greedy(int *coins, int n, int amount, int *selected_coins);

int main()
{
    int coins[] = {1, 5, 10, 25, 50}; // array of coins available
    int n = sizeof(coins) / sizeof(coins[0]); // size of array
    int amount = 57; // amount to be paid
    int selected_coins[n]; // array to store selected coins and their count

    int min_num_of_coins = greedy(coins, n, amount, selected_coins);

    printf("Minimum number of coins required to pay %d cents is: %d\n", amount, min_num_of_coins);

    printf("Selected coins and their count: \n");
    for (int i = 0; i < n; i++)
    {
        if (selected_coins[i] != 0)
        {
            printf("%d cents coins: %d\n", coins[i], selected_coins[i]);
        }
    }

    return 0;
}

int greedy(int *coins, int n, int amount, int *selected_coins)
{
    int count = 0; // variable to store total number of coins used

    for (int i = n - 1; i >= 0; i--) // loop through coins array in reverse order
    {
        while (amount >= coins[i]) // while amount to be paid is greater than or equal to current coin
        {
            amount -= coins[i]; // subtract current coin from total amount
            selected_coins[i]++; // increase count of current coin
            count++; // increase total count of coins used
        }
    }

    return count; // return total count of coins used
}