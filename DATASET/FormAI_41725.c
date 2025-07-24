//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

/**
 * Constants for elevator simulation
 */
#define FLOORS 10
#define MAX_PASSENGERS 10

/**
 * Enum for direction of elevator
 */
enum direction {
    UP, DOWN, IDLE
};

/**
 * Passenger struct to hold information about each passenger
 */
typedef struct passenger {
    int id;
    int current_floor;
    int destination_floor;
} Passenger;

/**
 * Elevator struct to hold information about the elevator
 */
typedef struct elevator {
    int current_floor;
    Passenger passengers[MAX_PASSENGERS];
    int num_passengers;
    enum direction direction;
} Elevator;

/**
 * Function to print the status of the elevator
 */
void print_elevator_status(Elevator e) {
    printf("Elevator Status: Currently on floor %d, going ", e.current_floor);
    if (e.direction == UP) {
        printf("up\n");
    } else if (e.direction == DOWN) {
        printf("down\n");
    } else {
        printf("nowhere\n");
    }
    printf("Number of Passengers: %d\n", e.num_passengers);
    printf("Passengers: ");
    for (int i = 0; i < e.num_passengers; i++) {
        printf("P%d(%d->%d) ", e.passengers[i].id, e.passengers[i].current_floor, e.passengers[i].destination_floor);
    }
    printf("\n");
}

/**
 * Function to initialize the elevator
 * Starts on floor 1, with direction IDLE, and no passengers
 */
Elevator init_elevator() {
    Elevator e;
    e.current_floor = 1;
    e.num_passengers = 0;
    e.direction = IDLE;
    return e;
}

/**
 * Function to initialize a passenger with the given id, current floor, 
 * and destination floor
 */
Passenger init_passenger(int id, int current_floor, int destination_floor) {
    Passenger p;
    p.id = id;
    p.current_floor = current_floor;
    p.destination_floor = destination_floor;
    return p;
}

/**
 * Function to check if the current floor is a destination floor for any passengers
 * and remove them from the elevator
 */
void check_and_remove_passengers(Elevator *e) {
    bool removed_passenger = false;
    for (int i = 0; i < e->num_passengers; i++) {
        if (e->passengers[i].destination_floor == e->current_floor) {
            printf("P%d left the elevator on floor %d\n", e->passengers[i].id, e->current_floor);
            e->num_passengers--;
            removed_passenger = true;
            for (int j = i; j < e->num_passengers; j++) {
                e->passengers[j] = e->passengers[j+1];
            }
            break;
        }
    }
    if (removed_passenger) {
        sleep(2);
        print_elevator_status(*e);
    }
}

/**
 * Function to check if the elevator is full
 * Returns true if elevator is full, false otherwise
 */
bool elevator_full(Elevator e) {
    return (e.num_passengers == MAX_PASSENGERS);
}

/**
 * Function to check if there are passengers waiting on the current floor
 * Returns true if there are passengers, false otherwise
 */
bool passengers_waiting(int current_floor, Passenger *passengers, int num_passengers) {
    for (int i = 0; i < num_passengers; i++) {
        if (passengers[i].current_floor == current_floor) {
            return true;
        }
    }
    return false;
}

/**
 * Function to check if there are any passengers in the elevator
 * Returns true if there are passengers, false otherwise
 */
bool passengers_in_elevator(Elevator e) {
    return (e.num_passengers > 0);
}

/**
 * Function to add a passenger to the elevator
 * Returns true if passenger was successfully added, false otherwise (elevator was full)
 */
bool add_passenger_to_elevator(Elevator *e, Passenger p) {
    if (elevator_full(*e)) {
        return false;
    }
    e->passengers[e->num_passengers] = p;
    e->num_passengers++;
    return true;
}

/**
 * Main function to simulate the elevator system
 */
int main() {
    // initialize elevator and passengers
    Elevator e = init_elevator();
    Passenger passengers[MAX_PASSENGERS] = {
        init_passenger(1, 1, 5),
        init_passenger(2, 2, 7),
        init_passenger(3, 3, 2),
        init_passenger(4, 4, 9),
        init_passenger(5, 5, 1),
        init_passenger(6, 6, 3),
        init_passenger(7, 7, 8),
        init_passenger(8, 8, 4),
        init_passenger(9, 9, 6),
        init_passenger(10, 10, 2)
    };
    int num_passengers = sizeof(passengers)/sizeof(passengers[0]);

    printf("Elevator Simulation starting...\n");
    print_elevator_status(e);

    // loop through floors in increasing order
    for (int current_floor = 1; current_floor <= FLOORS; current_floor++) {
        // first check if any passengers want to leave the elevator
        check_and_remove_passengers(&e);

        // then check if any passengers want to enter the elevator
        if (passengers_waiting(current_floor, passengers, num_passengers)) {
            for (int i = 0; i < num_passengers; i++) {
                if (passengers[i].current_floor == current_floor) {
                    if (add_passenger_to_elevator(&e, passengers[i])) {
                        printf("P%d entered the elevator on floor %d\n", passengers[i].id, current_floor);
                        for (int j = i; j < num_passengers; j++) {
                            passengers[j] = passengers[j+1];
                        }
                        num_passengers--;
                        i--;
                    } else {
                        printf("Elevator is full. P%d has to wait on floor %d\n", passengers[i].id, current_floor);
                    }
                }
            }
            sleep(2);
            print_elevator_status(e);
        }

        // finally, decide on the direction of elevator
        if (passengers_in_elevator(e)) {
            if (e.direction == IDLE) {
                if (e.current_floor < e.passengers[0].destination_floor) {
                    e.direction = UP;
                } else {
                    e.direction = DOWN;
                }
            }
            if (e.direction == UP && current_floor == FLOORS) {
                e.direction = DOWN;
            }
            if (e.direction == DOWN && current_floor == 1) {
                e.direction = UP;
            }
            e.current_floor = (e.direction == UP) ? e.current_floor + 1 : e.current_floor - 1;
        } else {
            e.direction = IDLE;
        }
    }

    printf("Elevator Simulation ending...\n");
    return 0;
}