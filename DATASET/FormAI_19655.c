//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define MAX_FLOOR 10           // Maximum number of floors in the building
#define MAX_ELEVATOR 2         // Maximum number of elevators in the building
#define MAX_CAPACITY 10        // Maximum capacity of each elevator

typedef enum { UP, DOWN, STATIONARY } direction_t;
typedef enum { OPEN, CLOSED } door_t;
typedef enum { MOVING, STOPPED } elevator_t;
typedef enum { SEQUENCE, PRIORITY } operation_t;

typedef struct {
    int floor;                  // Current floor of the elevator
    int capacity;               // Current capacity of the elevator
    direction_t direction;      // Current direction of the elevator
    door_t door;                // Current state of the elevator door
    elevator_t status;          // Current status of the elevator (MOVING or STOPPED)
} elevator;

typedef struct {
    int id;                     // ID of the floor (starts from 1)
    operation_t operation;      // Type of operation (SEQUENCE or PRIORITY)
    int priority;               // Priority of the floor (if operation type is PRIORITY)
} floor;

int main() {
    elevator elevators[MAX_ELEVATOR];       // Array of elevators in the building
    floor floors[MAX_FLOOR];                // Array of floors in the building

    // Initialize the elevators
    for (int i = 0; i < MAX_ELEVATOR; i++) {
        elevators[i].floor = 1;
        elevators[i].capacity = 0;
        elevators[i].direction = STATIONARY;
        elevators[i].door = CLOSED;
        elevators[i].status = STOPPED;
    }

    // Initialize the floors
    for (int i = 0; i < MAX_FLOOR; i++) {
        floors[i].id = i + 1;
        floors[i].operation = SEQUENCE;
        floors[i].priority = 0;
    }

    // Start the elevator simulation loop
    while (1) {
        // TODO: Implement the elevator simulation logic
    }

    return 0;
}