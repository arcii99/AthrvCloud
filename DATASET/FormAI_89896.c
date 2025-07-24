//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: imaginative
#include <stdio.h>

int main()
{
    const int coins[] = {1, 5, 10, 25}; // available coins
    const int num_coins = 4; // number of available coins
    int change, num_coins_used = 0;
    
    printf("Enter the amount of change: ");
    scanf("%d", &change);
    
    for (int i = num_coins - 1; i >= 0; i--)
    {
        while (change >= coins[i])
        {
            change -= coins[i];
            num_coins_used++;
        }
    }
    
    printf("The minimum number of coins needed is %d\n", num_coins_used);
    
    return 0;
}