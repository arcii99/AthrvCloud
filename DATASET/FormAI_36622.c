//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: minimalist
#include <stdio.h>

int main() {
    int coins[] = {50, 25, 10, 5, 1}; // available coin denominations
    int num_coins[5] = {0, 0, 0, 0, 0}; // number of coins for each denomination
    int total_money, remaining_money;

    printf("Enter the total amount of money: ");
    scanf("%d", &total_money);

    remaining_money = total_money; // initialize remaining_money with total_money

    for (int i = 0; i < 5; i++) {
        while (remaining_money >= coins[i]) { // keep subtracting the maximum possible coin from the remaining_money
            remaining_money -= coins[i]; // subtract coin[i] from remaining_money
            num_coins[i]++; // increment the corresponding num_coins
        }
    }

    printf("The minimum number of coins required to make %d cents is:\n", total_money);
    printf("%d Quarters\n", num_coins[0]);
    printf("%d Dimes\n", num_coins[1]);
    printf("%d Nickels\n", num_coins[2]);
    printf("%d Pennies\n", num_coins[3] + num_coins[4]);

    return 0;
}