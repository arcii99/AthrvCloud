//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ITEMS 100

struct Item {
    int weight;
    int value;
};

int compare(const void* a, const void* b) {
    struct Item* item1 = (struct Item*)a;
    struct Item* item2 = (struct Item*)b;
    double ratio1 = (double)item1->value / item1->weight;
    double ratio2 = (double)item2->value / item2->weight;
    if (ratio1 < ratio2) {
        return 1;
    }
    else if (ratio1 > ratio2) {
        return -1;
    }
    else {
        return 0;
    }
}

void printItems(struct Item* items, int size) {
    printf("Items: \n");
    for (int i = 0; i < size; ++i) {
        printf("%d. Weight: %d, Value: %d\n", i + 1, items[i].weight, items[i].value);
    }
}

double fractionalKnapsack(struct Item* items, int size, int maxWeight) {
    qsort(items, size, sizeof(struct Item), compare);
    printItems(items, size);

    int currentWeight = 0;
    double totalValue = 0.0;

    for (int i = 0; i < size; ++i) {
        if (currentWeight + items[i].weight < maxWeight) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        }
        else {
            int remainingWeight = maxWeight - currentWeight;
            double valuePerWeight = (double)items[i].value / items[i].weight;
            totalValue += valuePerWeight * remainingWeight;
            break;
        }
    }

    return totalValue;
}

int main() {
    struct Item items[] = {
        {10, 60},
        {20, 100},
        {30, 120}
    };
    int size = sizeof(items) / sizeof(items[0]);
    int maxWeight = 50;

    double maxTotalValue = fractionalKnapsack(items, size, maxWeight);
    printf("Maximum value that can be obtained = %.2lf\n", maxTotalValue);

    return 0;
}