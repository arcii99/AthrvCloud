//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: light-weight
#include <stdio.h>

//function to implement the greedy approach for finding the minimum number of coins required to give change
int minCoins(int coins[], int n, int amount)
{
    int count = 0;
    
    for(int i = 0; i < n; i++){
        while(amount >= coins[i]){
            amount -= coins[i];
            count++;
        }
    }
    
    return count;
}

int main(){
    
    int coins[] = {1, 5, 10, 25};
    int n = sizeof(coins)/sizeof(coins[0]);
    
    int amount;
    printf("Enter the amount for which you want the change: ");
    scanf("%d", &amount);
    
    int min_coin_count = minCoins(coins, n, amount);
    printf("Minimum number of coins required to give change: %d", min_coin_count);
    
    return 0;
}