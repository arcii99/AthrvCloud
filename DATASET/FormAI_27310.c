//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: lively
#include <stdio.h>

#define MAX_N 1000

int main() {
    int n, i, j, temp;
    int coins[MAX_N];

    printf("Enter the number of coins: ");
    scanf("%d", &n);

    printf("Enter the values of the coins:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }

    // sort the coins in descending order
    for (i = 0; i < n; i++) {
        for (j = i+1; j < n; j++) {
            if (coins[i] < coins[j]) {
                temp = coins[i];
                coins[i] = coins[j];
                coins[j] = temp;
            }
        }
    }

    int target;
    printf("Enter the target value: ");
    scanf("%d", &target);

    printf("Coins needed to make %d:\n", target);
    for (i = 0; i < n; i++) {
        while (target >= coins[i]) {
            target -= coins[i];
            printf("%d ", coins[i]);
        }
        if (target == 0) {
            break;
        }
    }

    return 0;
}