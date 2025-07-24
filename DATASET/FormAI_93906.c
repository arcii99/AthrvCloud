//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FLOORS 10
#define DOORS_OPEN_DELAY 3

typedef enum {
    UP = 1,
    STOPPED = 0,
    DOWN = -1
} Direction;

int current_floor = 1;
Direction current_direction = STOPPED;
int destination = -1;
int floors[NUM_FLOORS];

void sleep(int seconds) {
    clock_t start = clock();
    while((clock() - start) / CLOCKS_PER_SEC < seconds) {}
}

void open_doors() {
    printf("Doors are opening...\n");
    sleep(DOORS_OPEN_DELAY);
    printf("Doors are closing...\n");
}

void print_elevator_state() {
    printf("Elevator state:\nCurrent floor: %d\nDirection: %s\nDestination: %d\n", current_floor, current_direction == UP ? "UP" : current_direction == DOWN ? "DOWN" : "STOPPED", destination);
}

void handle_floor(int floor) {
    if (destination != -1 && destination == floor) {
        printf("Elevator arrived at destination floor %d.\n", destination);
        open_doors();
        destination = -1;
    } else if (floors[floor - 1] > 0 && (current_direction == STOPPED || current_direction == UP)) {
        printf("Elevator stopped at floor %d.\n", floor);
        open_doors();
        floors[floor - 1] = 0;
    } else if (floors[floor - 1] < 0 && (current_direction == STOPPED || current_direction == DOWN)) {
        printf("Elevator stopped at floor %d.\n", floor);
        open_doors();
        floors[floor - 1] = 0;
    }
}

int main() {
    // initialize floors to random number of people waiting
    srand(time(NULL));
    for (int i = 0; i < NUM_FLOORS; i++) {
        floors[i] = rand() % 6 - 3;
    }
    
    // loop until user quits
    while (1) {
        print_elevator_state();
        handle_floor(current_floor);
        
        // if elevator has a destination, move towards it
        if (destination != -1) {
            if (destination > current_floor) {
                current_direction = UP;
                current_floor++;
            } else if (destination < current_floor) {
                current_direction = DOWN;
                current_floor--;
            } else {
                current_direction = STOPPED;
            }
        }
        // else look for a destination
        else {
            int found_destination = 0;
            for (int i = 0; i < NUM_FLOORS; i++) {
                if (floors[i] != 0) {
                    if (i + 1 > current_floor) {
                        current_direction = UP;
                        current_floor++;
                    } else if (i + 1 < current_floor) {
                        current_direction = DOWN;
                        current_floor--;
                    } else {
                        current_direction = STOPPED;
                        found_destination = 1;
                        destination = i + 1;
                        break;
                    }
                }
            }
            if (!found_destination) {
                current_direction = STOPPED;
            }
        }
        
        // wait before moving to next floor
        sleep(1);
    }
    return 0;
}