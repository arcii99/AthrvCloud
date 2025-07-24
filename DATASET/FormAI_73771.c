//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_COINS 10

int compare(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    int coins[MAX_COINS] = {1, 2, 5, 10, 20, 50, 100, 500, 1000, 2000}; // Available coin denominations
    int amount, i = 0, j, count[MAX_COINS] = {0}; // i is the index of current denomination
    printf("Enter the amount: ");
    scanf("%d", &amount);
    while (amount > 0) {
        if (coins[i] > amount) { // Move to a smaller denomination
            i++;
            continue;
        }
        amount -= coins[i]; // Deduct the current denomination from remaining amount
        count[i]++; // Increment count of current denomination
    }
    printf("The minimum number of coins needed: %d\n", count[0] + count[1] + count[2] + count[3] + count[4] + count[5] + count[6] + count[7] + count[8] + count[9]);
    printf("The coins used: ");
    for (i = 0; i < MAX_COINS; i++) {
        for (j = 0; j < count[i]; j++)
            printf("%d ", coins[i]); // Print the coins used in descending order
    }
    printf("\n");
    return 0;
}