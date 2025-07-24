//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_FLOORS 10
#define MIN_FLOORS 5
#define NUM_ELEVATORS 3

typedef struct {
    int min_floor;
    int max_floor;
    int current_floor;
    int target_floor;
    bool in_use;
} Elevator;

void initialize_elevators(Elevator elevators[]);
void print_elevator_status(Elevator elevators[]);
int get_random_floor(int min_floor, int max_floor);
int get_random_elevator(Elevator elevators[]);
void update_elevator_status(Elevator *elevator);

int main() {
    srand(time(NULL));

    Elevator elevators[NUM_ELEVATORS];
    initialize_elevators(elevators);

    while (1) {
        print_elevator_status(elevators);

        if (rand() % 2) {
            int floor = get_random_floor(MIN_FLOORS, MAX_FLOORS);
            printf("\nA passenger has pressed the button on floor %d\n", floor);

            int elevator_id = get_random_elevator(elevators);

            if (elevator_id == -1) {
                printf("No elevators available. Please wait.\n");
            } else {
                printf("Elevator %d has been assigned to floor %d\n", elevator_id, floor);
                Elevator *elevator = &elevators[elevator_id];
                elevator->target_floor = floor;
                elevator->in_use = true;
            }
        }

        for (int i = 0; i < NUM_ELEVATORS; i++) {
            Elevator *elevator = &elevators[i];

            if (elevator->in_use) {
                update_elevator_status(elevator);

                if (elevator->current_floor == elevator->target_floor) {
                    printf("\nElevator %d has arrived at floor %d\n", i, elevator->current_floor);
                    elevator->in_use = false;
                }
            } else {
                elevator->target_floor = -1;
            }
        }

        printf("\n");
        getchar();
    }
}

void initialize_elevators(Elevator elevators[]) {
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        Elevator *elevator = &elevators[i];
        elevator->min_floor = MIN_FLOORS;
        elevator->max_floor = MAX_FLOORS;
        elevator->current_floor = MIN_FLOORS;
        elevator->target_floor = -1;
        elevator->in_use = false;
    }
}

void print_elevator_status(Elevator elevators[]) {
    printf("\n");
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        Elevator *elevator = &elevators[i];

        if (elevator->in_use) {
            printf("Elevator %d: occupied, currently on floor %d, heading to floor %d\n", i, elevator->current_floor, elevator->target_floor);
        } else if (elevator->target_floor != -1) {
            printf("Elevator %d: available, currently on floor %d, en route to floor %d\n", i, elevator->current_floor, elevator->target_floor);
        } else {
            printf("Elevator %d: available, currently on floor %d, not in use\n", i, elevator->current_floor);
        }
    }
}

int get_random_floor(int min_floor, int max_floor) {
    return (rand() % (max_floor - min_floor + 1)) + min_floor;
}

int get_random_elevator(Elevator elevators[]) {
    int available_elevators[NUM_ELEVATORS];
    int num_available_elevators = 0;

    for (int i = 0; i < NUM_ELEVATORS; i++) {
        Elevator *elevator = &elevators[i];

        if (!elevator->in_use) {
            available_elevators[num_available_elevators] = i;
            num_available_elevators++;
        }
    }

    if (num_available_elevators == 0) {
        return -1;
    }

    return available_elevators[rand() % num_available_elevators];
}

void update_elevator_status(Elevator *elevator) {
    if (elevator->current_floor < elevator->target_floor) {
        elevator->current_floor++;
    } else if (elevator->current_floor > elevator->target_floor) {
        elevator->current_floor--;
    }
}