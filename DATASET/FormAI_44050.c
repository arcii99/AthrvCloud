//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: surprised
#include<stdio.h>

int main()
{
    int amount, totalCoins = 0;
    int coins[] = {10, 5, 2, 1}; // Available coins in decreasing order

    printf("Enter the amount for which you need to provide change:\n");
    scanf("%d", &amount);

    for(int i = 0; i < 4; i++)
    {
        totalCoins += amount / coins[i]; // Number of coins of ith denomination
        amount %= coins[i]; // Remaining amount after using ith denomination coins

        if(amount == 0) // If exact change is provided, breakout
            break;
    }

    printf("Minimum number of coins required to provide change is: %d\n", totalCoins);

    return 0;
}