//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: careful
#include <stdio.h>
#include <stdlib.h>

struct item {
    int value;
    int weight;
};

// function to sort items in decreasing order of value-to-weight ratio
int compare(const void *a, const void *b) {
    double ratio_a = ((struct item *)a)->value / (double)((struct item *)a)->weight;
    double ratio_b = ((struct item *)b)->value / (double)((struct item *)b)->weight;
    return (ratio_b > ratio_a) - (ratio_b < ratio_a);
}

// function to solve the knapsack problem using the greedy algorithm
int knapsack(int capacity, struct item *items, int n) {
    int taken = 0;  // value of items taken so far
    int i;

    // sort items in decreasing order of value-to-weight ratio
    qsort(items, n, sizeof(struct item), compare);

    // take items until the knapsack is full
    for (i = 0; i < n && capacity > 0; i++) {
        if (items[i].weight <= capacity) {
            taken += items[i].value;
            capacity -= items[i].weight;
        } else {
            taken += capacity * (items[i].value / (double)items[i].weight);
            capacity = 0;
        }
    }

    return taken;
}

int main() {
    struct item items[] = {{60, 10}, {100, 20}, {120, 30}};
    int capacity = 50, n = sizeof(items) / sizeof(struct item);
    int taken = knapsack(capacity, items, n);
    printf("The maximum value that can be taken is %d.\n", taken);
    return 0;
}