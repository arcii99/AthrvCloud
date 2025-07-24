//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: lively
// Hey there! Let me show you a fun example of a greedy algorithm in C!

#include <stdio.h>

// Define the number of coins we have and their values
#define NUM_COINS 5
int coins[NUM_COINS] = {1, 5, 10, 25, 50};

// Function to count the minimum number of coins to make change for a given amount
int minCoins(int amount) {
    int count = 0;
    
    // Loop through the coins in descending order
    for(int i = NUM_COINS - 1; i >= 0; i--) {
        // If the current coin value is less than or equal to the remaining amount,
        // add the maximum number of that coin to the count and subtract its total value from the remaining amount
        while(coins[i] <= amount) {
            count++;
            amount -= coins[i];
        }
    }
    
    return count; // Return the minimum number of coins needed
}

int main() {
    int amount;
    printf("Welcome to the Coin Changing Program!\n");
    printf("Enter an amount (in cents) to make change for: ");
    scanf("%d", &amount);
    
    int numCoins = minCoins(amount); // Get the minimum number of coins needed
    printf("The minimum number of coins to make change for %d cents is: %d\n", amount, numCoins);
    
    return 0; // We did it! Let's celebrate and return to the terminal :)
}