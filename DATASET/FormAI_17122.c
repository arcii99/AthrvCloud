//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

// define structure for items
typedef struct item {
    int weight;
    int value;
    float ratio;
} Item;

// compare function for qsorting items based on ratio in descending order
int compare(const void *a, const void *b) {
    Item *item_a = (Item *)a;
    Item *item_b = (Item *)b;
    if (item_a->ratio < item_b->ratio)
        return 1;
    else if (item_a->ratio > item_b->ratio)
        return -1;
    else
        return 0;
}

// function to calculate maximum value for given capacity using greedy algorithm
void knapsack(Item *items, int n, int capacity) {
    // qsort items based on descending order of ratios
    qsort(items, n, sizeof(Item), compare);
    int i;
    float max_value = 0.0;
    for (i = 0; i < n; i++) {
        if (items[i].weight <= capacity) {
            // the entire item can be added to knapsack
            max_value += items[i].value;
            capacity -= items[i].weight;
        }
        else {
            // only a fraction of the item can be added to knapsack
            max_value += capacity * items[i].ratio;
            break;
        }
    }
    printf("Maximum value that can be obtained = %f\n", max_value);
}

int main() {
    // initialize items
    Item items[] = {{10, 60, 0}, {20, 100, 0}, {30, 120, 0}};
    int n = sizeof(items) / sizeof(Item);
    // calculate ratio for each item
    int i;
    for (i = 0; i < n; i++) {
        items[i].ratio = (float)items[i].value / items[i].weight;
    }
    // knapsack capacity
    int capacity = 50;
    knapsack(items, n, capacity);
    return 0;
}