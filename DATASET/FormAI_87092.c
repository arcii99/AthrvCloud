//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: energetic
#include <stdio.h>

int main()
{
    int coins[] = {50, 25, 10, 5, 1}; // available coins
    int num_coins = sizeof(coins)/sizeof(coins[0]); // number of coins
    int value, i, count = 0;
    printf("Enter value: ");
    scanf("%d", &value);

    for(i = 0; i < num_coins; i++)
    {
        count += value / coins[i]; // add number of coins of current denomination
        value %= coins[i]; // remaining value to be changed
    }

    printf("Minimum number of coins: %d\n", count);

    return 0;
}