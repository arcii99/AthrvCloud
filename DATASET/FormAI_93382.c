//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

struct Item {
    int weight;
    int value;
};

struct Knapsack {
    int capacity;
    int num_items;
    struct Item items[MAX_ITEMS];
};

int compare_items(const void* a, const void* b) {
    struct Item* item_a = (struct Item*)a;
    struct Item* item_b = (struct Item*)b;
    double ratio_a = (double)item_a->value / item_a->weight;
    double ratio_b = (double)item_b->value / item_b->weight;
    if (ratio_a > ratio_b) {
        return -1;
    } else if (ratio_a < ratio_b) {
        return 1;
    } else {
        return 0;
    }
}

void print_item(struct Item item) {
    printf("Weight: %d | Value: %d\n", item.weight, item.value);
}

int main() {
    struct Knapsack knapsack = {25, 8, {
        {10, 60},
        {20, 100},
        {5, 30},
        {15, 80},
        {25, 120},
        {15, 90},
        {10, 40},
        {30, 200}
    }};
    
    printf("Knapsack Capacity: %d\n\n", knapsack.capacity);
    printf("Items before sorting by value/weight ratio:\n");
    for (int i = 0; i < knapsack.num_items; i++) {
        print_item(knapsack.items[i]);
    }
    printf("\n");
    
    qsort(knapsack.items, knapsack.num_items, sizeof(struct Item), compare_items);
    
    printf("Items after sorting by value/weight ratio:\n");
    for (int i = 0; i < knapsack.num_items; i++) {
        print_item(knapsack.items[i]);
    }
    printf("\n");
    
    int current_weight = 0;
    int current_value = 0;
    printf("Items added to knapsack:\n");
    for (int i = 0; i < knapsack.num_items && current_weight < knapsack.capacity; i++) {
        if (current_weight + knapsack.items[i].weight <= knapsack.capacity) {
            print_item(knapsack.items[i]);
            current_weight += knapsack.items[i].weight;
            current_value += knapsack.items[i].value;
        }
    }
    printf("Total weight in knapsack: %d\n", current_weight);
    printf("Total value in knapsack: %d\n", current_value);
    
    return 0;
}