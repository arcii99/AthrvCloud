//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: standalone
#include <stdio.h>

// Constants
#define NUM_FLOORS 5
#define NUM_ELEVATORS 3
#define MAX_OCCUPANCY 10
#define TIME_BETWEEN_FLOORS 2

// Elevator struct
typedef struct Elevator {
    int currentFloor;
    int numberOfPassengers;
    int passengerDestinations[MAX_OCCUPANCY];
} Elevator;

// Function to move elevator to target floor
void moveElevator(Elevator* elevator, int targetFloor) {
    printf("Elevator moving from floor %d to floor %d\n", elevator->currentFloor, targetFloor);
    elevator->currentFloor = targetFloor;
}

int main() {
    // Initialize elevators
    Elevator elevators[NUM_ELEVATORS];
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        elevators[i].currentFloor = 1;
        elevators[i].numberOfPassengers = 0;
    }

    // Initialize floors
    int floors[NUM_FLOORS];
    for (int i = 0; i < NUM_FLOORS; i++) {
        floors[i] = 0;
    }

    // Loop until user quits
    int quit = 0;
    while (!quit) {
        // Print current status
        printf("\n\n==============================\n");
        printf("Elevator Simulation:\n");
        printf("==============================\n");
        printf("Elevators:\n");
        for (int i = 0; i < NUM_ELEVATORS; i++) {
            printf("Elevator %d is on floor %d with %d passengers\n", i+1, elevators[i].currentFloor, elevators[i].numberOfPassengers);
        }
        printf("Floors:\n");
        for (int i = 0; i < NUM_FLOORS; i++) {
            printf("Floor %d has %d waiting passengers\n", i+1, floors[i]);
        }

        // Get user input
        printf("\n\nEnter command (q to quit, u/d # to add passenger to floor, e # # to move elevator): ");
        char command;
        int arg1, arg2;
        scanf(" %c", &command);
        switch (command) {
            case 'q':
                quit = 1;
                break;
            case 'u':
                scanf(" %d", &arg1);
                floors[arg1-1]++;
                printf("Added passenger to floor %d\n", arg1);
                break;
            case 'd':
                scanf(" %d", &arg1);
                floors[arg1-1]--;
                printf("Removed passenger from floor %d\n", arg1);
                break;
            case 'e':
                scanf(" %d %d", &arg1, &arg2);
                if (arg1 < 1 || arg1 > NUM_ELEVATORS) {
                    printf("ERROR: Invalid elevator number\n");
                }
                else if (arg2 < 1 || arg2 > NUM_FLOORS) {
                    printf("ERROR: Invalid floor number\n");
                }
                else {
                    moveElevator(&elevators[arg1-1], arg2);
                }
                break;
            default:
                printf("ERROR: Unknown command\n");
                break;
        }

        // Move elevators
        for (int i = 0; i < NUM_ELEVATORS; i++) {
            // If elevator is empty, go to highest demand floor
            if (elevators[i].numberOfPassengers == 0) {
                int highestDemandFloor = 0;
                int highestDemandCount = 0;
                for (int j = 0; j < NUM_FLOORS; j++) {
                    if (floors[j] > highestDemandCount) {
                        highestDemandFloor = j+1;
                        highestDemandCount = floors[j];
                    }
                }
                moveElevator(&elevators[i], highestDemandFloor);
            }
            else {
                // If elevator has passengers, go to first passenger destination
                moveElevator(&elevators[i], elevators[i].passengerDestinations[0]);
                // Remove passengers who have arrived at their destination
                for (int j = 0; j < elevators[i].numberOfPassengers; j++) {
                    if (elevators[i].passengerDestinations[j] == elevators[i].currentFloor) {
                        elevators[i].numberOfPassengers--;
                        // Shift all remaining passengers down
                        for (int k = j; k < elevators[i].numberOfPassengers; k++) {
                            elevators[i].passengerDestinations[k] = elevators[i].passengerDestinations[k+1];
                        }
                    }
                }
                // Fill empty seats with passengers waiting on current floor
                while (elevators[i].numberOfPassengers < MAX_OCCUPANCY && floors[elevators[i].currentFloor-1] > 0) {
                    floors[elevators[i].currentFloor-1]--;
                    elevators[i].passengerDestinations[elevators[i].numberOfPassengers] = elevators[i].currentFloor + 1;
                    elevators[i].numberOfPassengers++;
                }
            }
        }

        // Pause for set amount of time between floors
        printf("\n\n");
        for (int i = 0; i < TIME_BETWEEN_FLOORS; i++) {
            printf("%d second(s) until next update...\n", TIME_BETWEEN_FLOORS-i);
            sleep(1);
        }
    }

    // Exit program
    return 0;
}