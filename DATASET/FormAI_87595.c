//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: complete
#include <stdio.h>

#define MAX_FLOOR 10
#define NUM_ELEVATORS 3

typedef enum {
    IDLE,
    GOING_UP,
    GOING_DOWN,
    MAINTENANCE
} ElevatorState;

typedef struct {
    int current_floor;
    int destination_floor;
    ElevatorState state;
} Elevator;

Elevator elevators[NUM_ELEVATORS];

void initialize_elevators() {
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        elevators[i].current_floor = 1;
        elevators[i].destination_floor = 1;
        elevators[i].state = IDLE;
    }
}

void print_elevator_status() {
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        printf("Elevator %d: Floor %d, Destination: %d, State: %d\n",
               i+1, elevators[i].current_floor, elevators[i].destination_floor, elevators[i].state);
    }
}

void move_elevators() {
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        switch (elevators[i].state) {
            case IDLE:
                break;
            case GOING_UP:
                elevators[i].current_floor++;
                if (elevators[i].current_floor == elevators[i].destination_floor) {
                    elevators[i].state = IDLE;
                }
                break;
            case GOING_DOWN:
                elevators[i].current_floor--;
                if (elevators[i].current_floor == elevators[i].destination_floor) {
                    elevators[i].state = IDLE;
                }
                break;
            case MAINTENANCE:
                break;
        }
    }
}

void assign_elevator(int floor, int direction) {
    int min_diff = MAX_FLOOR;
    int chosen_elevator = -1;
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        if (elevators[i].state == MAINTENANCE)
            continue;
        int distance = abs(elevators[i].current_floor - floor);
        if (distance < min_diff) {
            if (elevators[i].state == IDLE) {
                chosen_elevator = i;
                min_diff = distance;
            } else if ((elevators[i].state == GOING_UP && direction == 1) ||
                       (elevators[i].state == GOING_DOWN && direction == -1)) {
                chosen_elevator = i;
                min_diff = distance;
            }
        }
    }
    if (chosen_elevator != -1) {
        printf("Assigning elevator %d to floor %d\n", chosen_elevator+1, floor);
        elevators[chosen_elevator].destination_floor = floor;
        elevators[chosen_elevator].state = floor > elevators[chosen_elevator].current_floor ? GOING_UP : GOING_DOWN;
    } else {
        printf("No available elevators to take you to floor %d\n", floor);
    }
}

int main() {
    initialize_elevators();
    print_elevator_status();

    // simulate some traffic
    assign_elevator(5, 1);
    assign_elevator(9, -1);
    assign_elevator(2, 1);
    assign_elevator(4, -1);

    // move elevators and print status
    move_elevators();
    printf("\n");
    print_elevator_status();

    return 0;
}