//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>

typedef struct knapsack_item {
    int value;
    int weight;
} knapsack_item;

int compare(const void * a, const void * b) {
    knapsack_item * item1 = (knapsack_item*) a;
    knapsack_item * item2 = (knapsack_item*) b;
    double ratio1 = ((double) item1->value) / item1->weight;
    double ratio2 = ((double) item2->value) / item2->weight;
    if (ratio1 > ratio2) {
        return -1;
    } else if (ratio1 < ratio2) {
        return 1;
    } else {
        return 0;
    }
}

int knapsack(knapsack_item * items, int n, int w, int * solution) {
    qsort(items, n, sizeof(knapsack_item), compare);
    int i;
    double total_value = 0.0;
    for (i = 0; i < n; i++) {
        if (items[i].weight <= w) {
            solution[i] = 1;
            w -= items[i].weight;
            total_value += items[i].value;
        } else {
            solution[i] = 0;
        }
    }
    return (int) total_value;
}

int main() {
    int n = 5; // number of items
    knapsack_item items[n];
    items[0].value = 10;
    items[0].weight = 2;
    items[1].value = 5;
    items[1].weight = 3;
    items[2].value = 15;
    items[2].weight = 5;
    items[3].value = 7;
    items[3].weight = 7;
    items[4].value = 6;
    items[4].weight = 1;
    int w = 15; // maximum weight
    int solution[n];
    int total_value = knapsack(items, n, w, solution);
    printf("Maximum value: %d\n", total_value);
    printf("Selected items:\n");
    int i;
    for (i = 0; i < n; i++) {
        if (solution[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}