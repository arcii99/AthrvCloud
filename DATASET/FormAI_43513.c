//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_FLOORS 10
#define MAX_PASSENGERS 5

typedef struct {
    int current_floor;
    int destination_floor;
} Passenger;

typedef struct {
    int current_floor;
    int direction; // up = 1, down = -1, stopped = 0
    int num_passengers;
    Passenger passengers[MAX_PASSENGERS];
} Elevator;

int get_random_floor(int current_floor) {
    int random_floor = current_floor;
    while (random_floor == current_floor) {
        random_floor = rand() % MAX_FLOORS + 1;
    }
    return random_floor;
}

void print_elevator_status(Elevator elevator) {
    printf("Current floor: %d, Direction: %s, Number of passengers: %d\n", 
            elevator.current_floor, 
            elevator.direction == 1 ? "up" : elevator.direction == -1 ? "down" : "stopped",
            elevator.num_passengers);
}

void board_passenger(Elevator *elevator, Passenger passenger) {
    if (elevator->num_passengers < MAX_PASSENGERS) {
        elevator->passengers[elevator->num_passengers] = passenger;
        elevator->num_passengers++;
        printf("Passenger boarded the elevator at floor %d.\n", elevator->current_floor);
        print_elevator_status(*elevator);
    } else {
        printf("Elevator is full. Passenger cannot board.\n");
    }
}

void disembark_passengers(Elevator *elevator) {
    for (int i = 0; i < elevator->num_passengers; i++) {
        if (elevator->passengers[i].destination_floor == elevator->current_floor) {
            elevator->num_passengers--;
            printf("Passenger disembarked at floor %d.\n", elevator->current_floor);
            print_elevator_status(*elevator);
            for (int j = i; j < elevator->num_passengers; j++) {
                elevator->passengers[j] = elevator->passengers[j+1];
            }
        }
    }
}

void move_elevator(Elevator *elevator) {
    elevator->current_floor += elevator->direction;
    printf("Elevator moved to floor %d.\n", elevator->current_floor);
    print_elevator_status(*elevator);
}

void run_elevator_simulation() {
    Elevator elevator = {1, 1, 0, {}};
    print_elevator_status(elevator);
    while (1) {
        if (elevator.num_passengers == MAX_PASSENGERS) {
            printf("Elevator full. Moving to destination floors of passengers.\n");
            while (elevator.num_passengers > 0) {
                disembark_passengers(&elevator);
                if (elevator.num_passengers == 0) break;
                elevator.direction = elevator.current_floor < elevator.passengers[0].destination_floor ? 1 : -1;
                move_elevator(&elevator);
            }
            elevator.direction = 0;
            print_elevator_status(elevator);
        } else {
            int random_floor = get_random_floor(elevator.current_floor);
            Passenger passenger = {elevator.current_floor, random_floor};
            board_passenger(&elevator, passenger);
        }
    }
}

int main() {
    run_elevator_simulation();
    return 0;
}