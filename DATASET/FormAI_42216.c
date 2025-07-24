//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: rigorous
#include <stdio.h>

//Function to find the minimum coins required for the given amount
int minCoins(int coins[], int n, int amount)
{
    //Declare variables
    int result = 0;
    int i = 0;

    //Loop through all the coins from largest to smallest
    for (i = 0; i < n; i++)
    {
        //If the current coin is smaller than or equal to the given amount
        while (coins[i] <= amount)
        {
            //Add 1 to the result counter
            result++;
            //Reduce the amount by the current coin value
            amount -= coins[i];
        }
    }

    //Return the result
    return result;
}

int main()
{
    //Declare variables
    int coins[] = { 1, 5, 10, 25 }; //Coin denominations
    int n = sizeof(coins) / sizeof(coins[0]); //Number of denominations
    int amount = 37; //Amount to calculate

    //Calculate the minimum coins required for the given amount
    int min = minCoins(coins, n, amount);

    //Print the result
    printf("Minimum coins required to make change for %d cents: %d\n", amount, min);

    //Exit program
    return 0;
}