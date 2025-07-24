//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: complete
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VELOCITY 5
#define MAX_ACCELERATION 2

int main() {
    srand(time(NULL));
    
    // Define simulation constants
    const int numLanes = 4;
    const int laneLength = 20;
    const int numCycles = 20;
    
    // Initialize traffic array
    int traffic[numLanes][laneLength];
    
    // Initialize traffic to empty
    for (int i = 0; i < numLanes; i++) {
        for (int j = 0; j < laneLength; j++) {
            traffic[i][j] = 0;
        }
    }
    
    // Initialize traffic at random positions
    for (int i = 0; i < numLanes; i++) {
        for (int j = 0; j < laneLength/2; j++) {
            if (rand() % 2 == 1) {
                traffic[i][j] = rand() % MAX_VELOCITY + 1;
            }
        }
    }
    
    // Run simulation
    for (int i = 0; i < numCycles; i++) {
        // Initialize new traffic array for next cycle
        int nextTraffic[numLanes][laneLength];
        
        // Initialize new traffic to empty
        for (int j = 0; j < numLanes; j++) {
            for (int k = 0; k < laneLength; k++) {
                nextTraffic[j][k] = 0;
            }
        }
        
        // Update each car's position
        for (int j = 0; j < numLanes; j++) {
            for (int k = 0; k < laneLength; k++) {
                if (traffic[j][k] != 0) {
                    int velocity = traffic[j][k];
                    int distanceToNextCar = laneLength - 1;
                    
                    for (int m = k+1; m < laneLength; m++) {
                        if (traffic[j][m] != 0) {
                            distanceToNextCar = m - k;
                            break;
                        }
                    }
                    
                    int acceleration = rand() % MAX_ACCELERATION + 1;
                    
                    if (velocity + acceleration > distanceToNextCar) {
                        velocity = distanceToNextCar;
                    } else {
                        velocity += acceleration;
                    }
                    
                    nextTraffic[j][(k + velocity) % laneLength] = velocity;
                }
            }
        }
        
        // Update traffic array for next cycle
        for (int j = 0; j < numLanes; j++) {
            for (int k = 0; k < laneLength; k++) {
                traffic[j][k] = nextTraffic[j][k];
            }
        }
        
        // Print out current state of traffic
        printf("Cycle %d:\n", i+1);
        
        for (int j = 0; j < numLanes; j++) {
            printf("Lane %d: ", j+1);
            
            for (int k = 0; k < laneLength; k++) {
                if (traffic[j][k] == 0) {
                    printf("-");
                } else {
                    printf("%d", traffic[j][k]);
                }
            }
            
            printf("\n");
        }
        
        printf("\n");
    }
    
    return 0;
}