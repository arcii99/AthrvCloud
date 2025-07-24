//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Dennis Ritchie
/* This program demonstrates a greedy approach to minimize the number of coins to give as change. */

#include <stdio.h>

int main(void) {
    int coin_values[] = {10, 5, 1}; // list of coin values in cents
    int num_coins = sizeof(coin_values) / sizeof(coin_values[0]); // number of different coins
    int amount_due, num_each_coin[num_coins], num_total_coins = 0;

    printf("Enter the amount due in cents: ");
    scanf("%d", &amount_due);

    for (int i = 0; i < num_coins; i++) {
        num_each_coin[i] = amount_due / coin_values[i]; // determine how many of each coin is needed
        amount_due %= coin_values[i]; // update the remaining amount due
        num_total_coins += num_each_coin[i]; // keep track of the total number of coins
    }

    printf("The minimum number of coins required: %d\n", num_total_coins);
    printf("Number of each coin:\n");
    for (int i = 0; i < num_coins; i++) {
        printf("%d cent coin: %d\n", coin_values[i], num_each_coin[i]);
    }

    return 0;
}