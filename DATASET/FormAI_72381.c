//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: curious
#include <stdio.h>

int main() {
    printf("Welcome to the curious world of greedy algorithms!\n");

    // Let's say we have a set of weights for different items
    int weights[] = {10, 20, 5, 15, 25};
    int n = sizeof(weights) / sizeof(weights[0]);

    // And we also have a knapsack with a maximum capacity
    int max_capacity = 30;

    // Our goal is to find the maximum weight we can fit into the knapsack
    int current_weight = 0;
    int i = 0;
    while (current_weight < max_capacity && i < n) {
        // We'll select the item with the highest weight available
        int max_weight_index = -1;
        int max_weight = -1;
        for (int j = 0; j < n; j++) {
            if (weights[j] > max_weight && weights[j] <= max_capacity - current_weight) {
                max_weight_index = j;
                max_weight = weights[j];
            }
        }

        if (max_weight_index == -1) {
            // If we can't fit any more items in the knapsack, we break out of the loop
            break;
        } else {
            // Otherwise, we add the item to the knapsack
            current_weight += max_weight;
            printf("Added item %d with weight %d to the knapsack. Current weight: %d\n", max_weight_index + 1, max_weight, current_weight);
            
            // And remove it from our list of available items
            weights[max_weight_index] = -1;
        }

        i++;
    }

    printf("\nMaximum weight in the knapsack: %d\n", current_weight);

    return 0;
}