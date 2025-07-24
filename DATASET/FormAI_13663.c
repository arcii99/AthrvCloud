//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

struct item {
    int value;
    int weight;
};

int cmpfunc(const void *a, const void *b) {
    struct item *ia = (struct item *)a;
    struct item *ib = (struct item *)b;
    return (int)(100.0 * ((float)ib->value / (float)ib->weight - (float)ia->value / (float)ia->weight));
}

int main() {
    int i, total_weight = 0, capacity = 50, total_value = 0;
    struct item items[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(items) / sizeof(items[0]);

    qsort(items, n, sizeof(struct item), cmpfunc);

    for (i = 0; i < n && total_weight <= capacity; i++) {
        if (total_weight + items[i].weight <= capacity) {
            total_weight += items[i].weight;
            total_value += items[i].value;
            printf("Taking item %d with value %d and weight %d\n", i, items[i].value, items[i].weight);
        }
    }

    printf("Total value: %d\n", total_value);

    return 0;
}