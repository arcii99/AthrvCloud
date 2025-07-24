//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

int *calculate_coins(int amount, int *coin_types, int num_types, int *num_coins) {
    int *coins = (int*) calloc(num_types, sizeof(int));

    for (int i = num_types - 1; i >= 0; i--) {
        while (amount >= coin_types[i]) {
            amount -= coin_types[i];
            coins[i]++;
            (*num_coins)++;
        }
    }

    return coins;
}

int main() {
    int amount = 67;
    int coin_types[] = {1, 5, 10, 25};
    int num_types = 4;
    int num_coins = 0;

    int *coins = calculate_coins(amount, coin_types, num_types, &num_coins);

    printf("Number of coins required: %d\n", num_coins);
    printf("Coin breakdown:");

    for (int i = num_types - 1; i >= 0; i--) {
        if (coins[i] > 0) {
            printf("\n%d x %dc", coins[i], coin_types[i]);
        }
    }

    free(coins);

    return 0;
}