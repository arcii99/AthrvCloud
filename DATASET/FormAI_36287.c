//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: systematic
#include <stdio.h>

// function to sort the array in ascending order
void sort(int arr[], int size) {
    int temp;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[i]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// function implementing the greedy algorithm for coin change problem
void coinChange(int coins[], int size, int amount) {
    int coinCount[size], totalCoins = 0;
    sort(coins, size);  // sort the coins in ascending order
    
    // loop through the sorted array and find the number of coins needed
    for (int i = size - 1; i >= 0; i--) {
        if (amount == 0) break;
        coinCount[i] = amount / coins[i];
        totalCoins += coinCount[i];
        amount = amount % coins[i];
    }
    
    // print the result
    printf("Number of coins needed: %d\n", totalCoins);
    printf("Coins used: ");
    for (int i = size - 1; i >= 0; i--) {
        for (int j = 0; j < coinCount[i]; j++) {
            printf("%d ", coins[i]);
        }
    }
}

// main function to test the code
int main() {
    int coins[] = { 1, 5, 10, 25 };
    int size = sizeof(coins) / sizeof(int);
    int amount = 67;
    
    printf("Coins available: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", coins[i]);
    }
    printf("\n");
    
    coinChange(coins, size, amount);
    
    return 0;
}