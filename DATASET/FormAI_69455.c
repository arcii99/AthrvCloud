//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 1000

typedef struct {
    int weight;
    int value;
} item_t;

int cmp_item_ratio_desc(const void *a, const void *b) {
    item_t *ia = (item_t *)a;
    item_t *ib = (item_t *)b;
    double ra = (double)ia->value / ia->weight;
    double rb = (double)ib->value / ib->weight;
    if (ra < rb) {
        return 1;
    } else if (ra > rb) {
        return -1;
    } else {
        return 0;
    }
}

int main(void) {
    int capacity, n_items, i;
    item_t items[MAX_ITEMS];
    double max_value = 0.0;
    scanf("%d %d", &capacity, &n_items);
    for (i = 0; i < n_items; i++) {
        scanf("%d %d", &items[i].weight, &items[i].value);
    }
    qsort(items, n_items, sizeof(item_t), cmp_item_ratio_desc);
    for (i = 0; i < n_items && capacity > 0; i++) {
        if (capacity >= items[i].weight) {
            max_value += items[i].value;
            capacity -= items[i].weight;
        } else {
            max_value += (double)capacity * items[i].value / items[i].weight;
            capacity = 0;
        }
    }
    printf("%.2f\n", max_value);
    return 0;
}