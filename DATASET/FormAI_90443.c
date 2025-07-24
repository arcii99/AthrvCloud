//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROAD_LENGTH 10
#define NUM_SIMULATIONS 100000
#define MAX_SPEED 3

int main() {
    int traffic[ROAD_LENGTH] = {0}; // Initialize empty road
    int flow_count = 0;
    srand(time(NULL)); // Set random seed
    
    for (int i=0; i<NUM_SIMULATIONS; i++) {
        // Initialize car at beginning of road
        traffic[0] = rand() % MAX_SPEED + 1;
        
        // Iterate through each position on road (except last)
        for (int j=0; j<ROAD_LENGTH-1; j++) {
            // If car is stationary, skip this position
            if (traffic[j] == 0) {
                continue;
            }
            
            // Determine available space to move forward
            int space = 0;
            for (int k=j+1; k<ROAD_LENGTH; k++) {
                if (traffic[k] == 0) {
                    space++;
                } else {
                    break;
                }
            }
            
            // Determine desired speed of car
            int speed = traffic[j];
            if (speed > space) {
                speed = space; // Reduce speed to fit available space
            }
            if (speed > MAX_SPEED) {
                speed = MAX_SPEED; // Enforce maximum speed limit
            }
            
            // Move car forward
            traffic[j+speed] = traffic[j];
            traffic[j] = 0;
        }
        
        // Check if car has made it to the end of the road
        if (traffic[ROAD_LENGTH-1] > 0) {
            flow_count++;
        }
        
        // Reset road for next simulation
        for (int l=0; l<ROAD_LENGTH; l++) {
            traffic[l] = 0;
        }
    }
    
    // Calculate and print traffic flow rate
    float flow_rate = (float) flow_count / NUM_SIMULATIONS * 100.0;
    printf("Traffic flow rate: %.2f%%\n", flow_rate);
    
    return 0;
}