//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_FLOORS 10
#define NUM_ELEVATORS 3

typedef struct {
    int currentFloor;
    int destinationFloor;
    bool isOccupied;
} Elevator;

int main() {
    Elevator elevators[NUM_ELEVATORS];
    int floorRequests[NUM_FLOORS] = {0};
    int time = 0;

    // Initialize elevators
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        elevators[i].currentFloor = 0;
        elevators[i].destinationFloor = 0;
        elevators[i].isOccupied = false;
    }

    while (time < 100) {
        // Update elevator positions
        for (int i = 0; i < NUM_ELEVATORS; i++) {
            if (elevators[i].currentFloor < elevators[i].destinationFloor) {
                elevators[i].currentFloor++;
            } else if (elevators[i].currentFloor > elevators[i].destinationFloor) {
                elevators[i].currentFloor--;
            }

            // If elevator reached its destination, mark as unoccupied
            if (elevators[i].currentFloor == elevators[i].destinationFloor) {
                elevators[i].isOccupied = false;
            }
        }

        // Process floor requests
        for (int i = 0; i < NUM_FLOORS; i++) {
            if (floorRequests[i] > 0) {
                // Find unoccupied elevator closest to the floor
                int closestElevator = -1;
                int closestDistance = NUM_FLOORS;
                for (int j = 0; j < NUM_ELEVATORS; j++) {
                    if (!elevators[j].isOccupied) {
                        int distance = abs(elevators[j].currentFloor - i);
                        if (distance < closestDistance) {
                            closestElevator = j;
                            closestDistance = distance;
                        }
                    }
                }

                // If unoccupied elevator found, assign it to the request
                if (closestElevator != -1) {
                    elevators[closestElevator].destinationFloor = i;
                    elevators[closestElevator].isOccupied = true;
                    floorRequests[i]--;
                }
            }
        }

        // Generate new random floor requests
        for (int i = 0; i < NUM_FLOORS; i++) {
            int randNum = rand() % 10;
            if (randNum == 0) {
                floorRequests[i]++;
            }
        }

        // Print elevator positions
        printf("Time: %d\n", time);
        for (int i = 0; i < NUM_ELEVATORS; i++) {
            printf("Elevator %d: Floor %d\n", i, elevators[i].currentFloor);
        }
        printf("\n");

        // Increment time
        time++;
    }

    return 0;
}