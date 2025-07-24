//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Ada Lovelace
#include <stdio.h>

int main() {
    int num_coins, target_amount, total_value = 0, num_needed_coins = 0;
    printf("Enter the number of coins available: ");
    scanf("%d", &num_coins);
    int coins[num_coins];
    printf("Enter the value of each coin (ascending order): ");
    for(int i = 0; i < num_coins; i++){
        scanf("%d", &coins[i]);
    }
    printf("Enter the target amount: ");
    scanf("%d", &target_amount);
    for(int i = num_coins - 1; i >= 0; i--){
        while(total_value + coins[i] <= target_amount){
            total_value += coins[i];
            num_needed_coins++;
        }
    }
    printf("Minimum number of coins needed: %d", num_needed_coins);
    return 0;
}