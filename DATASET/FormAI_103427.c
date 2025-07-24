//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: unmistakable
#include <stdio.h>

// Function to perform greedy algorithm for coin change problem
void coinChange(int denomination[], int n, int amount)
{
    int coinsUsed[n]; // stores the minimum number of coins required to make up the ith amount
    int sum = 0; // initialized to 0
    int i;
    
    // Traverse the denomination array and calculate the minimum number of coins required for each amount
    for (i = 0; i < n; i++)
    {
        while (sum + denomination[i] <= amount) // Keep adding the denomination[i] until we reach the amount
        {
            sum += denomination[i];
            coinsUsed[i]++; // Increment the number of coins used for the denominations used
        }
    }
    
    // Print out the minimum number of coins for each amount
    printf("\nMinimum number of coins for each amount:\n");
    for (i = 0; i < n; i++)
    {
        printf("$%d: %d coins\n", denomination[i], coinsUsed[i]);
    }
}

int main()
{
    int denomination[] = {1, 5, 10, 25}; // denominations of coins available
    int n = sizeof(denomination)/sizeof(denomination[0]); // number of different denominations
    int amount; // amount for which we need to make change
    
    printf("Enter the amount for which you want to make the change: ");
    scanf("%d", &amount);
    
    coinChange(denomination, n, amount);
    
    return 0;
}