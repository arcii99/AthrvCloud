//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: modular
#include <stdio.h>
#include <stdbool.h>

#define NUM_FLOORS 6
#define ELEVATOR_CAPACITY 10

typedef struct {
    int current_floor;
    int destination[NUM_FLOORS];
    bool up_direction;
    bool down_direction;
    int num_passengers;
    int passengers[ELEVATOR_CAPACITY];
} Elevator;

void initialize_elevator(Elevator *elevator) {
    elevator->current_floor = 0;
    for(int i = 0; i < NUM_FLOORS; i++) {
        elevator->destination[i] = 0;
    }
    elevator->up_direction = true;
    elevator->down_direction = false;
    elevator->num_passengers = 0;
}

void elevator_arrive_at_floor(Elevator *elevator, int floor) {
    elevator->current_floor = floor;
    if(elevator->destination[floor] > 0) {
        printf("Elevator has arrived at floor %d\n", floor);
        printf("Passengers getting off:\n");
        for(int i = 0; i < elevator->num_passengers; i++) {
            if(elevator->passengers[i] == floor) {
                printf("- Passenger %d\n", i+1);
                elevator->passengers[i] = -1;
                elevator->destination[floor]--;
                elevator->num_passengers--;
            }
        }
    }
    if(elevator->up_direction && floor < NUM_FLOORS-1) {
        elevator->up_direction = false;
        elevator->down_direction = true;
    } else if(elevator->down_direction && floor > 0) {
        elevator->down_direction = false;
        elevator->up_direction = true;
    }
}

bool elevator_is_full(Elevator *elevator) {
    return elevator->num_passengers == ELEVATOR_CAPACITY;
}

int add_passenger_to_elevator(Elevator *elevator, int floor) {
    if(elevator_is_full(elevator)) {
        return -1;
    } else {
        elevator->passengers[elevator->num_passengers] = floor;
        elevator->destination[floor]++;
        elevator->num_passengers++;
        return elevator->num_passengers;
    }
}

int main() {
    Elevator elevator;
    initialize_elevator(&elevator);

    add_passenger_to_elevator(&elevator, 2);
    add_passenger_to_elevator(&elevator, 2);
    add_passenger_to_elevator(&elevator, 3);

    for(int i = 0; i < NUM_FLOORS; i++) {
        elevator_arrive_at_floor(&elevator, i);
    }

    add_passenger_to_elevator(&elevator, 4);

    for(int i = NUM_FLOORS-1; i >= 0; i--) {
        elevator_arrive_at_floor(&elevator, i);
    }

    return 0;
}