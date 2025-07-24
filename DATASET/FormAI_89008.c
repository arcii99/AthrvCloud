//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define ELEVATOR_CAPACITY 5 // Number of passengers elevator can hold
#define NUM_FLOORS 10 // Number of floors in building
#define ELEVATOR_SPEED 3 // Number of seconds it takes elevator to move between floors

// Struct to represent elevator
struct Elevator {
    int current_floor;
    int num_passengers;
    int passengers[ELEVATOR_CAPACITY];
    int direction;
};

// Function to move elevator up or down
void move_elevator(struct Elevator* elevator, int destination_floor) {
    int i;
    int start_floor = elevator->current_floor;
    
    // Move the elevator up
    if (destination_floor > start_floor) {
        printf("Elevator moving up from floor %d to floor %d...\n", start_floor, destination_floor);
        elevator->direction = 1;
        for (i = start_floor + 1; i <= destination_floor; i++) {
            printf("Elevator is at floor %d\n", i);
            elevator->current_floor = i;
            sleep(ELEVATOR_SPEED);
        }
    }
    // Move the elevator down
    else if (destination_floor < start_floor) {
        printf("Elevator moving down from floor %d to floor %d...\n", start_floor, destination_floor);
        elevator->direction = -1;
        for (i = start_floor - 1; i >= destination_floor; i--) {
            printf("Elevator is at floor %d\n", i);
            elevator->current_floor = i;
            sleep(ELEVATOR_SPEED);
        }
    }
    // Don't move if already at destination floor
    else {
        elevator->direction = 0;
        printf("Elevator is already at floor %d\n", destination_floor);
    }
}

// Function to add passenger to elevator
void add_passenger(struct Elevator* elevator, int passenger_id) {
    if (elevator->num_passengers < ELEVATOR_CAPACITY) {
        elevator->passengers[elevator->num_passengers] = passenger_id;
        elevator->num_passengers++;
        printf("Passenger %d added to elevator\n", passenger_id);
    }
    else {
        printf("Elevator is full\n");
    }
}

// Function to remove passenger from elevator
void remove_passenger(struct Elevator* elevator, int passenger_id) {
    int i;
    for (i = 0; i < elevator->num_passengers; i++) {
        if (elevator->passengers[i] == passenger_id) {
            elevator->passengers[i] = 0;
            elevator->num_passengers--;
            printf("Passenger %d removed from elevator\n", passenger_id);
            return;
        }
    }
}

int main() {
    int i, j;
    struct Elevator elevator;
    elevator.current_floor = 0;
    elevator.num_passengers = 0;
    elevator.direction = 0;
    
    // Simulate passengers arriving at building
    for (i = 0; i < NUM_FLOORS; i++) {
        int num_passengers = rand() % 5;
        for (j = 0; j < num_passengers; j++) {
            int passenger_id = rand() % 100 + i * 100; // Generate a unique ID for each passenger
            printf("Passenger %d has arrived on floor %d\n", passenger_id, i);
        }
    }
    
    // Simulate elevator running for 10 cycles
    for (i = 0; i < 10; i++) {
        int destination_floor = rand() % NUM_FLOORS;
        printf("Elevator called to floor %d\n", destination_floor);
        move_elevator(&elevator, destination_floor);
        for (j = 0; j < ELEVATOR_CAPACITY; j++) {
            if (elevator.passengers[j] != 0) {
                printf("Passenger %d is exiting the elevator on floor %d\n", elevator.passengers[j], elevator.current_floor);
                remove_passenger(&elevator, elevator.passengers[j]);
            }
        }
        for (j = 0; j < NUM_FLOORS; j++) {
            int num_passengers = rand() % 5;
            for (int k = 0; k < num_passengers; k++) {
                int passenger_id = rand() % 100 + j * 100;
                printf("Passenger %d is waiting on floor %d\n", passenger_id, j);
                add_passenger(&elevator, passenger_id);
            }
        }
    }
    
    return 0;
}