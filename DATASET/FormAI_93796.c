//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: imaginative
#include <stdio.h>

// Constants
#define ELEVATOR_CAPACITY 10
#define ELEVATOR_FLOORS 10

// Enumerations
enum direction { UP, DOWN };

// Structs
struct elevator {
    int capacity;
    int current_floor;
    enum direction direction;
    int occupancy;
} elevator;

// Function prototypes
void print_elevator_status();
void move_elevator(int target_floor);
void add_passengers(int num_passengers);
void remove_passengers(int num_passengers);
void simulate_elevator();

// Main function
int main() {
    // Initialize the elevator
    elevator.capacity = ELEVATOR_CAPACITY;
    elevator.current_floor = 1;
    elevator.direction = UP;
    elevator.occupancy = 0;

    simulate_elevator();

    return 0;
}

// Print the status of the elevator
void print_elevator_status() {
    printf("Elevator status:\n");
    printf("Capacity: %d\n", elevator.capacity);
    printf("Current floor: %d\n", elevator.current_floor);
    printf("Direction: %s\n", elevator.direction == UP ? "up" : "down");
    printf("Occupancy: %d\n", elevator.occupancy);
}

// Move the elevator to the target floor
void move_elevator(int target_floor) {
    if (target_floor < 1 || target_floor > ELEVATOR_FLOORS) {
        printf("Invalid floor selected\n");
        return;
    }

    if (elevator.current_floor == target_floor) {
        printf("Elevator already on floor %d\n", target_floor);
        return;
    }

    printf("Moving elevator from floor %d %s to floor %d\n",
        elevator.current_floor, elevator.direction == UP ? "up" : "down", target_floor);

    elevator.current_floor = target_floor;

    printf("Elevator arrived at floor %d\n", elevator.current_floor);

    print_elevator_status();
}

// Add passengers to the elevator
void add_passengers(int num_passengers) {
    if (num_passengers > elevator.capacity - elevator.occupancy) {
        printf("Elevator cannot hold that many passengers\n");
        return;
    }

    printf("Adding %d passengers to the elevator\n", num_passengers);

    elevator.occupancy += num_passengers;

    printf("Elevator now has %d passengers\n", elevator.occupancy);

    print_elevator_status();
}

// Remove passengers from the elevator
void remove_passengers(int num_passengers) {
    if (num_passengers > elevator.occupancy) {
        printf("Elevator does not have that many passengers\n");
        return;
    }

    printf("Removing %d passengers from the elevator\n", num_passengers);

    elevator.occupancy -= num_passengers;

    printf("Elevator now has %d passengers\n", elevator.occupancy);

    print_elevator_status();
}

// Simulate the elevator operation
void simulate_elevator() {
    printf("Starting elevator simulation\n");

    // Move elevator to floor 3
    move_elevator(3);

    // Add 5 passengers to the elevator
    add_passengers(5);

    // Move elevator to floor 7
    move_elevator(7);

    // Remove 3 passengers from the elevator
    remove_passengers(3);

    // Move elevator to floor 10
    move_elevator(10);

    // Add 8 passengers to the elevator
    add_passengers(8);

    // Move elevator to floor 5
    move_elevator(5);

    // End of simulation
    printf("End of elevator simulation\n");
}