//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct item {
    int value;
    int weight;
} ITEM;

int cmpfunc (const void * a, const void * b) {
    ITEM *itemA = (ITEM *)a;
    ITEM *itemB = (ITEM *)b;

    double ratioA = (double)itemA->value / (double)itemA->weight;
    double ratioB = (double)itemB->value / (double)itemB->weight;

    if (ratioA < ratioB) {
        return 1;
    } else if (ratioA > ratioB) {
        return -1;
    } else {
        return 0;
    }
}

int main() {
    srand(time(NULL));

    ITEM items[10];
    int maxWeight = 30;
    int totalWeight = 0;
    int totalValue = 0;
    int i;

    // Init random items values and weights
    for (i = 0; i < 10; i++) {
        items[i].value = rand() % 10 + 1;
        items[i].weight = rand() % 10 + 1;
    }

    // Print the items
    printf("Items:\n");
    for (i = 0; i < 10; i++) {
        printf("Item %d - Value: %d, Weight: %d\n", i, items[i].value, items[i].weight);
    }

    // Sort items by their ratios
    qsort(items, 10, sizeof(ITEM), cmpfunc);

    // Pick the items greedily
    printf("Picking the items greedily:\n");
    for (i = 0; i < 10; i++) {
        if (totalWeight + items[i].weight <= maxWeight) {
            printf("Picked item %d - Value: %d, Weight: %d\n", i, items[i].value, items[i].weight);
            totalWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            printf("Rejected item %d - Value: %d, Weight: %d\n", i, items[i].value, items[i].weight);
        }
    }

    printf("Total value: %d, Total weight: %d\n", totalValue, totalWeight);

    return 0;
}