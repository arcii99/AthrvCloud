//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdbool.h>

#define NUM_FLOORS 10
#define NUM_ELEVATORS 3

typedef struct {
    int floor;
    char direction;
} Request;

// Elevator struct
typedef struct {
    int current_floor;
    int num_passengers;
    bool is_full;
    Request current_request;
} Elevator;

// Initialize all elevators
void initialize_elevators(Elevator *elevators, int num_elevators) {
    for(int i = 0; i < num_elevators; i++) {
        elevators[i].current_floor = 1;
        elevators[i].num_passengers = 0;
        elevators[i].is_full = false;
    }
}

// Check if elevator is at the requested floor and in correct direction
bool is_elevator_at_request(Elevator elevator, Request request) {
    return elevator.current_floor == request.floor && elevator.current_request.direction == request.direction;
}

// Check if the elevator has room for more passengers
bool elevator_has_room(Elevator elevator) {
    return !elevator.is_full && elevator.num_passengers < 10;
}

// Check if there are any requests for a given floor
bool has_requests_for_floor(Request requests[], int num_requests, int floor, char direction) {
    for(int i = 0; i < num_requests; i++) {
        if(requests[i].floor == floor && requests[i].direction == direction) {
            return true;
        }
    }
    return false;
}

int main() {
    Elevator elevators[NUM_ELEVATORS];
    Request requests[NUM_FLOORS * 2]; // Two requests per floor

    initialize_elevators(elevators, NUM_ELEVATORS);

    // Run elevator simulation loop
    int iterations = 20;
    for(int i = 0; i < iterations; i++) {
        printf("Iteration %d:\n", i+1);

        // Simulate passengers requesting elevators
        for(int floor = 1; floor <= NUM_FLOORS; floor++) {
            // Check if someone wants to go up
            if(has_requests_for_floor(requests, NUM_FLOORS*2, floor, 'U')) {
                printf("Passenger on floor %d wants to go up.\n", floor);
                // Look for an elevator going up that has room
                for(int e = 0; e < NUM_ELEVATORS; e++) {
                    if(!elevator_has_room(elevators[e])) {
                        continue;
                    }
                    if(elevators[e].current_request.direction == 'U' && elevators[e].current_floor < floor) {
                        // Add request to elevator
                        if(elevators[e].num_passengers == 0) {
                            elevators[e].current_request = (Request){ .floor = floor, .direction = 'U' };
                        } else {
                            requests[floor-1] = (Request){ .floor = floor, .direction = 'U' };
                        }
                        break;
                    }
                }
            }
            // Check if someone wants to go down
            if(has_requests_for_floor(requests, NUM_FLOORS*2, floor, 'D')) {
                printf("Passenger on floor %d wants to go down.\n", floor);
                // Look for an elevator going down that has room
                for(int e = 0; e < NUM_ELEVATORS; e++) {
                    if(!elevator_has_room(elevators[e])) {
                        continue;
                    }
                    if(elevators[e].current_request.direction == 'D' && elevators[e].current_floor > floor) {
                        // Add request to elevator
                        if(elevators[e].num_passengers == 0) {
                            elevators[e].current_request = (Request){ .floor = floor, .direction = 'D' };
                        } else {
                            requests[NUM_FLOORS + floor - 1] = (Request){ .floor = floor, .direction = 'D' };
                        }
                        break;
                    }
                }
            }
        }

        // Simulate elevators moving
        for(int e = 0; e < NUM_ELEVATORS; e++) {
            // If elevator is idle, go to first request
            if(elevators[e].num_passengers == 0 && (elevators[e].current_floor != elevators[e].current_request.floor || elevators[e].current_request.direction == 'N')) {
                if(elevators[e].current_floor < elevators[e].current_request.floor) {
                    printf("Elevator %d is going up from floor %d to floor %d.\n", e+1, elevators[e].current_floor, elevators[e].current_request.floor);
                } else if(elevators[e].current_floor > elevators[e].current_request.floor) {
                    printf("Elevator %d is going down from floor %d to floor %d.\n", e+1, elevators[e].current_floor, elevators[e].current_request.floor);
                }
                elevators[e].current_request.direction = elevators[e].current_floor < elevators[e].current_request.floor ? 'U' : 'D';
            } else if(is_elevator_at_request(elevators[e], elevators[e].current_request)) {
                // If elevator is at current request, stop and let passengers on/off
                printf("Elevator %d has arrived at floor %d and is letting passengers on/off.\n", e+1, elevators[e].current_floor);
                // Unload passengers
                for(int p = 0; p < elevators[e].num_passengers; p++) {
                    if(elevators[e].current_request.floor == elevators[e].current_floor) {
                        // Passengers going in the same direction
                        if(elevators[e].current_request.direction == 'U' && elevators[e].num_passengers < 10) {
                            printf("Passenger %d exited elevator %d on floor %d.\n", p+1, e+1, elevators[e].current_floor);
                            elevators[e].num_passengers--;
                        } else if(elevators[e].current_request.direction == 'D' && elevators[e].num_passengers < 10) {
                            printf("Passenger %d exited elevator %d on floor %d.\n", p+1, e+1, elevators[e].current_floor);
                            elevators[e].num_passengers--;
                        } else {
                            // Elevator is full or not going in the right direction
                            printf("Passenger %d is staying on board elevator %d on floor %d.\n", p+1, e+1, elevators[e].current_floor);
                        }
                    }
                }
                // Load passengers
                for(int i = 0; i < NUM_FLOORS*2; i++) {
                    if(requests[i].floor == elevators[e].current_floor && !elevators[e].is_full) {
                        if(elevators[e].current_request.direction == 'U' && requests[i].direction == 'U' && elevators[e].num_passengers < 10) {
                            printf("Passenger requested to go up and entered elevator %d on floor %d.\n", e+1, elevators[e].current_floor);
                            elevators[e].num_passengers++;
                        } else if(elevators[e].current_request.direction == 'D' && requests[i].direction == 'D' && elevators[e].num_passengers < 10) {
                            printf("Passenger requested to go down and entered elevator %d on floor %d.\n", e+1, elevators[e].current_floor);
                            elevators[e].num_passengers++;
                        } else {
                            printf("Passenger requested to go in the opposite direction or elevator is full and couldn't enter on floor %d.\n", elevators[e].current_floor);
                        }
                    }
                }
                // Find next request
                elevators[e].current_request.direction = 'N'; // No request yet
                for(int i = elevators[e].current_floor+1; i <= NUM_FLOORS; i++) {
                    if(has_requests_for_floor(requests, NUM_FLOORS*2, i, 'U')) {
                        elevators[e].current_request.floor = i;
                        elevators[e].current_request.direction = 'U';
                        break;
                    } else if(has_requests_for_floor(requests, NUM_FLOORS*2, i, 'D')) {
                        elevators[e].current_request.floor = i;
                        elevators[e].current_request.direction = 'D';
                        break;
                    }
                }
                if(elevators[e].current_request.direction != 'N') {
                    if(elevators[e].current_floor < elevators[e].current_request.floor) {
                        printf("Elevator %d is going up from floor %d to floor %d.\n", e+1, elevators[e].current_floor, elevators[e].current_request.floor);
                    } else if(elevators[e].current_floor > elevators[e].current_request.floor) {
                        printf("Elevator %d is going down from floor %d to floor %d.\n", e+1, elevators[e].current_floor, elevators[e].current_request.floor);
                    }
                }
            } else {
                // Otherwise, keep moving in same direction
                if(elevators[e].current_request.direction == 'U') {
                    printf("Elevator %d is going up from floor %d to floor %d.\n", e+1, elevators[e].current_floor, elevators[e].current_floor+1);
                    elevators[e].current_floor++;
                } else if(elevators[e].current_request.direction == 'D') {
                    printf("Elevator %d is going down from floor %d to floor %d.\n", e+1, elevators[e].current_floor, elevators[e].current_floor-1);
                    elevators[e].current_floor--;
                }
            }
        }
        printf("\n");
    }
    return 0;
}