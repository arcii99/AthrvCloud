//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: invasive
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define NUM_BAGS 100
#define MAX_WEIGHT 50.0

struct Bag {
    int tag;
    float weight;
};

int main() {
    // Initialize random seed
    srand(time(NULL));

    // Create array of bags
    struct Bag bags[NUM_BAGS];

    // Generate tags and weights for bags
    for (int i = 0; i < NUM_BAGS; i++) {
        bags[i].tag = i+1;
        bags[i].weight = ((float)rand()/(float)(RAND_MAX)) * MAX_WEIGHT;
    }

    // Sort bags by weight
    for (int i = 0; i < NUM_BAGS-1; i++) {
        for (int j = i+1; j < NUM_BAGS; j++) {
            if (bags[i].weight < bags[j].weight) {
                struct Bag temp = bags[i];
                bags[i] = bags[j];
                bags[j] = temp;
            }
        }
    }

    // Display bags in order
    printf("Bags according to weight:\n");
    for (int i = 0; i < NUM_BAGS; i++) {
        printf("Tag: %d\tWeight: %.2f kg\n", bags[i].tag, bags[i].weight);
    }

    // Calculate total weight of bags
    float total_weight = 0.0;
    for (int i = 0; i < NUM_BAGS; i++) {
        total_weight += bags[i].weight;
    }

    // Display total weight
    printf("Total weight of bags: %.2f kg\n", total_weight);

    // Check for overweight bags
    bool overweight = false;
    for (int i = 0; i < NUM_BAGS; i++) {
        if (bags[i].weight > MAX_WEIGHT) {
            printf("Bag with tag %d is overweight!\n", bags[i].tag);
            overweight = true;
        }
    }

    // If no overweight bags, display message
    if (!overweight) {
        printf("No overweight bags.\n");
    }

    return 0;
}