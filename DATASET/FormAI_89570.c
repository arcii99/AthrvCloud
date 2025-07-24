//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: secure
#include <stdio.h>
#include <stdlib.h>

struct item {
    int weight;
    int value;
};

int cmp(const void *a, const void *b) {
    struct item *aa = (struct item *)a;
    struct item *bb = (struct item *)b;
    double a1 = (double)aa->value / aa->weight;
    double b1 = (double)bb->value / bb->weight;
    return b1 > a1 ? 1 : -1;
}

void fractional_knapsack(struct item items[], int n, int capacity) {
    double total_value = 0.0;
    int i;

    qsort(items, n, sizeof(struct item), cmp);

    for (i = 0; i < n; i++) {
        if (items[i].weight <= capacity) {
            capacity -= items[i].weight;
            total_value += items[i].value;
        } else {
            total_value += ((double)capacity / (double)items[i].weight) * (double)items[i].value;
            break;
        }
    }

    printf("Total value: %.2f\n", total_value);
}

int main(int argc, char **argv) {
    struct item items[] = {
        { 10, 60 },
        { 20, 100 },
        { 30, 120 },
    };
    int n = sizeof(items) / sizeof(struct item);
    int capacity = 50;

    fractional_knapsack(items, n, capacity);

    return 0;
}