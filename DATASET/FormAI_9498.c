//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: asynchronous
#include <stdio.h>

void findOptimalAmount(int amount) {
    int denominations[] = {1, 5, 10, 25, 50, 100};
    int coins[] = {0, 0, 0, 0, 0, 0};
    int i, remainingAmount;

    remainingAmount = amount;

    for (i = 5; i >= 0; i--) {
        coins[i] = remainingAmount / denominations[i];
        remainingAmount = remainingAmount % denominations[i];
    }

    printf("Minimum coins required:\n");
    printf("Dollar Coins: %d\n", coins[5]);
    printf("Half Dollars: %d\n", coins[4]);
    printf("Quarters: %d\n", coins[3]);
    printf("Dimes: %d\n", coins[2]);
    printf("Nickels: %d\n", coins[1]);
    printf("Pennies: %d\n", coins[0]);
}

int main() {
    int amount;
    printf("Enter amount (in cents): ");
    scanf("%d", &amount);

    findOptimalAmount(amount);

    return 0;
}