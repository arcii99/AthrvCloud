//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double weight;
    double value;
} Item; 

int compare(const void* a, const void* b) {
    Item* itemA = (Item*)a;
    Item* itemB = (Item*)b;
    double ratioA = itemA->value / itemA->weight;
    double ratioB = itemB->value / itemB->weight;
    if (ratioA < ratioB)
        return 1;
    else if (ratioA > ratioB)
        return -1;
    else
        return 0;
}

void knapsackGreedy(Item itemList[], int n, double capacity) {
    qsort(itemList, n, sizeof(Item), compare);
    double totalValue = 0.0;
    double totalWeight = 0.0;
    int i;
    for (i = 0; i < n; i++) {
        if (totalWeight + itemList[i].weight <= capacity) {
            totalWeight += itemList[i].weight;
            totalValue += itemList[i].value;
        }
        else {
            double remainingWeight = capacity - totalWeight;
            totalValue += remainingWeight * (itemList[i].value / itemList[i].weight);
            break;
        }
    }
    printf("Maximum value with weight %lf: %lf\n", capacity, totalValue);
}

int main() {
    Item itemList[] = {{10, 60}, {20, 100}, {30, 120}};
    int n = sizeof(itemList) / sizeof(itemList[0]);
    double capacity = 50.0;
    knapsackGreedy(itemList, n, capacity);
    return 0;
}