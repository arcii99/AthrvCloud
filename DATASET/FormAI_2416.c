//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: secure
#include <stdio.h>
#include <stdlib.h>

// define structure to hold item data
typedef struct {
    int value;
    int weight;
} Item;

// define function to compare two items based on their value-to-weight ratios
int cmp(const void *a, const void *b) {
    Item *item1 = (Item *) a;
    Item *item2 = (Item *) b;
    double ratio1 = (double) item1->value / item1->weight;
    double ratio2 = (double) item2->value / item2->weight;
    if (ratio1 > ratio2) { return -1; }
    else if (ratio1 < ratio2) { return 1; }
    else { return 0; }
}

// define function to solve the knapsack problem using greedy algorithm
int knapsack(Item *items, int n, int capacity) {
    int total_value = 0;
    int remaining_capacity = capacity;
    // sort items by value-to-weight ratio in descending order
    qsort(items, n, sizeof(Item), cmp);
    // add items to knapsack until capacity is full
    for (int i = 0; i < n; i++) {
        if (items[i].weight <= remaining_capacity) {
            total_value += items[i].value;
            remaining_capacity -= items[i].weight;
        } else {
            total_value += remaining_capacity * ((double) items[i].value / items[i].weight);
            break;
        }
    }
    return total_value;
}

int main() {
    // define example items
    Item item1 = {10, 2};
    Item item2 = {20, 5};
    Item item3 = {30, 10};
    Item item4 = {40, 20};
    Item items[4] = {item1, item2, item3, item4};
    // define example knapsack capacity
    int capacity = 25;
    // solve the knapsack problem using greedy algorithm
    int total_value = knapsack(items, 4, capacity);
    printf("Total value of items in knapsack with capacity %d is %d\n",capacity,total_value);
    return 0;
}