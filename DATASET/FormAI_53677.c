//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: medieval
#include <stdio.h>

// Function to calculate the minimum number of coins required to change a given amount
// using a greedy algorithm
int medieval_coin_change(int amount, int coins[], int n) {
    int coins_used = 0; // Counter to keep track of the coins used
    int i; // Variable to loop over the coins array

    // Iterate through the coins array in descending order
    for (i = n - 1; i >= 0; i--) {
        // While the current coin value is less than or equal to the remaining amount
        while (amount >= coins[i]) {
            // Subtract the coin value from the remaining amount
            amount -= coins[i];
            // Increment the coins used counter
            coins_used++;
        }
    }

    return coins_used;
}

// Driver program to test the function
int main() {
    int amount = 59; // Amount to be changed
    int coins[] = {50, 25, 10, 5, 1}; // Coin denominations in descending order
    int n = 5; // Number of coins

    // Call the function to calculate the minimum number of coins required
    int coins_used = medieval_coin_change(amount, coins, n);

    // Print the result
    printf("The minimum number of coins required to change %d is %d\n", amount, coins_used);

    return 0;
}