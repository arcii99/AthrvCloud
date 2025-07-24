//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

// Program to find the minimum number of coins needed to make a given sum
int main()
{
    int n; // number of coins
    printf("Enter the number of coins: ");
    scanf("%d", &n);
    
    int coins[n];
    int i;
    for (i = 0; i < n; i++) {
        printf("Enter the value of coin %d: ", i+1);
        scanf("%d", &coins[i]);
    }

    int sum;
    printf("Enter the sum: ");
    scanf("%d", &sum);
    
    int count = 0;
    for (i = n-1; i >= 0; i--) {
        while (sum >= coins[i]) {
            sum -= coins[i];
            count++;
        }
    }
    
    printf("The minimum number of coins needed to make the sum is: %d\n", count);

    return 0;
}