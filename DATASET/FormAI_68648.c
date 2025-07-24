//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10
#define MAX_WEIGHT 20

typedef struct Item {
    int value;
    int weight;
} Item;

int compare_items(const void *a, const void *b) {
    Item *item_a = (Item *)a;
    Item *item_b = (Item *)b;

    double ratio_a = (double)item_a->value / (double)item_a->weight;
    double ratio_b = (double)item_b->value / (double)item_b->weight;

    if (ratio_a < ratio_b) {
        return 1;
    } else if (ratio_a > ratio_b) {
        return -1;
    } else {
        return 0;
    }
}

int solve_knapsack_greedy(Item items[], int n, int max_weight) {
    int total_value = 0;
    int current_weight = 0;

    qsort(items, n, sizeof(Item), compare_items);

    for (int i = 0; i < n; i++) {
        if (current_weight + items[i].weight <= max_weight) {
            current_weight += items[i].weight;
            total_value += items[i].value;
        } else {
            int remaining_weight = max_weight - current_weight;
            double fraction = (double)remaining_weight / (double)items[i].weight;
            total_value += (int)(fraction * items[i].value);
            break;
        }
    }

    return total_value;
}

int main() {
    Item items[MAX_ITEMS] = {
        {10, 5},
        {30, 10},
        {20, 5},
        {40, 15},
        {50, 10},
        {15, 8},
        {10, 3},
        {25, 7},
        {35, 11},
        {45, 12}
    };

    int max_weight = MAX_WEIGHT;

    int total_value = solve_knapsack_greedy(items, MAX_ITEMS, max_weight);

    printf("Total value: %d\n", total_value);

    return 0;
}