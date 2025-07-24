//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent an item
struct Item {
    int value;
    int weight;
    float ratio;
};

// Define a comparison function to sort items in descending order of ratio
int compare(const void *a, const void *b) {
    struct Item *item1 = (struct Item*) a;
    struct Item *item2 = (struct Item*) b;
    return item2->ratio - item1->ratio;
}

int main() {
    // Initialize variables
    int capacity, num_items;
    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);
    printf("Enter number of items: ");
    scanf("%d", &num_items);
    struct Item items[num_items];
    float total_value = 0.0;
    int i;

    // Input items and calculate ratio
    for (i = 0; i < num_items; i++) {
        printf("Enter value of item %d: ", i+1);
        scanf("%d", &items[i].value);
        printf("Enter weight of item %d: ", i+1);
        scanf("%d", &items[i].weight);
        items[i].ratio = (float) items[i].value / items[i].weight;
    }

    // Sort items in descending order of ratio
    qsort(items, num_items, sizeof(struct Item), compare);

    // Fill the knapsack with items in a greedy way
    for (i = 0; i < num_items; i++) {
        if (capacity - items[i].weight >= 0) {
            capacity -= items[i].weight;
            total_value += items[i].value;
        } else {
            total_value += capacity * items[i].ratio;
            break;
        }
    }

    // Print the total value of items in the knapsack
    printf("Total value of items in the knapsack: %.2f\n", total_value);

    return 0;
}