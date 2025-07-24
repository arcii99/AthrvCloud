//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FLOORS 12
#define NUM_ELEVATORS 4

typedef struct {
    int floor;
    int dir;    // -1 for down, 0 for stopped, 1 for up
    int passengers[NUM_FLOORS];
} Elevator;

Elevator elevators[NUM_ELEVATORS];

int random_number(int min, int max) {
    return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

void move_elevator(Elevator* elevator) {
    int old_floor = elevator->floor;
    elevator->floor += elevator->dir;

    if (elevator->floor == 0 || elevator->floor == NUM_FLOORS - 1) {
        elevator->dir = -elevator->dir;     // change direction at top/bottom floor
    }

    int num_passengers = elevator->passengers[elevator->floor];
    if (num_passengers > 0) {
        printf("Elevator %d stopped at floor %d. %d passengers exited.\n",
            elevator - elevators, elevator->floor, num_passengers);

        elevator->passengers[elevator->floor] = 0;
    }

    num_passengers = random_number(0, 3);

    while (num_passengers > 0) {
        int dest_floor = random_number(0, NUM_FLOORS - 1);

        if (dest_floor != elevator->floor) {
            printf("Elevator %d stopped at floor %d. 1 passenger entered going to floor %d.\n",
                elevator - elevators, elevator->floor, dest_floor);

            elevator->passengers[dest_floor]++;
            num_passengers--;
        }
    }

    if (elevator->floor != old_floor) {
        printf("Elevator %d moved from floor %d to floor %d.\n",
            elevator - elevators, old_floor, elevator->floor);
    }
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < NUM_ELEVATORS; i++) {
        elevators[i].floor = NUM_FLOORS / 2;
        elevators[i].dir = i % 2 == 0 ? 1 : -1;   // alternate direction for each elevator
        elevators[i].passengers[NUM_FLOORS / 2] = random_number(0, 4);   // add initial passengers
    }

    while (1) {
        for (int i = 0; i < NUM_ELEVATORS; i++) {
            move_elevator(&elevators[i]);
        }
        printf("\n");
        fflush(stdout);
        sleep(1);
    }

    return 0;
}