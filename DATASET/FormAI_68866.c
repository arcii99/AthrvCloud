//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: grateful
#include <stdio.h>

int main() {
    int amount;
    int coin_count = 0;
    int coins[] = {25, 10, 5, 1};
    int coins_len = 4;
    printf("Welcome to the coin counting program!\n");
    printf("Enter the amount of change (cents) you need:\n");
    scanf("%d", &amount);
    for (int i = 0; i < coins_len; i++) {
        while(amount >= coins[i]){
            amount = amount - coins[i];
            coin_count++;
        }
        if(amount == 0){
            break;
        }
    }
    printf("You need %d coins in total.\n", coin_count);
    return 0;
}