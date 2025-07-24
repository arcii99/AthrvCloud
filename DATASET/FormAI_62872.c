//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdbool.h>

#define NUM_FLOORS 10

typedef struct {
    int current_floor;
    bool doors_open;
    bool going_up;
} Elevator;

void move_elevator(Elevator* elevator, int destination_floor) {
    printf("Elevator moving from floor %d to floor %d\n", elevator->current_floor, destination_floor);
    elevator->doors_open = false; // close doors while in motion
    if (destination_floor > elevator->current_floor) {
        elevator->going_up = true;
        while (elevator->current_floor < destination_floor) {
            elevator->current_floor++;
            printf("Elevator passing floor %d\n", elevator->current_floor);
        }
    } else {
        elevator->going_up = false;
        while (elevator->current_floor > destination_floor) {
            elevator->current_floor--;
            printf("Elevator passing floor %d\n", elevator->current_floor);
        }
    }
    printf("Elevator arrived at floor %d\n", elevator->current_floor);
    elevator->doors_open = true; // open doors once arrived
}

void print_elevator_status(Elevator* elevator) {
    printf("Elevator is currently on floor %d, doors ", elevator->current_floor);
    if (elevator->doors_open) {
        printf("open\n");
    } else {
        printf("closed\n");
    }
}

int main() {
    Elevator elevator = { .current_floor = 1, .doors_open = false, .going_up = true };
    printf("Elevator simulation starting!\n");

    // Simulate someone calling the elevator from a certain floor
    int call_floor = 4;
    printf("Someone has called the elevator from floor %d\n", call_floor);
    print_elevator_status(&elevator);
    move_elevator(&elevator, call_floor);
    print_elevator_status(&elevator);

    // Simulate someone getting on the elevator and selecting a floor
    int destination_floor = 8;
    printf("Someone has entered the elevator and selected floor %d\n", destination_floor);
    move_elevator(&elevator, destination_floor);

    // Simulate someone getting off the elevator
    printf("Someone has gotten off the elevator on floor %d\n", elevator.current_floor);

    printf("Elevator simulation complete!\n");
    return 0;
}