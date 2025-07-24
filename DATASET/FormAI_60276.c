//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: relaxed
#include <stdio.h>

// This program demonstrates a greedy approach to finding the minimum number of coins required to make change for a given amount

int main() {
    int amount;
    printf("Enter the amount for which you want to make change:\n");
    scanf("%d", &amount);

    int denominations[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000}; // array of available coin denominations
    int numCoins = sizeof(denominations) / sizeof(denominations[0]); // number of available coins
    int coinsUsed[numCoins]; // array to store how many of each denomination of coin was used
    int i;

    // initialize coinsUsed array to all zeros
    for(i=0; i<numCoins; i++) {
        coinsUsed[i] = 0;
    }

    for(i=numCoins-1; i>=0; i--) {
        while(amount >= denominations[i]) { // keep subtracting the largest denomination until the remaining amount is less than the denomination
            amount -= denominations[i];
            coinsUsed[i]++;
        }
    }

    printf("The minimum number of coins required to make change for the given amount is:\n");

    // print out the result
    for(i=numCoins-1; i>=0; i--) {
        if(coinsUsed[i] > 0) {
            printf("%d x %d paise\n", coinsUsed[i], denominations[i]);
        }
    }
    return 0;
}