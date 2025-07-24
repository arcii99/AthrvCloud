//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: Donald Knuth
#include <stdio.h>
#include <stdbool.h>

#define NUM_FLOORS 10
#define NUM_ELEVATORS 3

typedef enum {IDLE, MOVING_UP, MOVING_DOWN} ElevatorState;

typedef struct {
    int current_floor;
    ElevatorState state;
    bool floor_buttons[NUM_FLOORS];
    bool door_open;
} Elevator;

int main() {
    Elevator elevators[NUM_ELEVATORS];

    // initialize elevator states
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        elevators[i].current_floor = 0;
        elevators[i].state = IDLE;
        elevators[i].door_open = false;

        for (int j = 0; j < NUM_FLOORS; j++) {
            elevators[i].floor_buttons[j] = false;
        }
    }

    int requested_floor;

    // simulate elevator requests
    while (true) {
        printf("Enter the floor you want to go to (0-%d): ", NUM_FLOORS - 1);
        scanf("%d", &requested_floor);

        if (requested_floor >= 0 && requested_floor < NUM_FLOORS) {
            // find closest idle elevator
            int min_distance = NUM_FLOORS;
            int elevator_index = -1;

            for (int i = 0; i < NUM_ELEVATORS; i++) {
                if (elevators[i].state == IDLE) {
                    int distance = abs(requested_floor - elevators[i].current_floor);

                    if (distance < min_distance) {
                        min_distance = distance;
                        elevator_index = i;
                    }
                }
            }

            if (elevator_index == -1) {
                // all elevators are busy
                printf("All elevators are currently busy. Please wait.\n");
            } else {
                // send elevator to requested floor
                Elevator* elevator = &elevators[elevator_index];

                if (requested_floor > elevator->current_floor) {
                    elevator->state = MOVING_UP;
                } else if (requested_floor < elevator->current_floor) {
                    elevator->state = MOVING_DOWN;
                }

                while (elevator->current_floor != requested_floor) {
                    if (elevator->current_floor < requested_floor) {
                        elevator->current_floor++;
                    } else if (elevator->current_floor > requested_floor) {
                        elevator->current_floor--;
                    }

                    // check if any floor buttons were pressed during movement
                    if (elevator->floor_buttons[elevator->current_floor]) {
                        elevator->floor_buttons[elevator->current_floor] = false;
                        elevator->door_open = true;

                        // wait for door to close
                        printf("Please exit the elevator.\n");
                        elevator->door_open = false;
                        elevator->state = IDLE;
                        break; // exit while loop
                    }
                }

                // elevator reached floor without button press
                elevator->door_open = true;
                printf("You have arrived at your floor.\n");
                elevator->door_open = false;
                elevator->state = IDLE;
            }
        } else {
            printf("Invalid floor number. Please choose a number between 0 and %d.\n", NUM_FLOORS - 1);
        }
    }

    return 0;
}