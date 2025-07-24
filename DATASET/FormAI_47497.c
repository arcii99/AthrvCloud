//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: accurate
#include <stdio.h>

int coins[] = {25, 10, 5, 1}; // available coins
int numCoins = sizeof(coins)/sizeof(int); // number of coins available

int makeChange(int amount) // function to make change
{
    int count = 0;
    int i;

    for(i=0; i<numCoins; i++) // iterate over coins in descending order
    {
        while(amount >= coins[i]) // if coin value is smaller than amount
        {
            count++; // increment count
            amount -= coins[i]; // subtract coin value from amount
        }
    }

    return count; // return number of coins used
}

int main()
{
    int amount;
    printf("Enter the amount (in cents) for which you want to make change: ");
    scanf("%d", &amount); // read amount from user

    printf("You need at least %d coins to make change for %d cents.\n", makeChange(amount), amount); // print result

    return 0;
}