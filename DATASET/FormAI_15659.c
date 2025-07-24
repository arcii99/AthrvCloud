//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: genious
#include <stdio.h>

void coin_change(int coins[], int n, int amount) {
    int i, count = 0;
    
    // Sort coins in descending order
    for(i=0; i<n; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(coins[j] < coins[j+1]) {
                int temp = coins[j];
                coins[j] = coins[j+1];
                coins[j+1] = temp;
            }
        }
    }

    printf("Coins used: ");
    for(i=0; i<n; i++) {
        while(amount >= coins[i]) {
            amount -= coins[i];
            printf("%d ", coins[i]);
            count++;
        }
    }

    printf("\nNumber of coins required: %d\n", count);
}

int main() {
    int coins[] = {1, 5, 10, 25, 50};
    int n = sizeof(coins)/sizeof(coins[0]);
    int amount = 70;

    coin_change(coins, n, amount);

    return 0;
}