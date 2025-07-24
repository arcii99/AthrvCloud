//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: standalone
#include <stdio.h>

#define MAX 10000

// structure of an item in the knapsack problem
typedef struct {
    int weight;
    int value;
} Item;

// function to compare items by value per weight ratio
int comp(const void* a, const void* b) {
    Item* itemA = (Item*)a;
    Item* itemB = (Item*)b;
    double ratioA = (double)itemA->value / itemA->weight;
    double ratioB = (double)itemB->value / itemB->weight;
    return ratioB > ratioA ? 1 : -1;
}

// function to solve the knapsack problem
double knapsack(Item items[], int n, int capacity) {
    // sort items by value per weight ratio
    qsort(items, n, sizeof(Item), comp);

    double total_value = 0.0;
    int total_weight = 0;

    // loop over items and add them to the knapsack until capacity is reached
    for (int i = 0; i < n; i++) {
        if (total_weight + items[i].weight <= capacity) {
            total_weight += items[i].weight;
            total_value += items[i].value;
        }
        else {
            int remaining_capacity = capacity - total_weight;
            total_weight += remaining_capacity;
            total_value += (double)remaining_capacity * items[i].value / items[i].weight;
            break;
        }
    }

    return total_value;
}

int main() {
    Item items[] = {{10, 60}, {20, 100}, {30, 120}};
    int n = sizeof(items) / sizeof(Item);
    int capacity = 50;
    double max_value = knapsack(items, n, capacity);
    printf("Maximum value in knapsack: %.2f\n", max_value);
    return 0;
}