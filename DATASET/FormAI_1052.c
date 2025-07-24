//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_FLOORS 10
#define MAX_PASSENGERS 5
#define MAX_ELEVATOR_CAPACITY 4

// Struct to represent a passenger
typedef struct {
    int source_floor;
    int destination_floor;
} Passenger;

// Struct to represent an elevator
typedef struct {
    int current_floor;
    int destinations[MAX_PASSENGERS];
    int num_destinations;
} Elevator;

// Function to check if a floor has waiting passengers
bool has_waiting_passengers(int floor, Passenger *passengers, int num_passengers) {
    for (int i = 0; i < num_passengers; i++) {
        if (passengers[i].source_floor == floor) {
            return true;
        }
    }
    return false;
}

// Function to check if an elevator can accept more passengers
bool can_accept_passengers(Elevator *elevator) {
    return (elevator->num_destinations < MAX_ELEVATOR_CAPACITY);
}

// Function to check if an elevator should stop at a floor
bool should_stop_at_floor(Elevator *elevator, int floor) {
    if (elevator->current_floor == floor) {
        return true;
    }
    for (int i = 0; i < elevator->num_destinations; i++) {
        if (elevator->destinations[i] == floor) {
            return true;
        }
    }
    return false;
}

int main() {
    Elevator elevator = {0, {0}, 0};
    Passenger passengers[MAX_PASSENGERS] = {};
    int num_passengers = 0;
    bool going_up = true;

    // Loop through floors
    for (int floor = 0; floor < MAX_FLOORS; floor++) {
        printf("Elevator at floor %d\n", floor);

        // Check if elevator should stop at this floor
        if (should_stop_at_floor(&elevator, floor)) {
            printf("Elevator stopping at floor %d\n", floor);

            // Let off passengers at this floor
            for (int i = 0; i < elevator.num_destinations; i++) {
                if (elevator.destinations[i] == floor) {
                    printf("Passenger exiting at floor %d\n", floor);
                    elevator.destinations[i] = -1;
                }
            }
            elevator.num_destinations = 0;

            // Pick up waiting passengers
            while (has_waiting_passengers(floor, passengers, num_passengers) &&
                can_accept_passengers(&elevator)) {
                for (int i = 0; i < num_passengers; i++) {
                    if (passengers[i].source_floor == floor) {
                        printf("Passenger entering elevator at floor %d\n", floor);
                        elevator.destinations[elevator.num_destinations++] =
                            passengers[i].destination_floor;
                        passengers[i] = passengers[--num_passengers];
                    }
                }
            }
        }

        // Add new passengers to waiting list
        if (rand() % 3 == 0) {
            if (num_passengers < MAX_PASSENGERS) {
                Passenger new_passenger = {floor, rand() % MAX_FLOORS};
                printf("New passenger added at floor %d with destination %d\n",
                    new_passenger.source_floor, new_passenger.destination_floor);
                passengers[num_passengers++] = new_passenger;
            }
        }

        // Move elevator up or down one floor
        if (going_up) {
            elevator.current_floor++;
            if (elevator.current_floor == MAX_FLOORS - 1) {
                going_up = false;
            }
        } else {
            elevator.current_floor--;
            if (elevator.current_floor == 0) {
                going_up = true;
            }
        }
    }

    return 0;
}