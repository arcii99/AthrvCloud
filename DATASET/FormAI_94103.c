//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: medieval
#include <stdio.h>

int main() {

    int denominations[] = {1, 5, 10, 20, 50, 100};
    int num_denominations = 6;

    int amount, count = 0;
    printf("Enter the amount: ");
    scanf("%d", &amount);

    int i = num_denominations - 1;
    while (i >= 0) {
        while (amount >= denominations[i]) {
            amount -= denominations[i];
            count++;
        }
        i--;
    }

    printf("The minimum number of coins required is %d\n", count);

    return 0;
}