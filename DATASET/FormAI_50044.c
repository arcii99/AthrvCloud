//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: peaceful
#include <stdio.h>

int main()
{
    int coins[4] = {25, 10, 5, 1}; // Denominations of coins
    int amount; // Amount of change needed
    int count = 0; // Number of coins
    int i;

    printf("Enter the amount of change needed: ");
    scanf("%d", &amount);

    for(i=0; i<4; i++) // Loop through each denomination of coin
    {
        while(amount >= coins[i]) // Check if coin can be used for change
        {
            count++; // Increment number of coins used
            amount -= coins[i]; // Deduct coin value from remaining change
        }
    }

    printf("Minimum number of coins required: %d\n", count);

    return 0;
}