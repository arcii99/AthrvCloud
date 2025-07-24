//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_ITEMS 20

int main() {

    // Initialize seed for random number generator
    srand(time(NULL));

    // Generate random item weights and values
    int weights[MAX_ITEMS];
    int values[MAX_ITEMS];
    for (int i = 0; i < MAX_ITEMS; i++) {
        weights[i] = rand() % 10 + 1;
        values[i] = rand() % 20 + 1;
    }

    // Print out generated items
    printf("Generated Items:\n");
    printf("Item\tWeight\tValue\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        printf("%d\t%d\t%d\n", i+1, weights[i], values[i]);
    }
    printf("\n");

    // Set maximum weight and initialize total weight and value to 0
    int maxWeight = 40;
    int totalWeight = 0;
    int totalValue = 0;

    // Greedy algorithm to choose items
    bool chosen[MAX_ITEMS] = {false};
    while (totalWeight < maxWeight) {
        int maxIndex = -1;
        double maxValuePerWeight = 0;
        for (int i = 0; i < MAX_ITEMS; i++) {
            double valuePerWeight = (double) values[i] / weights[i];
            if (!chosen[i] && valuePerWeight > maxValuePerWeight) {
                maxValuePerWeight = valuePerWeight;
                maxIndex = i;
            }
        }
        if (maxIndex == -1) {
            break;
        }
        chosen[maxIndex] = true;
        totalWeight += weights[maxIndex];
        totalValue += values[maxIndex];
    }

    // Print out chosen items and total value
    printf("Chosen Items:\n");
    printf("Item\tWeight\tValue\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (chosen[i]) {
            printf("%d\t%d\t%d\n", i+1, weights[i], values[i]);
        }
    }
    printf("Total Weight: %d\n", totalWeight);
    printf("Total Value: %d\n", totalValue);

    return 0;
}