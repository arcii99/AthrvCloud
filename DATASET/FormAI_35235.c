//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: lively
#include <stdio.h>

int main() {
    int denominations[] = {1, 5, 10, 25, 100}; // available coin denominations
    int num_denominations = 5; // number of different denominations
    int amount_due = 78; // amount due in cents
    int num_coins[num_denominations]; // array to store number of coins of each denomination used
    int total_coins = 0; // total number of coins used
    
    for (int i = num_denominations - 1; i >= 0; i--) {
        num_coins[i] = amount_due / denominations[i]; // number of coins needed for this denomination
        amount_due %= denominations[i]; // remaining amount after using this denomination
        total_coins += num_coins[i]; // update total number of coins used
    }
    
    printf("Amount due: $%.2f\n", total_coins / 100.0); // print amount due in dollars
    printf("Number of coins used:\n");
    for (int i = 0; i < num_denominations; i++) {
        printf("%d x %d cents\n", num_coins[i], denominations[i]); // print number of coins of each denomination used
    }
    
    return 0; // done!
}