//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

#define MAX_FLOORS 10
#define MAX_ELEVATORS 3

typedef enum {
    IDLE,
    MOVING_UP,
    MOVING_DOWN
} elevator_state;

typedef struct {
    int current_floor;
    int requested_floor;
    elevator_state state;
} elevator;

int main() {
    srand(time(0));

    elevator elevators[MAX_ELEVATORS];

    for (int i=0; i<MAX_ELEVATORS; i++) {
        elevators[i].current_floor = 0;
        elevators[i].requested_floor = -1;
        elevators[i].state = IDLE;
    }

    int total_requests = 0;
    int total_completed_requests = 0;

    int floor_requests[MAX_FLOORS] = {0};

    while (total_completed_requests < 25) {

        // randomly generate floor requests
        for (int i=0; i<MAX_FLOORS; i++) {
            if (rand() % 2 == 1) {
                floor_requests[i]++;
                elevators[0].requested_floor = i;
                total_requests++;
            }
        }

        // update elevator states and move elevators
        for (int i=0; i<MAX_ELEVATORS; i++) {
            if (elevators[i].requested_floor != -1) {
                if (elevators[i].requested_floor > elevators[i].current_floor) {
                    elevators[i].state = MOVING_UP;
                } else if (elevators[i].requested_floor < elevators[i].current_floor) {
                    elevators[i].state = MOVING_DOWN;
                } else {
                    elevators[i].state = IDLE;
                    floor_requests[elevators[i].current_floor]--;
                    total_completed_requests++;
                }
            }
        }

        // print elevator and floor information
        printf("====================\n");
        printf("Total Requests: %d\n", total_requests);
        printf("Completed Requests: %d\n", total_completed_requests);
        printf("--------------------\n");

        for (int i=MAX_FLOORS-1; i>=0; i--) {
            printf("Floor %d |", i);
            if (i == elevators[0].current_floor) {
                printf("| E ");
            } else {
                printf("|   ");
            }
            printf("| %-2d |\n", floor_requests[i]);
        }
        printf("--------------------\n");

        for (int i=0; i<MAX_ELEVATORS; i++) {
            printf("Elevator %d: \n", i);
            printf("Current Floor: %d\n", elevators[i].current_floor);
            printf("Requested Floor: %d\n", elevators[i].requested_floor);
            printf("State: %d\n", elevators[i].state);
            printf("--------------------\n");
            if (elevators[i].state == MOVING_UP) {
                elevators[i].current_floor++;
            } else if (elevators[i].state == MOVING_DOWN) {
                elevators[i].current_floor--;
            }
        }
    }

    return 0;
}