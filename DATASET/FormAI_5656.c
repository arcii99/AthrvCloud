//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: detailed
#include <stdio.h>

void greedy(int coins[], int numCoins, int amount) {
    int i, coin;
    for(i = 0; i < numCoins; i++) {
        coin = coins[i];
        while(amount - coin >= 0) {
            amount -= coin;
            printf("%d ", coin);
        }
    }
}

int main() {
    int coins[] = {1, 5, 10, 25};
    int numCoins = 4;
    int amount = 37;
    printf("The coins required to make %d cents are: ", amount);
    greedy(coins, numCoins, amount);
    return 0;
}