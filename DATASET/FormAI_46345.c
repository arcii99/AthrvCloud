//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random numbers for traffic flow
int randomNum(int min, int max) {
    int num = (rand() % (max - min + 1)) + min;
    return num;
}

int main() {
    srand(time(NULL));
    
    int roadLength = 30;
    int trafficDensity = randomNum(1, 5);
    int carPositions[roadLength];
    int i, j;
    
    // Initialise road with no cars
    for (i = 0; i < roadLength; i++) {
        carPositions[i] = 0;
    }

    // Randomly add cars to the road based on traffic density
    for (i = 0; i < roadLength; i++) {
        if (randomNum(1, 10) <= trafficDensity) {
            carPositions[i] = 1;
        } else {
            carPositions[i] = 0;
        }
    }

    // Display the initial state of the road
    printf("Initial Traffic Flow\n");
    for (i = 0; i < roadLength; i++) {
        if (carPositions[i] == 1) {
            printf("|[X]");
        } else {
            printf("|---");
        }
    }
    printf("|\n");

    // Simulate traffic flow for 10 time steps
    for (j = 0; j < 10; j++) {
        
        // Move cars forward by 1 position if there is enough space
        for (i = 0; i < roadLength; i++) {
            if (carPositions[i] == 1 && i != roadLength - 1 && carPositions[i+1] == 0) {
                carPositions[i] = 0;
                carPositions[i+1] = 1;
            }
        }

        // Display the state of the road after each time step
        printf("\nTraffic Flow after Time Step %d\n", j+1);
        for (i = 0; i < roadLength; i++) {
            if (carPositions[i] == 1) {
                printf("|[X]");
            } else {
                printf("|---");
            }
        }
        printf("|\n");

        // Randomly add or remove cars from the road
        if (randomNum(1, 10) <= trafficDensity) {
            // Add a car to the road
            int carIndex = randomNum(0, roadLength - 1);
            if (carPositions[carIndex] == 0) {
                carPositions[carIndex] = 1;
            }
        } else {
            // Remove a car from the road
            for (i = 0; i < roadLength; i++) {
                if (carPositions[i] == 1 && randomNum(1, 10) <= trafficDensity) {
                    carPositions[i] = 0;
                    break;
                }
            }
        }
    }

    return 0;
}