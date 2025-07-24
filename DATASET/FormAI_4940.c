//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: complete
#include <stdio.h>

// define a struct to represent an item
struct Item {
    int weight;
    int value;
};

// define a function to sort items by ratio of value to weight
int cmp(const void* a, const void* b) {
    double ra = ((struct Item*)a)->value / (double)((struct Item*)a)->weight;
    double rb = ((struct Item*)b)->value / (double)((struct Item*)b)->weight;

    if(ra > rb) return -1;
    else if(ra < rb) return 1;
    else return 0;
}

int main() {
    // initialize items
    struct Item items[] = {{10, 60}, {20, 100}, {30, 120}};
    int capacity = 50;
    int n = sizeof(items) / sizeof(items[0]);

    // sort items by ratio of value to weight
    qsort(items, n, sizeof(struct Item), cmp);

    // initialize total weight and value
    int total_weight = 0;
    int total_value = 0;

    // iterate through items
    for(int i = 0; i < n; i++) {
        if(total_weight + items[i].weight <= capacity) {
            // add item to knapsack
            total_weight += items[i].weight;
            total_value += items[i].value;
        } else {
            // leave item out of knapsack
            break;
        }
    }

    // print the total value of items in the knapsack
    printf("Total value of items in the knapsack: %d\n", total_value);

    return 0;
}