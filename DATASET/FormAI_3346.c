//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_BAGS 100
#define MAX_WEIGHT 50

typedef struct {
    int id;
    int weight;
} Bag;

int main(void) {
    // Initialize random number generator with current time
    srand(time(NULL));
    
    // Create an array of bags
    Bag bags[NUM_BAGS];
    
    // Fill in each bag's id and weight with random values
    for (int i = 0; i < NUM_BAGS; i++) {
        bags[i].id = i;
        bags[i].weight = rand() % MAX_WEIGHT + 1; // Random number between 1 and MAX_WEIGHT
    }
    
    // Print out each bag's id and weight
    printf("Bags:\n");
    for (int i = 0; i < NUM_BAGS; i++) {
        printf("%d - %d kg\n", bags[i].id, bags[i].weight);
    }
    
    // Simulate the baggage handling process
    int total_weight = 0;
    int heavy_bags = 0;
    int damaged_bags = 0;
    
    // Loop through each bag
    for (int i = 0; i < NUM_BAGS; i++) {
        // Add the bag's weight to the total weight
        total_weight += bags[i].weight;
        
        // Check if the bag is too heavy (over 30 kg)
        if (bags[i].weight > 30) {
            printf("Bag %d is too heavy! It weighs %d kg.\n", bags[i].id, bags[i].weight);
            heavy_bags++;
        }
        
        // Check if the bag is damaged (10% chance)
        int damage_chance = rand() % 10; // Random number between 0 and 9
        if (damage_chance == 0) {
            printf("Bag %d has been damaged!\n", bags[i].id);
            damaged_bags++;
        }
    }
    
    // Print out the baggage handling statistics
    printf("Total weight of bags: %d kg\n", total_weight);
    printf("Number of bags over 30 kg: %d\n", heavy_bags);
    printf("Number of damaged bags: %d\n", damaged_bags);
    
    return 0;
}