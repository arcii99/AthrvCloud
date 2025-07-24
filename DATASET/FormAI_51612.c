//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10
#define MAX_WEIGHT 50

typedef struct {
    int weight;
    int value;
    float ratio;
} item;

int compare_items(const void *a, const void *b) {
    item *item_a = (item *)a;
    item *item_b = (item *)b;

    if (item_a->ratio > item_b->ratio) {
        return -1;
    } else if (item_a->ratio < item_b->ratio) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    item items[MAX_ITEMS] = {
        {10, 20},
        {20, 50},
        {30, 70},
        {40, 100},
        {50, 120},
        {5, 10},
        {15, 30},
        {25, 50},
        {35, 80},
        {45, 110}
    };

    for (int i = 0; i < MAX_ITEMS; i++) {
        items[i].ratio = items[i].value / (float)items[i].weight;
    }

    qsort(items, MAX_ITEMS, sizeof(item), compare_items);

    int i = 0;
    int weight = 0;
    int value = 0;

    while (i < MAX_ITEMS && weight < MAX_WEIGHT) {
        if (items[i].weight <= MAX_WEIGHT - weight) {
            weight += items[i].weight;
            value += items[i].value;
            printf("Selected item: Weight=%d Value=%d\n", items[i].weight, items[i].value);
        } else {
            float remaining_weight = MAX_WEIGHT - weight;
            value += remaining_weight * items[i].ratio;
            printf("Selected item: Weight=%.2f Value=%.2f (fraction of item)\n", remaining_weight, remaining_weight * items[i].ratio);
            break;
        }

        i++;
    }

    printf("Total weight: %d\nTotal value: %d\n", weight, value);

    return 0;
}