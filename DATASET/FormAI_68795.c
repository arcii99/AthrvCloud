//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10
#define MAX_KNAPSACK_WEIGHT 20

typedef struct {
    int weight;
    int value;
} Item;

int compare(const void* a, const void* b) {
    Item* itemA = (Item*)a;
    Item* itemB = (Item*)b;

    return (itemB->value / itemB->weight) - (itemA->value / itemA->weight);
}

int main() {
    Item items[MAX_ITEMS] = {
        {2, 40},
        {3, 50},
        {5, 140},
        {7, 160},
        {11, 200},
        {13, 220},
        {17, 280},
        {19, 320},
        {23, 380},
        {29, 400}
    };
    int knapsackWeight = MAX_KNAPSACK_WEIGHT;

    qsort(items, MAX_ITEMS, sizeof(Item), compare);

    int i;
    int totalValue = 0;

    for (i = 0; i < MAX_ITEMS; i++) {
        if (knapsackWeight - items[i].weight >= 0) {
            knapsackWeight -= items[i].weight;
            totalValue += items[i].value;
        } else {
            break;
        }
    }

    printf("Total value: %d\n", totalValue);

    return 0;
}