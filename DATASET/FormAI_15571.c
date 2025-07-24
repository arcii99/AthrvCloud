//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

typedef struct {
    int value;
    int weight;
} item;

int compare_items(const void *lhs, const void *rhs) {
    const item *li = lhs, *ri = rhs;
    double lval = (double) li->value / li->weight, rval = (double) ri->value / ri->weight;
    if (lval > rval) {
        return -1;
    } else if (rval > lval) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int n, W;
    scanf("%d %d", &n, &W);
    item items[MAX_ITEMS];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    qsort(items, n, sizeof(item), compare_items);

    double total_value = 0;
    int remaining_capacity = W;
    for (int i = 0; i < n && remaining_capacity > 0; i++) {
        double fraction = (double) remaining_capacity / items[i].weight;
        double item_value = fraction * items[i].value;
        total_value += item_value;
        remaining_capacity -= fraction * items[i].weight;
    }

    printf("The maximum value of items that can be taken is: %f\n", total_value);

    return 0;
}