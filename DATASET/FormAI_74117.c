//FormAI DATASET v1.0 Category: Image Classification system ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_CLASSES 3
#define NUM_FEATURES 5

int main() {
    // Initialize data
    int features[NUM_CLASSES][NUM_FEATURES] = { 
        {15, 20, 5, 10, 7},
        {10, 6, 18, 12, 3},
        {5, 3, 8, 4, 20},
    };
    char labels[NUM_CLASSES][10] = { "Archer", "Swordsman", "Knight" };
    int unknown_features[NUM_FEATURES];
    
    // Prompt user for input
    printf("Enter attributes for an unknown medieval character (separated by spaces):\n");
    for (int i = 0; i < NUM_FEATURES; i++) {
        scanf("%d", &unknown_features[i]);
    }
    
    // Calculate distances from unknown character to each class
    double distances[NUM_CLASSES];
    for (int c = 0; c < NUM_CLASSES; c++) {
        double total = 0;
        for (int f = 0; f < NUM_FEATURES; f++) {
            int difference = features[c][f] - unknown_features[f];
            total += difference * difference;
        }
        distances[c] = sqrt(total);
    }
    
    // Determine closest class
    int min_index = 0;
    for (int i = 1; i < NUM_CLASSES; i++) {
        if (distances[i] < distances[min_index]) {
            min_index = i;
        }
    }
    
    // Output result
    printf("The unknown character is most likely a %s.\n", labels[min_index]);
    
    return 0;
}