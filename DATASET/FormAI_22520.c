//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: standalone
#include <stdio.h>
#include <stdbool.h>

// Define Constants for Elevator Capacity and Number of Floors
#define CAPACITY 10
#define NUM_FLOORS 6

// Define Struct for Passenger 
struct Passenger {
    int current_floor;
    int destination_floor;
};

// Define Struct for Elevator
struct Elevator {
    int current_floor;
    int num_passengers;
    struct Passenger passengers[CAPACITY];
};

// Define Function to Check if Elevator is at Floor
bool is_at_floor(struct Elevator *elevator, int floor) {
    if (elevator->current_floor == floor) {
        printf("Elevator is now at floor %d.\n", floor);
        return true;
    }
    return false;
}

// Define Function to Board Passenger
void board_passenger(struct Elevator *elevator, struct Passenger passenger) {
    if (elevator->num_passengers < CAPACITY) {
        elevator->passengers[elevator->num_passengers] = passenger;
        elevator->num_passengers++;
        printf("Passenger boarded elevator at floor %d.\n", passenger.current_floor);
    } else {
        printf("Elevator is at capacity. Passenger at floor %d cannot board.\n", passenger.current_floor);
    }
}

// Define Function to Disembark Passenger
void disembark_passenger(struct Elevator *elevator, int index) {
    printf("Passenger disembarked elevator at floor %d.\n", elevator->passengers[index].destination_floor);
    elevator->num_passengers--;
    for (int i = index; i < elevator->num_passengers; i++) {
        elevator->passengers[i] = elevator->passengers[i+1];
    }
}

// Define Main Function
int main() {
    // Initialize Elevator and Passengers
    struct Elevator elevator = {1, 0};
    struct Passenger p1 = {1, 6};
    struct Passenger p2 = {2, 5};
    struct Passenger p3 = {3, 4};
    
    // Elevator Simulation
    while (true) {
        // Check if Elevator is at a Floor
        for (int i = 1; i <= NUM_FLOORS; i++) {
            if (is_at_floor(&elevator, i)) {
                // Disembark Passengers
                for (int j = 0; j < elevator.num_passengers; j++) {
                    if (elevator.passengers[j].destination_floor == i) {
                        disembark_passenger(&elevator, j);
                        j--;
                    }
                }
                // Board Passengers
                if (i == p1.current_floor) {
                    board_passenger(&elevator, p1);
                }
                if (i == p2.current_floor) {
                    board_passenger(&elevator, p2);
                }
                if (i == p3.current_floor) {
                    board_passenger(&elevator, p3);
                }
            }
        }
        // Move Elevator Up or Down
        if (elevator.num_passengers > 0) {
            elevator.current_floor = elevator.passengers[0].destination_floor;
        }
    }

    return 0;
}