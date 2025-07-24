//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: irregular
#include<stdio.h>
#include<stdlib.h>

// A structure for items that will be selected by the algorithm
struct item {
    int value;
    int weight;
};

// Sort function to sort items by their value per unit weight in non-increasing order
int cmpfunc(const void *a, const void *b) {
    struct item *i1 = (struct item *)a;
    struct item *i2 = (struct item *)b;
    return (i2->value / i2->weight) - (i1->value / i1->weight);
}

// Greedy method to get the maximum value of items that can be selected
double fractional_knapsack(struct item *items, int n, int capacity) {
    // Sort the items in non-increasing order of their value per unit weight
    qsort(items, n, sizeof(struct item), cmpfunc);
    // Initialize total value and remaining capacity
    double total_value = 0;
    int current_capacity = capacity;
    // Loop through every item
    for(int i=0; i<n; i++) {
        if(current_capacity == 0) {
            // If there is no remaining capacity, break the loop
            break;
        } else if(items[i].weight <= current_capacity) {
            // If the item can be fully selected, select it
            total_value += items[i].value;
            current_capacity -= items[i].weight;
        } else {
            // If the item cannot be fully selected, select a fraction of it that can fit in the remaining capacity
            total_value += (double)(current_capacity * items[i].value) / items[i].weight;
            current_capacity = 0;
        }
    }
    // Return the total value of selected items
    return total_value;
}

int main() {
    // Initialize some test items and capacity
    struct item items[] = {
        {60, 10},
        {100, 20},
        {120, 30}
    };
    int capacity = 50;
    int n = sizeof(items) / sizeof(items[0]);
    // Get the maximum value of items that can be selected
    double max_value = fractional_knapsack(items, n, capacity);
    // Print the result
    printf("Maximum value of items that can be selected is %0.2f\n", max_value);
    return 0;
}