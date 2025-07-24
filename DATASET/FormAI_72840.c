//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: puzzling
#include<stdio.h>
#define INF 1000000000

int main()
{
    int coins[100], n, targetSum;
    int dp[1000000];
    // Infinity initialization for empty positions
    for(int i=0; i<=1000000; i++) dp[i] = INF;
    
    printf("Enter the number of coins: ");
    scanf("%d", &n);
    
    printf("Enter the denominations of coins: ");
    for (int i=0; i<n; i++) scanf("%d", &coins[i]);
 
    printf("Enter the target sum: ");
    scanf("%d", &targetSum);
    // base case
    dp[0] = 0;
    // dp with greedy approach
    for (int i = 1; i <= targetSum; i++)
    {   
        for (int j = 0; j < n; j++)
        {    
            if (coins[j] <= i)
            {
                dp[i] = (dp[i] < dp[i - coins[j]] + 1)? dp[i]: dp[i - coins[j]] + 1;
            }
        }
    }
    if(dp[targetSum]!=INF){
        printf("Minimum number of coins required to make the target sum: %d \n", dp[targetSum]);
    }
    else{
        printf("Target sum not achievable with given denominations.");
    }
    return 0;
}