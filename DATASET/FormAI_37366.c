//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: imaginative
#include <stdio.h>

#define MAX_COINS 10

int main() {
    int coins[MAX_COINS] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
    int num_coins[MAX_COINS] = {0};
    int target_amount = 432;
    int remaining_amount = target_amount;
    int current_coin_index = MAX_COINS - 1;
    
    while (remaining_amount > 0) {
        int num_current_coin = remaining_amount / coins[current_coin_index];
        remaining_amount -= num_current_coin * coins[current_coin_index];
        num_coins[current_coin_index] = num_current_coin;
        current_coin_index--;
    }
    
    printf("To make %d, you need:\n", target_amount);
    for (int i = 0; i < MAX_COINS; i++) {
        if (num_coins[i] > 0) {
            printf("%d x %d\n", num_coins[i], coins[i]);
        }
    }
    
    return 0;
}