//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: scalable
#include <stdio.h>

// define struct to hold item information
struct Item {
    int value;
    int weight;
};

// define function to compare items based on value per unit weight
int compare_items(const void* a, const void* b) {
    struct Item* item_a = (struct Item*)a;
    struct Item* item_b = (struct Item*)b;
    double ratio_a = (double)item_a->value / item_a->weight;
    double ratio_b = (double)item_b->value / item_b->weight;
    if (ratio_a > ratio_b) {
        return -1;
    }
    else if (ratio_a < ratio_b) {
        return 1;
    }
    else {
        return 0;
    }
}

// define function to implement greedy algorithm
double knapsack_greedy(struct Item* items, int num_items, int capacity) {
    // sort items in descending order by value per unit weight
    qsort(items, num_items, sizeof(struct Item), compare_items);
    
    // initialize variables for total value and weight
    double total_value = 0;
    double total_weight = 0;
    
    // select items until capacity is reached
    for (int i = 0; i < num_items && total_weight <= capacity; i++) {
        struct Item item = items[i];
        if (total_weight + item.weight <= capacity) {
            total_value += item.value;
            total_weight += item.weight;
        }
        else {
            double remaining_weight = capacity - total_weight;
            double fraction = remaining_weight / item.weight;
            total_value += fraction * item.value;
            total_weight += fraction * item.weight;
        }
    }
    
    // return total value of selected items
    return total_value;
}

int main() {
    // initialize array of items
    struct Item items[] = {
        {60, 10},
        {120, 30},
        {100, 20},
        {80, 15},
        {200, 40},
        {160, 35},
    };
    int num_items = sizeof(items) / sizeof(struct Item);
    
    // initialize capacity of knapsack
    int capacity = 100;
    
    // implement greedy algorithm and print result
    double total_value = knapsack_greedy(items, num_items, capacity);
    printf("Total value of items selected: %lf", total_value);
    
    return 0;
}