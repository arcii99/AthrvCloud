//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Structure for an item which includes its value and weight
struct item {
    int value;
    int weight;
};

// Function to obtain maximum value from two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Greedy algorithm for 0/1 Knapsack problem
int knapsack(struct item items[], int n, int capacity) {
    int i, j;
    int table[n+1][capacity+1];

    for (i = 0; i <= n; i++) {
        for (j = 0; j <= capacity; j++) {
            if (i==0 || j==0)
                table[i][j] = 0; // Initialize first row and column to zero
            else if (items[i-1].weight <= j) // Check if current item can fit in the capacity of Knapsack or not
                table[i][j] = max(items[i-1].value + table[i-1][j-items[i-1].weight], table[i-1][j]); // Choose the max value between current item or previous item when  the current capacity is less than its weight
            else
                table[i][j] = table[i-1][j]; // Choose previous value when current item cannot fit in Knapsack
        }
    }

    return table[n][capacity];
}

int main() {
    int capacity = 50; // Knapsack capacity
    struct item items[] = {{60, 10}, {100, 20}, {120, 30}}; // Item list with values and weights
    int n = sizeof(items) / sizeof(items[0]); // Calculate total number of items

    // Displaying the maximum value that can be put inside the given knapsack capacity
    printf("The maximum value that can be put in a knapsack of capacity %d is %d. \n", capacity, knapsack(items, n, capacity));
    return 0;
}