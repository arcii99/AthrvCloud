//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

#define NUM_FLOORS 5
#define NUM_ELEVATORS 2

// Define the struct for the elevator
typedef struct {
    int floor;
    int direction;
    int num_riders;
} Elevator;

// Function to initialize an elevator
Elevator init_elevator(int floor, int direction, int num_riders) {
    Elevator elevator;
    elevator.floor = floor;
    elevator.direction = direction;
    elevator.num_riders = num_riders;
    return elevator;
}

// Function to print the elevator status
void print_elevator_status(Elevator elevator, int elevator_num) {
    printf("Elevator %d is on floor %d going ", elevator_num, elevator.floor);
    if (elevator.direction == 1) {
        printf("up");
    } else {
        printf("down");
    }
    printf(" with %d riders\n", elevator.num_riders);
}

// Function to simulate a rider entering the elevator
Elevator rider_enters_elevator(Elevator elevator) {
    // Rider enters the elevator
    elevator.num_riders++;
    return elevator;
}

// Function to simulate a rider exiting the elevator
Elevator rider_exits_elevator(Elevator elevator) {
    // Rider exits the elevator
    elevator.num_riders--;
    return elevator;
}

int main() {
    // Initialize the elevators
    Elevator elevators[NUM_ELEVATORS];
    elevators[0] = init_elevator(1, 1, 0);
    elevators[1] = init_elevator(5, -1, 0);

    // Simulate a rider entering the elevator
    elevators[0] = rider_enters_elevator(elevators[0]);
    elevators[1] = rider_enters_elevator(elevators[1]);
    elevators[1] = rider_enters_elevator(elevators[1]);
    elevators[1] = rider_enters_elevator(elevators[1]);

    // Simulate a rider exiting the elevator
    elevators[1] = rider_exits_elevator(elevators[1]);

    // Print the elevator status
    print_elevator_status(elevators[0], 1);
    print_elevator_status(elevators[1], 2);

    return 0;
}