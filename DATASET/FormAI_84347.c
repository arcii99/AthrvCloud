//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: modular
#include <stdio.h>

// Define constants for the elevator simulation
#define ELEVATOR_FLOORS 10
#define ELEVATOR_CAPACITY 10

// Elevator struct to keep track of floor and passengers
struct Elevator {
    int capacity;
    int current_floor;
    int passengers;
};

// Function to move the elevator to a specified floor
void move_elevator(struct Elevator *elevator, int floor) {
    printf("Moving elevator from floor %d to floor %d\n", elevator->current_floor, floor);
    elevator->current_floor = floor;
}

// Function to add a passenger to the elevator
void add_passenger(struct Elevator *elevator) {
    if (elevator->passengers < elevator->capacity) {
        elevator->passengers++;
        printf("Passenger added to elevator\n");
    } else {
        printf("Elevator is at capacity\n");
    }
}

int main() {
    // Initialize the elevator
    struct Elevator elevator = {
        .capacity = ELEVATOR_CAPACITY,
        .current_floor = 1,
        .passengers = 0
    };
    
    // Simulate someone calling the elevator to the 4th floor
    int destination_floor = 4;
    move_elevator(&elevator, destination_floor);

    // Simulate passengers entering the elevator
    add_passenger(&elevator);
    add_passenger(&elevator);

    // Simulate moving the elevator to the 7th floor
    destination_floor = 7;
    move_elevator(&elevator, destination_floor);

    // Simulate more passengers entering the elevator
    add_passenger(&elevator);
    add_passenger(&elevator);
    add_passenger(&elevator);

    // Simulate moving the elevator to the top floor
    destination_floor = ELEVATOR_FLOORS;
    move_elevator(&elevator, destination_floor);

    // Simulate passengers exiting the elevator
    elevator.passengers = 0;
    printf("All passengers have exited the elevator\n");

    return 0;
}