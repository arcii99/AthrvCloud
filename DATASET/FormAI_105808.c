//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: portable
#include <stdio.h>
#include <stdlib.h>

struct item {
    int value;
    int weight;
};

int cmpfunc(const void *a, const void *b) {
    struct item *ia = (struct item *)a;
    struct item *ib = (struct item *)b;
    return (ia->value / ia->weight) < (ib->value / ib->weight);
}

void knapsack(struct item items[], int n, int total_weight) {
    qsort(items, n, sizeof(struct item), cmpfunc);
    int i = 0;
    double max_value = 0;
    while (total_weight > 0 && i < n) {
        if (items[i].weight <= total_weight) {
            total_weight -= items[i].weight;
            max_value += items[i].value;
        } else {
            max_value += (double)total_weight / items[i].weight * items[i].value;
            total_weight = 0;
        }
        i++;
    }
    printf("Maximum value: %lf\n", max_value);
}

int main() {
    struct item items[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(items) / sizeof(struct item);
    int total_weight = 50;
    knapsack(items, n, total_weight);
    return 0;
}