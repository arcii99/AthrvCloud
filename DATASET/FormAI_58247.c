//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARR_SIZE 20 // Define size of array for road simulation

int main() {
    srand(time(NULL)); // Seed random number generator
    
    int road[ARR_SIZE]; // Initialize array to represent road
    
    // Fill array with randomly generated values to represent traffic flow
    for(int i=0;i<ARR_SIZE;i++) {
        road[i] = rand() % 2;
    }
    
    // Simulate traffic flow
    for(int i=0;i<ARR_SIZE;i++) {
        printf("%d ", road[i]); // Display current traffic flow
        if(road[i] == 1) { // If traffic is flowing
            if(i == ARR_SIZE-1) { // If at end of road
                road[i] = 0; // Stop traffic flow
            }
            else if(road[i+1] == 0) { // If next space is open for traffic flow
                road[i] = 0; // Stop traffic flow
                road[i+1] = 1; // Move traffic flow to next space
            }
        }
    }
    
    return 0;
}