//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: cheerful
#include <stdio.h>

int main() {
    int coins[5] = {25, 10, 5, 1}; // define the available coin denominations
    int numCoins[4] = {0}; // initialize the number of each coin needed to zero
    int amount, i = 0;
    printf("Welcome to the Coin Change Calculator! Please enter the amount of change you need (in cents): ");
    scanf("%d", &amount); // get the target amount of change from the user
    
    while (amount > 0) { // loop until the full amount is covered
        if (amount >= coins[i]) { // if the current coin is small enough to use
            amount -= coins[i]; // subtract the value of the coin from the remaining change
            numCoins[i]++; // increment the corresponding coin counter
        } else { // if the current coin is too big to use
            i++; // move on to the next-smallest denomination
        }
    }

    printf("\nHere is the smallest combination of coins needed to make %d cents:\n", amount);
    printf("%d quarters, %d dimes, %d nickels, and %d pennies.\n", numCoins[0], numCoins[1], numCoins[2], numCoins[3]);
    printf("Thank you for using the Coin Change Calculator! Have a great day! :)");
    
    return 0;
}