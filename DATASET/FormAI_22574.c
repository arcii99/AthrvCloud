//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: peaceful
#include<stdio.h>

//Implementing a simple greedy algorithm to find the minimum number of coins required to make change.
int main(){

    int coinTypes[10] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000}; //n different coin types available
    int denominationCount[10] = {0};

    int amount;
    printf("Enter the amount to make change for: ");
    scanf("%d", &amount);

    int remainingAmount = amount;
    int i = 9;

    while(remainingAmount > 0){

        if(remainingAmount >= coinTypes[i]){
            denominationCount[i]++;
            remainingAmount -= coinTypes[i];
        }
        else{
            i--;
        }

    }

    printf("Minimum number of coins required for change: \n");

    for(int j = 9; j >= 0; j--){
        if(denominationCount[j] > 0){
            printf("%d x Rs %d \n", denominationCount[j], coinTypes[j]);
        }
    }

    return 0;
}