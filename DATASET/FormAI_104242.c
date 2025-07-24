//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

struct Elevator {
    int current_floor;  // The current floor where the elevator is
    int direction;  // 1 for up and -1 for down
    int max_floor;  // The topmost floor the elevator can go
    int min_floor;  // The ground floor
    int current_passengers;  // The number of passengers in the elevator
    int max_passengers;  // The maximum number of passengers the elevator can hold
    int floors_visited[100];  // An array to keep track of the floors visited by the elevator
    int num_floors_visited;  // The number of floors visited by the elevator
};

// Function to initialize the elevator
void initialize(struct Elevator *elevator) {
    elevator->current_floor = 0;
    elevator->direction = 1;
    elevator->max_floor = 10;
    elevator->min_floor = 0;
    elevator->current_passengers = 0;
    elevator->max_passengers = 5;
    elevator->floors_visited[0] = 0;
    elevator->num_floors_visited = 1;
}

// Function to move the elevator
void move_elevator(struct Elevator *elevator) {
    elevator->current_floor += elevator->direction;
    elevator->floors_visited[elevator->num_floors_visited] = elevator->current_floor;
    elevator->num_floors_visited++;
    printf("Elevator moved to floor %d\n", elevator->current_floor);
}

// Function to add passengers to the elevator
void add_passengers(struct Elevator *elevator, int num_passengers) {
    if (elevator->current_passengers + num_passengers > elevator->max_passengers) {
        printf("Elevator full! Cannot add passengers.\n");
    } else {
        printf("Added %d passengers to elevator.\n", num_passengers);
        elevator->current_passengers += num_passengers;
    }
}

// Function to remove passengers from the elevator
void remove_passengers(struct Elevator *elevator, int num_passengers) {
    if (elevator->current_passengers - num_passengers < 0) {
        printf("Elevator empty! Cannot remove passengers.\n");
    } else {
        printf("Removed %d passengers from elevator.\n", num_passengers);
        elevator->current_passengers -= num_passengers;
    }
}

// Function to simulate the elevator's movement
void simulate_elevator(struct Elevator *elevator) {
    while (1) {
        if (elevator->direction == 1 && elevator->current_floor == elevator->max_floor) {
            elevator->direction = -1;
        } else if (elevator->direction == -1 && elevator->current_floor == elevator->min_floor) {
            elevator->direction = 1;
        }

        // Check if there are passengers waiting on the current floor
        if (elevator->current_floor == 2) {
            add_passengers(elevator, 2);
        } else if (elevator->current_floor == 5) {
            remove_passengers(elevator, 1);
        }

        move_elevator(elevator);

        // Check if the elevator has visited all floors
        if (elevator->num_floors_visited == elevator->max_floor - elevator->min_floor + 1) {
            break;
        }
    }

    printf("Elevator simulation complete. Visited floors:\n");
    for (int i = 0; i < elevator->num_floors_visited; i++) {
        printf("%d ", elevator->floors_visited[i]);
    }
}

int main() {
    struct Elevator elevator;
    initialize(&elevator);
    simulate_elevator(&elevator);
    return 0;
}