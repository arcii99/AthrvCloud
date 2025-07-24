//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: funny
#include <stdio.h>
#define NUM_OF_FLOORS 10
#define NUM_OF_ELEVATORS 3

int main()
{
    // The following code generates some random floor requests
    int floor_requests[NUM_OF_FLOORS] = {0};
    for(int i=0; i<NUM_OF_FLOORS; i++) {
        floor_requests[i] = rand() % 2;
    }

    // The following code simulates the elevators
    int elevator_positions[NUM_OF_ELEVATORS] = {0};
    printf("Welcome to the Funny Elevator Simulator!\n");

    for(int tick=0; tick<100; tick++) {
        // Update the elevator positions
        for(int i=0; i<NUM_OF_ELEVATORS; i++) {
            elevator_positions[i] += rand() % 3 - 1;
            if(elevator_positions[i] < 0) elevator_positions[i] = 0;
            if(elevator_positions[i] >= NUM_OF_FLOORS) elevator_positions[i] = NUM_OF_FLOORS - 1;
        }

        // Check if any elevators should stop at a floor
        for(int i=0; i<NUM_OF_ELEVATORS; i++) {
            if(floor_requests[elevator_positions[i]] == 1) {
                printf("Elevator %d stopping at floor %d\n", i+1, elevator_positions[i]+1);
                floor_requests[elevator_positions[i]] = 0;
            }
        }

        // Print the status of the elevators
        for(int i=0; i<NUM_OF_ELEVATORS; i++) {
            printf("Elevator %d is at floor %d\n", i+1, elevator_positions[i]+1);
        }
        printf("\n");

        // Wait for some time before the next tick
        sleep(1);
    }

    return 0;
}