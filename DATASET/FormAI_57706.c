//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

// Define our struct to hold items and their values
typedef struct {
    int weight;
    int value;
} Item;

// The function for our greedy algorithm
void greedyKnapsack(Item items[], int n, int capacity) {
    // Sort items by value per unit weight
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            double vpw1 = (double) items[i].value / items[i].weight;
            double vpw2 = (double) items[j].value / items[j].weight;
            if (vpw2 > vpw1) {
                Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }

    int i = 0;
    double totalValue = 0;
    // Keep adding items while we have capacity
    while (capacity > 0 && i < n) {
        if (items[i].weight <= capacity) {
            capacity -= items[i].weight;
            totalValue += items[i].value;
        } else {
            // We can only take a fraction of the last item
            double fraction = (double) capacity / items[i].weight;
            totalValue += items[i].value * fraction;
            capacity = 0;
        }
        i++;
    }

    // Print the total value of items taken
    printf("Total value of items taken: %.2f\n", totalValue);
}

int main() {
    // Generate some random items for our knapsack
    int n = 10;
    Item items[n];
    for (int i = 0; i < n; i++) {
        items[i].weight = rand() % 10 + 1;
        items[i].value = rand() % 100 + 1;
    }

    // Print out the items and their values
    printf("Items:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d - Weight: %d, Value: %d\n", i + 1, items[i].weight, items[i].value);
    }

    // Run our greedy algorithm
    int capacity = 20;
    greedyKnapsack(items, n, capacity);

    return 0;
}