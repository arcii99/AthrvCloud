//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: automated
#include <stdio.h>

//Greedy algorithm to find the minimum number of coins needed to make change

int main()
{
    int coins[] = {25, 10, 5, 1}; //quarters, dimes, nickels, pennies 
    int n = sizeof(coins)/sizeof(coins[0]); //number of coin denominations
    int change, count = 0;
    
    printf("Enter the amount of change needed (in cents): ");
    scanf("%d", &change);
    
    for(int i=0; i<n; i++){
        while(change >= coins[i]){
            change -= coins[i];
            count++;
        }
    }
    
    printf("Minimum number of coins needed: %d", count);
    
    return 0;
}