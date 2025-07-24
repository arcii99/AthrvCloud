//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: introspective
#include <stdio.h>

int main() {
    int coins[] = {1, 5, 10, 25}; // represents different coin denominations
    int totalChange, coinsUsed[4] = {}; // stores the minimum number of coins needed to make the change
    int i, j, remainingChange; // 'i' and 'j' are loop variables, 'remainingChange' is used to calculate the minimum number of coins needed for remaining changes

    printf("Enter the total change required: ");
    scanf("%d", &totalChange);

    remainingChange = totalChange; // initially set the remaining change to the total change required

    for (i = 3; i >= 0; i--) {
        coinsUsed[i] = remainingChange / coins[i]; // calculate the number of coins of denomination 'i' required to make the change
        remainingChange = remainingChange % coins[i]; // update remainingChange to consider the remaining change after using coins of denomination 'i'
    }

    printf("Minimum number of coins required to make change of %d is: \n", totalChange);
    for (j = 0; j < 4; j++) {
        printf("%d coin(s) of denomination %d \n", coinsUsed[j], coins[j]); // display the minimum number of coins used for each denomination
    }

    return 0;
}