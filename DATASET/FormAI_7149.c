//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: paranoid
#include <stdio.h>

int main() {
    int coins[] = {25, 10, 5, 1};
    int num_coins = 4;
    
    int change;
    printf("Enter change amount in cents: ");
    scanf("%d", &change);

    int num_of_each_coin[] = {0, 0, 0, 0};
    int total_coins = 0;

    int i, j;
    for (i = 0; i < num_coins; i++) {
        while (change >= coins[i]) {
            change -= coins[i];
            num_of_each_coin[i]++;
            total_coins++;
        }
    }

    if (change > 0) {
        printf("Error: Unable to make exact change.\n");
    } else {
        printf("Coins required:");
        for (j = 0; j < num_coins; j++) {
            printf(" %d x %dc", num_of_each_coin[j], coins[j]);
        }
        printf("\nTotal coins: %d\n", total_coins);
    }

    return 0;
}