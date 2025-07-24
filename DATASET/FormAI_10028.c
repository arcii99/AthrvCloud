//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: configurable
#include <stdio.h>
#include <stdbool.h>

#define NUM_FLOORS 10
#define NUM_ELEVATORS 3

// Struct to represent a person waiting for the elevator
typedef struct {
    int start_floor;
    int end_floor;
} Person;

// Struct to represent an elevator
typedef struct {
    int current_floor;
    int destination_floor;
    bool moving_up;
    bool doors_open;
} Elevator;

// Function to check if there are any people waiting on a given floor
bool is_floor_empty(Person waiting_list[], int floor) {
    for (int i = 0; i < NUM_FLOORS; i++) {
        if (waiting_list[i].start_floor == floor) {
            return false;
        }
    }
    return true;
}

// Function to check if all elevators are at their destination floor
bool all_elevators_at_dest(Elevator elevators[]) {
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        if (elevators[i].current_floor != elevators[i].destination_floor) {
            return false;
        }
    }
    return true;
}

int main() {
    int time = 0; // Simulation time
    Elevator elevators[NUM_ELEVATORS];
    Person waiting_list[NUM_FLOORS];

    // Initialize elevators to first floor
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        elevators[i].current_floor = 1;
        elevators[i].destination_floor = 1;
        elevators[i].moving_up = true;
        elevators[i].doors_open = false;
    }

    // Initialize waiting list
    for (int i = 0; i < NUM_FLOORS; i++) {
        waiting_list[i].start_floor = i + 1;
        waiting_list[i].end_floor = (i + 2) % NUM_FLOORS;
    }

    // Simulation loop
    while (!all_elevators_at_dest(elevators)) {
        printf("Time %d:\n", time);

        // Move elevators
        for (int i = 0; i < NUM_ELEVATORS; i++) {
            if (elevators[i].current_floor == elevators[i].destination_floor) {
                // Open doors
                elevators[i].doors_open = true;
                printf("Elevator %d doors opened at floor %d.\n", i, elevators[i].current_floor);

                // Let people off
                for (int j = 0; j < NUM_FLOORS; j++) {
                    if (waiting_list[j].end_floor == elevators[i].current_floor) {
                        printf("Person exited on floor %d.\n", elevators[i].current_floor);
                        waiting_list[j].start_floor = 0;
                        waiting_list[j].end_floor = 0;
                    }
                }

                // Let people on
                for (int j = 0; j < NUM_FLOORS; j++) {
                    if (!is_floor_empty(waiting_list, elevators[i].current_floor)) {
                        printf("Person entered elevator %d on floor %d.\n", i, elevators[i].current_floor);
                        elevators[i].destination_floor = waiting_list[j].end_floor;
                        elevators[i].doors_open = false;
                    }
                }
            } else {
                // Move elevator
                if (elevators[i].moving_up) {
                    elevators[i].current_floor++;
                } else {
                    elevators[i].current_floor--;
                }
                printf("Elevator %d on floor %d.\n", i, elevators[i].current_floor);
            }

            // Change direction if necessary
            if (elevators[i].current_floor == 1 || elevators[i].current_floor == NUM_FLOORS) {
                elevators[i].moving_up = !elevators[i].moving_up;
            }
        }

        // Wait one second
        time++;
    }

    return 0;
}