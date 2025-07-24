//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 100
#define MAX_PLANES 10

int main() {
    int num_planes, num_bags, i, j;
    int bags[MAX_BAGS], planes[MAX_PLANES];
    
    // Generate random number of planes and bags
    srand(time(0));
    num_planes = rand() % MAX_PLANES + 1;
    num_bags = rand() % (num_planes * 10) + 1;
    
    // Initialize planes and bags
    for (i = 0; i < num_planes; i++) {
        planes[i] = 0;
    }
    for (i = 0; i < num_bags; i++) {
        bags[i] = rand() % MAX_PLANES + 1;
    }
    
    // Print initial state
    printf("Number of planes: %d\n", num_planes);
    printf("Number of bags: %d\n", num_bags);
    printf("Initial state:\n");
    for (i = 0; i < num_bags; i++) {
        printf("Bag %d: Plane %d\n", i+1, bags[i]);
    }
    
    // Sort bags based on their destination plane
    for (i = 0; i < num_planes; i++) {
        for (j = 0; j < num_bags; j++) {
            if (bags[j] == i+1) {
                planes[i]++;
            }
        }
    }
    
    // Print final state
    printf("Final state:\n");
    for (i = 0; i < num_planes; i++) {
        printf("Plane %d has %d bags\n", i+1, planes[i]);
    }
    
    return 0;
}