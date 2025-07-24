//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: modular
#include <stdio.h>

int main() {
    int n, total_weight;
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter the total weight capacity: ");
    scanf("%d", &total_weight);

    int weights[n];
    int values[n];
    printf("Enter item weights: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }
    printf("Enter corresponding item values: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }

    int knapsack[n][total_weight + 1];
    for (int i = 0; i <= total_weight; i++) {
        knapsack[0][i] = 0;
    }
    for (int i = 1; i < n; i++) {
        knapsack[i][0] = 0;
        for (int j = 1; j <= total_weight; j++) {
            if (weights[i] > j) {
                knapsack[i][j] = knapsack[i-1][j];
            } else {
                knapsack[i][j] = fmax(knapsack[i-1][j], knapsack[i-1][j-weights[i]] + values[i]);
            }
        }
    }

    printf("Maximum value that can be obtained: %d\n", knapsack[n-1][total_weight]);

    return 0;
}