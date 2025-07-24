//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: unmistakable
#include <stdio.h>

#define MAX_COINS 50

int main() {
    int coin_values[MAX_COINS] = {1, 5, 10, 25, 50}; // a list of available coin values
    int num_coins = sizeof(coin_values) / sizeof(int); // the number of coin values available
    int target_amount = 67; // the amount we want to make change for
    int change_amount = 0; // the amount of change we've made so far
    
    int coin_counts[num_coins]; // an array to store the number of each type of coin we use
    // initialize all coin counts to zero
    for(int i = 0; i < num_coins; i++) {
        coin_counts[i] = 0;
    }
    
    // greedy algorithm to make change
    for(int i = num_coins - 1; i >= 0; i--) {
        while(change_amount + coin_values[i] <= target_amount) {
            change_amount += coin_values[i];
            coin_counts[i]++;
        }
    }
    
    // print out the number of each type of coin we used
    printf("Change for %d cents: ", target_amount);
    for(int i = 0; i < num_coins; i++) {
        if(coin_counts[i] > 0) {
            printf("%d %c", coin_counts[i], coin_values[i] == 1 ? 'c' : 's');
            if(i < num_coins - 1) {
                printf(", ");
            }
        }
    }
    printf("\n");
    
    return 0;
}