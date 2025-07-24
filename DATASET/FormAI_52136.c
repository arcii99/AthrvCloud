//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FLOORS 10
#define ELEVATORS 2

int elevator_pos[ELEVATORS] = {1, 1}; // Starting position of elevators
int elevator_direction[ELEVATORS] = {1, 1}; // Starting direction of elevators
int elevator_status[ELEVATORS] = {0, 0}; // Starting status of elevators (0 = idle, 1 = moving)
int elevator_target[ELEVATORS] = {0, 0}; // Starting target floor of elevators
int elevator_time[ELEVATORS] = {0, 0}; // Starting time for elevators to reach target floor
int elevator_capacity[ELEVATORS] = {10, 10}; // Starting capacity of elevators 
int elevator_current_capacity[ELEVATORS] = {0, 0}; // Starting current capacity of elevators
int elevator_floor[FLOORS] = {0}; // Starting elevator on each floor
int passenger_floor[FLOORS] = {0}; // Starting passengers on each floor
int passenger_count[FLOORS] = {0}; // Starting passenger count on each floor

// Function: get_random_floor
// Returns: A random floor (between 1 and FLOORS) for a passenger to spawn
int get_random_floor() {
    return rand() % FLOORS + 1;
}

// Function: get_random_destination
// Returns: A random floor (between 1 and FLOORS) for a passenger to go to
int get_random_destination(int current_floor) {
    int destination;
    do {
        destination = rand() % FLOORS + 1;
    } while (destination == current_floor);
    return destination;
}

// Function: spawn_passenger
// Creates a passenger on a random floor with a random destination
void spawn_passenger() {
    int spawn_floor = get_random_floor();
    int destination_floor = get_random_destination(spawn_floor);
    passenger_floor[spawn_floor - 1]++;
    passenger_count[spawn_floor - 1]++;
    printf("New passenger with destination %d spawned on floor %d\n", destination_floor, spawn_floor);
}

// Function: print_building_state
// Prints the state of the building (passenger count on each floor and elevator positions)
void print_building_state() {
    printf("Elevator positions: ");
    for (int i = 0; i < ELEVATORS; i++) {
        printf("%d ", elevator_pos[i]);
    }
    printf("\n");
    for (int i = 0; i < FLOORS; i++) {
        printf("Floor %d: %d passengers\n", i+1, passenger_count[i]);
    }
    printf("\n");
}

// Function: move_elevator
// Moves the specified elevator in the specified direction
void move_elevator(int elevator_num) {
    elevator_pos[elevator_num] += elevator_direction[elevator_num];
    printf("Elevator %d is now on floor %d heading %s\n", elevator_num+1, elevator_pos[elevator_num], elevator_direction[elevator_num] == 1 ? "up" : "down");
}

// Function: open_doors
// Opens the doors of the specified elevator and adds passengers to it
void open_doors(int elevator_num) {
    int floor_num = elevator_pos[elevator_num] - 1;
    printf("Elevator %d opening doors on floor %d\n", elevator_num+1, elevator_pos[elevator_num]);
    int passengers_to_add = elevator_capacity[elevator_num] - elevator_current_capacity[elevator_num];
    if (passengers_to_add > passenger_count[floor_num]) {
        passengers_to_add = passenger_count[floor_num];
    }
    elevator_current_capacity[elevator_num] += passengers_to_add;
    passenger_count[floor_num] -= passengers_to_add;
    printf("%d passengers entered elevator %d at floor %d\n", passengers_to_add, elevator_num+1, elevator_pos[elevator_num]);
}

// Function: close_doors
// Closes the doors of the specified elevator
void close_doors(int elevator_num) {
    printf("Elevator %d closing doors on floor %d\n", elevator_num+1, elevator_pos[elevator_num]);
}

// Function: get_closest_elevator_index
// Returns the index of the elevator closest to the specified floor
int get_closest_elevator_index(int floor_num) {
    int closest_elevator = -1;
    int closest_distance = FLOORS;
    for (int i = 0; i < ELEVATORS; i++) {
        int distance = abs(floor_num - elevator_pos[i]);
        if (distance < closest_distance) {
            closest_distance = distance;
            closest_elevator = i;
        }
    }
    return closest_elevator;
}

int main() {
    srand(time(0));
    printf("Elevator Simulation\n");

    // Main loop
    while (1) {
        // Spawn passengers
        if (rand() % 10 == 0) {
            spawn_passenger();
        }

        // Move elevators
        for (int i = 0; i < ELEVATORS; i++) {
            if (elevator_status[i] == 1) {
                if (elevator_time[i] == 0) {
                    open_doors(i);
                    close_doors(i);
                    if (elevator_current_capacity[i] == elevator_capacity[i]) {
                        elevator_direction[i] *= -1;
                        elevator_target[i] = elevator_pos[i] + elevator_direction[i];
                    }
                    elevator_status[i] = 0;
                } else {
                    move_elevator(i);
                    elevator_time[i]--;
                }
            } else {
                int closest_floor = -1;
                int closest_distance = FLOORS;
                for (int j = 0; j < FLOORS; j++) {
                    if (passenger_floor[j] > 0) {
                        int distance = abs(j - elevator_pos[i]);
                        if (distance < closest_distance) {
                            closest_distance = distance;
                            closest_floor = j;
                        }
                    }
                }
                if (closest_floor != -1) {
                    elevator_target[i] = closest_floor + 1;
                    elevator_direction[i] = elevator_pos[i] < elevator_target[i] ? 1 : -1;
                    elevator_status[i] = 1;
                    elevator_time[i] = abs(elevator_pos[i] - elevator_target[i]) * 2;
                }
            }
        }

        // Check if passengers arrived at their destination
        for (int i = 0; i < ELEVATORS; i++) {
            if (elevator_pos[i] == elevator_target[i] && elevator_status[i] == 1) {
                open_doors(i);
                close_doors(i);
                elevator_target[i] = 0;
                elevator_direction[i] = elevator_direction[i] == 1 ? -1 : 1;
                elevator_status[i] = 0;
            }
        }

        // Update elevator positions
        for (int i = 0; i < ELEVATORS; i++) {
            if (elevator_status[i] == 1) {
                move_elevator(i);
            }
            if (elevator_floor[elevator_pos[i] - 1] != i) {
                elevator_floor[elevator_pos[i] - 1] = i;
            }
        }

        // Print building state
        print_building_state();

        // Wait a second before looping again
        printf("--------------------------------------------------------\n");
        sleep(1);
    }

    return 0;
}