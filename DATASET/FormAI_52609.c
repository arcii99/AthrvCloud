//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: cheerful
#include <stdio.h>

/* This is a cheerful program that uses a Greedy Algorithm to find the minimum number of coins 
needed to make change for an amount specified by the user. Let's get started! */

int main() {
    int coins[] = {50, 25, 10, 5, 1}; // Array of coin denominations
    int num_coins = sizeof(coins)/sizeof(int); // Number of coin denominations
    int amount, coin_count, total_coins = 0; // Variables to keep track of the input amount, coin count for each denomination, and total coins used
    printf("Welcome to the coin changer program! Please enter the amount you would like to make change for: $");
    scanf("%d", &amount); // Taking input amount from user
    printf("Calculating minimum coins needed for $%d...\n", amount);
    for(int i = 0; i < num_coins; i++) { // Looping through each coin denomination
        coin_count = amount/coins[i]; // Calculating how many coins of current denomination can be used
        total_coins += coin_count; // Adding that number to the total coins used
        amount -= coin_count*coins[i]; // Updating the amount needed for next denomination
        printf("\t%d x $%d\n", coin_count, coins[i]); // Printing how many coins of current denomination were used
    }
    printf("Total number of coins used: %d\n", total_coins); // Printing the total number of coins used
    printf("Thanks for using the coin changer program! Have a great day!\n");
    return 0;
}