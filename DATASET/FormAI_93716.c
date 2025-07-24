//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of items and maximum weight of the knapsack
#define MAX_ITEMS 10
#define MAX_WEIGHT 200

// Define the structure of an item
typedef struct {
    int weight;
    int value;
} Item;

// Define the function for comparing two items based on their value-to-weight ratio
int cmp(const void* a, const void* b) {
    Item* item1 = (Item*)a;
    Item* item2 = (Item*)b;
    double ratio1 = (double)item1->value / item1->weight;
    double ratio2 = (double)item2->value / item2->weight;
    if (ratio1 < ratio2) {
        return 1;
    } else if (ratio1 > ratio2) {
        return -1;
    } else {
        return 0;
    }
}

// Define the function for solving the knapsack problem using greedy algorithm
void knapsack(Item* items, int n, int maxWeight) {
    qsort(items, n, sizeof(Item), cmp); // Sort the items based on their value-to-weight ratio
    int totalValue = 0;
    int remainingWeight = maxWeight;
    for (int i = 0; i < n; i++) {
        if (items[i].weight <= remainingWeight) {
            totalValue += items[i].value;
            remainingWeight -= items[i].weight;
        } else {
            totalValue += items[i].value * ((double)remainingWeight / items[i].weight);
            break;
        }
    }
    printf("The maximum value that can be obtained is %d.\n", totalValue);
}

int main() {
    Item items[MAX_ITEMS];
    items[0].weight = 27;
    items[0].value = 153;
    items[1].weight = 7;
    items[1].value = 92;
    items[2].weight = 2;
    items[2].value = 15;
    items[3].weight = 1;
    items[3].value = 7;
    items[4].weight = 43;
    items[4].value = 299;
    items[5].weight = 5;
    items[5].value = 50;
    items[6].weight = 19;
    items[6].value = 127;
    items[7].weight = 3;
    items[7].value = 22;
    items[8].weight = 2;
    items[8].value = 13;
    items[9].weight = 26;
    items[9].value = 136;
    knapsack(items, MAX_ITEMS, MAX_WEIGHT);
    return 0;
}