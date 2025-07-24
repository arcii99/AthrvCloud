//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEVATORS 8 // maximum number of elevators
#define NUM_FLOORS 20 // number of floors in building

typedef struct { 
    int current_floor; 
    int direction; // 1 indicates going up, -1 indicates going down, 0 indicates stationary
    int status; // 1 indicates available, 0 indicates busy
} Elevator;

int main() {
    Elevator elevators[MAX_ELEVATORS];
    int i, j;

    // initialize elevators
    for (i = 0; i < MAX_ELEVATORS; i++) {
        elevators[i].current_floor = 1;
        elevators[i].direction = 0;
        elevators[i].status = 1;
    }

    while (1) { // infinite loop
        // simulate user requests
        int request_floor = rand() % NUM_FLOORS + 1;
        int request_direction = rand() % 2 * 2 - 1; // randomly select up or down direction
        printf("User at floor %d requests elevator going in direction %d\n", request_floor, request_direction);

        // find closest available elevator
        int min_distance = NUM_FLOORS + 1; // initialize to maximum possible distance
        int min_index = -1;
        for (i = 0; i < MAX_ELEVATORS; i++) {
            if (elevators[i].status == 1) { // check if elevator is available
                int distance = abs(elevators[i].current_floor - request_floor);
                if (distance < min_distance) {
                    min_distance = distance;
                    min_index = i;
                }
            }
        }

        // assign elevator to user request
        if (min_index != -1) { // elevator found
            printf("Elevator %d assigned to user\n", min_index);
            elevators[min_index].status = 0; // set elevator to busy
            if (elevators[min_index].current_floor < request_floor) {
                elevators[min_index].direction = 1;
            } else if (elevators[min_index].current_floor > request_floor) {
                elevators[min_index].direction = -1;
            } // else direction already 0 (stationary)
        } else { // no available elevator found
            printf("No available elevator found\n");
        }

        // simulate elevator movement
        for (i = 0; i < MAX_ELEVATORS; i++) {
            if (elevators[i].status == 0) { // check if elevator is busy
                elevators[i].current_floor += elevators[i].direction;
                printf("Elevator %d moves to floor %d\n", i, elevators[i].current_floor);
                if (elevators[i].current_floor == request_floor) {
                    // user has reached destination
                    printf("User in elevator %d has reached destination at floor %d\n", i, elevators[i].current_floor);
                    elevators[i].status = 1; // set elevator to available
                    elevators[i].direction = 0; // set direction to stationary
                }
            }
        }
    }

    return 0;
}