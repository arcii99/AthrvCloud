//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Alan Touring
#include <stdio.h>

int coins[] = {25, 10, 5, 1};

int main() {
    int amount, count, i;

    printf("Enter amount: ");
    scanf("%d", &amount);

    count = 0;
    for (i = 0; i < 4; i++) {
        while (amount >= coins[i]) {
            count++;
            amount -= coins[i];
        }
    }

    printf("Number of coins needed: %d\n", count);
    
    return 0;
}