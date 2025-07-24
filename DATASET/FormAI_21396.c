//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// define the item structure
typedef struct {
    int id;
    int weight;
    int value;
} Item;

// compare two items based on their value
int compare_items(const void* a, const void* b) {
    Item* item1 = (Item*)a;
    Item* item2 = (Item*)b;

    double ratio1 = (double)item1->value / (double)item1->weight;
    double ratio2 = (double)item2->value / (double)item2->weight;

    if (ratio1 < ratio2) {
        return 1;
    } else if (ratio1 > ratio2) {
        return -1;
    } else {
        return 0;
    }
}

// the main knapsack function
void knapsack(int max_weight, Item* items, int n) {

    // sort the items based on their value-to-weight ratio
    qsort(items, n, sizeof(Item), compare_items);

    // initialize the current weight and value
    int current_weight = 0;
    int current_value = 0;

    // iterate through all the items
    for (int i = 0; i < n; i++) {

        // if adding the current item won't exceed the maximum weight, add it
        if (current_weight + items[i].weight <= max_weight) {
            current_weight += items[i].weight;
            current_value += items[i].value;
        }

    }

    // output the total value of the selected items
    printf("Maximum value of items that can be carried: %d\n", current_value);
}

int main() {

    // define the knapsack items
    Item items[] = {
        {1, 2, 10},
        {2, 5, 20},
        {3, 3, 15},
        {4, 1, 5},
        {5, 4, 30}
    };

    // define the maximum weight that can be carried
    int max_weight = 10;

    // get the number of items in the knapsack
    int n = sizeof(items) / sizeof(Item);

    // solve the knapsack problem
    knapsack(max_weight, items, n);

    return 0;
}