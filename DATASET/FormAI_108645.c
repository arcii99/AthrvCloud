//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FLOORS 10
#define NUM_ELEVATORS 3

// Struct to represent an elevator
typedef struct {
    int current_floor;
    int direction;
    int is_door_open;
} Elevator;

// Function to initialize an elevator with starting values
void init_elevator(Elevator* elevator) {
    elevator->current_floor = 1;
    elevator->direction = 0;
    elevator->is_door_open = 0;
}

int main() {
    // Seed random number generator for simulating elevator requests
    srand((unsigned) time(NULL));

    // Create array of elevators
    Elevator elevators[NUM_ELEVATORS];
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        init_elevator(&elevators[i]);
    }

    // Create 2D array to keep track of elevator requests on each floor
    int elevator_requests[NUM_FLOORS][2]; // column 0 is up request, column 1 is down request
    for (int i = 0; i < NUM_FLOORS; i++) {
        elevator_requests[i][0] = 0;
        elevator_requests[i][1] = 0;
    }

    // Begin elevator simulation loop
    int time = 0;
    while (1) {
        // Check for floor requests and assign elevators
        for (int i = 0; i < NUM_FLOORS; i++) {
            // Check up request
            if (elevator_requests[i][0] == 1) {
                // Assign nearest elevator going up
                int closest_elevator = -1;
                int closest_distance = NUM_FLOORS;
                for (int j = 0; j < NUM_ELEVATORS; j++) {
                    if (elevators[j].direction >= 0) {
                        int distance = abs(elevators[j].current_floor - i);
                        if (distance < closest_distance) {
                            closest_distance = distance;
                            closest_elevator = j;
                        }
                    }
                }
                if (closest_elevator != -1) {
                    elevators[closest_elevator].direction = 1;
                    printf("Elevator %d assigned to floor %d going up\n", closest_elevator, i);
                }
            }
            // Check down request
            if (elevator_requests[i][1] == 1) {
                // Assign nearest elevator going down
                int closest_elevator = -1;
                int closest_distance = NUM_FLOORS;
                for (int j = 0; j < NUM_ELEVATORS; j++) {
                    if (elevators[j].direction <= 0) {
                        int distance = abs(elevators[j].current_floor - i);
                        if (distance < closest_distance) {
                            closest_distance = distance;
                            closest_elevator = j;
                        }
                    }
                }
                if (closest_elevator != -1) {
                    elevators[closest_elevator].direction = -1;
                    printf("Elevator %d assigned to floor %d going down\n", closest_elevator, i);
                }
            }
        }

        // Move elevators and process requests on each floor
        for (int i = 0; i < NUM_ELEVATORS; i++) {
            if (elevators[i].direction == 1) {
                // Move up one floor
                elevators[i].current_floor++;
                printf("Elevator %d moving up to floor %d\n", i, elevators[i].current_floor);

                // Check for requests on this floor
                if (elevator_requests[elevators[i].current_floor-1][0] == 1) {
                    printf("Elevator %d has arrived at floor %d and is opening doors\n", i, elevators[i].current_floor);
                    elevators[i].is_door_open = 1;
                } else if (elevator_requests[elevators[i].current_floor-1][1] == 1) {
                    printf("Elevator %d has arrived at floor %d but cannot stop because it is going up\n", i, elevators[i].current_floor);
                }

                // Check if elevator has reached top floor
                if (elevators[i].current_floor == NUM_FLOORS) {
                    printf("Elevator %d has reached the top floor and is changing direction\n", i);
                    elevators[i].direction = -1;
                }
            } else if (elevators[i].direction == -1) {
                // Move down one floor
                elevators[i].current_floor--;
                printf("Elevator %d moving down to floor %d\n", i, elevators[i].current_floor);

                // Check for requests on this floor
                if (elevator_requests[elevators[i].current_floor-1][1] == 1) {
                    printf("Elevator %d has arrived at floor %d and is opening doors\n", i, elevators[i].current_floor);
                    elevators[i].is_door_open = 1;
                } else if (elevator_requests[elevators[i].current_floor-1][0] == 1) {
                    printf("Elevator %d has arrived at floor %d but cannot stop because it is going down\n", i, elevators[i].current_floor);
                }

                // Check if elevator has reached ground floor
                if (elevators[i].current_floor == 1) {
                    printf("Elevator %d has reached the ground floor and is changing direction\n", i);
                    elevators[i].direction = 1;
                }
            } else if (elevators[i].is_door_open == 1) {
                // Close elevator doors after wait time
                printf("Elevator %d doors closing\n", i);
                elevators[i].is_door_open = 0;
            }
        }

        // Reset requests for each floor every minute
        if (time % 60 == 0) {
            for (int i = 0; i < NUM_FLOORS; i++) {
                elevator_requests[i][0] = 0;
                elevator_requests[i][1] = 0;
            }
        }

        // Generate random floor requests for testing
        int request_floor = rand() % NUM_FLOORS; // Randomly choose floor between 0 and 9
        int request_direction = rand() % 2; // Randomly choose up or down request
        elevator_requests[request_floor][request_direction] = 1;
        printf("Request for elevator on floor %d going %s\n", request_floor+1, request_direction == 0 ? "up" : "down");

        // Increment time step
        time++;

        // Exit loop after 10 minutes for testing purposes
        if (time == 600) {
            break;
        }
    }

    return 0;
}