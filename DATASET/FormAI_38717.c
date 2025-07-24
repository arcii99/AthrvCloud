//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

#define NUM_FLOORS 5
#define MAX_CAPACITY 10

typedef enum {
    IDLE,
    MOVING_UP,
    MOVING_DOWN
} State;

typedef struct {
    int floor;
    int num_passengers;
} Elevator;

typedef struct {
    int floor;
    int num_passengers;
} Passenger;

Elevator elevator = {0, 0};

void add_passenger() {
    // Add a passenger to the elevator
    if (elevator.num_passengers < MAX_CAPACITY) {
        Passenger passenger = {rand() % NUM_FLOORS, 1};
        printf("Added passenger on floor %d\n", passenger.floor);
        elevator.num_passengers++;
    } else {
        printf("Elevator is at maximum capacity\n");
    }
}

void remove_passenger() {
    // Remove a passenger from the elevator
    if (elevator.num_passengers > 0) {
        printf("Removed passenger on floor %d\n", elevator.floor);
        elevator.num_passengers--;
    } else {
        printf("Elevator is empty\n");
    }
}

void move_elevator(int floor) {
    // Move the elevator to a specific floor
    if (floor > elevator.floor) {
        printf("Moving up to floor %d\n", floor);
        elevator.floor = floor;
    } else if (floor < elevator.floor) {
        printf("Moving down to floor %d\n", floor);
        elevator.floor = floor;
    } else {
        printf("Elevator already on floor %d\n", floor);
    }
}

void update_elevator() {
    // Update the elevator state
    if (elevator.num_passengers == 0) {
        if (elevator.floor != 0) {
            move_elevator(0);
        } else {
            printf("Elevator is idle\n");
        }
    } else {
        if (elevator.floor == 0) {
            move_elevator(rand() % NUM_FLOORS + 1);
        } else if (elevator.floor == NUM_FLOORS) {
            move_elevator(rand() % NUM_FLOORS);
        } else {
            if (rand() % 2 == 0) {
                move_elevator(elevator.floor + 1);
            } else {
                move_elevator(elevator.floor - 1);
            }
        }
    }
}

int main() {
    srand(42);

    while (1) {
        // Update elevator state at regular intervals
        update_elevator();

        // Add or remove passengers if necessary
        if (rand() % 2 == 0) {
            add_passenger();
        } else {
            remove_passenger();
        }
    }

    return 0;
}