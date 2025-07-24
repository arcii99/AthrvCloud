//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: satisfied
#include <stdio.h>

int main() {
    int change, coins = 0;
    int coins_arr[] = {50, 25, 10, 5, 1};
    int num_coins = sizeof(coins_arr) / sizeof(int);

    printf("Enter the amount of change needed: ");
    scanf("%d", &change);

    for (int i = 0; i < num_coins; i++) {
        int current_coin = coins_arr[i];
        while (change >= current_coin) {
            change -= current_coin;
            coins++;
        }
    }

    printf("Minimum coins required: %d\n", coins);
    
    return 0;
}