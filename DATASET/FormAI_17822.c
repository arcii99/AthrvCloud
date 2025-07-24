//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: unmistakable
#include <stdio.h>

#define MAX_SIZE 100

int main(){
    int coin_values[] = {1, 5, 10, 25, 50}; //array indicating coin values
    int n = sizeof(coin_values)/sizeof(coin_values[0]); //total number of coins
    int total_value = 73; //total money we want to make
    int change[MAX_SIZE], num_coins[MAX_SIZE]; //arrays to hold change and number of coins
    int i, j;

    //initialize change array to all zeros
    for(i=0; i<MAX_SIZE; i++){
        change[i] = 0;
    }

    //initialize num_coins array to all -1
    for(i=0; i<MAX_SIZE; i++){
        num_coins[i] = -1;
    }

    //base case: if total_value is zero, no change is needed
    change[0] = 0;
    num_coins[0] = 0;

    //for each coin value, calculate the minimum number of coins needed to make total_value
    for(i=1; i<=total_value; i++){
        int min_coins = MAX_SIZE; //set min_coins to a very high value initially
        int coin_index = -1;

        //check each coin value to see if it can be used to make change
        for(j=0; j<n; j++){
            int remaining_value = i - coin_values[j]; //calculate remaining value after using this coin

            //if remaining value is non-negative and the number of coins needed to make this value is smaller than min_coins, update min_coins and coin_index
            if(remaining_value >= 0 && num_coins[remaining_value] < min_coins){
                min_coins = num_coins[remaining_value] + 1;
                coin_index = j;
            }
        }

        //update change and num_coins arrays with the minimum values found
        change[i] = coin_values[coin_index];
        num_coins[i] = min_coins;
    }

    //print the results
    printf("Minimum number of coins needed to make %d cents: %d\n", total_value, num_coins[total_value]);
    printf("Change given in coins: ");

    //iterate through the change array backwards to get the actual coins used
    i = total_value;
    while(i > 0){
        printf("%d ", change[i]);
        i -= change[i];
    }

    printf("\n");

    return 0;
}