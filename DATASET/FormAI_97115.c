//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: peaceful
#include <stdio.h>
#include <stdbool.h>

#define NUMBER_OF_FLOORS 10
#define ELEVATOR_CAPACITY 8

typedef enum {IDLE, MOVING_UP, MOVING_DOWN} elevator_state_t;

typedef struct {
    int current_floor;
    int destination_floors[ELEVATOR_CAPACITY];
    int num_passengers;
    elevator_state_t state;
} elevator_t;

void print_elevator_state(elevator_t *elevator) {
    printf("Current floor: %d\n", elevator->current_floor);
    printf("Destination floors: ");
    for(int i = 0; i < ELEVATOR_CAPACITY; i++) {
        if(elevator->destination_floors[i] != -1) {
            printf("%d ", elevator->destination_floors[i]);
        }
    }
    printf("\n");
    printf("Number of passengers: %d\n", elevator->num_passengers);
    printf("State: ");
    switch(elevator->state) {
        case IDLE: printf("IDLE\n"); break;
        case MOVING_UP: printf("MOVING_UP\n"); break;
        case MOVING_DOWN: printf("MOVING_DOWN\n"); break;
    }
}

void initialize_elevator(elevator_t *elevator) {
    elevator->current_floor = 0;
    for(int i = 0; i < ELEVATOR_CAPACITY; i++) {
        elevator->destination_floors[i] = -1;
    }
    elevator->num_passengers = 0;
    elevator->state = IDLE;
}

bool check_destination_floors(elevator_t *elevator) {
    for(int i = 0; i < ELEVATOR_CAPACITY; i++) {
        if(elevator->destination_floors[i] != -1) {
            return true;
        }
    }
    return false;
}

int main() {
    elevator_t elevator;
    initialize_elevator(&elevator);
    print_elevator_state(&elevator);

    int destination_floor;
    while(true) {
        printf("Enter the destination floor (-1 to exit): ");
        scanf("%d", &destination_floor);
        if(destination_floor == -1) {
            break;
        }
        if(destination_floor < 0 || destination_floor >= NUMBER_OF_FLOORS) {
            printf("Invalid floor\n");
            continue;
        }
        if(elevator.num_passengers == ELEVATOR_CAPACITY) {
            printf("Elevator is full\n");
            continue;
        }
        elevator.destination_floors[elevator.num_passengers] = destination_floor;
        elevator.num_passengers++;
        if(elevator.current_floor == destination_floor) {
            printf("Already on destination floor\n");
            continue;
        }
        if(elevator.current_floor < destination_floor) {
            elevator.state = MOVING_UP;
        }
        else {
            elevator.state = MOVING_DOWN;
        }
        while(check_destination_floors(&elevator)) {
            if(elevator.state == MOVING_UP) {
                elevator.current_floor++;
            }
            else if(elevator.state == MOVING_DOWN) {
                elevator.current_floor--;
            }
            for(int i = 0; i < ELEVATOR_CAPACITY; i++) {
                if(elevator.destination_floors[i] == elevator.current_floor) {
                    printf("Passenger dropped off at floor %d\n", elevator.current_floor);
                    elevator.destination_floors[i] = -1;
                    elevator.num_passengers--;
                }
            }
            printf("Elevator at floor %d\n", elevator.current_floor);
        }
        elevator.state = IDLE;
    }
    return 0;
}