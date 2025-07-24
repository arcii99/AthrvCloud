//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: complex
// C program to solve the fractional knapsack problem using Greedy Algorithm.
#include <stdio.h>
#include <stdlib.h>

// Structure for an item which has a value and weight
struct Item {
    int value, weight;
};

// Function to compare two items according to value/weight ratio
int compare(const void* a, const void* b) {
    double ratio1 = (double)((struct Item*)a)->value / ((struct Item*)a)->weight;
    double ratio2 = (double)((struct Item*)b)->value / ((struct Item*)b)->weight;
    return (int)(ratio2 - ratio1);
}

// Function to solve the fractional knapsack problem
void fracKnapsack(struct Item arr[], int n, int capacity) {
    // Sort items based on value/weight ratio using quicksort
    qsort(arr, n, sizeof(struct Item), compare);

    // Initialize variables for total value and weight in knapsack
    int totalValue = 0, totalWeight = 0;

    // Loop through sorted items and add as much as possible while staying under capacity
    for (int i = 0; i < n; i++) {
        int weight = arr[i].weight, value = arr[i].value;

        // If adding the entire item exceeds capacity, add a fraction of it
        if (totalWeight + weight > capacity) {
            int remainingWeight = capacity - totalWeight;
            double fraction = (double)remainingWeight / weight;
            totalValue += fraction * value;
            totalWeight += remainingWeight;
            break;
        }

        // Otherwise, add entire item to knapsack
        totalValue += value;
        totalWeight += weight;
    }

    // Print total value and weight of items in knapsack
    printf("Total value in knapsack: %d\n", totalValue);
    printf("Total weight in knapsack: %d\n", totalWeight);
}

// Main function to test fracKnapsack() using example data
int main() {
    // Example data
    struct Item items[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(items) / sizeof(items[0]);
    int capacity = 50;

    // Solve fractional knapsack problem and print results
    fracKnapsack(items, n, capacity);

    return 0;
}