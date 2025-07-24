//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ELEVATORS 4
#define NUM_FLOORS 10
#define MAX_CAPACITY 10

// Struct to represent a passenger waiting for an elevator
typedef struct {
    int start_floor;
    int dest_floor;
} Passenger;

// Struct to represent an elevator
typedef struct {
    int curr_floor;
    int dir; // 1 for up, -1 for down, 0 for stopped
    int capacity;
    Passenger passengers[MAX_CAPACITY];
} Elevator;

// Function to randomly generate a passenger's start and destination floors
void generate_passenger(Passenger *p) {
    p->start_floor = rand() % NUM_FLOORS;
    // Make sure destination floor is different than start floor
    do {
        p->dest_floor = rand() % NUM_FLOORS;
    } while (p->dest_floor == p->start_floor);
}

// Function to move an elevator one floor
void move_elevator(Elevator *e) {
    if (e->dir == 1) {
        e->curr_floor++;
    } else if (e->dir == -1) {
        e->curr_floor--;
    }
}

// Function to check if an elevator needs to change direction
void check_direction(Elevator *e) {
    // Check if any passengers have destinations in the current direction
    int found = 0;
    for (int i = 0; i < e->capacity; i++) {
        if (e->passengers[i].dest_floor > e->curr_floor && e->dir == 1) {
            found = 1;
            break;
        } else if (e->passengers[i].dest_floor < e->curr_floor && e->dir == -1) {
            found = 1;
            break;
        }
    }
    // If not, change direction
    if (!found) {
        e->dir = -e->dir; // reverse direction
    }
}

// Function to pick up passengers waiting at the elevator's current floor
void pick_up_passengers(Elevator *e, Passenger *waiting_passengers) {
    int num_waiting = 0;
    // Find waiting passengers
    for (int i = 0; i < NUM_FLOORS; i++) {
        if (waiting_passengers[i].start_floor == e->curr_floor && e->capacity > 0) {
            // Add waiting passenger to elevator
            e->passengers[e->capacity - 1] = waiting_passengers[i];
            e->capacity--;
            num_waiting++;
            // Move waiting passengers array down
            for (int j = i; j < NUM_FLOORS - 1; j++) {
                waiting_passengers[j] = waiting_passengers[j+1];
            }
        }
    }
    // Print out how many passengers were picked up
    if (num_waiting > 0) {
        printf("Elevator on floor %d picked up %d passengers.\n", e->curr_floor, num_waiting);
    }
}

// Function to drop off passengers with the elevator's current destination floor
void drop_off_passengers(Elevator *e) {
    int num_dropped = 0;
    // Check each passenger
    for (int i = 0; i < MAX_CAPACITY - e->capacity; i++) {
        if (e->passengers[i].dest_floor == e->curr_floor) {
            // Remove passenger from elevator
            e->passengers[i] = (Passenger) { -1, -1};
            e->capacity++;
            num_dropped++;
        }
    }
    // Move dropped passengers to the front of the array
    for (int i = 0; i < MAX_CAPACITY - e->capacity; i++) {
        if (e->passengers[i].start_floor == -1) {
            for (int j = i; j < MAX_CAPACITY - e->capacity - 1; j++) {
                e->passengers[j] = e->passengers[j+1];
            }
            i--; // make sure we don't miss any passengers
        }
    }
    // Print out how many passengers were dropped off
    if (num_dropped > 0) {
        printf("Elevator on floor %d dropped off %d passengers.\n", e->curr_floor, num_dropped);
    }
}

// Function to print out the status of all the elevators
void print_elevator_status(Elevator elevators[]) {
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        printf("Elevator %d is on floor %d and has %d passengers.\n", i, elevators[i].curr_floor, MAX_CAPACITY - elevators[i].capacity);
    }
}

int main() {
    // Seed random number generator
    srand(time(NULL));
    // Create array of waiting passengers
    Passenger waiting_passengers[NUM_FLOORS];
    for (int i = 0; i < NUM_FLOORS; i++) {
        generate_passenger(&waiting_passengers[i]);
    }
    // Create array of elevators
    Elevator elevators[NUM_ELEVATORS];
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        elevators[i].curr_floor = 0;
        elevators[i].dir = 1;
        elevators[i].capacity = MAX_CAPACITY;
    }
    // Main loop
    int tick = 0;
    while (tick < 100) {
        // Move elevators
        for (int i = 0; i < NUM_ELEVATORS; i++) {
            move_elevator(&elevators[i]);
            check_direction(&elevators[i]);
        }
        // Pick up waiting passengers
        for (int i = 0; i < NUM_ELEVATORS; i++) {
            pick_up_passengers(&elevators[i], waiting_passengers);
        }
        // Drop off passengers
        for (int i = 0; i < NUM_ELEVATORS; i++) {
            drop_off_passengers(&elevators[i]);
        }
        // Print elevator status
        printf("Tick %d:\n", tick);
        print_elevator_status(elevators);
        // Wait 1 second
        sleep(1);
        tick++;
    }
    return 0;
}