//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define FLOORS 10
#define ELEVATORS 2

typedef enum DIRECTION {
    UP = 1,
    DOWN = -1
} Direction;

typedef struct PASSENGER {
    int start_floor;
    int destination_floor;
} Passenger;

typedef struct ELEVATOR {
    int current_floor;
    int load_capacity;
    int passengers_count;
    Direction direction;
    Passenger *passengers;
} Elevator;

typedef struct FLOOR {
    int queue_count;
    Passenger *queue;
} Floor;

Elevator elevators[ELEVATORS];
Floor floors[FLOORS];

void initialize();
int get_next_floor(int elevator_id);
void move_elevator(int elevator_id, int next_floor);
void unload_passengers(int elevator_id);
void load_passengers(int elevator_id);
void print_state();

int main() {
    srand(time(0)); // Set the seed for the random function

    initialize(); // Initialize the floors and elevators

    for(int i = 0; i < 100; i++) { // Run the simulation for 100 time steps
        for(int j = 0; j < ELEVATORS; j++) { // Move each elevator
            int next_floor = get_next_floor(j);
            move_elevator(j, next_floor);
            unload_passengers(j);
            load_passengers(j);
        }

        print_state(); // Print the current state of the system
    }

    return 0;
}

// Initialize the floors and elevators
void initialize() {
    for(int i = 0; i < ELEVATORS; i++) {
        elevators[i].current_floor = rand() % FLOORS;
        elevators[i].direction = (rand() % 2 == 0) ? UP : DOWN;
        elevators[i].load_capacity = rand() % 10 + 1;
        elevators[i].passengers_count = 0;
        elevators[i].passengers = malloc(sizeof(Passenger) * elevators[i].load_capacity); // Allocate memory for the passengers array
    }

    for(int i = 0; i < FLOORS; i++) {
        floors[i].queue_count = 0;
        floors[i].queue = malloc(sizeof(Passenger) * FLOORS); // Allocate memory for the passengers queue on each floor
    }
}

// Get the next floor for an elevator based on its current floor and direction
int get_next_floor(int elevator_id) {
    Elevator elevator = elevators[elevator_id];

    if(elevator.passengers_count > 0) { // If the elevator has passengers, go to the floor with the highest destination floor
        int highest_floor = -1;

        for(int i = 0; i < elevator.passengers_count; i++) {
            if(elevator.passengers[i].destination_floor > highest_floor) {
                highest_floor = elevator.passengers[i].destination_floor;
            }
        }

        return highest_floor;
    }

    if(elevator.direction == UP) { // If the elevator is going up, go to the next floor above it
        if(elevator.current_floor < FLOORS - 1) {
            return elevator.current_floor + 1;
        } else { // If the elevator is at the top floor, go down
            return elevator.current_floor - 1;
        }
    } else { // If the elevator is going down, go to the next floor below it
        if(elevator.current_floor > 0) {
            return elevator.current_floor - 1;
        } else { // If the elevator is at the bottom floor, go up
            return 1;
        }
    }
}

// Move an elevator to the next floor
void move_elevator(int elevator_id, int next_floor) {
    Elevator *elevator = &elevators[elevator_id];

    if(elevator->current_floor == next_floor) { // If the elevator is already at the next floor, don't move
        return;
    }

    printf("Elevator %d moving from floor %d to floor %d\n", elevator_id, elevator->current_floor, next_floor);

    elevator->current_floor = next_floor;

    if(elevator->direction == UP) { // If the elevator is going up and reaches the top floor, go down
        if(elevator->current_floor == FLOORS - 1) {
            elevator->direction = DOWN;
        }
    } else { // If the elevator is going down and reaches the bottom floor, go up
        if(elevator->current_floor == 0) {
            elevator->direction = UP;
        }
    }
}

// Unload passengers from an elevator at their destination floor
void unload_passengers(int elevator_id) {
    Elevator *elevator = &elevators[elevator_id];

    for(int i = 0; i < elevator->passengers_count; i++) {
        if(elevator->passengers[i].destination_floor == elevator->current_floor) {
            printf("Passenger unloaded from elevator %d at floor %d\n", elevator_id, elevator->current_floor);
            elevator->passengers_count--;

            // Move the last passenger in the array to the position of the passenger being removed
            if(i < elevator->passengers_count) {
                elevator->passengers[i] = elevator->passengers[elevator->passengers_count];
            }
        }
    }
}

// Load passengers onto an elevator from the floor's queue
void load_passengers(int elevator_id) {
    Elevator *elevator = &elevators[elevator_id];
    Floor *floor = &floors[elevator->current_floor];

    for(int i = 0; i < floor->queue_count; i++) {
        if(elevator->passengers_count < elevator->load_capacity) {
            elevator->passengers[elevator->passengers_count] = floor->queue[i];
            elevator->passengers_count++;
            printf("Passenger loaded onto elevator %d at floor %d\n", elevator_id, elevator->current_floor);

            // Move the last passenger in the queue array to the position of the passenger being removed
            if(i < floor->queue_count - 1) {
                floor->queue[i] = floor->queue[floor->queue_count - 1];
            }
            floor->queue_count--;
        } else {
            printf("Elevator %d is at full capacity, cannot load more passengers\n", elevator_id);
            return;
        }
    }
}

// Print the current state of the system
void print_state() {
    printf("ELEVATORS:\n");
    for(int i = 0; i < ELEVATORS; i++) {
        Elevator elevator = elevators[i];
        printf("Elevator %d - floor %d, direction %s, load capacity %d, passengers %d\n", i, elevator.current_floor, (elevator.direction == UP) ? "up" : "down", elevator.load_capacity, elevator.passengers_count);
        if(elevator.passengers_count > 0) {
            printf("  Passengers:\n");
            for(int j = 0; j < elevator.passengers_count; j++) {
                printf("  - From floor %d to floor %d\n", elevator.passengers[j].start_floor, elevator.passengers[j].destination_floor);
            }
        }
    }

    printf("\nFLOORS:\n");
    for(int i = 0; i < FLOORS; i++) {
        Floor floor = floors[i];
        printf("Floor %d - %d passengers in queue\n", i, floor.queue_count);
        if(floor.queue_count > 0) {
            printf("  Queue:\n");
            for(int j = 0; j < floor.queue_count; j++) {
                printf("  - From floor %d to floor %d\n", floor.queue[j].start_floor, floor.queue[j].destination_floor);
            }
        }
    }

    printf("--------------------------------------------------\n");
}