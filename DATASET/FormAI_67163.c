//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_FLOOR 10

typedef enum {
    IDLE,
    UP,
    DOWN
} ElevatorStatus;

typedef struct {
    int floor;
    ElevatorStatus status;
} Elevator;

typedef struct {
    Elevator elevator;
    bool floors[MAX_FLOOR];
} Building;

void initialize(Building *building);
void simulate(Building *building);
void print_status(Building *building);

int main() {
    Building building;
    initialize(&building);
    simulate(&building);
    return 0;
}

void initialize(Building *building) {
    printf("Initializing building...\n");
    building->elevator.floor = 0;
    building->elevator.status = IDLE;
    for (int i = 0; i < MAX_FLOOR; i++) {
        building->floors[i] = false;
    }
    building->floors[0] = true;
    printf("Building initialized!\n");
}

void simulate(Building *building) {
    printf("Starting simulation...\n");
    while (true) {
        print_status(building);
        switch (building->elevator.status) {
            case IDLE:
                for (int i = 0; i < MAX_FLOOR; i++) {
                    if (building->floors[i]) {
                        building->elevator.status = (i > building->elevator.floor)? UP : DOWN;
                        break;
                    }
                }
                break;
            case UP:
                if (building->floors[building->elevator.floor + 1]) {
                    building->floors[building->elevator.floor + 1] = false;
                    building->elevator.floor++;
                    building->elevator.status = IDLE;
                } else {
                    building->elevator.floor++;
                }
                break;
            case DOWN:
                if (building->floors[building->elevator.floor - 1]) {
                    building->floors[building->elevator.floor - 1] = false;
                    building->elevator.floor--;
                    building->elevator.status = IDLE;
                } else {
                    building->elevator.floor--;
                }
                break;
        }
    }
}

void print_status(Building *building) {
    printf("Floor: %d\t", building->elevator.floor);
    printf("Status: ");
    switch(building->elevator.status) {
        case IDLE:
            printf("idle\n");
            break;
        case UP:
            printf("going up\n");
            break;
        case DOWN:
            printf("going down\n");
            break;
    }
    printf("Floors: ");
    for (int i = 0; i < MAX_FLOOR; i++) {
        printf("%d ", (building->floors[i])? 1 : 0);
    }
    printf("\n");
}