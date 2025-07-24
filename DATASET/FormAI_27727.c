//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: light-weight
#include <stdio.h>

#define NUM_FLOORS 10      // number of floors in building
#define NUM_ELEVATORS 3    // number of elevators in building

int elevator_positions[NUM_ELEVATORS] = {1, 1, 1}; // array to store each elevator's current floor
int elevator_destinations[NUM_ELEVATORS] = {0, 0, 0}; // array to store each elevator's destination floor

void move_elevators() {
    // check if each elevator has reached its destination floor, and if so, set a new destination floor
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        if (elevator_positions[i] == elevator_destinations[i]) {
            // pick a random destination floor
            int new_floor = rand() % NUM_FLOORS + 1;
            while (new_floor == elevator_positions[i]) {
                new_floor = rand() % NUM_FLOORS + 1;
            }
            elevator_destinations[i] = new_floor;
        }
        // move elevator towards destination floor
        if (elevator_positions[i] < elevator_destinations[i]) {
            elevator_positions[i]++;
        } else if (elevator_positions[i] > elevator_destinations[i]) {
            elevator_positions[i]--;
        }
    }
}

void print_building_state() {
    // print the current state of the building
    printf("Building state:\n");
    for (int i = NUM_FLOORS; i >= 1; i--) {
        printf("%d ", i);
        for (int j = 0; j < NUM_ELEVATORS; j++) {
            if (elevator_positions[j] == i) {
                printf("E");
            } else {
                printf(".");
            }
            printf(" ");
        }
        printf("\n");
    }
    printf("  ");
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        printf("%d ", elevator_positions[i]);
    }
    printf("\n");
}

int main() {
    // seed random number generator
    srand(time(NULL));
    
    // start simulation loop
    for (int i = 0; i < 100; i++) {
        move_elevators();
        print_building_state();
        printf("\n");
    }
    
    return 0;
}