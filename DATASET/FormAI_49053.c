//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_FLOORS 20
#define MAX_PASSENGERS 10

// Create struct for passenger
typedef struct {
    int start_floor;
    int end_floor;
    bool arrived;
} Passenger;

// Create struct for elevator
typedef struct {
    int current_floor;
    int destination_floor;
    bool door_open;
    Passenger passengers[MAX_PASSENGERS];
    int num_passengers;
} Elevator;

// Function to print elevator status
void print_elevator_status(Elevator* elevator) {
    printf("Floor %d, Door %s, ",
           elevator->current_floor,
           elevator->door_open ? "Open" : "Closed");

    if (elevator->num_passengers == 0) {
        printf("No passengers\n");
    } else {
        printf("Passengers: ");

        for (int i = 0; i < elevator->num_passengers; i++) {
            Passenger* passenger = &(elevator->passengers[i]);
            printf("[%d->%d%s] ",
                   passenger->start_floor,
                   passenger->end_floor,
                   passenger->arrived ? "(Arrived)" : "");
        }

        printf("\n");
    }
}

// Function to move elevator to destination floor
void move_elevator(Elevator* elevator) {
    int direction = elevator->destination_floor - elevator->current_floor;

    if (direction > 0) {
        printf("Moving up...\n");

        for (int i = elevator->current_floor; i <= elevator->destination_floor; i++) {
            elevator->current_floor = i;
            printf("Elevator at floor %d\n", i);
        }
    } else if (direction < 0) {
        printf("Moving down...\n");

        for (int i = elevator->current_floor; i >= elevator->destination_floor; i--) {
            elevator->current_floor = i;
            printf("Elevator at floor %d\n", i);
        }
    }

    elevator->door_open = true;
}

int main() {
    Elevator elevator = {
        .current_floor = 1,
        .destination_floor = 1,
        .door_open = true,
        .num_passengers = 0
    };

    Passenger passengers[MAX_FLOORS] = {};

    // Generate random passengers
    for (int i = 1; i <= MAX_FLOORS; i++) {
        int num_passengers = rand() % 3;

        for (int j = 0; j < num_passengers; j++) {
            Passenger passenger = {
                .start_floor = i,
                .end_floor = rand() % MAX_FLOORS + 1,
                .arrived = false
            };

            passengers[i - 1] = passenger;
        }
    }

    while (true) {
        // Print elevator status
        print_elevator_status(&elevator);

        // Check if elevator is at destination floor
        if (elevator.current_floor == elevator.destination_floor) {
            elevator.door_open = true;

            // Let passengers exit elevator
            for (int i = 0; i < elevator.num_passengers; i++) {
                Passenger* passenger = &(elevator.passengers[i]);

                if (passenger->end_floor == elevator.current_floor) {
                    passenger->arrived = true;
                    printf("Passenger [%d->%d] has arrived!\n", passenger->start_floor, passenger->end_floor);
                }
            }

            // Remove arrived passengers from elevator
            for (int i = 0; i < elevator.num_passengers; i++) {
                if (elevator.passengers[i].arrived) {
                    elevator.num_passengers--;

                    for (int j = i; j < elevator.num_passengers; j++) {
                        elevator.passengers[j] = elevator.passengers[j+1];
                    }
                }
            }

            // Let passengers enter elevator
            for (int i = 0; i < MAX_PASSENGERS; i++) {
                Passenger* passenger = &(passengers[elevator.current_floor - 1]);

                if (elevator.num_passengers < MAX_PASSENGERS && passenger->start_floor == elevator.current_floor) {
                    elevator.passengers[elevator.num_passengers] = *passenger;
                    elevator.num_passengers++;
                    passenger->start_floor = 0;
                    printf("Passenger [%d->%d] has entered elevator!\n", passenger->start_floor, passenger->end_floor);
                }
            }

            // Choose next destination floor
            int destination_floor = 0;

            for (int i = 0; i < MAX_FLOORS; i++) {
                for (int j = 0; j < elevator.num_passengers; j++) {
                    Passenger* passenger = &(elevator.passengers[j]);

                    if (!passenger->arrived && passenger->end_floor == i+1) {
                        destination_floor = i+1;
                        break;
                    }
                }

                if (destination_floor > 0) {
                    break;
                }
            }

            elevator.destination_floor = destination_floor;
        }

        // Move elevator to destination floor
        if (elevator.door_open) {
            move_elevator(&elevator);
            elevator.door_open = false;
        }
    }

    return 0;
}