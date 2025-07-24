//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

// Struct definition of the item data type
struct item {
    int weight;
    int value;
};

// Function to compare the value per unit of weight of two items
int cmpfunc(const void* a, const void* b) {
    const struct item* item1 = (struct item*)a;
    const struct item* item2 = (struct item*)b;

    float ratio1 = (float)item1->value / item1->weight;
    float ratio2 = (float)item2->value / item2->weight;

    if (ratio1 < ratio2) {
        return 1;
    } else if (ratio1 > ratio2) {
        return -1;
    } else {
        return 0;
    }
}

// Function to return the maximum possible value of items that can be added to a knapsack of capacity W
int knapsack(int W, struct item items[], int n) {
    // Sort the items in decreasing order of value per unit weight
    qsort(items, n, sizeof(struct item), cmpfunc);

    // Initialize current weight of knapsack as 0 and the total value as 0
    int current_weight = 0;
    int total_value = 0;

    // Loop through each item
    for (int i = 0; i < n; i++) {
        // Check if the current weight of the knapsack plus the weight of the ith item
        // is less than or equal to the capacity of the knapsack
        if (current_weight + items[i].weight <= W) {
            // Add the value of the ith item to the total value
            total_value += items[i].value;

            // Add the weight of the ith item to the current weight of the knapsack
            current_weight += items[i].weight;
        } else {
            // Calculate the remaining capacity of the knapsack
            int remaining_capacity = W - current_weight;

            // Calculate the value of the ith item that can be added to the knapsack
            float value_per_unit_weight = (float)items[i].value / items[i].weight;
            int value_to_add = (int)(value_per_unit_weight * remaining_capacity);

            // Add the value of the ith item that can be added to the knapsack to the total value
            total_value += value_to_add;

            // Add the weight of the ith item that can be added to the knapsack to the current weight of the knapsack
            current_weight += remaining_capacity;

            // Break out of the loop since the knapsack is now full
            break;
        }
    }

    // Return the total value of items that were added to the knapsack
    return total_value;
}

int main() {
    // Create an array of items
    struct item items[] = {{20, 100}, {30, 120}, {10, 60}};

    // Calculate the length of the array
    int n = sizeof(items) / sizeof(items[0]);

    // Calculate the maximum possible value of items that can be added to a knapsack of capacity 50
    int max_value = knapsack(50, items, n);

    // Print the maximum possible value of items that can be added to the knapsack
    printf("Maximum possible value of items that can be added to the knapsack: %d\n", max_value);

    return 0;
}