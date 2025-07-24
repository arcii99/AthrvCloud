//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

// Define a struct to hold information about each item
typedef struct {
    int value;
    int weight;
} Item;

// Define a function to compare two items based on their value-to-weight ratio
int cmpfunc(const void* a, const void* b) {
    Item* item1 = (Item*)a;
    Item* item2 = (Item*)b;
    double ratio1 = (double)item1->value / item1->weight;
    double ratio2 = (double)item2->value / item2->weight;
    if (ratio1 > ratio2) {
        return -1;
    }
    else if (ratio1 == ratio2) {
        return 0;
    }
    else {
        return 1;
    }
}

// Define a function to solve the knapsack problem using a greedy algorithm
int knapsack(Item* items, int n, int capacity) {
    qsort(items, n, sizeof(Item), cmpfunc); // Sort the items by value-to-weight ratio
    int total_value = 0;
    int remaining_capacity = capacity;
    for (int i = 0; i < n; i++) {
        if (remaining_capacity == 0) {
            break;
        }
        if (items[i].weight <= remaining_capacity) {
            total_value += items[i].value;
            remaining_capacity -= items[i].weight;
        }
        else {
            total_value += (int)((double)remaining_capacity / items[i].weight * items[i].value); // Take a fractional amount of the item
            remaining_capacity = 0;
        }
    }
    return total_value;
}

int main() {
    // Example data
    Item items[] = {{5, 10}, {7, 7}, {2, 15}, {10, 5}, {1, 20}};
    int n = sizeof(items) / sizeof(Item);
    int capacity = 25;

    // Solve the knapsack problem
    int total_value = knapsack(items, n, capacity);

    // Print the result
    printf("The maximum value of items that can fit in the knapsack with capacity %d is %d\n", capacity, total_value);

    return 0;
}