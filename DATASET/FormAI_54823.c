//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

void findMinCoins(int coins[], int n, int amount){

    int ans[MAX_SIZE] = {0};
    int ans_size = 0; 

    qsort(coins, n, sizeof(int), cmpfunc); 

    for(int i=n-1; i>=0; i--){
        while(amount >= coins[i]){
            ans[ans_size++] = coins[i];
            amount -= coins[i];
        }
    }

    printf("Minimum number of coins required: %d\n", ans_size);

    printf("Coins used: ");
    for(int i=0; i<ans_size; i++){
        printf("%d ", ans[i]);
    }
}

int main(){

    int coins[] = {1, 2, 5, 10, 20, 50 ,100, 200, 500, 2000};
    int n = sizeof(coins)/sizeof(int);
    int amount;

    printf("Enter the amount to be paid: ");
    scanf("%d", &amount);

    findMinCoins(coins, n, amount);

    return 0;
}