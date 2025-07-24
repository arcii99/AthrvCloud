//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: ultraprecise
#include <stdio.h>

// Function to sort the coins in descending order of their denominations
void sortCoins(int coins[], int n) {
    int i, j, temp;
    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if(coins[i] < coins[j]) {
                temp = coins[i];
                coins[i] = coins[j];
                coins[j] = temp;
            }
        }
    }
}

// Function to calculate minimum number of coins required to make a given amount
int minCoins(int coins[], int n, int amount) {
    int count = 0;
    sortCoins(coins, n);
    for(int i = 0; i < n; i++) {
        while(amount >= coins[i]) {
            amount -= coins[i];
            count++;
        }
    }
    return count;
}

// Sample program to test the "minCoins" function
int main() {
    int coins[] = {10, 5, 2, 1};   // denominations of coins
    int n = 4;                     // number of coins
    int amount = 27;               // amount to be paid
    int minCoinsRequired = minCoins(coins, n, amount);
    printf("Minimum number of coins required to make %d rupees are %d", amount, minCoinsRequired);
    return 0;
}