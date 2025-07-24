//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: sophisticated
#include <stdio.h>

// Custom struct to represent items
struct Item {
    int weight;
    int value;
};

// Function to sort the items by value/weight ratio (descending)
void sort_items(struct Item items[], int n) {

    // Bubble sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            double ratio_j = (double) items[j].value / items[j].weight;
            double ratio_j1 = (double) items[j+1].value / items[j+1].weight;

            if (ratio_j < ratio_j1) {
                // Swap the items
                struct Item temp = items[j];
                items[j] = items[j+1];
                items[j+1] = temp;
            }
        }
    }
}

// Function to perform the greedy algorithm
int knapsack(struct Item items[], int n, int max_weight) {
    sort_items(items, n);

    int current_weight = 0;
    int total_value = 0;

    for (int i = 0; i < n; i++) {
        if (current_weight + items[i].weight <= max_weight) {
            current_weight += items[i].weight;
            total_value += items[i].value;
        } else {
            // If adding the current item would exceed the max weight, skip it
            continue;
        }
    }

    return total_value;
}

int main() {
    // Create some sample items
    struct Item items[] = {
        {5, 100},
        {10, 200},
        {7, 150},
        {3, 50},
        {4, 75}
    };

    int n = sizeof(items) / sizeof(items[0]);
    int max_weight = 15;

    int total_value = knapsack(items, n, max_weight);

    printf("Total value of items in knapsack: %d", total_value);

    return 0;
}