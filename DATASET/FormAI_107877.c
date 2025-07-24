//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>

// Maximum number of floors available in the building.
#define MAX_FLOORS 50

// Number of elevators available in the building.
#define NUM_ELEVATORS 3

// A struct representing an elevator in the building.
typedef struct elevator {
    int current_floor;      // the current floor that the elevator is on
    int dest_floor;         // the destination floor that the elevator is heading to
    int movement_direction; // direction of movement of the elevator: 1 for going up and -1 for going down
    int is_moving;          // a flag indicating whether the elevator is currently moving or not
} Elevator;

// A function to simulate elevator movement from its current floor to destination floor.
void moveElevator(Elevator *elevator) {
    printf("Elevator is moving from floor %d to floor %d in direction %s\n", 
           elevator->current_floor, elevator->dest_floor, 
           elevator->movement_direction == 1 ? "up" : "down");
    elevator->is_moving = 1;
    while(elevator->current_floor != elevator->dest_floor) {
        elevator->current_floor += elevator->movement_direction;
        printf("Elevator is now at floor %d\n", elevator->current_floor);
    }
    printf("Elevator has arrived at destination floor %d\n", elevator->dest_floor);
    elevator->is_moving = 0;
}

int main() {
    // Create an array of elevators
    Elevator elevators[NUM_ELEVATORS];
    int i, j;

    // Initialize all elevators at the ground floor and not moving.
    for(i = 0; i < NUM_ELEVATORS; i++) {
        elevators[i].current_floor = 0;
        elevators[i].dest_floor = 0;
        elevators[i].movement_direction = 1;
        elevators[i].is_moving = 0;
    }

    // Simulate a scenario where people are requesting elevators on different floors.
    int num_requests = 0;
    int request_floors[MAX_FLOORS];
    for(i = 0; i < MAX_FLOORS; i++)
        request_floors[i] = 0;

    // Randomly generate some elevator requests for demonstration purposes.
    for(i = 0; i < 10; i++) {
        int floor = rand() % MAX_FLOORS;
        request_floors[floor] = 1;
        num_requests++;
    }

    // Process each elevator request.
    for(i = 0; i < MAX_FLOORS; i++) {
        if(request_floors[i]) {
            printf("*** Elevator Requested on Floor %d\n", i);
            // Find the closest available elevator to the requested floor.
            int min_distance = 10000;
            int closest_elevator_index = -1;
            for(j = 0; j < NUM_ELEVATORS; j++) {
                if(!elevators[j].is_moving) {
                    int distance = abs(elevators[j].current_floor - i);
                    if(distance < min_distance) {
                        min_distance = distance;
                        closest_elevator_index = j;
                    }
                }
            }
            // Send the closest elevator to the requested floor.
            elevators[closest_elevator_index].dest_floor = i;
            if(elevators[closest_elevator_index].dest_floor > elevators[closest_elevator_index].current_floor)
                elevators[closest_elevator_index].movement_direction = 1;
            else
                elevators[closest_elevator_index].movement_direction = -1;
            moveElevator(&elevators[closest_elevator_index]);
        }
    }

    return 0;
}