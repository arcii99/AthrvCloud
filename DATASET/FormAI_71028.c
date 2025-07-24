//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Ken Thompson
#include <stdio.h> 

// function to implement the greedy algorithm 
int coinChange(int coins[], int n, int amount) 
{ 
    int count = 0; 

    // loop through all the coins 
    for (int i = 0; i < n; i++) { 
        while (coins[i] <= amount) { 
            amount -= coins[i]; 
            count++; 
        } 
    } 

    return count; 
} 

// main function 
int main() 
{ 
    int coins[] = { 1, 5, 10, 25 };  // coins available 
    int n = sizeof(coins) / sizeof(coins[0]);   // total no. of coins 
    int amount = 46;   // amount to be paid 

    printf("Minimum no. of coins required to pay %d cents: %d\n", amount, coinChange(coins, n, amount)); 

    return 0; 
}