//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define NUM_FLOORS 10
#define NUM_ELEVATORS 3

typedef struct {
    int current_floor;
    int target_floor;
    bool doors_open;
    bool going_up;
    int id;
} Elevator;

void print_state(Elevator elevators[]) {
    printf("Elevators: \n");
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        printf("Elevator %d:\n", elevators[i].id);
        printf("\tCurrent floor: %d\n", elevators[i].current_floor);
        printf("\tTarget floor: %d\n", elevators[i].target_floor);
        printf("\tDoors: %s\n", elevators[i].doors_open ? "open" : "closed");
    }
}

void simulate_elevators() {
    // Initialize elevators
    Elevator elevators[NUM_ELEVATORS];
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        elevators[i].current_floor = 1;
        elevators[i].target_floor = 1;
        elevators[i].doors_open = false;
        elevators[i].going_up = true;
        elevators[i].id = i + 1;
    }

    // Main simulation loop
    srand(time(NULL));
    while (true) {
        // Randomly select an elevator to move
        int elevator_index = rand() % NUM_ELEVATORS;
        Elevator* current_elevator = &elevators[elevator_index];

        // Move elevator towards target floor
        if (current_elevator->current_floor < current_elevator->target_floor) {
            current_elevator->current_floor++;
            current_elevator->going_up = true;
        } else if (current_elevator->current_floor > current_elevator->target_floor) {
            current_elevator->current_floor--;
            current_elevator->going_up = false;
        } else {
            // Elevator has reached target floor, open doors
            current_elevator->doors_open = true;
            printf("Elevator %d has arrived at floor %d and opened its doors.\n", current_elevator->id, current_elevator->current_floor);

            // Wait a few seconds before closing the doors
            int wait_time = rand() % 5 + 1;
            printf("Waiting %d seconds...\n", wait_time);
            for (int i = 0; i < wait_time; i++) {
                printf("%d...\n", wait_time - i);
                sleep(1);
            }

            // Close doors and choose a new target floor
            current_elevator->doors_open = false;
            int new_target = rand() % NUM_FLOORS + 1;
            while (new_target == current_elevator->current_floor) {
                new_target = rand() % NUM_FLOORS + 1;
            }
            current_elevator->target_floor = new_target;
            printf("Elevator %d has closed its doors and is now heading to floor %d.\n", current_elevator->id, current_elevator->target_floor);
        }

        // Print state
        print_state(elevators);

        // Sleep for a short time
        sleep(1);
    }
}

int main() {
    simulate_elevators();
    return 0;
}