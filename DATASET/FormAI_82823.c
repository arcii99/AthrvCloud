//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: sophisticated
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define NUM_FLOORS 10   // Number of floors in the building
#define NUM_ELEVATORS 2 // Number of elevators in the building

// Enumeration for the direction of the elevator
typedef enum {
    UP,
    DOWN,
    IDLE
} direction_t;

// A struct representing an elevator
typedef struct {
    int current_floor;  // The floor the elevator is currently on
    direction_t direction;  // The direction the elevator is currently moving
    bool is_busy;   // Whether the elevator is currently occupied with a task
} elevator_t;

// A struct representing a floor
typedef struct {
    bool has_up_button; // Whether there is an up button on this floor
    bool has_down_button;   // Whether there is a down button on this floor
} floor_t;

// Initialize the elevators to the first floor and idle
void init_elevators(elevator_t elevators[]) {
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        elevators[i].current_floor = 1;
        elevators[i].direction = IDLE;
        elevators[i].is_busy = false;
    }
}

// Initialize all the floors with both up and down buttons
void init_floors(floor_t floors[]) {
    for (int i = 0; i < NUM_FLOORS; i++) {
        floors[i].has_up_button = true;
        floors[i].has_down_button = true;
    }
}

// Check if there is an elevator on this floor that is not busy
int get_idle_elevator(elevator_t elevators[], int floor) {
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        if (elevators[i].current_floor == floor && !elevators[i].is_busy) {
            return i;
        }
    }
    return -1; // No idle elevator found
}

// Move the elevator by one floor in its current direction
void move_elevator(elevator_t *elevator) {
    if (elevator->direction == UP) {
        elevator->current_floor++;
    } else if (elevator->direction == DOWN) {
        elevator->current_floor--;
    }
}

// Find the floor with the closest active button to the elevator
int get_closest_floor(floor_t floors[], elevator_t elevator) {
    int closest_floor = -1;
    int closest_distance = NUM_FLOORS + 1; // Initialize to maximum distance

    for (int i = 0; i < NUM_FLOORS; i++) {
        if (elevator.direction == UP && floors[i].has_up_button || 
            elevator.direction == DOWN && floors[i].has_down_button) {
            
            int distance = abs(i - elevator.current_floor);
            if (distance < closest_distance) {
                closest_distance = distance;
                closest_floor = i;
            }
        }
    }

    return closest_floor;
}

int main() {

    floor_t floors[NUM_FLOORS];     // Declare the floors
    elevator_t elevators[NUM_ELEVATORS];    // Declare the elevators

    init_floors(floors);    // Initialize the floors
    init_elevators(elevators);  // Initialize the elevators

    // Initial status of the system
    printf("Initial status of the system:\nElevator 1 is on floor %d, elevator 2 is on floor %d\n\n", 
            elevators[0].current_floor, elevators[1].current_floor);

    // User presses up button on floor 3
    printf("User presses up button on floor 3\n");
    floors[3].has_up_button = true;

    // Elevator 1 gets idle and moves towards floor 3
    int idle_elevator = get_idle_elevator(elevators, 1);
    elevators[idle_elevator].is_busy = true;
    elevators[idle_elevator].direction = UP;

    // Elevator 1 moves towards floor 3
    printf("Elevator 1 moves towards floor 3\n");
    while (elevators[idle_elevator].current_floor != 3) {
        move_elevator(&elevators[idle_elevator]);
    }
    printf("Elevator 1 arrives at floor 3\n");

    // Elevator 1 opens its door and gets busy
    printf("Elevator 1 opens its door and gets busy\n");
    elevators[idle_elevator].is_busy = true;

    // User enters elevator 1 and presses the button for floor 7
    printf("User enters elevator 1 and presses the button for floor 7\n");
    elevators[idle_elevator].direction = UP;

    // Elevator 1 moves towards floor 7
    int closest_floor = get_closest_floor(floors, elevators[idle_elevator]);
    printf("Elevator 1 moves towards floor %d\n", closest_floor);
    while (elevators[idle_elevator].current_floor != closest_floor) {
        move_elevator(&elevators[idle_elevator]);
    }
    printf("Elevator 1 arrives at floor %d\n", closest_floor);

    // Elevator 1 opens its door and gets busy
    printf("Elevator 1 opens its door and gets busy\n");
    elevators[idle_elevator].is_busy = true;

    // Elevator 1 moves towards the top floor
    printf("Elevator 1 moves towards the top floor\n");
    elevators[idle_elevator].direction = UP;
    while (elevators[idle_elevator].current_floor != NUM_FLOORS) {
        move_elevator(&elevators[idle_elevator]);
    }
    printf("Elevator 1 arrives at the top floor\n");

    // Elevator 1 moves towards the bottom floor
    printf("Elevator 1 moves towards the bottom floor\n");
    elevators[idle_elevator].direction = DOWN;
    while (elevators[idle_elevator].current_floor != 1) {
        move_elevator(&elevators[idle_elevator]);
    }
    printf("Elevator 1 arrives at the bottom floor\n");

    return 0;
}