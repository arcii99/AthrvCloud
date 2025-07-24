//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

/*
 * This program uses a greedy algorithm to find the minimum number of coins required to make a given amount.
 * The available coins are of denominations 1, 5, 10, 25, 50 and 100 cents.
 */

int main() {
    int amount, coins = 0;
    printf("Enter the amount: ");
    scanf("%d", &amount);
    if (amount <= 0) {
        printf("Invalid amount\n");
        exit(0);
    }
    while (amount > 0) {
        if (amount >= 100) { // check if 100-cent coin can be used
            coins++;
            amount -= 100;
        }
        else if (amount >= 50) { // check if 50-cent coin can be used
            coins++;
            amount -= 50;
        }
        else if (amount >= 25) { // check if 25-cent coin can be used
            coins++;
            amount -= 25;
        }
        else if (amount >= 10) { // check if 10-cent coin can be used
            coins++;
            amount -= 10;
        }
        else if (amount >= 5) { // check if 5-cent coin can be used
            coins++;
            amount -= 5;
        }
        else if (amount >= 1) { // check if 1-cent coin can be used
            coins++;
            amount--;
        }
    }
    printf("The minimum number of coins required to make the amount is %d\n", coins);
    return 0;
}