//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEVATORS 5
#define MAX_FLOORS 20

typedef enum {
    UP,
    DOWN,
    IDLE
} ElevatorDirection;

typedef struct {
    int num_floors;
    int current_floor;
    ElevatorDirection direction;
    int stops[MAX_FLOORS];
    int num_stops;
} Elevator;

Elevator elevators[MAX_ELEVATORS];

void move_elevator(Elevator *elevator) {
    if (elevator->direction == UP) {
        elevator->current_floor++;
    } else if (elevator->direction == DOWN) {
        elevator->current_floor--;
    }

    for (int i = 0; i < elevator->num_stops; i++) {
        if (elevator->stops[i] == elevator->current_floor) {
            // We have arrived at a stop
            printf("Elevator #%d has arrived at floor %d\n", elevator - elevators, elevator->current_floor);
            for (int j = i; j < elevator->num_stops - 1; j++) {
                elevator->stops[j] = elevator->stops[j+1];
            }
            elevator->num_stops--;
            return;
        }
    }
}

void print_status() {
    for (int i = 0; i < MAX_ELEVATORS; i++) {
        if (elevators[i].num_stops > 0) {
            printf("Elevator #%d is going %s and currently at floor %d with stops at: ", i, elevators[i].direction == UP ? "up" : "down", elevators[i].current_floor);
            for (int j = 0; j < elevators[i].num_stops; j++) {
                printf("%d ", elevators[i].stops[j]);
            }
            printf("\n");
        } else {
            printf("Elevator #%d is idle and currently at floor %d\n", i, elevators[i].current_floor);
        }
    }
}

int main() {
    for (int i = 0; i < MAX_ELEVATORS; i++) {
        elevators[i].num_floors = MAX_FLOORS;
        elevators[i].current_floor = 1;
        elevators[i].direction = IDLE;
        elevators[i].num_stops = 0;
    }

    elevators[0].stops[0] = 5;
    elevators[0].num_stops++;

    elevators[1].stops[0] = 10;
    elevators[1].num_stops++;
    elevators[1].stops[1] = 3;
    elevators[1].num_stops++;

    elevators[3].stops[0] = 15;
    elevators[3].num_stops++;
    elevators[3].stops[1] = 7;
    elevators[3].num_stops++;
    elevators[3].stops[2] = 11;
    elevators[3].num_stops++;

    int num_iterations = 30;
    for (int i = 0; i < num_iterations; i++) {
        printf("Iteration %d:\n", i + 1);
        for (int j = 0; j < MAX_ELEVATORS; j++) {
            if (elevators[j].num_stops > 0) {
                if (elevators[j].stops[0] > elevators[j].current_floor) {
                    elevators[j].direction = UP;
                } else if (elevators[j].stops[0] < elevators[j].current_floor) {
                    elevators[j].direction = DOWN;
                }
                move_elevator(&elevators[j]);
            } else {
                elevators[j].direction = IDLE;
            }
        }
        print_status();
        printf("\n");
    }

    return 0;
}