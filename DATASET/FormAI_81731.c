//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>

// Function to compare two integers
int cmpfunc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Function to implement Greedy Algorithm to find the minimum number of coins required to make a given sum
void coin_change(int coinSet[], int n, int sum) {
    int count = 0; 
    int *result = (int*) malloc(sizeof(int) * sum); // Allocate memory to the result array

    qsort(coinSet, n, sizeof(int), cmpfunc); // Sort the coin set
    for (int i = n - 1; i >= 0; i--) { // Traverse through the sorted coin set
        while (sum >= coinSet[i]) { // Keep subtracting the coins from the sum until sum becomes zero
            sum -= coinSet[i]; // Subtract the coin from the sum
            result[count++] = coinSet[i]; // Add the coin to the result array
        }
    }

    printf("Minimum number of coins required to make the sum is: %d\n", count);
    printf("The coins required are:");
    for (int i = 0; i < count; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result); // Free the allocated memory
}

// Driver function
int main() {
    int coinSet[] = {1, 2, 5, 10, 20, 50, 100}; // Coin set
    int n = 7; // Number of coins in the coin set
    int sum = 126; // Given sum

    coin_change(coinSet, n, sum); // Function call to find the minimum number of coins required

    return 0;
}