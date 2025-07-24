//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

// The total number of floors in the building
#define FLOORS 10

// The number of elevators in the building
#define ELEVATORS 3

// The time it takes for an elevator to move one floor up or down
#define FLOOR_TRAVEL_TIME 2

// The time it takes for an elevator to open or close its doors
#define DOOR_ACTION_TIME 1

// The maximum number of passengers an elevator can carry
#define MAX_PASSENGERS 6

// Enumeration to represent the direction of an elevator
typedef enum {
    DIRECTION_UP,
    DIRECTION_DOWN,
    DIRECTION_STOP
} direction_t;

// Structure to represent a passenger
typedef struct {
    int start_floor;    // The floor where the passenger will enter the elevator
    int end_floor;      // The floor where the passenger wants to go
} passenger_t;

// Structure to represent an elevator
typedef struct {
    int current_floor;          // The floor where the elevator is currently located
    direction_t current_direction;  // The current direction of the elevator
    passenger_t passengers[MAX_PASSENGERS]; // The passengers currently in the elevator
    int num_passengers;         // The number of passengers currently in the elevator
} elevator_t;

// Array of elevators in the building
elevator_t elevators[ELEVATORS];

// Array to keep track of the passengers waiting on each floor
passenger_t waiting_passengers[FLOORS][MAX_PASSENGERS];
int num_waiting_passengers[FLOORS];

// Function to add a passenger to the waiting list on the given floor
void add_passenger_to_waiting_list(int floor, passenger_t passenger) {
    int index = num_waiting_passengers[floor];
    waiting_passengers[floor][index] = passenger;
    num_waiting_passengers[floor]++;
}

// Function to remove a passenger from the waiting list on the given floor
void remove_passenger_from_waiting_list(int floor, int index) {
    for (int i = index; i < num_waiting_passengers[floor] - 1; i++) {
        waiting_passengers[floor][i] = waiting_passengers[floor][i + 1];
    }
    num_waiting_passengers[floor]--;
}

// Function to add a passenger to the given elevator
void add_passenger_to_elevator(int elevator_index, passenger_t passenger) {
    elevator_t *elevator = &elevators[elevator_index];
    int num_passengers = elevator->num_passengers;
    elevator->passengers[num_passengers] = passenger;
    elevator->num_passengers++;
}

// Function to remove a passenger from the given elevator
void remove_passenger_from_elevator(int elevator_index, int passenger_index) {
    elevator_t *elevator = &elevators[elevator_index];
    for (int i = passenger_index; i < elevator->num_passengers - 1; i++) {
        elevator->passengers[i] = elevator->passengers[i + 1];
    }
    elevator->num_passengers--;
}

// Function to get the next floor that the elevator should travel to
int get_next_floor(elevator_t *elevator) {
    if (elevator->current_direction == DIRECTION_UP) {
        // Check if there are any passengers going up beyond the current floor
        for (int i = elevator->current_floor + 1; i < FLOORS; i++) {
            for (int j = 0; j < num_waiting_passengers[i]; j++) {
                if (waiting_passengers[i][j].start_floor > i) {
                    return i;
                }
            }
            for (int j = 0; j < elevator->num_passengers; j++) {
                if (elevator->passengers[j].end_floor > i) {
                    return i;
                }
            }
        }
        // If there are no passengers going up beyond the current floor, change direction
        elevator->current_direction = DIRECTION_DOWN;
        return elevator->current_floor - 1;
    } else if (elevator->current_direction == DIRECTION_DOWN) {
        // Check if there are any passengers going down beyond the current floor
        for (int i = elevator->current_floor - 1; i >= 0; i--) {
            for (int j = 0; j < num_waiting_passengers[i]; j++) {
                if (waiting_passengers[i][j].start_floor < i) {
                    return i;
                }
            }
            for (int j = 0; j < elevator->num_passengers; j++) {
                if (elevator->passengers[j].end_floor < i) {
                    return i;
                }
            }
        }
        // If there are no passengers going down beyond the current floor, change direction
        elevator->current_direction = DIRECTION_UP;
        return elevator->current_floor + 1;
    } else {
        // If the elevator is stopped, check if there are any passengers on any floor or in any elevator
        // If so, start moving in the appropriate direction
        for (int i = 0; i < FLOORS; i++) {
            if (num_waiting_passengers[i] > 0) {
                if (i > elevator->current_floor) {
                    elevator->current_direction = DIRECTION_UP;
                    return i;
                } else if (i < elevator->current_floor) {
                    elevator->current_direction = DIRECTION_DOWN;
                    return i;
                }
            }
        }
        for (int i = 0; i < ELEVATORS; i++) {
            if (i != elevator - elevators) {
                elevator_t *other_elevator = &elevators[i];
                if (other_elevator->num_passengers > 0) {
                    if (other_elevator->current_floor > elevator->current_floor) {
                        elevator->current_direction = DIRECTION_UP;
                        return other_elevator->current_floor;
                    } else if (other_elevator->current_floor < elevator->current_floor) {
                        elevator->current_direction = DIRECTION_DOWN;
                        return other_elevator->current_floor;
                    }
                }
            }
        }
        // If there are no passengers on any floor or in any elevator, stay stopped
        return elevator->current_floor;
    }
}

// Function to simulate the movement of the elevators
void simulate_elevators() {
    while (true) {
        // Move each elevator to its next floor
        for (int i = 0; i < ELEVATORS; i++) {
            elevator_t *elevator = &elevators[i];
            int next_floor = get_next_floor(elevator);
            if (next_floor != elevator->current_floor) {
                printf("Elevator %d: Moving %s to floor %d\n", i, elevator->current_direction == DIRECTION_UP ? "up" : "down", next_floor);
                sleep(FLOOR_TRAVEL_TIME);
                elevator->current_floor = next_floor;
            }
            // Open the doors if there are passengers that need to get off or on
            bool doors_open = false;
            for (int j = 0; j < elevator->num_passengers; j++) {
                if (elevator->passengers[j].end_floor == elevator->current_floor) {
                    printf("Elevator %d: Opening doors\n", i);
                    doors_open = true;
                    sleep(DOOR_ACTION_TIME);
                    printf("Elevator %d: Passenger %d getting off the elevator on floor %d\n", i, j, elevator->current_floor);
                    remove_passenger_from_elevator(i, j);
                    j--;
                }
            }
            for (int j = 0; j < num_waiting_passengers[elevator->current_floor]; j++) {
                if (elevator->num_passengers < MAX_PASSENGERS) {
                    printf("Elevator %d: Opening doors\n", i);
                    doors_open = true;
                    sleep(DOOR_ACTION_TIME);
                    printf("Elevator %d: Passenger %d getting on the elevator on floor %d\n", i, j, elevator->current_floor);
                    add_passenger_to_elevator(i, waiting_passengers[elevator->current_floor][j]);
                    remove_passenger_from_waiting_list(elevator->current_floor, j);
                    j--;
                }
            }
            if (doors_open) {
                // Close the doors if they were opened
                sleep(DOOR_ACTION_TIME);
                printf("Elevator %d: Closing doors\n", i);
            }
        }
    }
}

// Main function to start the program
int main() {
    // Initialize the elevators to the ground floor
    for (int i = 0; i < ELEVATORS; i++) {
        elevators[i].current_floor = 0;
        elevators[i].current_direction = DIRECTION_STOP;
        elevators[i].num_passengers = 0;
    }
    // Add some sample passengers
    add_passenger_to_waiting_list(2, (passenger_t) {.start_floor = 2, .end_floor = 7});
    add_passenger_to_waiting_list(4, (passenger_t) {.start_floor = 4, .end_floor = 1});
    add_passenger_to_waiting_list(8, (passenger_t) {.start_floor = 8, .end_floor = 5});
    // Start simulating the elevators
    simulate_elevators();
    return 0;
}