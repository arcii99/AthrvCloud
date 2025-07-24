//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define NUM_FLOORS 10
#define NUM_ELEVATORS 3

typedef struct {
    int floor;
    int direction;
    int passengers;
} Elevator;

typedef struct {
    int from_floor; 
    int to_floor; 
} Request;

Elevator elevators[NUM_ELEVATORS];
Request requests[NUM_FLOORS];

void initialize_elevators();
void initialize_requests();
void print_status();
void step_simulation();
int get_nearest_elevator(int floor);
void add_request(int floor, int direction);

int main() {
    // Initialize elevators and requests
    initialize_elevators();
    initialize_requests();
    
    // Start simulation
    for (int i = 0; i < 100; i++) {
        step_simulation();
        print_status();
    }
    
    return 0;
}

void initialize_elevators() {
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        elevators[i].floor = 0;
        elevators[i].direction = 0;
        elevators[i].passengers = 0;
    }
}

void initialize_requests() {
    for (int i = 0; i < NUM_FLOORS; i++) {
        requests[i].from_floor = 0;
        requests[i].to_floor = 0;
    }
}

void print_status() {
    printf("Elevator status:\n");
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        printf("Elevator %d: Floor %d, Direction %d, Passengers %d\n", 
               i, elevators[i].floor, elevators[i].direction, elevators[i].passengers);
    }
    printf("\n");
    
    printf("Request status:\n");
    for (int i = 0; i < NUM_FLOORS; i++) {
        if (requests[i].from_floor != 0 || requests[i].to_floor != 0) {
            printf("Request from floor %d to floor %d\n", requests[i].from_floor, requests[i].to_floor);
        }
    }
    printf("\n");
}

void step_simulation() {
    // Randomly generate requests
    for (int i = 0; i < NUM_FLOORS; i++) {
        int direction = rand() % 2;
        if (direction == 0) {
            add_request(i, 1);
        } else {
            add_request(i, -1);
        }
    }
    
    // Handle requests
    for (int i = 0; i < NUM_FLOORS; i++) {
        int nearest_elevator = get_nearest_elevator(i);
        if (requests[i].from_floor != 0 && nearest_elevator != -1) {
            elevators[nearest_elevator].passengers += 1;
            elevators[nearest_elevator].direction = requests[i].to_floor - requests[i].from_floor > 0 ? 1 : -1;
            requests[i].from_floor = 0;
            requests[i].to_floor = 0;
        }
    }
    
    // Move elevators
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        elevators[i].floor += elevators[i].direction;
    }
}

int get_nearest_elevator(int floor) {
    int distance = NUM_FLOORS;
    int nearest_elevator = -1;
    
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        if (elevators[i].direction == 0) {
            int elevator_distance = abs(elevators[i].floor - floor);
            if (elevator_distance < distance) {
                distance = elevator_distance;
                nearest_elevator = i;
            }
        } else if (elevators[i].direction > 0 && floor >= elevators[i].floor) {
            int elevator_distance = abs(elevators[i].floor - floor);
            if (elevator_distance < distance) {
                distance = elevator_distance;
                nearest_elevator = i;
            }
        } else if (elevators[i].direction < 0 && floor <= elevators[i].floor) {
            int elevator_distance = abs(elevators[i].floor - floor);
            if (elevator_distance < distance) {
                distance = elevator_distance;
                nearest_elevator = i;
            }
        }
    }
    
    return nearest_elevator;
}

void add_request(int floor, int direction) {
    if (direction > 0 && floor < NUM_FLOORS - 1) {
        requests[floor].from_floor = floor;
        requests[floor].to_floor = floor + 1;
    } else if (direction < 0 && floor > 0) {
        requests[floor].from_floor = floor;
        requests[floor].to_floor = floor - 1;
    }
}