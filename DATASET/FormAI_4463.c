//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

// Greedy algorithm to find the minimum number of coins needed to make a given sum

int main()
{
    int coins[] = {1, 2, 5, 10, 20, 50, 100};
    int n = sizeof(coins)/sizeof(coins[0]);
    
    int sum;
    printf("Enter a sum to be paid: ");
    scanf("%d", &sum);
    
    int coin_count[n];
    for(int i = 0; i < n; i++)
        coin_count[i] = 0;
    
    // greedy approach
    int i = n-1;
    while(sum > 0 && i >= 0){
        if(coins[i] <= sum){
            sum -= coins[i];
            coin_count[i]++;
        }
        else{
            i--;
        }
    }
    
    // print results
    if(sum == 0){
        printf("Coins needed to pay the sum: ");
        for(int i = n-1; i >= 0; i--){
            if(coin_count[i] > 0){
                printf("%dx%d ", coins[i], coin_count[i]);
            }
        }
    }
    else{
        printf("Cannot pay the given sum with the available coins.");
    }
    
    return 0;
}