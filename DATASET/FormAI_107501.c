//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

typedef struct Item {
    int value;
    int weight;
    double ratio;
} Item;

int compare(const void *a, const void *b) {
    Item *ia = (Item *)a;
    Item *ib = (Item *)b; 
    return (int) (ib->ratio - ia->ratio);
}

double fractional_knapsack(Item *items, int n, int W) {
    qsort(items, n, sizeof(Item), compare);

    double total_value = 0.0;

    for (int i = 0; i < n; i++) {
        if (items[i].weight <= W) {
            total_value += items[i].value;
            W -= items[i].weight;
        } else {
            total_value += items[i].ratio * W;
            break;
        }
    }

    return total_value;
}

int main() {
    Item items[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(items) / sizeof(items[0]);
    int W = 50;

    for (int i = 0; i < n; i++) {
        items[i].ratio = (double) items[i].value / items[i].weight;
    }

    double max_value = fractional_knapsack(items, n, W);

    printf("Maximum value in knapsack = %lf", max_value);

    return 0;
}