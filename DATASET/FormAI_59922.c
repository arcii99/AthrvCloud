//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Ada Lovelace
#include<stdio.h>

void changeCoins(int numCoins, int denom[], int amount, int coins[]) {

    int i, total=0;
    for (i=numCoins-1; i>=0; i--) {

        while (total+denom[i] <= amount) {

            coins[i]++;
            total += denom[i];
        }
    }
}

int main() {

    int numCoins=3, amount=12;
    int denom[] = {5, 2, 1}, coins[] = {0, 0, 0};

    changeCoins(numCoins, denom, amount, coins);

    printf("The minimum coins required for the amount %d is:\n", amount);
    int i;
    for (i=0; i<numCoins; i++) {
        printf("%d coins of %d denomination\n", coins[i], denom[i]);
    }
    return 0;
}