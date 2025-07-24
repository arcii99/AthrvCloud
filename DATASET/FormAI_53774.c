//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: enthusiastic
#include<stdio.h>

int main(){
    int coins[] = {1, 5, 10, 25, 50}; // available coins
    int amount;
    int numCoins = 0; // keep count of the coins used

    // Prompt the user for input
    printf("Enter the amount you want to make change for: ");
    scanf("%d", &amount);

    // Perform the greedy algorithm
    for(int i=4; i>=0; i--){
        while(amount >= coins[i]){
            amount -= coins[i];
            numCoins++;
        }
    }

    // Output the results
    printf("The minimum number of coins required is: %d\n", numCoins);
    printf("Congratulations, you have changed your coins with Joy!\n");

    return 0;
}