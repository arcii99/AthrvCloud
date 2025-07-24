//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: grateful
#include <stdio.h>

int coinSet[] = { 1, 3, 7, 15, 25 }; // set of available coins
int numOfCoins = 5; // number of available coins

int maxChange(int amount)
{
    int i, count = 0;
    for (i = numOfCoins - 1; i >= 0; i--)
    {
        while (amount >= coinSet[i])
        {
            amount -= coinSet[i];
            count++;
        }
    }
    return count;
}

int main()
{
    int amount = 82;
    int maxCoins = maxChange(amount);
    printf("The maximum amount of change that can be made using the available coins is: %d\n", maxCoins);
    return 0;
}