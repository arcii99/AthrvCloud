//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define NUM_FLOORS 10 // Number of floors in the building
#define NUM_ELEVATORS 3 // Number of elevators in the building

typedef struct {
    int destFloor; // Destination floor of the elevator
    int currFloor; // Current floor of the elevator
    int isMoving; // 1 if elevator is moving, 0 otherwise
    int numRiders; // Number of riders currently in the elevator
} Elevator;

Elevator elevators[NUM_ELEVATORS]; // Array of elevators in the building

// Function to update the state of an elevator
void updateElevator(int e) {
    if (elevators[e].isMoving) {
        // Check if elevator has reached its destination
        if (elevators[e].currFloor == elevators[e].destFloor) {
            elevators[e].isMoving = 0;
            printf("Elevator %d has reached floor %d\n", e, elevators[e].currFloor);
        } else {
            // Move elevator towards destination floor
            if (elevators[e].currFloor < elevators[e].destFloor) {
                elevators[e].currFloor++;
            } else {
                elevators[e].currFloor--;
            }
            printf("Elevator %d is moving to floor %d\n", e, elevators[e].currFloor);
        }
    } else {
        printf("Elevator %d is idle\n", e);
    }
}

int main() {
    // Initialize elevators
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        elevators[i].destFloor = 1;
        elevators[i].currFloor = 1;
        elevators[i].isMoving = 0;
        elevators[i].numRiders = 0;
    }

    int numRequests = 0; // Number of elevator requests
    int requests[NUM_FLOORS]; // Array of elevator requests on each floor
    for (int i = 0; i < NUM_FLOORS; i++) {
        requests[i] = 0;
    }

    // Main loop of the simulation
    while (1) {
        // Check for new elevator requests
        int newRequests = 0;
        for (int i = 0; i < NUM_FLOORS; i++) {
            if (rand() % 2 == 1) {
                requests[i]++;
                numRequests++;
                newRequests++;
                printf("Elevator request on floor %d\n", i+1);
            }
        }

        // If there are new requests, assign elevators to handle them
        if (newRequests > 0) {
            // Choose the elevator with the least number of riders to handle the request
            int minRiders = NUM_FLOORS + 1;
            int selectedElevator = -1;
            for (int i = 0; i < NUM_ELEVATORS; i++) {
                if (!elevators[i].isMoving) {
                    if (elevators[i].numRiders < minRiders) {
                        selectedElevator = i;
                        minRiders = elevators[i].numRiders;
                    }
                }
            }

            // Update the selected elevator with the new request
            elevators[selectedElevator].destFloor = -1; // Set destination floor to unknown
            for (int i = 0; i < NUM_FLOORS; i++) {
                if (requests[i] > 0) {
                    elevators[selectedElevator].destFloor = i+1;
                    requests[i]--;
                    break;
                }
            }
            elevators[selectedElevator].isMoving = 1;
            printf("Elevator %d assigned to handle request\n", selectedElevator);
        }

        // Update the state of all elevators
        for (int i = 0; i < NUM_ELEVATORS; i++) {
            updateElevator(i);
        }

        // Check if all requests have been handled
        if (numRequests == 0) {
            break;
        }

        // Wait for some time before checking for new elevator requests
        printf("Waiting for elevator requests...\n");
        sleep(3);
    }

    return 0;
}