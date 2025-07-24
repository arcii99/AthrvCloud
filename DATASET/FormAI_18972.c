//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FLOORS 20
#define MAX_PASSENGERS 10
#define MAX_WAIT_TIME 60
#define MAX_TRAVEL_TIME 10

typedef struct {
    int current_floor;
    int destination_floor;
    int wait_time;
    int travel_time;
} Passenger;

typedef struct {
    int current_floor;
    int direction; // -1 down, 1 up
    int num_passengers;
    Passenger passengers[MAX_PASSENGERS];
} Elevator;

int get_random_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void print_elevator_status(Elevator *elevator) {
    printf("Elevator is on the floor %d, going %s with %d passengers.\n",
           elevator->current_floor, elevator->direction == -1 ? "down" : "up", elevator->num_passengers);
}

void print_passenger_status(Passenger *passenger) {
    printf("Passenger is on the floor %d, going to the floor %d, waiting for %d seconds, "
           "and will take %d seconds to travel.\n",
           passenger->current_floor, passenger->destination_floor, passenger->wait_time, passenger->travel_time);
}

int main() {
    srand(time(NULL));
    Elevator elevator = {1, 1, 0};
    Passenger passengers[MAX_PASSENGERS];
    int num_passengers = 0;

    while (1) {
        // Spawn new passenger
        if (num_passengers < MAX_PASSENGERS && get_random_int(0, 1)) {
            Passenger new_passenger = {get_random_int(1, MAX_FLOORS),
                                       get_random_int(1, MAX_FLOORS),
                                       get_random_int(1, MAX_WAIT_TIME),
                                       get_random_int(1, MAX_TRAVEL_TIME)};
            print_passenger_status(&new_passenger);
            passengers[num_passengers++] = new_passenger;
        }

        // Move elevator
        if (elevator.direction == 1) {
            elevator.current_floor++;
        } else {
            elevator.current_floor--;
        }
        print_elevator_status(&elevator);

        // Check if any passenger has arrived
        int i = 0;
        while (i < num_passengers) {
            if (passengers[i].current_floor == elevator.current_floor) {
                printf("Passenger arrived at floor %d.\n", elevator.current_floor);
                if (elevator.num_passengers < MAX_PASSENGERS) {
                    elevator.passengers[elevator.num_passengers++] = passengers[i];
                    printf("Passenger entered the elevator.\n");
                } else {
                    printf("Elevator is full. Passenger could not enter the elevator.\n");
                }
                passengers[i] = passengers[--num_passengers];
            } else {
                i++;
            }
        }

        // Check if any passenger wanted to get off
        i = 0;
        while (i < elevator.num_passengers) {
            if (elevator.passengers[i].destination_floor == elevator.current_floor) {
                printf("Passenger reached the destination floor %d and left the elevator.\n", elevator.current_floor);
                elevator.passengers[i] = elevator.passengers[--elevator.num_passengers];
            } else {
                i++;
            }
        }

        // Check direction and change if necessary
        if (elevator.current_floor == 1) {
            elevator.direction = 1;
        } else if (elevator.current_floor == MAX_FLOORS) {
            elevator.direction = -1;
        }

        // Wait some time before continuing
        sleep(1);
    }

    return 0;
}