//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Dennis Ritchie
#include<stdio.h>

// function to implement greedy approach
void coinChange(int coin[], int n, int m) {
    int result[m], i, j;

    // Initially, set the result = 0
    for(i=0;i<m;i++) {
        result[i]=0;
    }

    // Initialize index to be used in coin array
    int index = 0;

    // Traverse through all given denominations
    for(i=n-1;i>=0;i--) {
        while(m >= *(coin+i)) {
            m -= *(coin+i);
            result[index]++;
        }
        index++;
    }
    printf("Coins required to get %d: ", m);
    for(i=0;i<index;i++) {
        printf("%d: %d \t", coin[i], result[i]);
    }
}

int main() {
    int coins[10], i, n, amount;

    printf("Enter the number of denominations: ");
    scanf("%d", &n);

    // Input denominations
    printf("Enter the denominations:\n");
    for(i=0;i<n;i++) {
        scanf("%d", &coins[i]);
    }

    printf("Enter the amount: ");
    scanf("%d", &amount);

    // Function call
    coinChange(coins, n, amount);

    return 0;
}