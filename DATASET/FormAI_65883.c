//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: genious
#include <stdio.h>

struct coin {
    int denom;
    int amount;
};

// Comparator function for sorting the coins in decreasing order based on denomination.
int cmpfunc(const void *a, const void *b) {
    return (*(const struct coin *)b).denom - (*(const struct coin *)a).denom;
}

// Function to calculate minimum number of coins required for a given amount using the Greedy algorithm.
int minCoins(struct coin coins[], int num_coins, int amount) {
    qsort(coins, num_coins, sizeof(struct coin), cmpfunc);
    int coin_count = 0;
    for(int i=0; i<num_coins; i++) {
        if(amount == 0) {
            break;
        }
        if(amount >= coins[i].denom && coins[i].amount > 0) {
            int num = amount / coins[i].denom;
            if(num > coins[i].amount) {
                num = coins[i].amount;
            }
            amount -= num * coins[i].denom;
            coins[i].amount -= num;
            coin_count += num;
        }
    }  
    if(amount > 0) {
        // If it is not possible to give exact change.
        return -1;
    }
    return coin_count;   
}

int main() {
    // Initializing array of coins and amount to be paid.
    struct coin coins[] = {{10, 3}, {5, 5}, {1, 10}};
    int amount = 67;

    // Calling the greedy algorithm function.
    int numCoins = minCoins(coins, 3, amount);

    if(numCoins == -1) {
        printf("Cannot give exact change.\n");
    } else {
        printf("Minimum number of coins required: %d\n", numCoins);
    }
    return 0;
}