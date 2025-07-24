//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: safe
#include <stdio.h>

#define MAX_ITEMS 100

struct Item {
    int value;
    int weight;
};

int compare(const void *a, const void *b) {
    double r1 = (*(struct Item *) b).value / (double) (*(struct Item *) b).weight;
    double r2 = (*(struct Item *) a).value / (double) (*(struct Item *) a).weight;

    return r1 > r2 ? 1 : -1;
}

double knapsack(int capacity, struct Item items[], int n) {
    qsort(items, n, sizeof(items[0]), compare);

    double total_value = 0.0;
    int i;

    for (i = 0; i < n && capacity > 0; i++) {
        if (items[i].weight <= capacity) {
            capacity -= items[i].weight;
            total_value += items[i].value;
        } else {
            total_value += items[i].value * ((double) capacity / items[i].weight);
            capacity = 0;
        }
    }

    return total_value;
}

int main() {
    struct Item items[MAX_ITEMS] = {
            {60, 10},
            {100, 20},
            {120, 30},
    };

    int capacity = 50;
    int n = sizeof(items) / sizeof(items[0]);

    double result = knapsack(capacity, items, n);

    printf("Maximum value: %0.2f\n", result);

    return 0;
}