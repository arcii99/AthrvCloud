//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: relaxed
#include <stdio.h>

int main() {
    int coins[] = {25, 10, 5, 1}; // available coin denominations
    int num_coins[] = {0, 0, 0, 0}; // initialize to 0 coins of each type
    int amount, i;

    printf("Enter the amount you want to represent in cents: ");
    scanf("%d", &amount);

    for (i = 0; i < 4; i++) { // iterate through the coin denominations
        while (amount >= coins[i]) { // keep subtracting until we can't anymore
            amount -= coins[i];
            num_coins[i]++;
        }
    }

    printf("Minimum number of coins needed: %d\n", num_coins[0] + num_coins[1] + num_coins[2] + num_coins[3]);
    printf("Number of each coin type:\n");
    printf("Quarters: %d\n", num_coins[0]);
    printf("Dimes: %d\n", num_coins[1]);
    printf("Nickels: %d\n", num_coins[2]);
    printf("Pennies: %d\n", num_coins[3]);

    return 0;
}