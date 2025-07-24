//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

struct item {
    int weight;
    int value;
};

// Function to compare two items by their value/weight ratio
int compare(const void* a, const void* b)
{
    struct item* item1 = (struct item*)a;
    struct item* item2 = (struct item*)b;
    double ratio1 = (double)(item1->value) / item1->weight;
    double ratio2 = (double)(item2->value) / item2->weight;
    if (ratio1 > ratio2)
        return -1;
    else if (ratio1 < ratio2)
        return 1;
    else
        return 0;
}

// Function to solve the fractional knapsack problem using a greedy approach
double fractional_knapsack(struct item* items, int n, int capacity)
{
    // Sort the items by their value/weight ratio in non-increasing order
    qsort(items, n, sizeof(struct item), compare);
    double total_value = 0;
    int i;
    for (i = 0; i < n && capacity > 0; i++) {
        if (items[i].weight <= capacity) {
            // Take the whole item if it fits into the knapsack
            total_value += items[i].value;
            capacity -= items[i].weight;
        }
        else {
            // Take a fraction of the item if it doesn't fit into the knapsack
            double fraction = (double)capacity / items[i].weight;
            total_value += fraction * items[i].value;
            capacity = 0;
        }
    }
    return total_value;
}

int main()
{
    // Example usage of the fractional knapsack algorithm
    struct item items[] = {{10, 60}, {20, 100}, {30, 120}};
    int n = sizeof(items) / sizeof(struct item);
    int capacity = 50;
    double max_value = fractional_knapsack(items, n, capacity);
    printf("The maximum value achievable by the fractional knapsack algorithm is: %.2f", max_value);
    return 0;
}