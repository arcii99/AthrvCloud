//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: random
#include <stdio.h>

int main()
{
    int n, m;
    printf("Enter the number of coins and target value: ");
    scanf("%d %d", &n, &m);
    
    int coins[n], i;
    printf("Enter the values of coins: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &coins[i]);
    }
    
    int count = 0, j;
    printf("Coin selected: ");
    for(i = n-1; i >= 0; i--)
    {
        while(m >= coins[i])
        {
            m = m - coins[i];
            count++;
            printf("%d ", coins[i]);
        }
    }
    printf("\nMinimum number of coins required: %d", count);
    
    return 0;
}